#pragma once

#include <string>
#include <memory>
#include <grpcpp/grpcpp.h>
#include "ClientListener.grpc.pb.h"

using Russian_Roulette::ClientListener;

class Pre_Game_Player {
    unsigned int in_game_id;
    std::string name;
    std::shared_ptr<grpc::Channel> channel;
    std::unique_ptr<ClientListener::Stub> stub;
public:
    explicit Pre_Game_Player(unsigned int in_game_id=0,const std::string& ip="", int port=0, std::string name="");
    unsigned int get_id() const;
    std::string get_name() const;
    void send_player_information(Pre_Game_Player &player);

    friend class In_Game_Player;
};

