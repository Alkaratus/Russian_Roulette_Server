//
// Created by alkaratus on 03.01.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_ROUND_QUESTION_2_H
#define RUSSIAN_ROULETTE_SERVER_ROUND_QUESTION_2_H
#include "Question_Round_1.h"

class Question_Round_2: public Question_Round_1 {
    std::string answer3;
public:
    Question_Round_2(std::string content, std::string answer1, std::string answer2, std::string answer3, unsigned int correct);
    std::string get_answer_3() const;
    void accept(Choice_Question_Visitor& visitor) override;
};


#endif //RUSSIAN_ROULETTE_SERVER_ROUND_QUESTION_2_H
