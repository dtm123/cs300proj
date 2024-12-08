#include <iostream>
#include "Analysis.h"
#include "Menu.h"
#include <Python.h>
#include <vector>

int main()
{
    std::cout << "Hello, World! --we doing climate analysis now\n";

    Menu menu;
    menu.displayMenu();

    return 0;

    //start the menu



}

/*
#include <Python.h>
#include <iostream>
#include <vector>

int main() {
    // Initialize the Python interpreter
    Py_Initialize();

    // Check if Python was initialized successfully
    if (!Py_IsInitialized()) {
        std::cerr << "Python initialization failed!" << std::endl;
        return -1;
    }

    // Import necessary Python modules (matplotlib.pyplot)
    PyObject* pName = PyUnicode_DecodeFSDefault("matplotlib.pyplot");
    PyObject* pModule = PyImport_Import(pName);
    Py_XDECREF(pName);  // Clean up reference to module name

    if (pModule != NULL) {
        // Retrieve the 'plot' function from matplotlib.pyplot
        PyObject* pFuncPlot = PyObject_GetAttrString(pModule, "plot");
        if (PyCallable_Check(pFuncPlot)) {
            // Prepare data for plotting (e.g., x and y values)
            std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
            std::vector<double> y = {1.0, 4.0, 9.0, 16.0, 25.0};

            // Create Python lists from C++ vectors
            PyObject* pX = PyList_New(x.size());
            PyObject* pY = PyList_New(y.size());
            for (size_t i = 0; i < x.size(); ++i) {
                PyList_SetItem(pX, i, PyFloat_FromDouble(x[i]));
                PyList_SetItem(pY, i, PyFloat_FromDouble(y[i]));
            }

            // Pack the arguments into a tuple
            PyObject* pArgs = PyTuple_Pack(2, pX, pY);

            // Call the plot function
            PyObject* pValue = PyObject_CallObject(pFuncPlot, pArgs);

            // Clean up references
            Py_XDECREF(pArgs);
            Py_XDECREF(pX);
            Py_XDECREF(pY);
            Py_XDECREF(pValue);
        } else {
            std::cerr << "Function 'plot' not found!" << std::endl;
        }

        // Show the plot
        PyObject* pFuncShow = PyObject_GetAttrString(pModule, "show");
        if (PyCallable_Check(pFuncShow)) {
            PyObject_CallObject(pFuncShow, NULL);
        }

        // Clean up
        Py_XDECREF(pFuncShow);
        Py_XDECREF(pFuncPlot);
        Py_XDECREF(pModule);
    } else {
        std::cerr << "Failed to load matplotlib.pyplot!" << std::endl;
    }

    // Finalize the Python interpreter
    Py_Finalize();
    return 0;
}
*/