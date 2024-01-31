//
// Created by alkaratus on 03.01.24.
//

#include "Question.h"

#include <utility>

Question::Question(std::string content):content(std::move(content)) {
}

std::string Question::get_content() const {
    return content;
}
