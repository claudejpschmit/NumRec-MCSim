#include "MyMinimizer.h"
#include "MyFileReader.h"

int main(int argc, char *argv[])
{
    mat test(2,2);
    test(0,0) = 1;
    test(1,0) = 0;
    test(0,1) = 0;
    test(1,1) = 1;

    cout << test << endl;
    return 0;
}
