#pragma once

#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <list>
#include <thread>
#include "Messenger.h"
#include <condition_variable>
#include "services.pb.h"
#include "services.grpc.pb.h"
#include "Pre_Game_Lobby.h"
#include "In_Game_Lobby.h"
#include "Messenger/Messenger.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerWriter;
using grpc::Status;

using Russian_Roulette::MainService;
using Russian_Roulette::Server_New_Game_Data;
using Russian_Roulette::Server_Game_Params;
using Russian_Roulette::Server_Players_Data;
using Russian_Roulette::Server_Game_ID;
using Russian_Roulette::Server_Empty;

class MainServer final: public MainService::Service{
    std::list<Pre_Game_Lobby> lobbies;
    std::list<In_Game_Lobby> running_games;

    Messenger<std::list<Pre_Game_Lobby>::iterator> lobby_messenger;
    Messenger<std::list<In_Game_Lobby>::iterator> running_games_messenger;

    std::thread lobby_checker;
    std::thread running_games_checker;

    Status create_game(ServerContext* context, const Server_New_Game_Data* request, Server_Game_Params* response) override;
    Status join_game(ServerContext* context, const Server_New_Game_Data* request, Server_Game_Params* response)override;
    Status get_players(ServerContext* context,const Server_Game_ID* request, Server_Players_Data *response)override;

    void lobbies_checking();
    void running_games_checking();

public:
    MainServer();

};



std::string extract_ip(ServerContext* context);
