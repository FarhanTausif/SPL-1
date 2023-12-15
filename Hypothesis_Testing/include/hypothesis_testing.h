#ifndef HYPOTHESIS_TESTING_H
#define HYPOTHESIS_TESTING_H

#include<vector>
using namespace std;

/// @brief Performs one sided z test on a single variable dataset
/// @param x single variable dataset
/// @param null_hypothesis null hypothesis 
/// @param sigma standard deviation
void oneSidedZTest(vector<double> &x, double null_hypothesis, double sigma);

/// @brief Performs one sided z test on a paired dataset
/// @param x single variable dataset x 
/// @param y single variable dataset y
/// @param sigma_x standard deviation of single variable dataset 
/// @param sigma_y standard deviation of paired dataset 
void oneSidedZTest(vector<double> &x, vector<double> &y, double sigma_x, double sigma_y);

/// @brief Performs two sided z test on a single variable dataset
/// @param x single variable dataset
/// @param null_hypothesis null hypothesis 
/// @param sigma standard deviation
void twoSidedZTest(vector<double> &x, double null_hypothesis, double sigma);

/// @brief Performs two sided z test on a paired dataset
/// @param x single variable dataset x 
/// @param y single variable dataset y
/// @param sigma_x standard deviation of single variable dataset 
/// @param sigma_y standard deviation of paired dataset 
void twoSidedZTest(vector<double> &x, vector<double> &y, double sigma_x, double sigma_y);

/// @brief reads z table
/// @param z_table 
void readZTable(vector<vector<double>> &z_table);

/// @brief calculates z alpha by 2
/// @param confidence_interval confidence interval 
/// @return z alpha by 2
double calculateZAlphaByTwo(double confidence_interval);

/// @brief Performs one sided t test on a single variable dataset
/// @param x single variable dataset x 
/// @param null_hypothesis null hypothesis 
void oneSided_t_Test(vector<double> &x, double null_hypothesis);

/// @brief Performs one sided t test on a paired dataset
/// @param x single variable dataset x 
/// @param y single variable dataset y
void oneSided_t_Test(vector<double> &x, vector<double> &y);

/// @brief Performs one sided t test on a single variable dataset
/// @param x single variable dataset x 
/// @param null_hypothesis null hypothesis 
void twoSided_t_Test(vector<double> &x, double null_hypothesis);

/// @brief Performs two sided t test on a paired dataset
/// @param x single variable dataset x 
/// @param y single variable dataset y
void twoSided_t_Test(vector<double> &x, vector<double> &y);

/// @brief reads t table
/// @param t_table 
void read_t_Table(vector<vector<pair<double,double>>> &t_table);

/// @brief calculates t alpha
/// @param dof degree of freedom
/// @param alpha level of significance
/// @return t alpha
double calculateTAlpha(int dof, double alpha);

/// @brief Performs f test on a paired dataset
/// @param x single variable dataset x 
/// @param y single variable dataset y
void f_test(vector<double> &x, vector<double> &y);

/// @brief reads f table
/// @param f_table 
void readFTable(map<pair<int, int>, double> &f_table);

/// @brief calculates f alpha
/// @param m degree of freedom for numerator
/// @param n degree of freedom for denominator
/// @return f alpha
double calculateFAlpha(int m, int n);

/// @brief performs paired t test
/// @param w single variable dataset (after - before)
void paired_t_test(vector<double> &w);

#endif