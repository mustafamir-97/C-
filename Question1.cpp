#include <stdio.h>                      //added C headerfile
#include <iostream>                     //added C++ headerfile
#include <iomanip>                      //added input/output manipulation headerfile
#include <cmath>                        //added cmath headerfile

using namespace std;                    //this is used for clarity and ease of use

double dydt(double y, double t);                //derivative calculating function

int main()                                      //main function starts
{
        cout.precision(6);                      //Output precision changed to show up to six decimal places
        cout.setf(ios::fixed);

        cout << "--------------------------Euler Method---------------------------\n";
        double y, y0, t, h;                             //a variable y created to store yn+1, y0 is the intial value of y at t = 0., h is initialized as 0.1
        h = 0.1; t = 0; y0 = 1;

        cout << "Time" << setw(20) << setw(20) << "yn+1\n";             //Output header
        do
        {
                y = y0 + (h*dydt(y0, t));
                cout << t << setw(20) << y << endl;                     //Eulers Method

                y0 = y;
                t += h;
        } while (t < 10);

        printf("The approximate value of y at t = %0.0f is %0.0f.\n\n", t, y);          //Output shown

        cout << "--------------------------RK4 Method---------------------------\n";

        double y_new, t_knot, y_knot, k1, k2, k3, k4;                                   //y_new is created to store yn+1, t_knot is initial time; y_knot is
        //using the same step size variable from previous Euler method, i.e. h          //initial starting y. k1, k2, k3, k4 are the RK variables that get
        t_knot = 0;                                                                     //calculated in order to solve the ODE
        y_knot = 1.0;

        cout << "Time" << setw(20) << "yn+1\n";                                         //Output header

        double n = (10.0 - 0.0)/h;                                                      //number of iterations found using step size and time interval.

        for (int i = 0; i <= n; i++)
        {
                k1 = dydt(y_knot, t_knot);
                k2 = dydt((y_knot+(h/2.0)*k1), (t_knot+(h/2.0)));
                k3 = dydt((y_knot+(h/2.0)*k2), (t_knot+(h/2.0)));                       //The actual RK coefficients and method applied here
                k4 = dydt((y_knot+(h/2.0)*k3), (t_knot+(h/2.0)));
                y_new = y_knot + (h/6.0)*(k1 + 2.0*k2 + 2*k3 + k4);

                cout << t_knot << setw(20) << y_new << endl;

                t_knot += h;
        }

        printf("The approximate value of y at t = %0.0f is %0.4f.\n\n", t_knot, y_new);                 //Final output

        return 0;
}

double dydt(double y, double t)
{
        double a = -1.0*(1.0/3.0)*y*pow(t, 2);                                          //derivative function which returns the computed derivative value at t.
        return a;
}

