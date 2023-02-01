#include <iostream>
#include <Tape.h>


int main() {
    Tape<int> tape(7);
    tape.Write(4);
    tape.Move(1);
//    tape.Write(50);
//    tape.Move(-1);
//    std::cout << tape.Read();
//    std::cout << " ";
//    tape.Move(1);
//    std::cout << tape.Read();
//    std::cout << " ";

    return 0;
}
