//
// Created by alkaratus on 03.01.24.
//

#include <utility>
#include "Question_Round_3.h"
#include "Choice_Question_Visitor.h"


Question_Round_3::Question_Round_3(std::string content, std::string answer1, std::string answer2, std::string answer3, std::string answer4,
                                   unsigned int correct): Question_Round_2(std::move(content),std::move(answer1),std::move(answer2),std::move(answer3),correct),answer4(std::move(answer4)) {
}

std::string Question_Round_3::get_answer_4() const {
    return answer4;
}

void Question_Round_3::accept(Choice_Question_Visitor *visitor) {
    visitor->visit_round_3_question(this);
}
