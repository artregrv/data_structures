#ifndef PROFILE_H
#define PROFILE_H

#include <chrono>
#include <iostream>
#include <string>

class LogDuration
{
public:
    explicit LogDuration(const std::string &message = "") :
        _message(message),
        _start(std::chrono::steady_clock::now())
    {}

    ~LogDuration()
    {
        auto finish = std::chrono::steady_clock::now();
        auto duration = finish - _start;
        std::cerr << _message << " "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count()
                  << " ms" << std::endl;
    }

private:
    std::string _message;
    std::chrono::steady_clock::time_point _start;

};

#define LOG_DURATION(message) \
    LogDuration duration(message);

#endif // PROFILE_H