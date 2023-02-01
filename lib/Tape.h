//
// Created by Кирилл Куницын on 28.01.2023.
//

#ifndef YADRO_TEST_TASK_TAPE_H
#define YADRO_TEST_TASK_TAPE_H

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

template<typename T> Tape<T>::Tape(int n){
    size = n;
    current = 0;
    data = new T[size];
};

template<typename T> Tape<T>::~Tape(){
    free(data);
}

template<typename T> void Tape<T>::Write(T information){
    data[current] = information;
}

template<typename T> void Tape<T>::Move(int steps){
    current += steps;
    if (current > size - 1)
        throw std::out_of_range("Out of range of Tape");
    if (current < 0)
        throw std::out_of_range("Out of range of Tape");
}

template<typename T> T Tape<T>::Read(){
    return data[current];
}


#endif //YADRO_TEST_TASK_TAPE_H
