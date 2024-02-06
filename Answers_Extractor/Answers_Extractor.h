//
// Created by alkaratus on 30.01.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_ANSWERS_EXTRACTOR_H
#define RUSSIAN_ROULETTE_SERVER_ANSWERS_EXTRACTOR_H

#include "Choice_Question_Visitor.h"
#include "ClientListener.pb.h"
#include "Question_Round_4.h"

class Answers_Extractor:private Choice_Question_Visitor {
    Russian_Roulette::Listener_Answers_Data data;
    void visit_round_1_question(Question_Round_1 *question) override;
    void visit_round_2_question(Question_Round_2 *question) override;
    void visit_round_3_question(Question_Round_3 *question) override;
    void visit_round_4_question(Question_Round_4 *question) override;
public:
    Russian_Roulette::Listener_Answers_Data extract_answers(Choice_Question &question);

};


#endif //RUSSIAN_ROULETTE_SERVER_ANSWERS_EXTRACTOR_H
