//
// Created by Кирилл Куницын on 28.01.2023.
//

#ifndef YADRO_TEST_TASK_TAPE_H
#define YADRO_TEST_TASK_TAPE_H

#include <cstdio>

template <typename T>
class Tape {
private:
    size_t size;
    size_t current;
    T* data;
public:
    explicit Tape(int n);

    ~Tape();

    void Write(T information);

    void Move(int steps);

    T Read();
};


#endif //YADRO_TEST_TASK_TAPE_H
