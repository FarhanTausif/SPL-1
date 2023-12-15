#ifndef TWO_VARIABLE_H
#define TWO_VARIABLE_H

#include<iostream>
#include<vector>

using namespace std;
/// @brief reads two variable dataset form a txt file
/// @param x vector of the dataset of X-variable
/// @param y vector of the dataset of Y-variable
void readTwoVariableDatasetFromTxtFile(vector<double> &x, vector<double> &y);

/// @brief reads two variable dataset from a csv file
/// @param x vector of the dataset of X-variable
/// @param y vector of the dataset of Y-variable
void readTwoVariableDatasetFromCsvFile(vector<double> &x, vector<double> &y);


/// @brief reads two variable dataset from a csv file
/// @param x vector of the dataset of X-variable
/// @param y vector of the dataset of Y-variable
/// @param filepath filepath of the file(can be of .txt or .csv format)
void readTwoVariableDataset(vector<double> &x, vector<double> &y, string filepath);

#endif