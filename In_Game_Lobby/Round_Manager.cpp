//
// Created by alkaratus on 26.01.24.
//

#include "Round_Manager.h"

Round_Manager::Round_Manager(In_Game_Lobby &lobby):lobby(lobby) {
}

In_Game_Lobby &Round_Manager::get_lobby() {
    return lobby;
}

