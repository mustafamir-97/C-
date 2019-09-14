#include <stdio.h>              //added C headerfile
#include <iostream>             //added C++ headerfile
#include <cmath>                //added Cmath headerfile
#include <iomanip>              //added input output manipluation headerfile

using namespace std;            //this is used for clarity and ease of use

double function( double x);                     //this is a function that solves for the equation in the question
double second_derivative( double x);            //this function solves for the second derivative of the equation using the central difference method

int main()                                      //Main function started
{
        int i = 0;                              //increment and accessing variable
        double t[51];                           //this the input range array that contains all 51 data recording points
        for (i; i < 51; i++)
        {
                t[i] = (i*0.1);                 //this range is intitialized here
//              cout << t[i] << endl;           //to check if range is correct
        }

        double h = t[1] - t[0];                 //this finds the gap between consecutive recording points and stores it in h which is a double
//      cout << h << endl;                      //to check value of h

        int j = 0;                              //increment and accessing variable
        double f_x[51];                         //array created of 51 elements that store the value of function at the recording points
        for (j; j < 51; j++)
        {
        f_x[j] = function(t[j]);                //here the fucntion function is used to compute value of function at the particular point and store this value
//      cout << f_x[j] << endl;                 //in the array created for it. To check function values
        }
        cout << endl;

        int k = 1;                              //Incrementing and accessing variable. This is initialized to 1 as 0 is starting value which needs to be excluded
        double f2ndder_x[49];                   //Second derivative value storing array initialized. It has 49 elements
        for (k; k < 50; k++)                    //This is the necessary for loop for central difference method. It goes only up to the 49th data point as the one
        {                                       //after that needs to be excluded
                f2ndder_x[k] = (f_x[k+1]+f_x[k-1]-2*f_x[k])/(pow(h, 2.0));              //The second derivative calcuated using function function and central
//              cout << f2ndder_x[k] << endl;                                           //difference method
        }

        int u = 0;                              //Incrementing and accessing variable
        double analytical[51];                  //Analytical values stored in this new array
        for (u; u < 51; u++)                    //Since analytically the derivative may be found for all data, this is the for loop conditions
        {
                analytical[u] = (-4.0*pow(t[u], 2.0)*sin(pow(t[u], 2.0))) + 3.0*t[u];           //Analytic calculation translated to C code
        }

        int l = 1;                              //This is variable for displaying both analytic and central difference values on screen
        char z[10] = "N/A";                     //A character of 10 that stores the phrase Not Available as N/A
        cout << "Analytical \t\t\t Numerical" << endl;                  // Column headings
        cout << analytical[0] << " \t\t\t\t " << z << endl;             // The first element of analytical array and character z displayed on one line
        for (l; l < 50; l++)
        {                                                               // For loop to display entire central difference array and the analytical array upto second las$
        cout << std::setprecision(8) << analytical[l] <<  " \t\t\t " << f2ndder_x[l] << endl;
        }
        cout << analytical[50] << " \t\t\t " << z << endl;              //Last element of analytical array displayed along with N/A for numerical method
        return 0;                                                       // End of main function
}

double function( double x)                                              // Function that finds the value of equation at a given value of x
{
        return sin(pow(x, 2.0)) + (0.5*(pow(x, 3.0)));
}

