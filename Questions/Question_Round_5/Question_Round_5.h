//
// Created by alkaratus on 04.01.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_QUESTION_ROUND_5_H
#define RUSSIAN_ROULETTE_SERVER_QUESTION_ROUND_5_H

#include "Question.h"

class Question_Round_5:public Question {
    std::string correct;
public:
    Question_Round_5(std::string content, std::string correct);
    bool is_answer_correct(const std::string& answer) const;
};


#endif //RUSSIAN_ROULETTE_SERVER_QUESTION_ROUND_5_H
