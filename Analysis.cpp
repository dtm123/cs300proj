#include "Analysis.h"
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <Python.h>
#include <vector>

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

    std::stringstream ss(values_str);
    std::string item;

    int cnt = 64;
    while (std::getline(ss, item, ',')) {
        temp[cnt] = std::stod(item);
        cnt--;
    }

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

};

// double Analysis::pearsonCorrelation(int y[64],double x[64], int size) {
//     if (size != 64) {
//         throw std::invalid_argument("Array size must be 64.");
//     }
//     // Initialize sums
//     double sum_x = 0, sum_y = 0, sum_xx = 0, sum_yy = 0, sum_xy = 0;
//
//     // Calculate the necessary sums
//     for (int i = 0; i < size; ++i) {
//         sum_x += x[i] * 10000;
//         sum_y += y[i];
//         sum_xx += x[i] * x[i]*10000*10000;
//         sum_yy += y[i] * y[i];
//         sum_xy += x[i] * y[i]*10000;
//     }
//
//     // Calculate the Pearson correlation coefficient using the formula
//     double numerator = size * sum_xy - sum_x * sum_y;
//     double denominator = std::sqrt((size * sum_xx - sum_x * sum_x) * (size * sum_yy - sum_y * sum_y));
//
//     if (denominator == 0) {
//         std::cerr << "Denominator is zero, correlation coefficient cannot be computed!" << std::endl;
//         return -1; // Error: division by zero
//     }
//
//     // std::cout << sum_x << " " << sum_y << " " << sum_xx << " " << sum_xy << " " << sum_yy << std::endl;
//     // std::cout << sqrt((size * sum_xx - sum_x * sum_x) * (size * sum_yy - sum_y * sum_y)) << std::endl;
//     std::cout << x[0] << " " << y[0] << std::endl;
//
//     std::cout << "Numerator: " << numerator << " Denominator: " << denominator << std::endl;
//
//     if (denominator == 0) {
//         throw std::runtime_error("Denominator is zero, correlation cannot be determined.");
//
//         // Return the Pearson correlation coefficient
//
//
//     }
//     return numerator / denominator;
// }

//     //size = 64;
//     //ppmCO2 == x[];
//     //temp == y[];
//     double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0;
//     double sum_x2 = 0.0, sum_y2 = 0.0;
//
//     for (int i = 0; i < size; i++) {
//         sum_x += x[i];
//         sum_y += y[i];
//         sum_xy += x[i] * y[i];
//         sum_x2 += x[i] * x[i];
//         sum_y2 += y[i] * y[i];
//
//     }
//     double numerator = size * sum_xy - sum_x * sum_y;
//     double denominator = std::sqrt((size * sum_x2 - sum_x * sum_x) * (size * sum_y2 - sum_y * sum_y));
//
//     std::cout << sum_x << " " << sum_y << " " << sum_x2 << " " << sum_xy << " " << sum_y2 << std::endl;
//     std::cout << sqrt((size * sum_x2 - sum_x * sum_x) * (size * sum_y2 - sum_y * sum_y)) << std::endl;
//     std::cout << x[0] << " " << y[0] << std::endl;
//
//     std::cout << "Numerator: " << numerator << " Denominator: " << denominator << std::endl;
//
//     if (denominator == 0) {
//         throw std::runtime_error("Denominator is zero, correlation cannot be determined.");
//     }
//
//     return numerator / denominator;
// }

void Analysis::calculatePearsonCorrelation() {
    std::vector<double> tempVector;
    std::vector<double> co2Vector;
    int i=0;
    while (tempVector.size() < 64) {
        tempVector.push_back(temp[i]);
        co2Vector.push_back(ppmCO2[i]);
        i++;
    }
    calculatePearsonCorrelation(tempVector, co2Vector);

}


double Analysis::calculatePearsonCorrelation(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size() || x.size() == 0) {
        throw std::invalid_argument("Vectors must be of the same size and non-empty.");
    }

    double sumX = 0, sumY = 0, sumXY = 0;
    double sumX2 = 0, sumY2 = 0;
    int n = x.size();

    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    double numerator = n * sumXY - sumX * sumY;
    double denominator = std::sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY));

    std::cout << x[0] << " " << y[0] << std::endl;
    if (denominator == 0) {
        throw std::runtime_error("Denominator is zero, cannot calculate correlation.");
    }
    std::cout << "Numerator: " << numerator << " Denominator: " << denominator << std::endl;
    coefficient = numerator / denominator;
    std::cout << "Coefficient: " << coefficient << std::endl;
    return coefficient;
}




