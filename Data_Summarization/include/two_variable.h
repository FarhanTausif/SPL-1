#include<iostream>
#include<vector>

using std::vector;
using std:: cout;
using std:: cerr;
using std:: endl;

/// @brief generates a two-variable dataset
/// @param x vector to hold the data set
void generateTwoVariableDataset(vector<double> &x, vector<double> &y);

/// @brief writes two-variable dataset into a file 
/// @param x vector of the dataset of X-variable
/// @param y vector of the dataset of Y-variable
void writeTwoVariableDatasetIntoFile(vector<double> &x, vector<double> &y);