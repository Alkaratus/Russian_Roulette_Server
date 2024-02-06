//
// Created by alkaratus on 21.12.23.
//
#include "In_Game_Lobby.h"

#include <utility>
#include "Utilities.h"
#include "In_Game_Server.h"
#include "Hard_Coded_Question_Provider.h"

using grpc::Server;
using grpc::ServerBuilder;
using std::this_thread::sleep_for;

const std::array<unsigned int,5>MONEY_FOR_ROUND={300,600,900,1200,1500};
const std::array<unsigned int,5>NUMBER_OF_QUESTIONS_FOR_ROUND={12,10,8,6,4};
const unsigned int NONE_PLAYER_MARKED=6;
const unsigned int NUMBER_OF_PLAYERS=6;

int In_Game_Lobby::next_in_game_server_port=2049;

In_Game_Lobby::In_Game_Lobby(Pre_Game_Lobby &&lobby,Messenger<std::list<In_Game_Lobby>::iterator> &running_games_messenger):
game_id(lobby.game_id),
round(1),
question_number(0),
answering_player(NONE_PLAYER_MARKED),
choosing_player(NONE_PLAYER_MARKED),
running_games_messenger(running_games_messenger),
provider(std::make_unique<Hard_Coded_Question_Provider>()),
service(*this){
    for (unsigned int i=0;i<NUMBER_OF_PLAYERS;i++){
        players[i]=std::make_unique<In_Game_Player>(std::move(lobby.players[i]));
    }
    ServerBuilder builder;
    builder.RegisterService(&service);
    do{
        in_game_server_port=next_in_game_server_port;
        auto server_address="0.0.0.0:"+std::to_string(in_game_server_port);
        builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
        server= builder.BuildAndStart();
        next_in_game_server_port++;
    }while(server==nullptr);
    game_thread= std::thread(&In_Game_Lobby::serve_game,this);
    in_game_server_thread=std::thread(&Server::Wait,server.get());
}

In_Game_Lobby::~In_Game_Lobby() {
    server->Shutdown();
    in_game_server_thread.join();
    game_thread.join();
}

void In_Game_Lobby::start_countdown() {
    for(auto &player: players){
        if(player){
            player->send_countdown();
        }
    }
}

void In_Game_Lobby::start_game() {
    for(auto &player: players){
        if(player) {
            player->send_start_game(in_game_server_port);
        }
    }
}

void In_Game_Lobby::start_next_round() {
    for(auto &player:players){
        if(player) {
            player->start_next_round();
        }
    }
}

void In_Game_Lobby::start_roulette() {
    for(auto &player: players){
        if(player){
            player->send_start_roulette();
        }
    }
}

void In_Game_Lobby::change_roulette_state(unsigned int state) {
    for(auto &player: players){
        if(player) {
            player->send_change_roulette_state(state);
        }
    }
}

void In_Game_Lobby::start_elimination_roulette() {
    for(auto &player: players){
        if(player) {
            player->send_start_elimination_roulette();
        }
    }
}

void In_Game_Lobby::pre_question_sequence() {
    for(auto &player: players){
        if(player) {
            player->send_pre_question_sequence();
        }
    }
}

void In_Game_Lobby::question_data(const std::string& string) {
    for(auto &player: players){
        if(player){
            player->send_question_data(string);
        }
    }
}

void In_Game_Lobby::send_answers(Choice_Question &question) {
    for(auto &player: players){
        if(player) {
            player->send_answers(question);
        }
    }
}

void In_Game_Lobby::mark_answer(unsigned int index, Russian_Roulette::Answer_State state) {
    for(auto &player: players){
        if(player) {
            player->send_mark_answer(index, state);
        }
    }
}

void In_Game_Lobby::clear_answers() {
    for(auto &player: players){
        if(player){
            player->clear_answers();
        }
    }
}

void In_Game_Lobby::change_player_state(unsigned int index, Russian_Roulette::Player_State state) {
    for(auto &receiver:players){
        if(receiver){
            receiver->send_change_player_state(index,state);
        }

    }
}

void In_Game_Lobby::change_player_money(In_Game_Player &player) {
    for(auto &receiver:players){
        if(receiver){
            receiver->send_change_player_money(player);
        }
    }
}

void In_Game_Lobby::eliminate_player() {
    for(auto &receiver:players){
        if(receiver){
            receiver->send_eliminate_player(answering_player);
        }
    }
}

void In_Game_Lobby::change_one_trap(unsigned int trap_id, Russian_Roulette::Trap_State state) {
    for(auto &player: players){
        if(player){
            player->send_change_one_trap(trap_id,state);
        }
    }
}

void In_Game_Lobby::change_all_traps(Russian_Roulette::Trap_State state) {
    for(auto &player: players){
        if(player){
            player->send_change_all_traps(state);
        }
    }
}

