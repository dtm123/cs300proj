
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