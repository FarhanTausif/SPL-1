#include<iostream>
#include<vector>
#include "../Data_Summerization/oneVariable.h"
#include "../Data_Summerization/dataSummarization.h"

using namespace std;

int main(){ 
    
    vector<double> x;
    int datasetSize;
    
    cout << "Enter the size of one variable dataset: " << endl;
    cin >> datasetSize;
    x.resize(datasetSize);

    generateOneVariableDataset(x); 
    writeOneVariableDatasetIntoFile(x);
    summarizeDataset(x,datasetSize);

    return 0;
}
