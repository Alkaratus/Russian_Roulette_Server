//
// Created by alkaratus on 27.01.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_CHOICE_QUESTION_H
#define RUSSIAN_ROULETTE_SERVER_CHOICE_QUESTION_H

#include "Question.h"

class Choice_Question_Visitor;

class Choice_Question: public Question {
protected:
    explicit Choice_Question(std::string content);
public:
    virtual void accept(Choice_Question_Visitor* visitor)=0;
    ~Choice_Question() override=default;
};


#endif //RUSSIAN_ROULETTE_SERVER_CHOICE_QUESTION_H
