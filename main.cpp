#include "Data_Summarization/src/one_variable.cpp"
#include "Data_Summarization/src/two_variable.cpp"
#include "Data_Summarization/src/data_summarization.cpp"
#include "Hypothesis_Testing/src/hypothesis_testing.cpp"
#include "Anova/src/anova.cpp"
#include "Linear_Regression/src/linear_regression.cpp"

using namespace std;

vector<double> x;
vector<double> y;
vector<double> w;
vector<vector<double>> groups;
int choice; 
bool continueOuterLoop = true;
bool continueLoop = true;

/// @brief starts the program
void start();

/// @brief user interface
void interface();

int main(){ 
    start();
    return 0;
}

void start(){
    while(continueOuterLoop){
        interface();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                continueLoop = true;
                while(continueLoop){
                    cout << "\033[1;35m" << "\033[4m" << "\n\n\t\tData Summarization" << "\033[0m" << "\033[1;0m" << endl;
                    cout << "\033[1;32m" << "1.Single-Variable Data summarization\n2.Two-Variable Data/Paired Data summarization\n3.Go to Main Menu(Press any numbers other than 1 & 2)" << "\033[1;0m" << endl;
                    cout << "Enter your choice:";
                    cin >> choice;
                    if(choice == 1){
                        single_var_data_summarization:
                        int oneVariableDatasetSize;
                        string file_type = "";
                        cout << "Enter file type: txt or csv or xlsx or xls" << endl;
                        cout << "File Type:";
                        cin >> file_type;
                        if(file_type == "txt"){
                            x.clear();
                            string txtFilePath;
                            cout << "Enter .txt file path: ";
                            cin >> txtFilePath;
                            readOneVariableDataset(x, txtFilePath);
                            oneVariableDatasetSize = x.size();
                        }else if(file_type == "csv"){
                            x.clear();
                            string csvFilePath;
                            cout << "Enter .csv file path: ";
                            cin >> csvFilePath;
                            readOneVariableDataset(x, csvFilePath);
                            oneVariableDatasetSize = x.size();
                        }else if(file_type == "xlsx"){
                            x.clear();
                            string excelFilePath;
                            cout << "Enter .xlsx file path: ";
                            cin >> excelFilePath;
                            const char* outputCsvFile = "x.csv";
                            const char* command = "ssconvert x.xls x.csv";
                            system(command);
                            readOneVariableDataset(x, string(outputCsvFile));
                            oneVariableDatasetSize = x.size();
                        }else if(file_type == "xls"){
                            x.clear();
                            string excelFilePath;
                            cout << "Enter .xls file path: ";
                            cin >> excelFilePath;
                            const char* outputCsvFile = "one.csv";
                            string command = "ssconvert " + excelFilePath + " " + string(outputCsvFile);
                            system(command.c_str());
                            readOneVariableDataset(x, string(outputCsvFile));
                            oneVariableDatasetSize = x.size();
                        }else{
                            cout << "Invalid file type! Try again\n";
                            goto single_var_data_summarization;
                        }
                        stat_finder:
                        int option;
                        do{
                            cout << "\033[4m" << "\n\n\tSelect Summarizing Method" << "\033[0m" << endl;
                            cout << "\033[1;33m" << "1.Individual Statistic Finder\n2.Full Summarization\n3.Go to Data Summarization(Press any key other than 1 & 2)\n" << "\033[1;0m";
                            cin.ignore();
                            cout << "option:";
                            cin >> option;
                            if(option == 1){
                                    cout << "\033[4m" << "\tIndividual Statistic Finder" << "\033[0m" << endl;
                                    cout << "Select Statistic:-" << endl;
                                    cout <<"\033[1;34m" << "1.Mean\n2.Median\n3.Mode\n4.Sample Standard Variance\n5.Sample Standard Deviation\n";
                                    cout << "6.Quartiles\n7.Deciles\n8.Outliers\n9.Skewness\n10.Kurtosis\n" << "\033[1;0m";
                                    int statistic;
                                    cout << "Enter statistic:";
                                    cin >> statistic;
                                    if(statistic == 1){
                                        double mean = calculateMean(x);
                                        cout << "Sample mean:" << mean << endl;
                                    }else if(statistic == 2){
                                        double median = calculateMedian(x);
                                        cout << "Sample median:" << median << endl;
                                    }else if(statistic == 3){
                                        vector<double>modes = calculateMode(x);
                                            if(!modes.empty()){
            
                                                cout << "Sample Mode(s): ";
                                                for(double mode : modes){
                                                    cout << mode << " ";
                                                }
                                                cout << endl;

                                                if(modes.size() == 1){
                                                    cout << "The Dataset is Uni-modal" << endl;
                                                }
                                                else if(modes.size() == 2){
                                                    cout << "The Dataset is Bi-modal" << endl;
                                                }
                                                else{
                                                    cout << "The Dataset is Tri-modal" << endl;
                                                }

                                            }
                                            else{
                                                cout << "No modes!" << endl;
                                            }

                                    }else if(statistic == 4){
                                        double variance = calculateVariance(x);
                                        cout << "Sample standard variance:" << variance << endl;
                                    }else if(statistic == 5){
                                        double standardDeviation = calculateStandardDeviation(x);
                                        cout << "Sample standard deviation:" << standardDeviation << endl;
                                    }else if(statistic == 6){
                                        vector<double> quartiles = calculateQuartiles(x);
                                        cout << "Quartiles:" << endl;
                                        cout << "Lower Quartile, Q1 = " << quartiles[0] << "  Middle Quartile, Q2 = " << quartiles[1] << "  Upper Quartile, Q3 = " << quartiles[2] << endl;
                                    }else if(statistic == 7){
                                        vector<double> deciles = calculateDeciles(x);
                                        cout << "Deciles:" << endl;
                                        for(double decile: deciles){
                                            cout << decile << " ";
                                        }
                                        cout << endl;
                                    }else if(statistic == 8){
                                        vector<double> outliersUsingInterQuartileRange = detectOutliersUsingInterQuartileRange(x);
                                        vector<double> outliersUsingZScore = detectOutliersUsingZScore(x);
                                        cout << "Outliers(" << outliersUsingInterQuartileRange.size() << " values)" << " Using inter quartile range:"   << endl;
                                        if(outliersUsingInterQuartileRange.empty()){
                                            cout << "No outliers detected using IQR method!" << endl;
                                        }
                                        else{
                                            for(double outlier : outliersUsingInterQuartileRange){
                                                cout << outlier << " ";
                                            }
                                            cout << endl;
                                        }
                                        cout << endl;
                                        cout << "Outliers(" << outliersUsingZScore.size() << " values)" << " Using z-score:"   << endl;
                                        if(outliersUsingZScore.empty()){
                                            cout << "No outliers detected using z-score method!" << endl;
                                        }
                                        else{
                                            for(double outlier : outliersUsingZScore){
                                                cout << outlier << " ";
                                            }
                                            cout << endl;
                                        }
                                    }else if(statistic == 9){
                                        double skewness;
                                        vector<double>modes = calculateMode(x);
                                        if(modes.size() == 1){
                                            skewness = calculateSkewnessUsingPearsonsFirstMeasure(x, modes[0]);
                                        }
                                        else{
                                            skewness = calculateSkewnessUsingPearsonsSecondMeasure(x);
                                        }
                                        cout << "Skewness value: " << skewness << endl;
                                    }else if(statistic == 10){
                                        double kurtosis = calculateKurtosis(x);
                                        cout << "Kurtosis:" << kurtosis << endl;
                                    }else{
                                        goto stat_finder;
                                    }
                                    
                            }else if(option == 2){
                                summarizeOneVariableDataset(x,oneVariableDatasetSize);
                            }
                        }while(option == 1 || option == 2);

                    }else if(choice == 2){
                        paired_data_summarization:
                        int twoVariableDatasetSize; 
                        string file_type = "";
                        cout << "Enter file type: txt or csv or xlsx or xls" << endl;
                        cout << "File Type:";
                        cin >> file_type;
                        if(file_type == "txt"){
                            x.clear();
                            y.clear();
                            string txtFilePath;
                            cout << "Enter .txt file path: ";
                            cin >> txtFilePath;
                            readTwoVariableDataset(x, y, txtFilePath);
                            twoVariableDatasetSize = x.size();
                        }else if(file_type == "csv"){
                            x.clear();
                            y.clear();
                            string csvFilePath;
                            cout << "Enter .csv file path: ";
                            cin >> csvFilePath;
                            readTwoVariableDataset(x, y, csvFilePath);
                            twoVariableDatasetSize = x.size();
                        }else if(file_type == "xlsx"){
                            x.clear();
                            y.clear();
                            string excelFilePath;
                            cout << "Enter .xlsx file path: ";
                            cin >> excelFilePath;
                            const char* outputCsvFile = "xy.csv";
                            const char* command = "ssconvert xy.xls xy.csv";
                            system(command);
                            readTwoVariableDataset(x, y, string(outputCsvFile));
                            twoVariableDatasetSize = x.size();
                        }else if(file_type == "xls"){
                            x.clear();
                            y.clear();
                            string excelFilePath;
                            cout << "Enter .xls file path: ";
                            cin >> excelFilePath;
                            const char* outputCsvFile = "two.csv";
                            string command = "ssconvert " + excelFilePath + " " + string(outputCsvFile);
                            system(command.c_str());
                            readTwoVariableDataset(x, y, string(outputCsvFile));
                            twoVariableDatasetSize = x.size();
                        }else{
                            cout << "Invalid file type! Try again\n";
                            goto paired_data_summarization;
                        }
                        
                        summarizeTwoVariableDataset(x,y,twoVariableDatasetSize);
                    
                    }else {
                        continueLoop = false;
                        break;
                    }
                }

                break;
            
            case 2:
                continueLoop = true;
                while(continueLoop){
                    cout << "\033[1;35m" << "\033[4m" << "\n\n\t\tHypothesis Testing" << "\033[0m" << endl << "\033[1;0m";
                    cout << "\033[1;32m" << "1.Z-Test\n2.T-Test\n3.F-Test\n4.Paired T test\n5.Go to Main Menu(Press any number other than 1 to 4)\n" << "\033[1;0m";
                    cout << "Enter your choice:";
                    cin >> choice;
                    if (choice == 1){  
                        x.clear();  
                        readOneVariableDatasetFromTxtFile(x);
                        double null_hypothesis;
                        cout << "Enter the null hypothesis," << " \u00b5" << "0 = ";
                        cin >> null_hypothesis;
                        double sigma;
                        cout << "Enter the Population standard deviation," << " \u03c3" << " = ";
                        cin >> sigma;
                        twoSidedZTest(x, null_hypothesis, sigma);
                    }else if (choice == 2){
                        x.clear();  
                        readOneVariableDataset(x, "t_test.txt");
                        double null_hypothesis;
                        cout << "Enter the null hypothesis," << " \u00b5" << "0 = ";
                        cin >> null_hypothesis;
                        oneSided_t_Test(x, null_hypothesis);
                    }else if (choice == 3){
                        x.clear();  
                        y.clear();
                        readTwoVariableDataset(x, y, "t_test.txt");
                        f_test(x, y);
                    }else if (choice == 4){
                        x.clear();
                        y.clear();
                        readTwoVariableDataset(x, y, "paired_t_test.txt");
                        for(int i = 0; i < x.size(); ++i){
                            w.push_back(y[i] - x[i]); // w -> after - before
                        }
                        paired_t_test(w);
                    }else{
                        continueLoop = false;
                        break;
                    }
                }
                break;

            case 3:
                cout << "\033[1;35m" << "\033[4m" << "\n\n\t\tAnalysis Of Variance" << "\033[0m" << "\033[1;0m" << endl;
                groups.clear();
                read_groups(groups);
                anova_test(groups);
                break;

            case 4:
                cout << "\033[1;35m" << "\033[4m" << "\n\n\t\tLinear Regression" << "\033[0m" << "\033[1;0m" << endl;
                x.clear();
                y.clear();
                readTwoVariableDataset(x,y, "linear_regression.csv");
                linear_regression(x,y);
                break;
            
            default:
                cout << "\033[1;39m" << "\n\t\tThanks for using Stat-Inferno\n" << "\033[1;0m";
                continueOuterLoop = false;
                break;
            }
    }
}

void interface(){
    string projectTitle = "Stat-Inferno: Explorations of Statistical Inference";
        const int boxWidth = projectTitle.length() + 4;
        cout << "\n\n\t\t" << '+' << string(boxWidth - 2, '-') << '+' << endl;
        cout << "\t\t| " << projectTitle;
        cout << string(boxWidth - 4 - projectTitle.length(), ' ');
        cout << " |" << endl;
        cout << "\t\t" << '+' << string(boxWidth - 2, '-') << '+' << endl;
        cout << "\033[1;33m" << "1.Data Summarization\n";
        cout << "2.Hypothesis Testing\n";
        cout << "3.ANOVA Test\n";
        cout << "4.Linear Regression\n";
        cout << "5.Quit(Press any number other than 1-4)\n" << "\033[1;0m";
}