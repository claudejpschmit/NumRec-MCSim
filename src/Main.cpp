#include "MyMinimizer.h"
#include "MyFileReader.h"
#include "MyChiSquared.h"
#include "MyPdf.h"
#include "MaxLikelihood.h"
#include "TMinuit.h"

MaxLikelihood * theMaxLikelihoodObject = 0;

void fcn(Int_t& npar, Double_t* deriv, Double_t& f, Double_t par[], Int_t flag) {
    mat p(2,1);
    p(0,0) = par[0];
    p(1,0) = par[1];
    theMaxLikelihoodObject->setParameters(p);
    double result = theMaxLikelihoodObject->evaluate();
    cout << " In FCN " << p(0,0) << " " << p(1,0) << "          result " << result << endl;
    f = result;
        
}

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

    cout << "----likelihood" << endl;

    mat distribution_Mat(1000,1);
    for (int i = 0; i < 1000; ++i)
        distribution_Mat(i,0) = distribution[i];
    
    mat parameters(2,1);
    parameters(0,0)=1.4;
    parameters(1,0)=0.1;

    MaxLikelihood maxL(distribution_Mat, parameters, 6.0);
    theMaxLikelihoodObject = &maxL;

    TMinuit m_minuit(2);
    m_minuit.SetFCN(fcn);
    m_minuit.SetErrorDef(1.0);
    m_minuit.SetPrintLevel(1);

    m_minuit.DefineParameter(0, "tau", 1.4, 0.1, -10.0, 10.0);
    m_minuit.DefineParameter(1, "A", 0.1, 0.1, -10.0, 10.0);

    mat A_meas(500,1)
    for (int i = 0; i < 500; ++i) {
        //this was the code before
        //m_minuit.Migrad();
        //but Migrad returns a number of type Int_t???
        //so that needs to be stored somewhere no?
        A_meas(i,0) = m_minuit.Migrad();

        // would I need to use:
        // Int_t TMinuit::GetParameter(Int_t parNo, Double_t &currentValue, Double_t &currentError) const
        // but what are currentValue and currentError? are they the addresses where the results will be
        // stored? but then what does the function return?
    }

    // this is unnecessary,
    // don't use a matrix to store intermediate values 
    // don't have 2 for loops
    ofstream output;
    output.open("A_measured.txt");
    for (int i = 0; i < 500; ++i) {
        output << A_meas(i,0) << endl;
    }
    output.close();

    // then use the python script to plot
    cout << "check progress -> done" << endl;
    return 0;
}
