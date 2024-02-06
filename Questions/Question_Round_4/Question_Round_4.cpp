//
// Created by alkaratus on 03.01.24.
//

#include <utility>
#include "Question_Round_4.h"
#include "Choice_Question_Visitor.h"


Question_Round_4::Question_Round_4(std::string content, std::string answer1, std::string answer2, std::string answer3,
                                   std::string answer4, std::string answer5, unsigned int correct):
        Question_Round_3(std::move(content),std::move(answer1),std::move(answer2),std::move(answer3),std::move(answer4),
                         correct),answer5(std::move(answer5)){
}

std::string Question_Round_4::get_answer_5() const{
    return answer5;
}

void Question_Round_4::accept(Choice_Question_Visitor *visitor) {
    visitor->visit_round_4_question(this);
}
