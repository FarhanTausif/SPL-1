#include<bits/stdc++.h>
#include "../include/two_variable.h"

void generateTwoVariableDataset(vector<double> &x, vector<double> &y){
    srand(time(NULL));
    double randomValue;
    for(int i = 0; i < x.size(); ++i){
        randomValue = (rand() % 501) / (double)(rand() % 10 + 1);
        x[i] = randomValue;
    }
    for(int i = 0; i < y.size(); ++i){
        randomValue = (rand() % 501) / (double)(rand() % 10 + 1);
        y[i] = randomValue;
    }
}

void writeTwoVariableDatasetIntoFile(vector<double> &x, vector<double> &y){
    FILE *fp;
    fp = fopen("twoVariableDataset.txt","w");
    if(!fp){
        cerr << "Error opening the file!\n";
        return;  
    }
    for(int i = 0; i < x.size(); ++i){
        fprintf(fp,"%7.2lf\t\t%7.2lf\n",x[i], y[i]);
    }
    fclose(fp);
}