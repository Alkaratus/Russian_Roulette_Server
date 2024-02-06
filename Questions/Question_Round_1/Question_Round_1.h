//
// Created by alkaratus on 03.01.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_QUESTION_ROUND_1_H
#define RUSSIAN_ROULETTE_SERVER_QUESTION_ROUND_1_H

#include <string>
#include "Choice_Question.h"

class Question_Round_1 : public Choice_Question{
    std::string answer1;
    std::string answer2;
    unsigned int correct;
public:
    Question_Round_1(std::string content,std::string answer1,std::string answer2, unsigned int correct);
    std::string get_answer_1() const;
    std::string get_answer_2() const;
    bool is_answer_correct(unsigned int answer)const;
    unsigned int get_correct()const;
    void accept(Choice_Question_Visitor* visitor) override;
};


#endif //RUSSIAN_ROULETTE_SERVER_QUESTION_ROUND_1_H
