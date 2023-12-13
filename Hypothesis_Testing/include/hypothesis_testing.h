#ifndef HYPOTHESIS_TESTING_H
#define HYPOTHESIS_TESTING_H

#include<vector>
using namespace std;

void oneSidedZTest(vector<double> &x, double null_hypothesis, double sigma);
void oneSidedZTest(vector<double> &x, vector<double> &y, double sigma_x, double sigma_y);
void twoSidedZTest(vector<double> &x, double null_hypothesis, double sigma);
void twoSidedZTest(vector<double> &x, vector<double> &y, double sigma_x, double sigma_y);
void readZTable(vector<vector<double>> &z_table);
double calculateZAlphaByTwo(double confidence_interval);

void oneSided_t_Test(vector<double> &x, double null_hypothesis);
void oneSided_t_Test(vector<double> &x, vector<double> &y);
void twoSided_t_Test(vector<double> &x, double null_hypothesis);
void twoSided_t_Test(vector<double> &x, vector<double> &y);
void read_t_Table(vector<vector<pair<double,double>>> &t_table);
double calculateTAlpha(double t_value_of, int dof, double alpha);

void f_test(vector<double> &x, vector<double> &y);
void readFTable(map<pair<int, int>, double> &f_table);
double calculateFAlpha(int m, int n);

#endif