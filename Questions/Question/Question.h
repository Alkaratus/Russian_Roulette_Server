//
// Created by alkaratus on 03.01.24.
//

#ifndef RUSSIAN_ROULETTE_SERVER_QUESTION_H
#define RUSSIAN_ROULETTE_SERVER_QUESTION_H

#include <string>

class Question {
    std::string content;
protected:
    explicit Question(std::string content);
public:
    virtual ~Question()=default;
    std::string get_content() const;
};


#endif //RUSSIAN_ROULETTE_SERVER_QUESTION_H
