#include "Data_Summarization/src/one_variable.cpp"
#include "Data_Summarization/src/data_summarization.cpp"

using namespace std;

int main(){ 
    
    vector<double> x;
    int datasetSize;
    
    cout << "---------------MODULE-1: DATA SUMMARIZATION---------------" << endl;
    
    cout << "Enter the size of one variable dataset: " << endl;
    cin >> datasetSize;
    x.resize(datasetSize);

    generateOneVariableDataset(x); 
    writeOneVariableDatasetIntoFile(x);
    summarizeDataset(x,datasetSize);

    return 0;
}
