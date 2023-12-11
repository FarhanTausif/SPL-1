#include "../include/one_variable.h"
#include<fstream>

void generateOneVariableDataset(vector<double> &x){
    srand(time(NULL));
    double randomValue;
    for(int i = 0; i < x.size(); ++i){
        randomValue = (rand() % 500 + 1) / (double)(rand() % 10 + 1);
        x[i] = randomValue;
    }
}

void readOneVariableDatasetFromTxtFile(vector<double> &x){
    FILE *fp;
    fp = fopen("oneVariableDataset.txt", "r");
    while(!feof(fp)){
        double data;
        fscanf(fp,"%lf", &data);
        x.push_back(data);
    }
}

void readOneVariableDatasetFromCsvFile(vector<double> &x){
    ifstream input;
    input.open("oneVariableDataset.csv");
    if(input.fail()){
        cerr << "Unable to open the file!" <<  "oneVariableDataset.csv" << endl;
        input.close();
    }else{
        double data;
        while(input >> data){
            x.push_back(data);
        }
        //for(auto data : x) cout << data << endl;
        input.close();
    }
}

void writeOneVariableDatasetIntoFile(vector<double> &x){
    FILE *fp;
    fp = fopen("oneVariableDataset.txt","w");
    if(!fp){
        cerr << "Error opening the file!\n";
        return;  
    }
    for(int i = 0; i < x.size(); ++i){
        fprintf(fp,"%7.2lf\n",x[i]);
    }
    fclose(fp);
}

