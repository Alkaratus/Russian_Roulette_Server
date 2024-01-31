#pragma once

#include <string>
#include <array>
#include "Pre_Game_Player.h"

class Pre_Game_Lobby {
    static unsigned int game_counter;
    unsigned int game_id;
    unsigned int next_player_id;
    std::string game_name;
    std::array<Pre_Game_Player,6> players;
public:
    explicit Pre_Game_Lobby(std::string game_name);

    void add_player(const std::string& ip, int port,const std::string& name);

    unsigned int get_game_id() const;
    std::string get_game_name();
    std::array<Pre_Game_Player,6>& get_players();
    unsigned int get_next_player_id() const;

    friend class In_Game_Lobby;
};

