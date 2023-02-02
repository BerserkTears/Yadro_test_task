#include <iostream>
#include "Tape.h"
#include "fstream"

int main() {
    Tape<int> tape;
    tape.Write(103);
    std::cout << tape.Read();
    tape.Move(1);
    tape.Write(7);
    std::cout << tape.Read();
    tape.Move(-1);
    tape.Write(7);
    std::cout << tape.Read();

    return 0;
}
