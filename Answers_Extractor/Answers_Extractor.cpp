//
// Created by alkaratus on 30.01.24.
//

#include "Answers_Extractor.h"

void Answers_Extractor::visit_round_1_question(Question_Round_1 &question) {
    data.set_answer1(question.get_answer_1());
    data.set_answer2(question.get_answer_2());
}

void Answers_Extractor::visit_round_2_question(Question_Round_2 &question) {
    visit_round_1_question(question);
    data.set_answer3(question.get_answer_3());
}

void Answers_Extractor::visit_round_3_question(Question_Round_3 &question) {
    visit_round_2_question(question);
    data.set_answer4(question.get_answer_4());
}

void Answers_Extractor::visit_round_4_question(Question_Round_4 &question) {
    visit_round_3_question(question);
    data.set_answer5(question.get_answer_5());
}

Russian_Roulette::Listener_Answers_Data Answers_Extractor::extract_answers(Choice_Question &question) {
    data.Clear();
    question.accept(*this);
    return data;
}
