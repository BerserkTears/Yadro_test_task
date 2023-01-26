#include <iostream>

template<typename T>
class Tape{
private:
    size_t size;
    size_t current;
    T* data;
public:
    explicit Tape(int n){
        size = n;
        current = 0;
        data = new T[size];
    };

    ~Tape(){
        free(data);
    }

    void Write(T& information){
        data[current] = information;
    }

    void Move(int steps){
        current += steps;
        if (current > size - 1)
            throw std::out_of_range(current);
        if (current < 0)
            throw std::out_of_range(current);
    }

    T Read(){
        return data[current];
    }
};

int main() {

    return 0;
}
