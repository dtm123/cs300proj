#include "Menu.h"
#include "Analysis.h"
#include <iostream>


void Menu::displayMenu() {

    int choice;
    std::cout << "enter an integeger 1-4 of your chocie of the following\n";
    std::cout << "1. Load data and provide analysis\n";
    std::cout << "2. save analysis\n";
    std::cout << "3. load previous analysis\n";
    std::cout << "4. Exit program\n";
    std::cin >> choice;


    switch (choice) {
        case 1: {
            std::cout << "loading & providing analsyis\n";  //import data - run analysis/visualization
            Analysis analysis;
            //read in the temperature data into a vector --
            analysis.readTempFile("monthly-average-surface-temperatures-by-year.csv");
            //read in the co2 data
            analysis.readCO2File("co2_annmean_mlo.csv");
            //run whatever analysis?  -- display it
            //analysis.pearsonCorrelation();
            analysis.calculatePearsonCorrelation();
            //mat plot lib to display it (or just graph() method)
            analysis.graph();
            displayMenu();
            break;
        }

        case 2: {
            Analysis analysis;
            //read in the temperature data into a vector --
            analysis.readTempFile("monthly-average-surface-temperatures-by-year.csv");
            //read in the co2 data
            analysis.readCO2File("co2_annmean_mlo.csv");
            std::cout << "saving analsyis\n";
            //output our analysis to some sort of save file
            analysis.saveAnalysis("saveAnalysisFile.csv");
            displayMenu();
            break;
        }

        case 3: {
            Analysis analysis;
            std::cout << "loading previous analysis\n";
            analysis.loadAnalysis("saveAnalysisFile.csv");
            //call sometihg to load the prev analysis and display visualization
            analysis.calculatePearsonCorrelation();
            analysis.graph();
            displayMenu();
            break;
        }

        case 4: {
            return;
        }

    }

};
