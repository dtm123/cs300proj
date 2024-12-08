#include "Analysis.h"
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdio>

void Analysis::readTempFile(const std::string& filename) {

    //check to make sure the file can open
    //note file is heavily modified to make sure we don't get any errors on input
    //value is the temperature in Jan of that year
    //Array Index 0 indicates 1959
    //Array Index 1 indicates 1960... and so on
    //Array Index 63 indicates 2023

    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }

    //parse the temperature file into an array with index 0 = 1959, index 1 = 1960, etc... up to 2023 where index 64
    std::string line;
    std::getline(infile, line);
    std::getline(infile, line);
    std::string values_str = line;
    // std::cout << values_str << std::endl;

    std::stringstream ss(values_str);
    std::string item;

    int cnt = 64;
    while (std::getline(ss, item, ',')) {
        temp[cnt] = std::stod(item);
        cnt--;
    }

    // for (int i = 0; i < 65; i++) {
    //     std::cout << temp[i] << std::endl;
    // }
};

void Analysis::readCO2File(const std::string& filename) {


    //add CO2 values into a new array with the following constraints:
    //Array Index 0 indicates 1959
    //Array Index 1 indicates 1960... and so on
    //Array Index 63 indicates 2023

    //check to make sure the file can open
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }

    //parse the values out
    std::string line;
    std::vector<int> second_value;

    int cnt = 0;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string first, second;

        std::getline(ss, first, ',');
        std::getline(ss, second, ',');

        ppmCO2[cnt] = std::stoi(second);
        cnt++;
    }

    // for (int i = 0; i < 65; i++) {
    //     std::cout << ppmCO2[i] << std::endl;
    // }
};

double Analysis::pearsonCorrelation(int y[64],double x[64], int size) {

    if (size <= 0) {
        throw std::invalid_argument("Array size must be positive.");
    }
    //size = 64;
    //ppmCO2 == x[];
    //temp == y[];
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0;
    double sum_x2 = 0.0, sum_y2 = 0.0;

    for (int i = 0; i < size; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
        sum_y2 += y[i] * y[i];

    }
    double numerator = size * sum_xy - sum_x * sum_y;
    double denominator = std::sqrt((size * sum_x2 - sum_x * sum_x) * (size * sum_y2 - sum_y * sum_y));

    std::cout << sum_x << " " << sum_y << " " << sum_x2 << " " << sum_xy << " " << sum_y2 << std::endl;
    std::cout << sqrt((size * sum_x2 - sum_x * sum_x) * (size * sum_y2 - sum_y * sum_y)) << std::endl;
    std::cout << x[0] << " " << y[0] << std::endl;

    std::cout << "Numerator: " << numerator << " Denominator: " << denominator << std::endl;

    if (denominator == 0) {
        throw std::runtime_error("Denominator is zero, correlation cannot be determined.");
    }

    return numerator / denominator;
}


//install koolplot https://www.koolplot.codecutter.org/
//
int graph() {
    return 0;
}
