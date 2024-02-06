//
// Created by alkaratus on 03.01.24.
//

#include "Question_Round_2.h"
#include "Choice_Question_Visitor.h"

Question_Round_2::Question_Round_2(std::string content, std::string answer1, std::string answer2, std::string answer3,
                                   unsigned int correct): Question_Round_1(content,answer1,answer2,correct),answer3(answer3) {
}

std::string Question_Round_2::get_answer_3() const {
    return answer3;
}

void Question_Round_2::accept(Choice_Question_Visitor *visitor) {
    visitor->visit_round_2_question(this);
}
