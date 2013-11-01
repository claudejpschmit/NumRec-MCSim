#include "MyMinimizer.h"
#include "MyFileReader.h"
#include "MyPdf.h"

int main(int argc, char *argv[])
{

    srand(time(NULL));
    
    if (argc < 2){
        cout << "This program should be run as follows: " <<
            argv[0] << " input_filename" << endl;
        return -1;
    }

    string inputstring = argv[1];

    cout << "----test armadillo" << endl;
    mat test(2,2);
    test(0,0) = 1;
    test(1,0) = 0;
    test(0,1) = 0;
    test(1,1) = 1;
    
    cout << test << endl;
   
    cout << "----test pdf" << endl;
    MyPdf pdf(1400.0, 1.0, 20.0);
   
    double testpdf = pdf.drawNextValueNoise(0.0);

    cout << testpdf << endl;


    cout << "----test file reader" << endl;    
    cout << inputstring << endl;


    return 0;
}
