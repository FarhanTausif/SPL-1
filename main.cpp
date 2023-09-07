#include "Data_Summarization/src/one_variable.cpp"
#include "Data_Summarization/src/two_variable.cpp"
#include "Data_Summarization/src/data_summarization.cpp"

using namespace std;

int main(){ 

    vector<double> x;
    vector<double> y;
    int twoVariableDatasetSize;
    int choice; 

    cout << "------------------------------   DATA SUMMARIZATION   ------------------------------" << endl;
    
    cout << "Enter your choice:::Press 1 for One Variable Data summarization\nOr,\nPress 2 for Two Variable Data summarization" << endl;
    cin >> choice;
    switch (choice){
    case 1:

        int oneVariableDatasetSize; 
        cout << "Enter the size of one variable dataset: " << endl;
        cin >> oneVariableDatasetSize;
        x.resize(oneVariableDatasetSize);

        generateOneVariableDataset(x); 
        writeOneVariableDatasetIntoFile(x);
        summarizeOneVariableDataset(x,oneVariableDatasetSize);
    
        break;

    case 2:

        int twoVariableDatasetSize; 
        cout << "Enter the size of two variable dataset: " << endl;
        cin >> twoVariableDatasetSize;
        x.resize(twoVariableDatasetSize);
        y.resize(twoVariableDatasetSize);

        generateTwoVariableDataset(x, y); 
        writeTwoVariableDatasetIntoFile(x, y);
        break;

    default:
        break;
    }
    
    return 0;
}
