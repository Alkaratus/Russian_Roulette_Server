#include <algorithm>
#include "MainServer.h"

using Russian_Roulette::Server_Player_Data;


Status MainServer ::create_game(ServerContext* context, const Server_New_Game_Data* request, Server_Game_Params* response){

    if(std::any_of(lobbies.begin(),lobbies.end(),[request](Pre_Game_Lobby &lobby){return request->game_name()==lobby.get_game_name();})){
        response->set_success(false);
        response->set_game_id(0);
    }
    else{
        Pre_Game_Lobby new_lobby(request->game_name());
        auto client_ip= extract_ip(context);
        new_lobby.add_player(request->player_bonus_ip(),request->player_listener_port(),request->player_name());
        lobbies.emplace_back(std::move(new_lobby));
        response->set_success(true);
        response->set_game_id(new_lobby.get_game_id());
    }

    return Status::OK;
}

Status MainServer::join_game(ServerContext *context, const Server_New_Game_Data *request, Server_Game_Params *response) {
    auto game_iterator=std::find_if(lobbies.begin(),lobbies.end(),[request](Pre_Game_Lobby &lobby){return request->game_name()==lobby.get_game_name();});
    if(game_iterator==lobbies.end()){
        response->set_success(false);
        response->set_game_id(0);
        return Status::OK;
    }
    game_iterator->add_player(request->player_bonus_ip(),request->player_listener_port(),request->player_name());
    response->set_success(true);
    response->set_game_id(game_iterator->get_game_id());
    response->set_player_id(game_iterator->get_next_player_id()-1);
    return Status::OK;
}

Status MainServer::get_players(ServerContext* context,const Server_Game_ID* request, Server_Players_Data *response) {
    auto game_iterator=std::find_if(lobbies.begin(),lobbies.end(),[request](const Pre_Game_Lobby& lobby){return request->id()==lobby.get_game_id();});
    auto &players=game_iterator->get_players();
    response->set_player_1(players[0].get_name());
    response->set_player_2(players[1].get_name());
    response->set_player_3(players[2].get_name());
    response->set_player_4(players[3].get_name());
    response->set_player_5(players[4].get_name());
    response->set_player_6(players[5].get_name());

    if(game_iterator->get_next_player_id()==6){
        lobby_messenger.send_message(game_iterator);
    }
    return Status::OK;
}

void MainServer::lobbies_checking() {
    std::cout<<"Lobbies checker thread running\n";
    while(true){
        auto lobby=lobby_messenger.receive_message();
        running_games.emplace_back(std::move(*lobby),running_games_messenger);
        lobbies.erase(lobby);
    }
}

void MainServer::running_games_checking() {
    std::cout<<"Running games checker thread running\n";
    while(true){
        auto game=running_games_messenger.receive_message();
        //running_games.erase(game);
    }
}


MainServer::MainServer():lobby_checker(&MainServer::lobbies_checking,this),running_games_checker(&MainServer::running_games_checking,this) {
}



std::string extract_ip(ServerContext* context){
    auto client_ip= context->peer().substr(5);
    client_ip=client_ip.substr(0,client_ip.find(':'));
    return client_ip;
}