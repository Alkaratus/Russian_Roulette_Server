//
// Created by alkaratus on 26.01.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_ROUND_MANAGER_H
#define RUSSIAN_ROULETTE_SERVER_ROUND_MANAGER_H

class In_Game_Lobby;

class Round_Manager {
    In_Game_Lobby &lobby;
protected:
    In_Game_Lobby & get_lobby();
    virtual void show_traps_visualisation()=0;
public:
    explicit Round_Manager(In_Game_Lobby &lobby);
    virtual void start_round()=0;
    virtual void ask_questions()=0;

};


#endif //RUSSIAN_ROULETTE_SERVER_ROUND_MANAGER_H