void In_Game_Lobby::serve_game() {
    pre_game();
    start_round_1();
    ask_round_1_questions();
    round_end();
    drop_player();
    start_round_2();
}

void In_Game_Lobby::listen_roulette_stop() {
    get_decision_message();
    roulette_stop=true;
}

void In_Game_Lobby::pre_game() {
    sleep_for(std::chrono::seconds(2));
    start_countdown();
    sleep_for(std::chrono::seconds(3));
    start_game();
    sleep_for(std::chrono::seconds(1));
}

void In_Game_Lobby::player_select_roulette() {
    change_all_traps(Russian_Roulette::Trap_State::red);
    sleep_for(std::chrono::seconds(2));
    choosing_player=generate_random_uint(0,5);
    for(int i=0;i<9+ generate_random_uint(3,9);i++){
        change_one_trap(choosing_player,Russian_Roulette::Trap_State::red);
        choosing_player= choosing_player==5 ? 0 : choosing_player+1;
        change_one_trap(choosing_player,Russian_Roulette::Trap_State::blue);
        sleep_for(std::chrono::milliseconds(500));
    }
    for(int i=0;i<generate_random_uint(3,9);i++){
        change_one_trap(choosing_player,Russian_Roulette::Trap_State::red);
        choosing_player= choosing_player==5 ? 0 : choosing_player+1;
        change_one_trap(choosing_player,Russian_Roulette::Trap_State::blue);
        sleep_for(std::chrono::seconds(1));
    }
    sleep_for(std::chrono::seconds(1));
    change_all_traps(Russian_Roulette::Trap_State::closed);
}

bool In_Game_Lobby::russian_roulette() {
    unsigned int limit=5;
    if(round%2==0){
        limit=2;
    }
    else if(round%3==0){
        limit=1;
    }
    start_roulette();
    get_decision_message();
    roulette_stop=false;
    auto thread=std::thread(&In_Game_Lobby::listen_roulette_stop,this);
    unsigned int state=generate_random_uint(0,limit);
    change_roulette_state(state);
    do{
        state= state==(limit)? 0:state+1;
        change_roulette_state(state);
        sleep_for(std::chrono::milliseconds(500));
    }while(!roulette_stop);
    thread.join();
    for(int i=0;i<generate_random_uint(3,9);i++){
        state= state==(limit)? 0:state+1;
        change_roulette_state(state);
        sleep_for(std::chrono::seconds(1));
    }
    sleep_for(std::chrono::seconds(1));
    return round<3?answering_player%(limit+1)==state:answering_player%(limit+1)!=state;
}

void In_Game_Lobby::automatic_elimination_roulette() {
    start_elimination_roulette();
    sleep_for(std::chrono::seconds(2));
    answering_player=generate_random_uint(0,5);
    for(int i=0;i<9+ generate_random_uint(3,9);i++){
        change_one_trap(answering_player,Russian_Roulette::Trap_State::blue);
        answering_player= answering_player==5 ? 0 : answering_player+1;
        change_one_trap(answering_player,Russian_Roulette::Trap_State::red);
        sleep_for(std::chrono::milliseconds(500));
    }
    auto steps_to_end= set_valid_number_of_steps(answering_player,generate_random_uint(5,7));
    for(int i=0;i<steps_to_end;i++){
        change_one_trap(choosing_player,Russian_Roulette::Trap_State::blue);
        choosing_player= choosing_player==5 ? 0 : choosing_player+1;
        change_one_trap(choosing_player,Russian_Roulette::Trap_State::red);
        sleep_for(std::chrono::seconds(1));
    }
    sleep_for(std::chrono::seconds(1));
}

void In_Game_Lobby::manual_elimination_roulette() {
    start_elimination_roulette();
    get_decision_message();
    roulette_stop=false;
    answering_player=generate_random_uint(0,5);
    auto thread=std::thread(&In_Game_Lobby::listen_roulette_stop,this);
    do{
        change_one_trap(answering_player,Russian_Roulette::Trap_State::blue);
        answering_player= answering_player==5 ? 0 : answering_player+1;
        change_one_trap(answering_player,Russian_Roulette::Trap_State::red);
        sleep_for(std::chrono::milliseconds(500));
    }while(!roulette_stop);
    thread.join();
    auto steps_to_end= set_valid_number_of_steps(answering_player,generate_random_uint(5,7));
    for(int i=0;i<steps_to_end;i++){
        change_one_trap(answering_player,Russian_Roulette::Trap_State::blue);
        answering_player= answering_player==5 ? 0 : answering_player+1;
        change_one_trap(answering_player,Russian_Roulette::Trap_State::red);
        sleep_for(std::chrono::seconds(1));
    }
    sleep_for(std::chrono::seconds(1));
}

