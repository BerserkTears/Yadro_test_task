#include <iostream>
#include "Tape.h"
#include "fstream"

int main() {
//    std::fstream a("tapes/a", std::fstream::out);
    Tape<int> tape;
    tape.Write(12);
//    tape.Write(7);
    return 0;
}
