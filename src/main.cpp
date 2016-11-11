#include "cpu.h"

int main(int argv, char **argc)
{
    if(argv < 2){
        cout << "Make sure you specify a file!" << endl;
        exit(1);
    }
    CPU c;
    c.run(argc[1]);
}
