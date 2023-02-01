//
// Created by Кирилл Куницын on 28.01.2023.
//

#include <stdexcept>
#include "Tape.h"


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