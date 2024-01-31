//
// Created by alkaratus on 04.01.24.
//

#include "Question_Round_5.h"

#include <utility>

Question_Round_5::Question_Round_5(std::string content, std::string correct):Question(std::move(content)),correct(std::move(correct)) {
}

bool Question_Round_5::is_answer_correct(const std::string& answer) const{
    return answer==correct;
}
