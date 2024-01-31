#pragma once

#include <string>
#include <array>
#include <vector>
#include <thread>
#include "Messenger.h"
#include "Pre_Game_Lobby.h"
#include "In_Game_Player.h"
#include "Hard_Coded_Question_Provider.h"
#include "In_Game_Server.h"

class In_Game_Lobby {
    static int next_in_game_server_port;

    unsigned int game_id;
    unsigned int round;
    unsigned int question_number;
    unsigned int choosing_player;
    unsigned int answering_player;
    std::string game_name;
    std::array<std::unique_ptr<In_Game_Player>,6>players;

    Messenger<std::list<In_Game_Lobby>::iterator> &running_games_messenger;

    //TODO: I have to release dependencies
    Hard_Coded_Question_Provider provider;

    Messenger<unsigned int>option_messenger;
    Messenger<std::string>answer_messenger;
    Messenger<bool>decision_messenger;

    In_Game_Server service;
    int in_game_server_port;
    std::unique_ptr<grpc::Server> server;

    std::thread game_thread;
    std::thread in_game_server_thread;

    bool roulette_stop;

    void serve_game();
    void listen_roulette_stop();
    void pre_game();

    void player_select_roulette();
    bool russian_roulette();
    void automatic_elimination_roulette();
    void manual_elimination_roulette();

    void start_countdown();
    void start_game();

    void start_next_round();

    void start_roulette();
    void change_roulette_state(unsigned int state);
    void start_elimination_roulette();

    void pre_question_sequence();
    void question_data(const std::string& string);

    void send_answers(Choice_Question &question);

    void mark_answer(unsigned int index, Russian_Roulette::Answer_State state);
    void clear_answers();

    void change_player_state(unsigned int index, Russian_Roulette::Player_State state);
    void change_player_money(In_Game_Player &player);
    void eliminate_player();

    void change_one_trap(unsigned int trap_id,Russian_Roulette::Trap_State state);
    void change_all_traps(Russian_Roulette::Trap_State state);

    void start_round_1();
    void start_round_2();

    void ask_round_1_questions();
    void round_end();
    void drop_player();

    void let_choosing_select_answering();
    void find_financial_leader();
    unsigned int set_valid_number_of_steps(unsigned int offset, unsigned int number_of_steps);

public:
    In_Game_Lobby(Pre_Game_Lobby &&lobby, Messenger<std::list<In_Game_Lobby>::iterator> &running_games_messenger);
    ~In_Game_Lobby();

    void set_option_message(unsigned int message);
    unsigned int get_option_message();

    void set_answer_message(std::string message);
    std::string get_answer_message();

    void set_decision_message(bool message);
    bool get_decision_message();
};
