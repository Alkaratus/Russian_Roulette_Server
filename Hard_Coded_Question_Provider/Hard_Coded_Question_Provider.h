//
// Created by alkaratus on 05.01.24.
//
#pragma once

#include "Question_Provider.h"

class Hard_Coded_Question_Provider: public Question_Provider{
public:
    Hard_Coded_Question_Provider();
    Question_Round_1 get_round_1_question_data(unsigned int index) override;
    Question_Round_2 get_round_2_question_data(unsigned int index) override;
    Question_Round_3 get_round_3_question_data(unsigned int index) override;
    Question_Round_4 get_round_4_question_data(unsigned int index) override;
    Question_Round_5 get_round_5_question_data(unsigned int index) override;
};

