//
// Created by alkaratus on 26.01.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_CHOICE_QUESTION_VISITOR_H
#define RUSSIAN_ROULETTE_SERVER_CHOICE_QUESTION_VISITOR_H

class Question_Round_1;
class Question_Round_2;
class Question_Round_3;
class Question_Round_4;

class Choice_Question_Visitor {
public:
    virtual void visit_round_1_question(Question_Round_1 &question)=0;
    virtual void visit_round_2_question(Question_Round_2 &question)=0;
    virtual void visit_round_3_question(Question_Round_3 &question)=0;
    virtual void visit_round_4_question(Question_Round_4 &question)=0;

};


#endif //RUSSIAN_ROULETTE_SERVER_CHOICE_QUESTION_VISITOR_H
