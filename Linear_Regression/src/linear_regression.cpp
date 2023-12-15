#ifndef LINEAR_REGRESSION_CPP
#define LINEAR_REGRESSION_CPP

#include <bits/stdc++.h>
#include "../include/linear_regression.h"
#include "../../Data_Summarization/src/data_summarization.cpp"

void linear_regression(vector<double> &x, vector<double> &y){
    double beta0_hat;
    double beta1_hat;
    vector<double> estimates;
    estimates.resize(2);
    double x_bar = calculateMean(x);
    double y_bar = calculateMean(y);
    int n = x.size();
    double x_sq = 0.0;
    double xy = 0.0;
 
    for(int i = 0; i < n; ++i){
        xy += (x[i] * y[i]);
    }

    double Sxy;
    double Sxx;

    Sxy = xy - (n * x_bar * y_bar);

    for(int i = 0; i < n; ++i){
        x_sq += (x[i] * x[i]);
    }

    Sxx = x_sq - n*(pow(x_bar,2));

    beta1_hat = Sxy / Sxx;
    beta0_hat = y_bar - (beta1_hat * x_bar);
    estimates[0] = beta0_hat;
    estimates[1] = beta1_hat;

    cout << "Linear Regression Model, Y = " <<  "\u03b2" << "0 + " << "\u03b2" << "1x + " << "\u03b5" << endl;  
    cout << "The Fitted Model, Y_hat = " << beta0_hat << " + " << beta1_hat << "x" << endl;
    cout << "The estimates of the parameters: " << endl;
    cout << "(";
    for(auto estimate : estimates) {
        cout << estimate << " ";
    }
    cout << ")^T" << endl;
}

#endif