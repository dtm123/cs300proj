
#include "Analysis.h"

// std::ifstream inputFile()


void importFile(const std::string& filename) {
    std::ifstream inputFile(filename); // Open the file for reading

    if (!inputFile.is_open()) { // Check if the file opened successfully
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (getline(inputFile, line)) { // Read file line by line
        std::cout << line << std::endl; // Output each line to console
    }

    inputFile.close(); // Close the file
}