void In_Game_Lobby::start_round_1() {
    question_data("Witam w Rosyjskiej Ruletce");
    sleep_for(std::chrono::seconds(1));
    question_data("Na początku gry każdy z was otrzymuje po 300 punktów i tyle jest warta każda poprawna odpowiedź w tej rundzie");
    sleep_for(std::chrono::milliseconds(500));
    for(auto &player: players){
        player->add_money(MONEY_FOR_ROUND[round-1]);
        change_player_money(*player);
        sleep_for(std::chrono::milliseconds(300));
    }
    sleep_for(std::chrono::milliseconds(500));
    question_data("W tej rundzie mamy 12 pytań, ale jeżeli ktoś źle odpowie i odpadnie, to szybciej zaczniemy rundę 2");
    sleep_for(std::chrono::seconds(2));
    question_data("W pierwszej rundzie aktywna jest jedna zapadnia");
    sleep_for(std::chrono::seconds(1));
    change_one_trap(0,Russian_Roulette::Trap_State::red);
    sleep_for(std::chrono::milliseconds(500));
    question_data("Zatem gracz który źle odpowie na pytanie ma 1/6 prawdopodobieństwa że wypadnie z gry, dosłownie");
    sleep_for(std::chrono::seconds(2));
    change_one_trap(0,Russian_Roulette::Trap_State::open);
    sleep_for(std::chrono::seconds(2));
    change_one_trap(0,Russian_Roulette::Trap_State::closed);
    sleep_for(std::chrono::seconds(1));
    question_data("Teraz wskażę gracza który wybierze kto odpowie na pierwsze pytanie");
    sleep_for(std::chrono::seconds(1));
    question_data("");
    player_select_roulette();
    sleep_for(std::chrono::seconds(1));
    change_player_state(choosing_player,Russian_Roulette::Player_State::chosing);
    question_data(players[choosing_player]->get_name()+" wskaże gracza który odpowie na pierwsze pytanie");
    sleep_for(std::chrono::seconds(1));
}

void In_Game_Lobby::start_round_2() {
    question_data("W drugiej rundzie mamy 10 pytań, ale jeżeli ktoś odpadnie wcześniej to szybciej zaczniemy rundę 3");
    sleep_for(std::chrono::seconds(2));
    question_data("W drugiej rundzie aktywne są dwie zapadnie");
}

void In_Game_Lobby::ask_round_1_questions() {
    int index=0;
    do{
        pre_question_sequence();
        sleep_for(std::chrono::seconds(3));
        auto question=provider->get_round_1_question(index);
        question_data(question.get_content());
        sleep_for(std::chrono::seconds(1));
        question_data(question.get_content()+"\nDla kogo to pytanie?");
        let_choosing_select_answering();
        answering_player=get_option_message();
        change_player_state(answering_player,Russian_Roulette::Player_State::answering);
        sleep_for(std::chrono::seconds(1));
        question_data(question.get_content()+"\n"+players[answering_player]->get_name()+", oto warianty odpowiedzi:");
        sleep_for(std::chrono::seconds(1));
        send_answers(question);
        sleep_for(std::chrono::seconds(2));
        // TODO timer activation need to be placed there;
        auto answer=get_option_message();
        mark_answer(answer,Russian_Roulette::Answer_State::marked);
        auto correct=question.is_answer_correct(answer);
        sleep_for(std::chrono::seconds(1));
        if(correct){
            question_data(question.get_content()+"\nTak jest!");
            sleep_for(std::chrono::seconds(1));
            mark_answer(answer,Russian_Roulette::Answer_State::correct);
        }
        else{
            question_data(question.get_content()+"\nNiestety!");
            sleep_for(std::chrono::seconds(1));
            mark_answer(answer,Russian_Roulette::Answer_State::wrong);
            mark_answer(question.get_correct(),Russian_Roulette::Answer_State::correct);
        }
        sleep_for(std::chrono::seconds(2));
        clear_answers();
        if(correct){
            question_data(std::to_string(MONEY_FOR_ROUND[round-1])+" punktów trafia na konto "+players[answering_player]->get_name());
            sleep_for(std::chrono::seconds(1));
            players[answering_player]->add_money(MONEY_FOR_ROUND[round-1]);
            change_player_money(*players[answering_player]);
            sleep_for(std::chrono::milliseconds(500));
        }
        else{
            question_data("Punkty z konta "+players[answering_player]->get_name()+" trafia na konto "+players[choosing_player]->get_name());
            sleep_for(std::chrono::seconds(1));
            players[answering_player]->give_money(*players[choosing_player]);
            change_player_money(*players[choosing_player]);
            change_player_money(*players[answering_player]);
            sleep_for(std::chrono::milliseconds(500));
            question_data("Natomiast "+players[answering_player]->get_name()+" zagra w rosyjską ruletkę");
            sleep_for(std::chrono::seconds(1));
            question_data("");
            if(russian_roulette()){
                return;
            }
            question_data(players[answering_player]->get_name()+" Zostaje w grze");
            change_all_traps(Russian_Roulette::Trap_State::closed);
            sleep_for(std::chrono::seconds(1));

        }
        index++;
        if(index<NUMBER_OF_QUESTIONS_FOR_ROUND[round-1]){
            question_data("I teraz wskaże osobę która odpowie na kolejne pytanie");
            change_player_state(choosing_player,Russian_Roulette::Player_State::default_);
            choosing_player=answering_player;
            change_player_state(choosing_player,Russian_Roulette::Player_State::chosing);
        }
        else{
            change_player_state(answering_player,Russian_Roulette::Player_State::default_);
            change_player_state(choosing_player,Russian_Roulette::Player_State::default_);
            answering_player=NONE_PLAYER_MARKED;
            choosing_player=NONE_PLAYER_MARKED;
        }
        sleep_for(std::chrono::seconds(1));
    }while(index<NUMBER_OF_QUESTIONS_FOR_ROUND[round-1]);
}

