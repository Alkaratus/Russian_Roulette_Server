//
// Created by alkaratus on 15.12.23.
//

#include <utility>
#include "Pre_Game_Player.h"
#include "ClientListener.pb.h"


using grpc::ClientContext;

using Russian_Roulette::Listener_Player_Data;
using Russian_Roulette::Listener_Empty_Message;


Pre_Game_Player::Pre_Game_Player(unsigned int in_game_id, const std::string& ip, int port, std::string name):in_game_id(in_game_id),name(std::move(name)) {
    if(port!=0){
        channel=grpc::CreateChannel(ip+':'+std::to_string(port), grpc::InsecureChannelCredentials());
        stub=ClientListener::NewStub(channel);
    }
}

unsigned int Pre_Game_Player::get_id() const {
    return in_game_id;
}

std::string Pre_Game_Player::get_name() const{
    return name;
}

void Pre_Game_Player::send_player_information(Pre_Game_Player &player) {
    if(stub==nullptr){
        return;
    };
    Listener_Player_Data request;
    request.set_name(player.name);
    request.set_id(player.in_game_id);
    Listener_Empty_Message response;
    ClientContext context;
    auto status= stub->send_player_information(&context,request,&response);
}
