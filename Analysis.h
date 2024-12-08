

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
    void calculatePearsonCorrelation();
    double calculatePearsonCorrelation(const std::vector<double>& x, const std::vector<double>& y);
    int graph();
    int saveAnalysis(const std::string& filename);
    int loadAnalysis(const std::string& filename);
    double coefficient;

private:

};



#endif //ANALYSIS_H
