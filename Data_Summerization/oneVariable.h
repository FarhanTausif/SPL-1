#include<iostream>
#include<vector>

using namespace std;

void generateOneVariableDataset(vector<double> &x);
void writeOneVariableDatasetIntoFile(vector<double> &x);

void generateOneVariableDataset(vector<double> &x){
    srand(time(NULL));
    double randomValue;
    for(int i = 0; i < x.size(); ++i){
        randomValue = (rand() % 2001) / (double)(rand() % 10 + 1);
        x[i] = randomValue;
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

