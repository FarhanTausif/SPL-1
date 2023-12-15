#ifndef ONE_VARIABLE_H
#define ONE_VARIABLE_H

#include<iostream>
#include<vector>

using namespace std;


/// @brief reads one variable dataset form a txt file
/// @param x vector of the dataset
void readOneVariableDatasetFromTxtFile();

/// @brief reads one variable dataset from a csv file
/// @param x vector of the dataset
void readOneVariableDatasetFromCsvFile();

/// @brief reads one variable dataset from txt or csv file
/// @param x vector of the dataset
/// @param filepath filepath of the file(can be of .txt or .csv format)
void readOneVariableDataset(vector<double> &x, string filepath);

#endif