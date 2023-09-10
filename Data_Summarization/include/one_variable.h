#include<iostream>
#include<vector>

using namespace std;

/// @brief generates a one-variable dataset
/// @param x vector to hold the data set
void generateOneVariableDataset(vector<double> &x);

/// @brief writes one-variable dataset into a file 
/// @param x vector of the dataset
void writeOneVariableDatasetIntoFile(vector<double> &x);