#include "cpu.h"


CPU::CPU()
{
    // where the function pointer map will be init'd
    return;
}

void CPU::run(char *file)
{
    load(file);
}

void CPU::load(char *file)
{
    vector<int> v;
    for (ifstream f(file, ios::binary); f.good();)
        v.push_back(f.get());
}