void In_Game_Lobby::round_end() {
    if(answering_player != NONE_PLAYER_MARKED){
        return;
    }
    question_data("Zadaliśmy już wszystkie pytania w tej rundzie");
    sleep_for(std::chrono::seconds(1));
    find_financial_leader();
    answering_player=choosing_player;
    if(choosing_player==NONE_PLAYER_MARKED){
        question_data("Nie mamy punktowego lidera więc ja wskażę gracza który nas opuści");
        automatic_elimination_roulette();
    }
    else{
        question_data(players[choosing_player]->get_name()+" ma najwięcej pieniędzy i to on zdecyduje kto nas opuści");
        change_player_state(choosing_player,Russian_Roulette::Player_State::chosing);
        manual_elimination_roulette();
    }
}

void In_Game_Lobby::drop_player() {
    eliminate_player();
    sleep_for(std::chrono::seconds(3));
    question_data(players[answering_player]->get_name()+" wypadł z naszej gry");
    sleep_for(std::chrono::seconds(1));
    if(players[answering_player]->have_money()){
        question_data("Jego punkty dzielimy między pozostałych graczy");
        sleep_for(std::chrono::seconds(1));
        players[answering_player]->divide_money(players);
        for(auto &player: players){
            if(player!=players[answering_player]){
                change_player_money(*player);
            }
        }
        sleep_for(std::chrono::seconds(1));
    }
    players[answering_player].reset(nullptr);
    round++;
    if(round<6){
        question_data("A ja zapraszam na rundę "+std::to_string(round));
    }
    else{
        question_data("A ja zapraszam na finał");
    }
    sleep_for(std::chrono::seconds(1));
    change_all_traps(Russian_Roulette::Trap_State::closed);
    sleep_for(std::chrono::seconds(4));
}

void In_Game_Lobby::let_choosing_select_answering() {
    for(int i=0;i<players.size();i++){
        if(i!=choosing_player){
            players[choosing_player]->send_change_player_state(i,Russian_Roulette::Player_State::enable);
        }
    }
}

void In_Game_Lobby::find_financial_leader() {
    unsigned int max_money=0, financial_leader_index=NONE_PLAYER_MARKED;
    for (int i=0;i<players.size();i++){
        if(players[i]->get_money()>max_money){
            max_money=players[i]->get_money();
            financial_leader_index=i;
        }
        else if(players[i]->get_money()==max_money){
            financial_leader_index=NONE_PLAYER_MARKED;
        }
    }
    choosing_player=financial_leader_index;
}

unsigned int In_Game_Lobby::set_valid_number_of_steps(unsigned int offset, unsigned int number_of_steps) {
    auto valid_number_of_steps= offset + number_of_steps;
    int step=1;
    while(players[valid_number_of_steps%NUMBER_OF_PLAYERS]==nullptr || valid_number_of_steps%NUMBER_OF_PLAYERS==choosing_player){
        valid_number_of_steps+= step & 1 ? step: step*(-1);
        step++;
    }
    return valid_number_of_steps;
}

void In_Game_Lobby::set_option_message(unsigned int message) {
    option_messenger.send_message(message);
}

unsigned int In_Game_Lobby::get_option_message() {
    return option_messenger.receive_message();
}

void In_Game_Lobby::set_answer_message(std::string message) {
    answer_messenger.send_message(std::move(message));
}

std::string In_Game_Lobby::get_answer_message() {
    return answer_messenger.receive_message();
}

void In_Game_Lobby::set_decision_message(bool message) {
    decision_messenger.send_message(message);
}

bool In_Game_Lobby::get_decision_message() {
    return decision_messenger.receive_message();
}
