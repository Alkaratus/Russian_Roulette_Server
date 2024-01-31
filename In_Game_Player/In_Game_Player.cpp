//
// Created by alkaratus on 21.12.23.
//

#include "In_Game_Player.h"

using grpc::ClientContext;
using Russian_Roulette::Listener_Empty_Message;
using Russian_Roulette::Listener_Game_Service_Port;
using Russian_Roulette::Listener_Question_Data;
using Russian_Roulette::Listener_Answers_Data;
using Russian_Roulette::Listener_Choosen_Player_State;
using Russian_Roulette::Listener_Choosen_Player_Money;
using Russian_Roulette::Listener_Trap_To_Change;
using Russian_Roulette::Listener_Traps_State;
using Russian_Roulette::Listener_Answer_Mark;
using Russian_Roulette::Listener_Index;

In_Game_Player::In_Game_Player(Pre_Game_Player &&player):in_game_id(player.in_game_id),money(0),
name(std::move(player.name)){
    channel=player.channel;
    stub=ClientListener::NewStub(channel);
}

In_Game_Player::In_Game_Player():in_game_id(0),money(0),channel(nullptr),stub(nullptr) {
}

std::string In_Game_Player::get_name() {
    return name;
}

unsigned int In_Game_Player::get_money() {
    return money;
}

bool In_Game_Player::have_money() {
    return money>0;
}

void In_Game_Player::add_money(unsigned int _money) {
    money+=_money;
}

void In_Game_Player::give_money(In_Game_Player &player) {
    player.money+=money;
    money=0;
}

void In_Game_Player::divide_money(std::array<std::unique_ptr<In_Game_Player>, 6> &players) const {
    const auto number_of_players_in_game=std::count_if(players.begin(),players.end(),[](const std::unique_ptr<In_Game_Player> &player){return player.operator bool();});
    for(auto &player:players){
        if(player->in_game_id!=in_game_id)
            player->add_money(money/(number_of_players_in_game-1));
    }
}

void In_Game_Player::send_countdown() {
    Listener_Empty_Message request,response;
    ClientContext context;
    auto status=stub->countdown(&context,request,&response);
}

void In_Game_Player::send_start_game(int port) {
    Listener_Game_Service_Port request;
    request.set_port(port);
    Listener_Empty_Message response;
    ClientContext context;
    auto status= stub->start_game(&context,request,&response);
}

void In_Game_Player::start_next_round() {
    Listener_Empty_Message request,response;
    ClientContext context;
    auto status=stub->start_next_round(&context,request,&response);
}

void In_Game_Player::send_start_roulette() {
    Listener_Empty_Message request,response;
    ClientContext context;
    auto status=stub->start_roulette(&context,request,&response);
}

void In_Game_Player::send_change_roulette_state(unsigned int state) {
    Listener_Index request;
    request.set_id(state);
    Listener_Empty_Message response;
    ClientContext context;
    auto status=stub->change_roulette_state(&context,request,&response);
}

void In_Game_Player::send_start_elimination_roulette() {
    Listener_Empty_Message request,response;
    ClientContext context;
    auto status= stub->start_elimination_roulette(&context,request,&response);
}

void In_Game_Player::send_pre_question_sequence() {
    Listener_Empty_Message request,response;
    ClientContext context;
    auto status= stub->pre_question_sequence(&context,request,&response);
}

void In_Game_Player::send_question_data(std::string data) {
    Listener_Question_Data request;
    request.set_data(data);
    Listener_Empty_Message response;
    ClientContext context;
    auto status=stub->question_data(&context,request,&response);
}

void In_Game_Player::send_answers(Choice_Question &question) {
    auto request= Answers_Extractor().extract_answers(question);
    Listener_Empty_Message response;
    ClientContext context;
    auto status= stub->answers_data(&context,request,&response);
}

void In_Game_Player::send_mark_answer(unsigned int index, Russian_Roulette::Answer_State mark) {
    Listener_Answer_Mark request;
    request.set_id(index);
    request.set_state(mark);
    Listener_Empty_Message response;
    ClientContext context;
    auto status= stub->mark_answer(&context,request,&response);
}

void In_Game_Player::clear_answers() {
    Listener_Empty_Message request,response;
    ClientContext context;
    auto status= stub->clear_answers(&context,request,&response);
}

void In_Game_Player::send_change_player_state(unsigned int index, Russian_Roulette::Player_State state) {
    Listener_Choosen_Player_State request;
    request.set_id(index);
    request.set_state(state);
    Listener_Empty_Message response;
    ClientContext context;
    auto status=stub->change_player_state(&context,request,&response);
}

void In_Game_Player::send_change_player_money(In_Game_Player &player) {
    Listener_Choosen_Player_Money request;
    request.set_id(player.in_game_id);
    request.set_money(player.money);
    Listener_Empty_Message response;
    ClientContext context;
    auto status=stub->change_player_money(&context,request,&response);
}

void In_Game_Player::send_eliminate_player(unsigned int index) {
    Listener_Index request;
    request.set_id(index);
    Listener_Empty_Message response;
    ClientContext context;
    auto status=stub->eliminate_player(&context,request,&response);
}

void In_Game_Player::send_change_one_trap(unsigned int trap_id, Russian_Roulette::Trap_State state) {
    Listener_Trap_To_Change request;
    request.set_id(trap_id);
    request.set_state(state);
    Listener_Empty_Message response;
    ClientContext context;
    auto status=stub->change_one_trap(&context,request,&response);
}

void In_Game_Player::send_change_all_traps(Russian_Roulette::Trap_State state) {
    Listener_Traps_State request;
    request.set_state(state);
    Listener_Empty_Message response;
    ClientContext context;
    auto status=stub->change_all_traps(&context,request,&response);
}
