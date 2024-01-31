#include "Pre_Game_Lobby.h"

#include <utility>

unsigned int Pre_Game_Lobby::game_counter=1;

Pre_Game_Lobby::Pre_Game_Lobby(std::string game_name):game_id(game_counter), next_player_id(0), game_name(std::move(game_name)) {
    game_counter++;
}

std::string Pre_Game_Lobby::get_game_name() {
    return game_name;
}

void Pre_Game_Lobby::add_player(const std::string& ip, int port, const std::string& name) {
    Pre_Game_Player new_player(next_player_id,ip,port,name);
    for(auto &player: players){
        player.send_player_information(new_player);
    }
    players[next_player_id]=std::move(new_player);
    next_player_id++;
}

std::array<Pre_Game_Player,6>& Pre_Game_Lobby::get_players() {
    return players;
}

unsigned int Pre_Game_Lobby::get_game_id() const {
    return game_id;
}

unsigned int Pre_Game_Lobby::get_next_player_id() const {
    return next_player_id;
}