int Analysis::graph() {
    // Initialize the Python interpreter
    Py_Initialize();

    // Check if Python was initialized successfully
    if (!Py_IsInitialized()) {
        std::cerr << "Python initialization failed!" << std::endl;
        return -1;
    }

    // Import necessary Python modules (matplotlib.pyplot)
    //PyObject* pName = PyUnicode_DecodeFSDefault("matplotlib.pyplot");
    //PyObject* pModule = PyImport_Import(pName);
    //Py_XDECREF(pName);  // Clean up reference to module name

    // NEW CODE Import necessary Python modules (matplotlib.pyplot, numpy)
    PyObject* pNameMatplotlib = PyUnicode_DecodeFSDefault("matplotlib.pyplot");
    PyObject* pModuleMatplotlib = PyImport_Import(pNameMatplotlib);
    Py_XDECREF(pNameMatplotlib);  // Clean up reference to module name

    // NEW CODE
    PyObject* pNameNumpy = PyUnicode_DecodeFSDefault("numpy");
    PyObject* pModuleNumpy = PyImport_Import(pNameNumpy);
    Py_XDECREF(pNameNumpy);

    if (pModuleMatplotlib != NULL && pModuleNumpy != NULL) {
        // Retrieve the 'plot' function from matplotlib.pyplot
        //PyObject* pFuncPlot = PyObject_GetAttrString(pModule, "plot");
        PyObject* pFuncPlot = PyObject_GetAttrString(pModuleMatplotlib, "plot");
        PyObject* pFuncShow = PyObject_GetAttrString(pModuleMatplotlib, "show");
        PyObject* pFuncXLabel = PyObject_GetAttrString(pModuleMatplotlib, "xlabel");
        PyObject* pFuncYLabel = PyObject_GetAttrString(pModuleMatplotlib, "ylabel");
        PyObject* pFuncTitle = PyObject_GetAttrString(pModuleMatplotlib, "title");

        if (PyCallable_Check(pFuncPlot)) {
            // Prepare data for plotting (e.g., x and y values)
            std::vector<double> x;
            std::vector<double> y;
            for (int i = 0; i < 64; i++) {
                y.insert (y.begin(),temp[i]);
                x.insert (x.begin(),ppmCO2[i]);
            }




            // Create Python lists from C++ vectors
            PyObject* pX = PyList_New(x.size());
            PyObject* pY = PyList_New(y.size());
            for (size_t i = 0; i < x.size(); ++i) {
                PyList_SetItem(pX, i, PyFloat_FromDouble(x[i]));
                PyList_SetItem(pY, i, PyFloat_FromDouble(y[i]));
            }

            // Pack the arguments into a tuple
            //PyObject* pArgs = PyTuple_Pack(2, pX, pY);
            PyObject* pArgsPlot = PyTuple_Pack(2, pX, pY);

            // Call the plot function
            //PyObject* pValue = PyObject_CallObject(pFuncPlot, pArgs);
            PyObject* pValuePlot = PyObject_CallObject(pFuncPlot, pArgsPlot);


            // Clean up references
            //Py_XDECREF(pArgs);
            //Py_XDECREF(pX);
            //Py_XDECREF(pY);
            //Py_XDECREF(pValue);

            Py_XDECREF(pArgsPlot);
            Py_XDECREF(pValuePlot);

            PyObject* pFuncPolyfit = PyObject_GetAttrString(pModuleNumpy, "polyfit");
            PyObject* pFuncPolyval = PyObject_GetAttrString(pModuleNumpy, "polyval");
            //} else {
            //std::cerr << "Function 'plot' not found!" << std::endl;
            // Fit a linear trendline (degree 1)
            if (pFuncPolyfit && pFuncPolyval) {
                PyObject* pArgsPolyfit = PyTuple_Pack(3, pX, pY, PyLong_FromLong(1));
                PyObject* pValuePolyfit = PyObject_CallObject(pFuncPolyfit, pArgsPolyfit);
                Py_XDECREF(pArgsPolyfit);

                if (pValuePolyfit) {
                    // Evaluate the trendline values (y-values for the fitted model)
                    PyObject* pArgsPolyval = PyTuple_Pack(2, pValuePolyfit, pX);
                    PyObject* pValuePolyval = PyObject_CallObject(pFuncPolyval, pArgsPolyval);
                }

                // Show the plot
                //PyObject* pFuncShow = PyObject_GetAttrString(pModule, "show");
                //if (PyCallable_Check(pFuncShow)) {
                //PyObject_CallObject(pFuncShow, NULL);
                //}

                // Evaluate the trendline values (y-values for the fitted model)
                PyObject* pArgsPolyval = PyTuple_Pack(2, pValuePolyfit, pX);
                PyObject* pValuePolyval = PyObject_CallObject(pFuncPolyval, pArgsPolyval);

                // Plot the trendline (using the x-values and the fitted y-values)
                PyObject* pArgsTrendline = PyTuple_Pack(2, pX, pValuePolyval);
                PyObject* pValueTrendline = PyObject_CallObject(pFuncPlot, pArgsTrendline);
                Py_XDECREF(pArgsPolyfit);
                Py_XDECREF(pValuePolyfit);
                Py_XDECREF(pArgsPolyval);
                Py_XDECREF(pValuePolyval);
                Py_XDECREF(pArgsTrendline);
                Py_XDECREF(pValueTrendline);

                // Clean up
                //Py_XDECREF(pFuncShow);
                //Py_XDECREF(pFuncPlot);
                //Py_XDECREF(pModule);

                // Add labels to the axes
                if (pFuncXLabel && pFuncYLabel) {
                    // Set the x and y axis labels
                    PyObject* pXLabel = PyUnicode_FromString("CO2 Concentration (ppm)");
                    PyObject* pYLabel = PyUnicode_FromString("Temperature (°C)");

                    // Call xlabel and ylabel functions
                    PyObject_CallFunctionObjArgs(pFuncXLabel, pXLabel, NULL);
                    PyObject_CallFunctionObjArgs(pFuncYLabel, pYLabel, NULL);

                    // Clean up references to the labels
                    Py_XDECREF(pXLabel);
                    Py_XDECREF(pYLabel);
                }

                // Add a title to the plot
                if (pFuncTitle) {
                    // Set the title for the plot
                    std::string title="Temperature Affected by CO2 \n Coefficient: " + std::to_string(coefficient);
                    PyObject* pTitle = PyUnicode_FromString(title.c_str());
                    PyObject_CallFunctionObjArgs(pFuncTitle, pTitle, NULL);
                    Py_XDECREF(pTitle);
                }


                // Show the plot
                if (PyCallable_Check(pFuncShow)) {
                    PyObject_CallObject(pFuncShow, NULL);
                }

                // Clean up references
                Py_XDECREF(pFuncShow);
                Py_XDECREF(pFuncPlot);
                Py_XDECREF(pFuncPolyfit);
                Py_XDECREF(pFuncPolyval);
                Py_XDECREF(pModuleMatplotlib);
                Py_XDECREF(pModuleNumpy);
            } else {
                std::cerr << "Failed to load matplotlib.pyplot!" << std::endl;
            }

            // Finalize the Python interpreter
            Py_Finalize();
            return 0;
        }
    }
    return 0;
}

int Analysis::saveAnalysis(const std::string& filename) {

    // std::vector<double> x;
    // std::vector<double> y;
    // for (int i = 0; i < 64; i++) {
    //     y.insert (y.begin(),temp[i]);
    //     x.insert (x.begin(),ppmCO2[i]);
    // }


    std::ofstream outputFile(filename);

    if (!outputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Write the header row to the CSV
    outputFile << "CO2 Concentration (ppm), Temperature (°C)" << std::endl;
    std::cout << ppmCO2[0] << std::endl;

    // Write the data rows (pair each x and y)
    for (int i = 0; i < 64; ++i) {
        outputFile << ppmCO2[i] << "," << temp[i] << std::endl;

    }

    // Close the file
    outputFile.close();

    std::cout << "Data has been written to saveAnalysisFile.csv" << std::endl;
    return 0;

};

int Analysis::loadAnalysis(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }

    int cnt = 0;


    std::string line;
    std::getline(infile, line);
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::string first, second;

        std::getline(ss, first, ',');
        std::getline(ss, second, ',');
        ppmCO2[cnt] = std::stoi(first);
        temp[cnt] = std::stod(second);
        cnt++;
    }
    std::cout << temp[0] <<std::endl;
    return 0;
}