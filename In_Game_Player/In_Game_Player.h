#pragma once

#include "Pre_Game_Player.h"
#include "Answers_Extractor.h"

class In_Game_Player {
    unsigned int in_game_id;
    unsigned int money;
    std::string name;
    std::shared_ptr<grpc::Channel> channel;
    std::unique_ptr<ClientListener::Stub> stub;


public:
    In_Game_Player();
    explicit In_Game_Player(Pre_Game_Player &&player);

    std::string get_name();
    unsigned int get_money();
    bool have_money();

    void add_money(unsigned int money);
    void give_money(In_Game_Player &player);
    void divide_money(std::array<std::unique_ptr<In_Game_Player>,6> &players) const;

    void send_countdown();
    void send_start_game(int port);

    void start_next_round();

    void send_start_roulette();
    void send_change_roulette_state(unsigned int state);
    void send_start_elimination_roulette();

    void send_pre_question_sequence();
    void send_question_data(std::string data);


    void send_answers(Choice_Question& question);

    void send_mark_answer(unsigned int index, Russian_Roulette::Answer_State mark);
    void clear_answers();

    void send_change_player_money(In_Game_Player &player);
    void send_change_player_state(unsigned int index,Russian_Roulette::Player_State state);
    void send_eliminate_player(unsigned int index);

    void send_change_one_trap(unsigned int trap,Russian_Roulette::Trap_State state);
    void send_change_all_traps(Russian_Roulette::Trap_State state);

};


