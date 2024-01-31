#include "Utilities.h"
#include <random>
#include <chrono>
#include <stdexcept>
#include <algorithm>

unsigned int generate_random_uint(const unsigned int min,const unsigned int max){
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<unsigned int> distribution(min,max);
    return distribution(generator);
}

std::vector<unsigned int> generate_random_unique_list(const unsigned int min,const unsigned int max, const unsigned int count) {
    if((max-min+1)<count){
        throw std::invalid_argument("Zone of numbers is smaller than provided size of unique array");
    }
    std::vector<unsigned int> numbers(count,-1);
    unsigned int i=0;
    while(i<count){
        numbers[i]= generate_random_uint(min,max);
        while(std::any_of(numbers.cbegin(),numbers.cbegin()+(i),[&numbers, &i](unsigned int number){return number==numbers[i];})){
            numbers[i]= generate_random_uint(min,max);
        }
        i++;
    }
    return numbers;
}
