

#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <vector>
#include <fstream>
#include <iostream>
#include <string>


class Analysis {
public:
    void readTempFile(const std::string& filename);
    void readCO2File(const std::string& filename);
    int ppmCO2[64];
    double temp[64];
    void pearsonCorrelation() {pearsonCorrelation(&ppmCO2[64], &temp[64], 64);}
    double pearsonCorrelation(int y[], double x[], int size);  //const int ppmCO2[], const double temp[], int size = 64
    int graph();
    int saveAnalysis(const std::string& filename);

private:

};



#endif //ANALYSIS_H
