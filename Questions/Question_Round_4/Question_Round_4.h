//
// Created by alkaratus on 03.01.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_QUESTION_ROUND_4_H
#define RUSSIAN_ROULETTE_SERVER_QUESTION_ROUND_4_H

#include "Question_Round_3.h"

class Question_Round_4: public Question_Round_3 {
    std::string answer5;
public:
    Question_Round_4(std::string content, std::string answer1, std::string answer2, std::string answer3,
                     std::string answer4, std::string answer5, unsigned int correct);
    std::string get_answer_5() const;
    void accept(Choice_Question_Visitor& visitor) override;
};


#endif //RUSSIAN_ROULETTE_SERVER_QUESTION_ROUND_4_H
