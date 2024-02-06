//
// Created by alkaratus on 05.02.24.
//

#include "Question_Provider.h"

void Question_Provider::set_round_1_questions_IDs(std::vector<unsigned int> IDs) {
    std::move(IDs.begin(), IDs.begin()+ROUND_1_QUESTIONS_NUMBER,round_1_questions_IDs.begin());
}

void Question_Provider::set_round_2_questions_IDs(std::vector<unsigned int> IDs) {
    std::move(IDs.begin(), IDs.begin()+ROUND_1_QUESTIONS_NUMBER,round_2_questions_IDs.begin());
}

void Question_Provider::set_round_3_questions_IDs(std::vector<unsigned int> IDs) {
    std::move(IDs.begin(), IDs.begin()+ROUND_1_QUESTIONS_NUMBER,round_3_questions_IDs.begin());
}

void Question_Provider::set_round_4_questions_IDs(std::vector<unsigned int> IDs) {
    std::move(IDs.begin(), IDs.begin()+ROUND_1_QUESTIONS_NUMBER,round_4_questions_IDs.begin());
}

void Question_Provider::set_round_5_questions_IDs(std::vector<unsigned int> IDs) {
    std::move(IDs.begin(), IDs.begin()+ROUND_1_QUESTIONS_NUMBER,round_5_questions_IDs.begin());
}

Question_Round_1 Question_Provider::get_round_1_question(unsigned int index) {
    return get_round_1_question_data(round_1_questions_IDs[index]);
}

Question_Round_2 Question_Provider::get_round_2_question(unsigned int index) {
    return get_round_2_question_data(round_2_questions_IDs[index]);
}

Question_Round_3 Question_Provider::get_round_3_question(unsigned int index) {
    return get_round_3_question_data(round_3_questions_IDs[index]);
}

Question_Round_4 Question_Provider::get_round_4_question(unsigned int index) {
    return get_round_4_question_data(round_4_questions_IDs[index]);
}

Question_Round_5 Question_Provider::get_round_5_question(unsigned int index) {
    return get_round_5_question_data(round_5_questions_IDs[index]);
}

