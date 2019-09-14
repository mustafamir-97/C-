/*
Name: MUSTAFA HAFEEZ MIR
Class: MAE 2360-003
Assignment: Lab 5 Question 1
*/

#include <stdio.h>                      // standard headerfile included for c
#include <stdlib.h>
#include <iostream>                     // standard headerfile added for c++
#include <cmath>                        // standard headerfile added for math
#include <time.h>                       // standard headerfile added for time

using namespace std;                    // Standard namespace for clarity and ease of use

struct molecular_dynamics               // Structure declared and named
{                                       // Structure initialization
        double position[3];             // A vector of three elements that are the 3 coordinates for position of a particle in space
        double velocity[3];             // A vector of three elements that are the 3 components for velocity of a particle in x, y, and z axes
        double kinetic_energy;          // A scalar value of Kinetic Energy of the particle
        double potential_energy;        // A scalar value of Potential Energy of the particle relative to all other particles in space.
};

int main()                              // Main function starts here
{
        srand(time(NULL));              // Rand() seeded with time from Jan 1, 1970

        int N, A, B, C;                 // N is number of particles. A, B, and C are constants from question statement
        A = 5;
        B = 10;
        C = 100;
        int mass_of_particle = 1;               // Mass of each particle was assumed to be 1.

        int lowest = -100;                      // Lowest value for a position coordinate for a particle if it is in (100x100x100) cube placed at origin
        int highest = 100;                      // Highest value for a position coordinate for a particle if it is in (100x100x100) cube placed at origin
        double range = (highest - lowest) + 1;  // Range of values for position coordinate for a particle within -100 and 100
        double p[3];                            // An array containing the three positon coordinates
        double v[3];                            // An array containing the three velocity components for a particle

        double low_v = -sqrt(200);              // Lowest value a velocity component can take if the magnitude of velocity needs to remain above than or equal to -200
        double high_v = sqrt(200);              // Highest value a velocity component can take if the magnitude of velocity needs to remain less than or equal to 200
        double v_range = (high_v - low_v) + 1;  // Range of values for velocity components between -200 and 200
        double PEnergies = 0;                   // Total Potential Energy is set initially to zero
        double KEnergies = 0;                   // Total Kinetic Energy is set initially to zero

        cout << "Enter the number of particles that you want to be simulated for observation: ";                // User prompted to enter number of particles
        cin >>  N;

        molecular_dynamics a_particle[N];               // An array of structures of type molecular_dynamics initialized. Notice the name, to hint for 1 particle

for (int i = 0; i <= N-1; i++)                          // For all particles
{
        double s;                                       // A variable required to initialize the Kinetic energy for each particle as the loop computes kinetic energy.
        p[0] = lowest + (range*(rand())/RAND_MAX);      // Particles' x coordinate calculated
        p[1] = lowest + (range*(rand())/RAND_MAX);      // Particles' y coordinate calculated
        p[2] = lowest + (range*(rand())/RAND_MAX);      // Particles' z coordinate calculated

        a_particle[i].position[0] = p[0];               // Particle actually given the calculated coordinate values
        a_particle[i].position[1] = p[1];               // Syntax needed to access particular structure for each particle
        a_particle[i].position[2] = p[2];

        v[0] = low_v + (v_range*(rand())/RAND_MAX);     // Particles' velocity components calculated for x, y, and z directions
        v[1] = low_v + (v_range*(rand())/RAND_MAX);
        v[2] = low_v + (v_range*(rand())/RAND_MAX);

        a_particle[i].velocity[0] = v[0];               // Particle actually given the calculated velocity components
        a_particle[i].velocity[1] = v[1];
        a_particle[i].velocity[2] = v[2];

        s = (0.5) * (mass_of_particle) * (pow(a_particle[i].velocity[0], 2) + pow(a_particle[i].velocity[1], 2) + pow(a_particle[i].velocity[2], 2)); // Kinetic Energy Calculated
        a_particle[i].kinetic_energy = s;               // Particle structure given the value of calculated Kinetic Energy for official storing
        KEnergies += a_particle[i].kinetic_energy;      // Total kinetic energy incremented by this particular loops' calculated Kinetic Energy
}


for (int o = 0; o < N; o++)
{
        a_particle[o].potential_energy = 0;             // Each structure's 4th element is Potential energy and those are set to zero so that junk is emptied.
}

/*
for (int o = 0; o < N; o++)                             // If user wants to see the potential energies without any computation, they may open this comment
{
        cout << a_particle[o].potential_energy << endl;
}
cout << "\n";
*/

for (int i = 0; i < N; i++)                     // Increments over all particles
{
        double summing_interactions = 0;        // Sums the interactions of one particle with all others in a system
        for (int j = 0; j < N; j++)             // Increments over all particles
        {
                if(j!=i)        // Crucial statement, each particle must not be compared with itself but must be compared with all particles before it and after it
                {               // The following lines only work for all i and j values where i is not equal to j
                double ith, jth, d, phi;
                ith = sqrt(pow(a_particle[i].position[0], 2) + pow(a_particle[i].position[1], 2) + pow(a_particle[i].position[2], 2)); // Computes distance of ith particle from origin and stores it in local variable ith.  
	            jth = sqrt(pow(a_particle[j].position[0], 2) + pow(a_particle[j].position[1], 2) + pow(a_particle[j].position[2], 2)); // Computes distance of jth particle from origin and stores it in local variable jth
                        if (ith < jth)
                        {
                                d = jth - ith;          // All these relational statements are necessary for positive values of d
                        }
                        else if (ith > jth)
                        {
                        d = ith - jth;
                        }
                        else
                        {
                        d = ith - jth;
                        }
                phi = (A/(pow(d, 12))) - (B/(pow(d, 6))) + (C/d);       // Computation for potential energy between particle at i and j structure
//              cout << phi << "\t";                                    // To see number and value of interactions for each particle
                summing_interactions += phi;                            // Sums all these energies at each interaction
                }

        }
        a_particle[i].potential_energy = summing_interactions;          // gives the energy of all interactions for a particular particle to the structue element for P$
//      cout << "\n";                                                   // You may undo this comment when looking at values of interactions

        PEnergies += a_particle[i].potential_energy;            // Each paricles' stored potential energy stored in Total Potential energy variable
}

PEnergies = PEnergies/2;                        // Total potential energy divided by two as that is its true value from question
cout << "\n";


for (int i = 0; i < 3; i++)     // Displays the Position vector, Velocity vector, Kinetic Energy, Potential Energy for first three particles
{
        cout << "Position vector of particle " << i+1 << ": (" << a_particle[i].position[0] << ", " << a_particle[i].position[1] << ", " << a_particle[i].position[2] << ")" << endl;
        cout << "Velocity vector of this particle is (" << a_particle[i].velocity[0] << ", " << a_particle[i].velocity[1] << ", " << a_particle[i].velocity[2] << ")" << endl;
        cout << "Kinetic Energy of particle " << i + 1 << " = " << a_particle[i].kinetic_energy << endl;
        cout << "Potential Energy of particle " << i + 1 << " = " << a_particle[i].potential_energy << endl;
        cout << "\n\n";
}

cout << "The Kinetic energy for this system of particles is: " << KEnergies << endl;            // Displays the Kinetic Energy of entire system of N particles
cout << "The Potential energy for this system of particles is: " << PEnergies << endl;          // Displays the Potential Energy of entire system of N particles

        return 0;
}                       // End of main function

