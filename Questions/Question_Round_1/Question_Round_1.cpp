//
// Created by alkaratus on 03.01.24.
//

#include <utility>
#include "Question_Round_1.h"
#include "Choice_Question_Visitor.h"

Question_Round_1::Question_Round_1(std::string content, std::string answer1, std::string answer2,unsigned int correct):
Choice_Question(std::move(content)), answer1(std::move(answer1)),answer2(std::move(answer2)),correct(correct) {
}

std::string Question_Round_1::get_answer_1() const {
    return answer1;
}

std::string Question_Round_1::get_answer_2() const {
    return answer2;
}

bool Question_Round_1::is_answer_correct(unsigned int answer) const {
    return answer==correct;
}

unsigned int Question_Round_1::get_correct() const {
    return correct;
}

void Question_Round_1::accept(Choice_Question_Visitor *visitor) {
    visitor->visit_round_1_question(this);
}
