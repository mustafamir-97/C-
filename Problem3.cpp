#include <stdio.h>                      // added C headerfile
#include <iostream>                     // added C++ headerfile
#include <cmath>                        // added input output manipulation headerfile
#include <iomanip>

using namespace std;                    // For clarity and ease of use

double function( double x );            // This calculates value of function at x

int main()
{
        int N;                          // Number of partitions
        do
        {
        cout << "Enter the number of EVEN partitions to be made:" << endl;
        cin >> N;                                                               // User defined N
        if (N % 2 != 0)
        cout << "You have entered odd number of partitions, enter again." << endl;
        }
        while (N % 2 != 0);                                                     // Will not go forward until N is even


        cout << "\nNumerical integration using the right rectangular rule.\n\n";                // Header for first method
        double h1 = (3.0-1.0)/N;                                                // the difference between each partition determined and intialized to h1
        double x1[N];                                           // array that contains the partitions for the requred range
        double start = 1.0+h1;                                  // This is the right rectangular, so we start from f1, not f0
        for (int i = 0; i < N; i++)
        {
                x1[i] = start;                                  // The array is initialized
                start += h1;
//              cout << x1[i] << endl;                          // for checking values of each partition
        }

        double f_x[N];                                          // array created that stores value using right rectangular method
        double sum1 = 0;                                        // the sum is intialized to 0
        for (int j = 0; j < N; j++)
        {
                f_x[j] = function(x1[j]);                       // the function function is used to find value of y at particular x
                sum1 += f_x[j];                                 // this value is added to sum
//              cout << f_x[j] << endl;                         // if the array elements need to be checked
        }
//      cout << sum1;                                           // if sum needs to be checked
        cout << "The value from this computation was:\n";
        cout << std::setprecision(8) << sum1*h1 << endl;        // The value from this computation is stated

        cout << "\nNumerical Integration using the trapezoidal rule. \n\n";             // header for second method

        double x2[N];                                           //partition array
        double initial = 1.0;
        for (int k = 0; k <= N; k++)
        {
                x2[k] = initial;
                initial += h1;                                  //partitions made again
//              cout << x2[k] << endl;
        }

        double ft_x[N];                                 //array containing function evaluated values
        ft_x[0] = function(x2[0]);                      // however first and last elements intitialized manually as they needed to be summed differently
//      cout << ft_x[0] << endl << endl;
        ft_x[N] = function(x2[N]);
//      cout << ft_x[N] << endl << endl;
        double sum21 = (h1/2)*(ft_x[0] + ft_x[N]);              // sum of first and last elements
        double sum22 = 0;                                       // sum of rest of elements

        for (int l = 1; l < N; l++)
        {
        ft_x[l] = function(x2[l]);                              // function values evaluated again here
        sum22 += ft_x[l];                                       // each value added to sum22
//      cout << ft_x[l] << endl;
        }

        cout << "The value from this computation was:\n";
        cout << std::setprecision(8) << sum21 + (h1*sum22) << endl;     // the value displayed using trapezoidal method

        cout << "\nNumerical Integration using the Simpson's rule. \n\n";               // Header for Simpson's rule

        double h2 = (3.0-1.0)/(2.0*N);                          // the difference between each partition is different here as N increases to 2*N

        double x3[2*N];                                         // Partition array has 2*N elements
        double beginning = 1.0;
        for (int m = 0; m <= 2*N; m++)
        {
                x3[m] = beginning;                              // Partition array iniitalized to go from 1 to 3
                beginning += h2;
//              cout << x3[m] << endl;
        }

        double ds_x[2*N];                                       // function array declared
        for (int n = 0; n <= 2*N; n++)
        {
                ds_x[n] = function(x3[n]);                      // function array initialized using function function
//              cout << ds_x[n] << endl;
        }
//      cout << "\n";

        double firstandlast_sum = ds_x[0] + ds_x[2*N];          // first and last function values summed and stored in new variable
//      cout << firstandlast_sum << endl << endl;

double odd[2*N/2];                                              // Odd array created that only has odd partition function values
        double Oddsum = 0;                                      // the sum of odd partition function values declared
        for (int o = 1; o <= (2*N - 1); o += 2)
        {
                odd[o] = ds_x[o];
                Oddsum += odd[o];                               // the function values are added and stored in Oddsum
//              cout << ds_x[o] << endl;
        }
//      cout << Oddsum << endl;

        double even[(2*N)-1];                                   // even array created that has only even partition function values
        double Evensum = 0;                                     // the sum of even partition function values declared
        for (int p = 2; p <= (2*N - 2); p += 2)
        {
                even[p] = ds_x[p];
                Evensum += even[p];                             // the function values are added and stored in Evensum
//              cout << ds_x[p] << endl;
        }
//      cout << Evensum << endl;

        double final = (h2/3.0)*(firstandlast_sum) + ((4.0*h2)/3.0)*(Oddsum)+ ((2.0*h2)/3.0)*(Evensum);         // All values are added according to Simpsons rule
        cout << "The value from this computation was:\n";
        cout << std::setprecision(8) << final << endl << endl;          // Result is displayed

        return 0;
}

double function( double x )                             // Function that finds value of y at a particular value of x
{
        double g = -1.0*pow(x, 2.0) + 4.0*x - 3.0;
        if (g < 0) g = 0;
        return pow(g, 0.5);
}

