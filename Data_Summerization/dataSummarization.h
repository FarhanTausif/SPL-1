#include "dataSummarization.cpp"

double calculateMean(vector<double> &x){
    double sum = 0.0;
    size_t sizeOfDataset  = x.size();
    double mean;
    
    for(double value : x){
        sum += value;
    }

    mean = sum/sizeOfDataset;
    
    return mean;
}

double calculateMedian(vector<double> &x){

    size_t sizeOfDataset = x.size();
    //sort
    sort(x.begin(), x.end());
    double median;
    // sizeOfDataset & 1  = 1 --> odd
    if(sizeOfDataset & 1){
        median = x[sizeOfDataset/2];
    }
    else{
        median = ( x[sizeOfDataset/2 - 1] + x[sizeOfDataset/2] ) / 2.0;
    }
    
    return median;
}

vector<double> calculateMode(vector<double> &x){
    
    vector<double> modes;
    int maxFrequency = 0, frequency;
    bool hasModes = false;

    for(size_t i = 0; i < x.size();++i){
        frequency = 0;

        //checking if the value has already been counted as a mode
        for(double value : modes){
            if(value == x[i]){
                continue;
            }
        }
        
        for(size_t j = i+1; j < x.size(); ++j){
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

void summarizeDataset(vector<double> &x,int size){
    vector<double>modes;

    cout << setprecision(4) << endl;
    cout << "Mean: " << calculateMean(x) << endl;
    cout << "Median: " << calculateMedian(x) << endl;
    
    modes = calculateMode(x);

    if(!modes.empty()){
        cout << "Modes: ";
        for(double mode : modes){
            cout << mode << " ";
        }
        cout << endl;
    }
    else{
        cout << "No modes!" << endl;
    }

}