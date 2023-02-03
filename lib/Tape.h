#ifndef YADRO_TEST_TASK_TAPE_H
#define YADRO_TEST_TASK_TAPE_H

#include <utility>

#include "stdexcept"
#include "fstream"
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
public:
    int getReadDelay() const;

    int getWriteDelay() const;

    int getMoveDelay() const;

    int getMoveNextDelay() const;

private:
    int writeDelay{};
    int moveDelay{};
    int moveNextDelay{};

    static void Wait(int time);
public:
    explicit Tape(std::string configName);

    Tape(std::string configN, std::string fileN, size_t size1, int readD, int writeD, int moveD, int moveNextD);

    ~Tape();

    void SetConfig(std::string configName);

    void SetConfig(std::string configN, std::string fileN, size_t size1, int readD, int writeD, int moveD, int moveNextD);

    void Write(int information);

    void Move(int steps);

    int Read();

    size_t GetSize() const;
};


#endif //YADRO_TEST_TASK_TAPE_H
