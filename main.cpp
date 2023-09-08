#include "Data_Summarization/src/one_variable.cpp"
#include "Data_Summarization/src/two_variable.cpp"
#include "Data_Summarization/src/data_summarization.cpp"

using namespace std;

int main(){ 

    vector<double> x;
    vector<double> y;
    int choice; 
    bool continueLoop = true;

    cout << "------------------------------------------------------------   DATA SUMMARIZATION   ------------------------------------------------------------" << endl;
    cout << "1.Single-Variable Data summarization\n2.Two-Variable Data/Paired Data summarization\n3.Quit(Press any numbers other than 1 & 2)" << endl;
        
    while(continueLoop){
        cout << "Enter your choice:" << endl;
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

                generateTwoVariableDataset(x, y, twoVariableDatasetSize); 
                writeTwoVariableDatasetIntoFile(x, y);
                summarizeTwoVariableDataset(x,y,twoVariableDatasetSize);
                break;

            default:
                continueLoop = false;
                break;
        }
    }
    
    return 0;
}
