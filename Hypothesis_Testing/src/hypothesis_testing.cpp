#ifndef HYPOTHESIS_TESTING_CPP
#define HYPOTHESIS_TESTING_CPP

#include <fstream>
#include <map>
#include "../include/hypothesis_testing.h"
#include "../../Data_Summarization/src/one_variable.cpp"
#include "../../Data_Summarization/src/data_summarization.cpp"


void oneSidedZTest(vector<double> &x, double null_hypothesis, double sigma){
    double sample_mean = calculateMean(x);
    int n = x.size();
    double z_statistic = fabs((sample_mean - null_hypothesis) / (sigma / sqrt(n)));
    double alpha = 0.05;
    double confidence_interval = 1 - alpha;
    double z_alpha = 1.645;
   
    if(z_statistic > z_alpha){
        cout << "We can reject the Null hypothesis that the population mean is: " << null_hypothesis << endl;
    }else{
        cout << "We fail to reject the Null hypothesis that the population mean is: " << null_hypothesis << endl;  
    }
}

void oneSidedZTest(vector<double> &x, vector<double> &y, double sigma_x, double sigma_y){
    double x_bar = calculateMean(x);
    double y_bar = calculateMean(y);
    double sample_mean = x_bar - y_bar;
    int n = x.size();
    int m = y.size();
    double sigma = sqrt( ((pow(sigma_x, 2))/n) + ((pow(sigma_y, 2))/m) );
    double null_hypothesis = 0.0; // mu_X = mu_Y
    double z_statistic = fabs((sample_mean - null_hypothesis) / sigma);
    double alpha = 0.05;
    double confidence_interval = 1 - alpha;
    double z_alpha = 1.645;
   
    if(z_statistic > z_alpha){
        cout << "We can reject the Null hypothesis that the two group has the same mean!" << endl;
    }else{
        cout << "We fail to reject the Null hypothesis that the two group has the same mean!" << endl;  
    }  
}

void twoSidedZTest(vector<double> &x, double null_hypothesis, double sigma){
    double sample_mean = calculateMean(x);
    int n = x.size();
    double z_statistic = fabs((sample_mean - null_hypothesis) / (sigma / sqrt(n)));
    double alpha = 0.05;
    double confidence_interval = 1 - alpha/2;
    double z_alpha_by_2 = calculateZAlphaByTwo(confidence_interval);
   
    if(z_statistic > z_alpha_by_2){
        cout << "We can reject the Null hypothesis that the population mean is: " << null_hypothesis << endl;
    }else{
        cout << "We fail to reject the Null hypothesis that the population mean is: " << null_hypothesis << endl;  
    }
}

void twoSidedZTest(vector<double> &x, vector<double> &y, double sigma_x, double sigma_y){
    double x_bar = calculateMean(x);
    double y_bar = calculateMean(y);
    double sample_mean = x_bar - y_bar;
    int n = x.size();
    int m = y.size();
    double sigma = sqrt( ((pow(sigma_x, 2))/n) + ((pow(sigma_y, 2))/m) );
    double null_hypothesis = 0.0;
    double z_statistic;
    // if n and m are large then z_statistic is differently calculated
    if(n > 30 and m > 30){
        double var_x = calculateVariance(x);
        double var_y = calculateVariance(y);
        double sigma = var_x/n + var_y/m;
        z_statistic = (sample_mean - null_hypothesis) / sqrt(sigma);
    }else{
        z_statistic = fabs((sample_mean - null_hypothesis) / sigma);
    }
    double alpha = 0.05;
    double confidence_interval = 1 - alpha/2;
    double z_alpha_by_2 = calculateZAlphaByTwo(confidence_interval);
   
    if(z_statistic > z_alpha_by_2){
        cout << "We can reject the Null hypothesis that the two group has the same mean!" << endl;
    }else{
        cout << "We fail to reject the Null hypothesis that the two group has the same mean!" << endl;  
    }
}

void readZTable(vector<vector<double>> &z_table){
    ifstream input;
    input.open("z_table.txt");
    vector<double> row;
    double value;
    for(int i = 0; i < 40; ++i){
        row.clear();
        for(int j = 0; j < 10; ++j){
            input >> value;
            row.push_back(value);
        }
        z_table.push_back(row);
    }
    input.close();
}

