#pragma once
#include <mutex>
#include <condition_variable>
#include <chrono>

///Realize communication alternately between writers and readers threads with single buffer
template <typename T>
class Messenger {
    ///Message storage
    T messenger;
    ///Signaler is turn of reader at beginning value set on false;
    bool reading_time;
    ///Secure access to buffer and reading_time attributes
    std::mutex guard;
    ///Sleep thread if it is not it turn
    std::condition_variable_any checker;

public:
    Messenger();
    void send_message(T message);
    T receive_message();
    T receive_message_in_time(unsigned int seconds);
};

template<typename T>
Messenger<T>::Messenger():reading_time(false){

}

template<typename T>
void Messenger<T>::send_message(T message) {
    guard.lock();
    if (reading_time) {
        checker.wait(guard);
    }
    messenger=message;
    reading_time = true;
    checker.notify_one();
    guard.unlock();
}

template<typename T>
T Messenger<T>::receive_message() {
    guard.lock();
    if (!reading_time) {
        checker.wait(guard);
    }
    auto message = messenger;
    reading_time = false;
    checker.notify_one();
    guard.unlock();
    return message;
}
using namespace std::chrono_literals;

//TODO function to be created in future
template<typename T>
T Messenger<T>::receive_message_in_time(unsigned int seconds) {
    guard.lock();
    if (!reading_time) {
        checker.wait_for(guard,std::chrono::seconds(seconds));

    }
    return nullptr;
}