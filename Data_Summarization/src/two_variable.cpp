#include<cmath>
#include<algorithm>
#include "../include/two_variable.h"

/*Box-Muller Transformation to generate Normal dataset*/
double randomUniform(){
    return static_cast<double>(rand()) / RAND_MAX;
}

double randomNormalX(){
    double u1 = randomUniform();
    double u2 = randomUniform();
    double r = sqrt(-2.0 * log(u1));
    double theta = (2* M_PI* u2);
    double x = r * cos(theta);
    return x;
}

double randomNormalY(){
    double u1 = randomUniform();
    double u2 = randomUniform();
    double r = sqrt(-2.0 * log(u1));
    double theta = (2* M_PI* u2);
    double y =  r * sin(theta);
    return y;
}

double scaleAndShift(double value, double range, double mean){
    return value * (range / 2.0) + mean;
}

void generateTwoVariableDataset(vector<double> &x, vector<double> &y, int size){
    // srand(time(NULL));
    // double randomValue;
    // for(int i = 0; i < x.size(); ++i){
    //     randomValue = (rand() % 501) / (double)(rand() % 10 + 1);
    //     x[i] = randomValue;
    // }
    // for(int i = 0; i < y.size(); ++i){
    //     randomValue = (rand() % 501) / (double)(rand() % 10 + 1);
    //     y[i] = randomValue;
    // }

    srand(time(NULL));
    double desiredRangeOfX = 150.0;
    double desiredRangeOfY = 1500.0;
    double desiredMean = 0.0;
    double randomX;
    double randomY;

    for(int i = 0; i < size; ++i){
        randomX = randomNormalX();
        randomY = randomNormalY();
        x[i] = fabs(scaleAndShift(randomX, desiredRangeOfX, desiredMean));
        y[i] = fabs(scaleAndShift(randomY, desiredRangeOfY, desiredMean));
    }
}

void writeTwoVariableDatasetIntoFile(vector<double> &x, vector<double> &y){
    FILE *fp;
    fp = fopen("twoVariableDataset.txt","w");
    if(!fp){
        cerr << "Error opening the file!\n";
        return;  
    }
    //sort(x.begin(), x.end());
    //sort(y.begin(), y.end());
    for(int i = 0; i < x.size(); ++i){
        fprintf(fp,"%7.2lf\t\t%7.2lf\n",x[i], y[i]);
    }
    fclose(fp);
}