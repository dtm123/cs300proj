#include <cmath>
#include <stdexcept>
#include "Analysis.h"


void Analysis::readTempFile(const std::string& filename) {

    //check to make sure the file can open
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }

    //parse the temperature file into an array with index 0 = 1959, index 1 = 1960, etc... up to 2023 where index 64
    //value is the temperature in Jan of that year


};

void Analysis::readCO2File(const std::string& filename) {

    //check to make sure the file can open
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }

    //parse the co2 file into an array with index 0 = 1959, index 1 = 1960, etc... up to 2023 where index 64
    //value is the PPM of CO2 per year


};

//
// double pearsonCorrelation(const int x[], const double y[], int size) {
//
//     x[64] = ppmCO2[int];
//
//
//     if (size <= 0) {
//         throw std::invalid_argument("Array size must be positive.");
//     }
//
//     double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0;
//     double sum_x2 = 0.0, sum_y2 = 0.0;
//
//     for (int i = 0; i < size; ++i) {
//         sum_x += x[i];
//         sum_y += y[i];
//         sum_xy += x[i] * y[i];
//         sum_x2 += x[i] * x[i];
//         sum_y2 += y[i] * y[i];
//     }
//
//     double numerator = size * sum_xy - sum_x * sum_y;
//     double denominator = std::sqrt((size * sum_x2 - sum_x * sum_x) * (size * sum_y2 - sum_y * sum_y));
//
//     if (denominator == 0) {
//         throw std::runtime_error("Denominator is zero, correlation cannot be determined.");
//     }
//
//     return numerator / denominator;
// }


// int ppmCO2[64];
// double temp[64];

// double pearsonCorrelation() {
//
//     int* x[64] = temp;
//     double* y[64] = ppmCO2;
//
//
//     double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0;
//     double sum_x2 = 0.0, sum_y2 = 0.0;
//     size_t n = x.size();
//
//     for (size_t i = 0; i < n; ++i) {
//         sum_x += x[i];
//         sum_y += y[i];
//         sum_xy += x[i] * y[i];
//         sum_x2 += x[i] * x[i];
//         sum_y2 += y[i] * y[i];
//     }
//
//     double numerator = n * sum_xy - sum_x * sum_y;
//     double denominator = std::sqrt((n * sum_x2 - sum_x * sum_x) * (n * sum_y2 - sum_y * sum_y));
//
//     if (denominator == 0) {
//         throw std::runtime_error("Denominator is zero, correlation cannot be determined.");
//     }
//
//     return numerator / denominator;
// }




// std::ifstream inputFile();
// if (!inputFile().is_open()) {
//     std::cerr << "Error opening file " << filename << std::endl;
//     return;
// }


// void importFile(const std::string& filename) {
//     std::ifstream inputFile(filename); // Open the file for reading
//
//     if (!inputFile.is_open()) { // Check if the file opened successfully
//         std::cerr << "Error opening file: " << filename << std::endl;
//         return;
//     }
//
//     std::string line;
//     while (getline(inputFile, line)) { // Read file line by line
//         std::cout << line << std::endl; // Output each line to console
//     }
//
//     inputFile.close(); // Close the file
// }