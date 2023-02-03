#ifndef YADRO_TEST_TASK_TAPE_H
#define YADRO_TEST_TASK_TAPE_H

#include <utility>

#include "stdexcept"
#include "fstream"
#include "iostream"
#include "cstdlib"
#include <filesystem>

#include "unistd.h"

class Tape {
private:
    std::fstream file;
    std::fstream config;
    size_t size;
    size_t current;
    std::string fileName;
    int readDelay{};
    int writeDelay{};
    int moveDelay{};
    int moveNextDelay{};

    void Wait(int time);
public:
    explicit Tape();

    ~Tape();

    void SetConfig();

    void Write(int information);

    void Move(int steps);

    int Read();
};


#endif //YADRO_TEST_TASK_TAPE_H
