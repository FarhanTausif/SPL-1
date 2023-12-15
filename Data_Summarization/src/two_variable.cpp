#ifndef TWO_VARIABLE_CPP
#define TWO_VARIABLE_CPP

#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
#include "../include/two_variable.h"

void readTwoVariableDatasetFromTxtFile(vector<double> &x, vector<double> &y){
    FILE *fp;
    fp = fopen("twoVariableDataset.txt", "r");
    if(fp == NULL) {
        cout << "ERROR OPENING FILE!" << "twoVariable.txt" << endl;
    }
    while(!feof(fp)){
        double x_var, y_var;
        fscanf(fp,"%lf %lf", &x_var, &y_var);
        x.push_back(x_var);
        y.push_back(y_var);
    }
    fclose(fp);
}

void readTwoVariableDatasetFromCsvFile(vector<double> &x, vector<double> &y){
    ifstream input;
    input.open("twoVariableDataset.csv");
    if(input.fail()){
        cerr << "Unable to open the file!" <<  "twoVariableDataset.csv" << endl;
        input.close();
    }else{
        double point1, point2;
        while(input >> point1 >> point2){
            x.push_back(point1);
            y.push_back(point2);
        }
        input.close();
    }
}

void readTwoVariableDataset(vector<double> &x, vector<double> &y, string filepath){
    ifstream input;
    input.open(filepath);
    if(input.fail()){
        cerr << "Unable to open the file!" <<  filepath << endl;
        input.close();
    }else{
        double point1, point2;
        while(input >> point1 >> point2){
            x.push_back(point1);
            y.push_back(point2);
        }
        input.close();
    }
}

#endif