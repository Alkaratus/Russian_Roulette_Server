//
// Created by alkaratus on 05.02.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_QUESTION_PROVIDER_H
#define RUSSIAN_ROULETTE_SERVER_QUESTION_PROVIDER_H
#include <array>
#include <vector>
#include "Game_Params.h"
#include "Question_Round_4.h"
#include "Question_Round_5.h"

class Question_Provider {
    std::array<unsigned int,ROUND_1_QUESTIONS_NUMBER>round_1_questions_IDs;
    std::array<unsigned int,ROUND_2_QUESTIONS_NUMBER>round_2_questions_IDs;
    std::array<unsigned int,ROUND_3_QUESTIONS_NUMBER>round_3_questions_IDs;
    std::array<unsigned int,ROUND_4_QUESTIONS_NUMBER>round_4_questions_IDs;
    std::array<unsigned int,ROUND_5_QUESTIONS_NUMBER>round_5_questions_IDs;
protected:
    void set_round_1_questions_IDs(std::vector<unsigned int> IDs);
    void set_round_2_questions_IDs(std::vector<unsigned int> IDs);
    void set_round_3_questions_IDs(std::vector<unsigned int> IDs);
    void set_round_4_questions_IDs(std::vector<unsigned int> IDs);
    void set_round_5_questions_IDs(std::vector<unsigned int> IDs);

    virtual Question_Round_1 get_round_1_question_data(unsigned int id)=0;
    virtual Question_Round_2 get_round_2_question_data(unsigned int id)=0;
    virtual Question_Round_3 get_round_3_question_data(unsigned int id)=0;
    virtual Question_Round_4 get_round_4_question_data(unsigned int id)=0;
    virtual Question_Round_5 get_round_5_question_data(unsigned int id)=0;
public:

    virtual ~Question_Provider()=default;

    Question_Round_1 get_round_1_question(unsigned int index);
    Question_Round_2 get_round_2_question(unsigned int index);
    Question_Round_3 get_round_3_question(unsigned int index);
    Question_Round_4 get_round_4_question(unsigned int index);
    Question_Round_5 get_round_5_question(unsigned int index);

};


#endif //RUSSIAN_ROULETTE_SERVER_QUESTION_PROVIDER_H
