#ifndef ONE_VARIABLE_CPP
#define ONE_VARIABLE_CPP

#include "../include/one_variable.h"
#include<fstream>

void readOneVariableDatasetFromTxtFile(vector<double> &x){
    FILE *fp;
    fp = fopen("oneVariableDataset.txt", "r");
    if(fp == NULL){
        cerr << "ERROR OPENING FILE!" << endl;
    }
    while(!feof(fp)){
        double data;
        fscanf(fp,"%lf", &data);
        x.push_back(data);
    }
    fclose(fp);
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
        input.close();
    }
}

void readOneVariableDataset(vector<double> &x, string filepath) {
    ifstream input;
    input.open(filepath);
    if(input.fail()){
        cerr << "ERROR OPENING THE FILE:" << filepath << endl;
        input.close();
    }else{
        double value;
        while(input >> value){
            x.push_back(value);
        }
        input.close();
    }
}

#endif

