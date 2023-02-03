#include <iostream>
#include "Tape.h"

int main() {
    Tape tape("testcfg","testtape", 4, 0, 0, 0, 0);
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
