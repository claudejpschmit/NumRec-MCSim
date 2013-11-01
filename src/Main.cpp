#include "MyMinimizer.h"
#include "MyFileReader.h"
#include "MyChiSquared.h"
#include "MyPdf.h"
//#include "Minuit2Minimizer.h"

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
    MyPdf pdf(1.4, 0.1, 6.0);
    
    vector<double> distribution;
    for (int i = 0; i < 1000; ++i){
        distribution.push_back(pdf.drawNextValueNoise(0.0));
    }
    
    FILE * pFile;
    pFile = fopen("distribution.txt","w");
    for (int i = 0; i < 1000; ++i){
        fprintf(pFile,"%f\n",distribution[i]);
    }
    fclose (pFile);



    cout << "----test file reader" << endl;    
    cout << inputstring << endl;
    
    MyFileReader file(inputstring);



    return 0;
}
