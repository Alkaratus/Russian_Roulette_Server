//
// Created by alkaratus on 05.01.24.
//
#pragma once
#include <array>
#include <vector>
#include "Question_Round_4.h"
#include "Question_Round_5.h"

class Hard_Coded_Question_Provider{
    std::array<std::vector<unsigned int>,5>questions_IDs;
public:
    Hard_Coded_Question_Provider();
    Question_Round_1 get_round_1_question(unsigned int index);
    Question_Round_2 get_round_2_question(unsigned int index);
    Question_Round_3 get_round_3_question(unsigned int index);
    Question_Round_4 get_round_4_question(unsigned int index);
    Question_Round_5 get_round_5_question(unsigned int index);
};

