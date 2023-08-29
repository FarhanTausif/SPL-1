#include "../include/data_summarization.h"

double calculateMean(vector<double> &x){

    double sum = 0.0;
    int datasize  = x.size();
    double mean;
    
    for(double value : x){
        sum += value;
    }

    mean = sum/datasize;
    
    return mean;
}

double calculateMedian(vector<double> &x){

    int datasize = x.size();
    //sort
    sort(x.begin(), x.end());
    double median;
    // datasize & 1  = 1 --> odd
    if(datasize & 1){
        median = x[datasize/2];
    }
    else{
        median = ( x[datasize/2 - 1] + x[datasize/2] ) / 2.0;
    }
    
    return median;
}

vector<double> calculateMode(vector<double> &x){
    
    vector<double> modes;
    int maxFrequency = 0, frequency;
    bool hasModes = false;

    for(int i = 0; i < x.size();++i){
        frequency = 0;

        //checking if the value has already been counted as a mode
        for(double value : modes){
            if(value == x[i]){
                continue;
            }
        }
        
        for(int j = i+1; j < x.size(); ++j){
            if(x[i] == x[j]){
                ++frequency;
            }
        }

        if(frequency > maxFrequency){
            maxFrequency = frequency;
            modes.clear();
            modes.push_back(x[i]);
            hasModes = true;
        }
        else if(frequency == maxFrequency){
            modes.push_back(x[i]);
        }
    }

    if(!hasModes){
        modes.clear();
    }

    return modes;
}

double getMinimum(vector<double> &x){
    
    double min = INT_MAX;

    for(double value : x){
        if(value < min){
            min = value;
        }
    }

    return min;
}

double getMaximum(vector<double> &x){

    double max = INT_MIN;

    for(double value : x){
        if(value > max){
            max = value;
        }
    }
    
    return max;
}

double calculateRange(vector<double> &x){
    
    double maxValue = getMaximum(x); 
    double minValue = getMinimum(x);
    double range = (maxValue-minValue);
    
    return range;
}

double calculateVariance(vector<double> &x){
    
    int datasize = x.size();
    double mean = calculateMean(x);
    double sumSquaredValues = 0.0; 
    double variance;

    for(double value : x){
        sumSquaredValues += value * value;
    }

    variance = (sumSquaredValues - (datasize * mean * mean) )/ (datasize - 1);

    return variance;
}

double calculateStandardDeviation(vector<double> &x){

    double variance = calculateVariance(x);
    double standardDeviation = sqrt(variance);

    return standardDeviation;
}

void summarizeDataset(vector<double> &x,int size){
    
    double mean = calculateMean(x);
    double median = calculateMedian(x);
    vector<double>modes = calculateMode(x);
    double range = calculateRange(x);
    double variance = calculateVariance(x);
    double standardDeviation = calculateStandardDeviation(x);

    cout << setprecision(4) << endl;
    cout << "::Summary based on Measures of Central Tendency::" << endl;
    cout << "Sample Mean: " << mean << endl;
    cout << "Sample Median: " << median << endl;

    if(!modes.empty()){
        cout << "Sample Mode(s): ";
        for(double mode : modes){
            cout << mode << " ";
        }
        cout << endl;
    }
    else{
        cout << "No modes!" << endl;
    }

    cout << endl << endl;
    
    cout << "::Summary based on Measures of Disperse::" << endl;
    cout << "Range of the dataset: " << range << endl; 
    cout << "Sample Variance: " << variance << endl;
    cout << "Sample Std. Deviation: " << standardDeviation << endl;
}