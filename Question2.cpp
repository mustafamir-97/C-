#include <stdio.h>                              //added C headerfile
#include <iostream>                             //added C++ headerfile
#include <iomanip>                              //added input/output manipulation headerfile
#include <cmath>                                //added math headerfile

using namespace std;

double f(double Y, double Z, double time);              //function that calculates first derivative
double g(double Y, double Z, double time);              //function that calculates second derivative

int main()                                              //Main function begins
{
        cout.precision(6);                              //Output decimal places set to 6
        cout.setf(ios::fixed);

        cout << "--------------------------RK4 Method---------------------------\n";
        double k0, l0, k1, l1, k2, l2, k3, l3, dt, y, z, t, steps, y_new, z_new;                //RK4 method coefficients declared, as well as new y, new z and t
        int start, end;                                                                         //y and z
        start = 0; end = 10;                                                                    //starting time and ending time
        dt = 0.1;                                                                               // dt or h initialized as 0.1 as given in question
        y = 1.0;                                                // y is 1 at t=0
        z = 0.0;                                                // z is 0 at t=0
        t = 0.0;                                                // t is 0 initially

        steps = (end - start)/dt;                               // number of steps for RK4 method to increment by computed

        cout << "t" << setw(20) << "y" << setw(22) << "dy/dt" << endl;                  //Output header

        cout << t << setw(20) << y << setw(20) << 0 << endl;                    // First set of values manually displayed as all values were predetermined and RK4
                                                                                // did not need to be applied
        t = 0.1;
        for (int inc = 0; inc <= steps; inc++)
        {
                k0 = dt*f(y, z, t);
                l0 = dt*g(y, z, t);
                k1 = dt*f(y + 0.5*k0, z + 0.5*l0, t + 0.5*dt);
                l1 = dt*g(y + 0.5*k0, z + 0.5*l0, t + 0.5*dt);
                k2 = dt*f(y + 0.5*k1, z + 0.5*l1, t + 0.5*dt);
                l2 = dt*g(y + 0.5*k1, z + 0.5*l1, t + 0.5*dt);
                k3 = dt*f(y + 0.5*k2, z + 0.5*l2, t + dt);                      //RK4 method, coefficients calculated
                l3 = dt*g(y + 0.5*k2, z + 0.5*l2, t + dt);

                y_new = y + ((k0 + 2.0*k1 + 2.0*k2 + k3)/6.0);                  //y_new initialized
                z_new = z + ((l0 + 2.0*l1 + 2.0*l2 + l3)/6.0);                  //z_new initialized
                y = y_new;                                                      //y set to updated y
                z = z_new;                                                      //z set to updated z

                cout << t << setw(20) << y_new << setw(20) << z_new << endl;    //Displayed on screen
                t += dt;                                                        //time incremented
        }

        printf("\nThe approximate value of y and dy/dt at t = %0.0f are %0.4f and %0.4f.\n\n", t, y_new, z_new);        //Final answer printed on screen

        return 0;                                       //Main function ends
}
double f(double Y, double Z, double time)
{
        double dy1dt = Z;                               //Simply returns Z value
        return dy1dt;
}

double g(double Y, double Z, double time)
{
        double dy2dt = 1 - 10*Y - 2*Z;                  //Returns the second derivative value from the original ODE
        return dy2dt;
}