double calculateZAlphaByTwo(double confidence_interval){
    vector<vector<double>> z_table;
    readZTable(z_table);
    double threshold = 10e-4;
    int row, column;
    bool flag = false;
    for(row = 0; row < 40; ++row){
        for(column = 0 ; column < 10; ++column){
            if(fabs(z_table[row][column] - confidence_interval) < threshold){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    row--;
    double z_value = (double) row / 10 + (double) column / 100;
    return z_value;
}

void oneSided_t_Test(vector<double> &x, double null_hypothesis){
    double sample_mean = calculateMean(x);
    double sample_dev = calculateStandardDeviation(x);
    int n = x.size();
    double t_statistic = fabs((sample_mean - null_hypothesis) / (sample_dev / sqrt(n)));
    double alpha = 0.05;
    double t_value_of = alpha;
    int dof = n - 1;
    double t_alpha = calculateTAlpha(t_value_of, dof, alpha);
   
    if(t_statistic > t_alpha){
        cout << "We can reject the Null hypothesis that the population mean is: " << null_hypothesis << endl;
    }else{
        cout << "We fail to reject the Null hypothesis that the population mean is: " << null_hypothesis << endl;  
    }
}

void oneSided_t_Test(vector<double> &x, vector<double> &y){
    double x_bar = calculateMean(x);
    double y_bar = calculateMean(y);
    double sample_mean = (x_bar - y_bar);
    double var_x = calculateVariance(x);
    double var_y = calculateVariance(y);
    int n = x.size();
    int m = y.size();
    int dof = n + m - 2;
    double pooled_variance = ( (n-1)*var_x + (m-1)*var_y ) / dof;
    double pooled_dev = sqrt(pooled_variance);
    double null_hypothesis = 0.0; // muX = muY
    double t_statistic = fabs((sample_mean - null_hypothesis) / (pooled_dev * sqrt(1/n + 1/m)));
    double alpha = 0.05;
    double t_value_of = alpha;
    double t_alpha = calculateTAlpha(t_value_of, dof, alpha);
   
    if(t_statistic > t_alpha){
        cout << "We can reject the Null hypothesis that the two group has the same mean!" << endl;
    }else{
        cout << "We fail to reject the Null hypothesis that the two group has the same mean!" << endl;  
    }
}

void twoSided_t_Test(vector<double> &x, double null_hypothesis){
    double sample_mean = calculateMean(x);
    double sample_dev = calculateStandardDeviation(x);
    int n = x.size();
    double t_statistic = fabs((sample_mean - null_hypothesis) / (sample_dev / sqrt(n)));
    double alpha = 0.05;
    double t_value_of = alpha/2;
    int dof = n - 1;
    double t_alpha_by_2 = calculateTAlpha(t_value_of, dof, alpha);
   
    if(t_statistic > t_alpha_by_2){
        cout << "We can reject the Null hypothesis that the population mean is: " << null_hypothesis << endl;
    }else{
        cout << "We fail to reject the Null hypothesis that the population mean is: " << null_hypothesis << endl;  
    }
}
void twoSided_t_Test(vector<double> &x, vector<double> &y){
    double x_bar = calculateMean(x);
    double y_bar = calculateMean(y);
    double sample_mean = (x_bar - y_bar);
    double var_x = calculateVariance(x);
    double var_y = calculateVariance(y);
    int n = x.size();
    int m = y.size();
    int dof = n + m - 2;
    double pooled_variance = ( (n-1)*var_x + (m-1)*var_y ) / dof;
    double pooled_dev = sqrt(pooled_variance);
    double null_hypothesis = 0.0; // muX = muY
    double t_statistic = fabs((sample_mean - null_hypothesis) / (pooled_dev * sqrt(1/n + 1/m)));
    double alpha = 0.05;
    double t_value_of = alpha/2;
    double t_alpha_by_2 = calculateTAlpha(t_value_of, dof, alpha);
   
    if(t_statistic > t_alpha_by_2){
        cout << "We can reject the Null hypothesis that the two group has the same mean!" << endl;
    }else{
        cout << "We fail to reject the Null hypothesis that the two group has the same mean!" << endl;  
    }
}

void read_t_Table(vector<vector<pair<double,double>>> &t_table){
    t_table.push_back({{0.0,0.0}});
    ifstream input;
    input.open("t_table.txt");
    vector<pair<double, double>> t_values;
    int dof;
    double alpha, value;
    for(int i = 1; i <= 29; i++){
        t_values.clear();
        for(int j = 1; j <=5; ++j){
            input >> dof >> alpha >> value;
            t_values.push_back({alpha, value});   
        }
        t_table.push_back(t_values);
    }
    input.close();
}

double calculateTAlpha(double t_value_of, int dof, double alpha){
    vector<vector<pair<double, double>>> t_table;
    read_t_Table(t_table);
    double t_alpha;
    for(int i = 0; i < 5; ++i){
        if(t_table[dof][i].first == alpha) t_alpha = t_table[dof][i].second;
    }
    return t_alpha;
}


void f_test(vector<double> &x, vector<double> &y){
    double var_x = calculateVariance(x);
    double var_y = calculateVariance(y);
    double f_statistic = var_x/var_y; // if Ho -> population variances are equal
    int n = x.size() - 1;
    int m = y.size() - 1;
    double f_alpha = calculateFAlpha(m, n);
    if(f_statistic > f_alpha){
        cout << "We can reject the null hypothesis that two groups has the same variance!" << endl;
    }else{
        cout << "We fail to reject the null hypothesis that two groups has the same variance!" << endl;
    }
}

void readFTable(map<pair<int, int>, double> &f_table){
    ifstream input;
    input.open("f_table.txt");
    int m, n;
    double value;
    while(input >> m >> n >> value){
        f_table[{m,n}] = value;
    }
    input.close();
}

double calculateFAlpha(int m, int n){
    map<pair<int, int>, double> f_table;
    readFTable(f_table);
    return f_table[{m,n}];
}

#endif