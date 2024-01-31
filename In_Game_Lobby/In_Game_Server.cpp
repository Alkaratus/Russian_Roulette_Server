//
// Created by alkaratus on 13.01.24.
//

#include "In_Game_Server.h"
#include "In_Game_Lobby.h"

using grpc::Status;

grpc::Status
In_Game_Server::select_player(grpc::ServerContext *context, const Russian_Roulette::InGame_Selected_Player *request,
                              Russian_Roulette::InGame_Empty_Message *response) {
    lobby.set_option_message(request->id());
    return Status::OK;
}

grpc::Status
In_Game_Server::get_answer(grpc::ServerContext *context, const Russian_Roulette::InGame_Selected_Answer *request,
                           Russian_Roulette::InGame_Empty_Message *response) {
    lobby.set_option_message(request->id());
    return Status::OK;
}

grpc::Status
In_Game_Server::get_text_answer(grpc::ServerContext *context, const Russian_Roulette::InGame_Text_Answer *request,
                                Russian_Roulette::InGame_Empty_Message *response) {
    lobby.set_answer_message(request->answer());
    return Status::OK;
}

grpc::Status
In_Game_Server::trigger_roulette(grpc::ServerContext *context, const Russian_Roulette::InGame_Empty_Message *request,
                                 Russian_Roulette::InGame_Empty_Message *response) {
    lobby.set_decision_message(true);
    return Status::OK;
}

grpc::Status
In_Game_Server::decide_in_final(grpc::ServerContext *context, const Russian_Roulette::InGame_Decision_In_Final *request,
                                Russian_Roulette::InGame_Empty_Message *response) {
    lobby.set_decision_message(request->continue_());
    return Status::OK;
}

In_Game_Server::In_Game_Server(In_Game_Lobby &lobby):lobby(lobby) {
}