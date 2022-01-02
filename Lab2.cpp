#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "Lab2.h"

//implement the function initialize
void initialize(double& k, int& n0) {
    //If the values stored in k and n0 are 0 this if statement will run
    if (*(&k) == 0 && *(&n0) == 0) {
        cout << "Initializing Bacteria:" << endl;
        cout << "\tGrowth Factor: (k) [0.0-1.0] : ";
        cin  >> *(&k); //Asks the user to input value for k, and stores it in its original location.
        cout << "\tInitial Population (N0) [1-1000] : ";
        cin  >> *(&n0); //Asks the user to input value for k, and stores it in its original location.
    }
    // If the values of k and n0 are not 0 else statement will run 
    //(this is the case for Part 2 which avoids asking the user to input k and n0)
    else {
        cout << "Initializing Bacteria:" << endl;
        cout << "\tGrowth Factor: (k) [0.0-1.0] : " << *(&k) << endl;
        cout << "\tInitial Population (N0) [1-1000] : " << *(&n0) << endl;
    };        
};

//implement the function calculate
void calculate( const double k, const int n0, double array[]) {
    for (int t = 0; t < 11; t++) {
        array[t] = n0*exp(t*k); // the equation calculates N(t) based on the arguments k and n0, and stores the values in "array"
    };
};

//implement the function display
// displays the results from "array" in a table format
void display(const double array[]) {
    cout << "\tGrowth Summary:"     << endl 
         << "\tHour     Population" << endl //Headings of the table
         << "\t====     ==========" << endl;
    // for loop prints time, and the content of "array" in table format under correct headings.
    for (int t = 0; t < 11; t++) {
        cout << "\t" << t << "        " << array[t] << endl; 
    };
};

//implement the function twoDdisplay
//displays the results from "twodimensionArray" in table format
void twoDdisplay(int num, const double arr[][11]) {
    char equalSign = '=';
    
    cout << endl << "\tagar Summary:" << endl 
                                      << endl;
    cout << "\tHour"; // Heading of the table
    
    for (int i = 0; i < num; i++) {
        cout << setw(18) << "Population(" << i << ")"; //Heading of the table
    }
    
    cout << endl;
    cout << "\t=====" << string(num*20, equalSign) << endl;
    
    // for loop prints time, and the content of "twodimensionArray" in table format under correct headings
    for (int i = 0; i < 11; i++) {
        cout << "\t   " << i;
        for (int j = 0; j < num; j++) {
            cout << setw(20) << arr[i][j];
        };
        cout << endl;
    };
};

int main(int argc, char* argv[]) {
    
    double k = 0; //Initialize the value of k to 0
    int n0 = 0; //Initialize the value of n0 to 0
    double array[11]; // 1D Array to store the values from the calculations of N(t) equation.
    
    //Part I
    if (1 == argc) {
        initialize(k, n0);
        cout << endl;
        calculate(k, n0, array);
        display(array);
    }
    //Part III
    else if (2 == argc) {
        int populationNumber = atoi(argv[1]); //stores integer value of argv[1] into populationNumber
        double kvalues[populationNumber]; // 1D array created with size of populationNumber to be used in holding values of k
        int n0values[populationNumber]; // 1D array created with size of populationNumber to be used in holding value of n0
        double twodimensionArray[11][11]; // 2D array created to hold all values from the multiple population calculations
        
        for(int i = 0; i < populationNumber; i++) {
            initialize(k, n0);
            kvalues[i] = k; // holds the k value taken from the user through initialize at element i
            n0values[i] = n0; // / holds the n0 value taken from the user through initialize at element i
            k = 0; n0 = 0; // k and n0 are set to 0, so that the initialize function can be used repeatedly to ask for user input.
            
            calculate(kvalues[i], n0values[i], array); // the 2 arrays kvalues and n0values are used as arguments into 'calculate' to get the calculations for the specific population
            
            //for loop is used to store results in the correct order from the previous calculations.
            for (int j = 0; j < 11; j++) {
                twodimensionArray[j][i] = array[j]; //values stored in 'twodimensionArray'
            };  
        };
        twoDdisplay(populationNumber, twodimensionArray); //twodimensionArray is displayed through the function twoDdisplay
    }
    //Part II
    else if (3 == argc) {  
        k = atof(argv[1]); 
        n0 = atoi(argv[2]);
        initialize(k, n0);
        cout << endl;
        calculate(k, n0, array);
        display(array);   
    }
    else {
        cout << "Number of command-line arguments "
             << "(including the name of the program) "
             << "should be three or less." << endl;
    }
}; //end of main