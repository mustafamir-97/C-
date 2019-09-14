#include <iostream>                     // C++ headerfile added
#include <stdio.h>                      // C headerfile added
#include <iomanip>                      // Input Output manipulation headerfile added
#include <cmath>                        // Math headerfile added

using namespace std;                    // Standard namespace used for clarity

int main()                              // Main function starts
{
        int N = 100;                    // Variable for max allowable iterations
        double  error = 0.00001;        // Variable for max allowable error. Since MATLAB default dispalyed the roots upto 4 decimal places, chosen error was
                                        // selected to precision of 5 decimal places

        cout.precision(4);              // Sets the precision of output values to screen to 4 decimal places
        cout.setf(ios::fixed);

        cout << "-------------------------Gauss Jordan Method--------------------------\n";             // Header for Gauss Jordan method

        double A[4][5] = { {10, 2, 3, 5, 7}, {1, -11, 1, -1, 1}, {1, 2, 6, 24, 12}, {2, 4, 18, 0, 32} };        // Original matrix initialized
        double x[4];                            // an array of four elements that will contain the four roots

        cout << "The original matrix," << endl;         // Stating that original matrix is displayed next
        for (int i = 0; i < 4; i++)
        {
                for (int j = 0; j < 4; j++)
                {
                cout << A[i][j] << setw(12);            // Procedure to display matrix
                }
                cout << A[i][4] << endl;
        }

        for (int i = 0; i < 4; i++)
        {
                for (int k = i + 1; k < 4; k++)
                {
                        if (abs(A[i][i]) < abs(A[k][i]))
                        {
                                for (int j = 0; j <= 4; j++)            // Process of partial pivotization for each of the four rows so each root
 								{
                                        double temp = A[i][j];
                                        A[i][j] = A[k][j];
                                        A[k][j] = temp;
                                }
                        }
                }
        }
        cout << endl << "The matrix after pivotization,"<< endl;
        for (int i = 0; i < 4; i++)
        {
                for (int j = 0; j < 4; j++)
                {
                cout << A[i][j] << setw(12);                            // Pivotized matrix is displayed
                }
                cout << A[i][4] << endl;
        }
        for (int i = 0; i < 3; i++)
        {
                for (int k = i + 1; k < 4; k++)
                {
                        double factor = A[k][i] / A[i][i];              // Gauss elimination  method applied here
                        for (int j = 0; j < 5; j++)
                        {
                                A[k][j] = A[k][j] - factor*A[i][j];
                        }
                }
        }
        cout << "\n\nAfter Gauss elimination," << endl;
        for (int i = 0; i < 4; i++)
        {
                for (int j = 0; j < 4; j++)
                {
                cout << A[i][j] << setw(12);
                }
                cout << A[i][4] << endl;
        }

        for (int i=3; i>= 0; i--)
        {
        x[i]=A[i][4];
        for (int j = i+1; j < 4; j++)                                   // Gauss Jordan method completed at this step
            if (j != i)
                x[i] = x[i] - A[i][j]*x[j];
        x[i] = x[i]/A[i][i];
        }

        cout << "\n\nThe value of the variables are as follows," << endl;
        cout << "x1 = " << x[0] << endl;
        cout << "x2 = " << x[1] << endl;                                        // Values of roots displayed here
        cout << "x3 = " << x[2] << endl;
        cout << "x4 = " << x[3] << endl;

        cout << "\n\n-------------------------Gauss Seidel Method--------------------------\n";                 // Gauss Seidel method heading

        //We have the same matrix A, however, since that matrix was modified. A new matrix is introduced. I called it B.

        double B[4][5] = { {10, 2, 3, 5, 7}, {1, -11, 1, -1, 1}, {1, 2, 6, 24, 12}, {2, 4, 18, 0, 32} };

        double sub;                     // A substituting variable
        int inc = 0;                    // Number of increments
        int z = 0;                      // a flag variable that helps increment method for each x value
        double guess1[3];               // The array that contains the 4 guess roots of the equation

        cout << "The original matrix," << endl;
        for (int i = 0; i < 4; i++)
        {
                for (int j = 0; j < 4; j++)
                {
                cout << B[i][j] << setw(12);                            // Original matrix displayed
                }
                cout << B[i][4] << endl;
        }
        cout << "\nEnter your four initial guesses for x1, x2, x3, and x4\n";
        cout << "x1 = ";
        cin >> guess1[0];
        cout << "x2 = ";
        cin >> guess1[1];                                               // 4 user defined guess values initialized in guess1 array
        cout << "x3 = ";
        cin >> guess1[2];
        cout << "x4 = ";
        cin >> guess1[3];

        cout << "\nYour guess matrix is [" << guess1[0] << ", " << guess1[1] << ", " << guess1[2] << ", " << guess1[3] << "]\n";        // guess values displayed

        cout << "\nGauss Seidel  condition of diagonal dominance is conducted next." << endl;

        for (int i = 0; i < 4; i++)
        {
                for (int k = i + 1; k < 4; k++)
                {
                        if (abs(B[i][i]) < abs(B[k][i]))
                        {
                                for (int j = 0; j <= 4; j++)
                                {
                                        double temp = B[i][j];                  // Method to make the matrix diagonally dominant
                                        B[i][j] = B[k][j];
                                        B[k][j] = temp;
                                }
                        }
                }
        }
        cout << "\nThe matrix after this operation is,\n";
        for (int i = 0; i < 4; i++)
        {
                for (int j = 0; j < 4; j++)
                {
                cout << B[i][j] << setw(12);                    // Matix showed after the previous operation
                }
                cout << B[i][4] << endl;
        }
        cout << "\n\n number\n   of\niterations" << setw(8) << "x1" << setw(16) << "x2" << setw(18) << "x3" << setw(18) << "x4\n";
        // Heading for output of next operation.

        do
        {
                cout << inc+1 << "." << setw(20);

                for (int i = 0; i < 4; i++)
                {
                        sub = guess1[i];
                        guess1[i] = B[i][4];
                        for (int j = 0; j < 4; j++)
                        {
                                if (j != i)                                             // Gauss Seidel method
                                {
                                        guess1[i] = guess1[i] - B[i][j]*guess1[j];
                                }
                        }
                        guess1[i] = guess1[i]/B[i][i];
                        if (abs(guess1[i] - sub) <= error)
                        {
                                z++;
                        }
                        std::cout << std::setprecision(5) << std::fixed << guess1[i] << setw(17);
                }
                cout << "\n";
                inc++;

        } while(z < 4);

        cout.precision(4);
        cout.setf(ios::fixed);

cout << "\nFinal values of roots are:\nx1 = " << guess1[0] << endl << "x2 = " << guess1[1] << endl << "x3 = " << guess1[2] << endl << "x4 = " << guess1[3] << endl;
cout << "Number of iterations: " << inc << endl;
                                                        // Final root values dispalyed together with number of iterations needed to reach these values
        return 0;
}

