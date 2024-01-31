//
// Created by alkaratus on 13.01.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_IN_GAME_SERVER_H
#define RUSSIAN_ROULETTE_SERVER_IN_GAME_SERVER_H

#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include "InGameServer.pb.h"
#include "InGameServer.grpc.pb.h"
#include "Messenger.h"

class In_Game_Lobby;

class In_Game_Server: public Russian_Roulette::InGameServer::Service {
    In_Game_Lobby &lobby;
    grpc::Status select_player(grpc::ServerContext* context, const Russian_Roulette::InGame_Selected_Player* request, Russian_Roulette::InGame_Empty_Message *response) override;
    grpc::Status get_answer(grpc::ServerContext* context, const Russian_Roulette::InGame_Selected_Answer* request, Russian_Roulette::InGame_Empty_Message *response) override;
    grpc::Status get_text_answer(grpc::ServerContext* context, const Russian_Roulette::InGame_Text_Answer* request, Russian_Roulette::InGame_Empty_Message *response) override;
    grpc::Status trigger_roulette(grpc::ServerContext* context, const Russian_Roulette::InGame_Empty_Message* request, Russian_Roulette::InGame_Empty_Message *response) override;
    grpc::Status decide_in_final(grpc::ServerContext* context, const Russian_Roulette::InGame_Decision_In_Final* request, Russian_Roulette::InGame_Empty_Message *response) override;
public:
    explicit In_Game_Server(In_Game_Lobby& lobby);
};


#endif