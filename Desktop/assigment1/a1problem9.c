#include <stdio.h>

// Model parameters
double alpha = 0.1;   // prey growth rate
double beta = 0.02;   // predation rate
double delta = 0.01;  // predator growth rate
double gamma = 0.1;   // predator death rate

double x = 40;  // initial prey population
double y = 9;   // initial predator population

double dt = 0.01;   // time step
int N = 1000;       // number of steps

int main() {
    for (int i = 0; i < N; i++) {
        // Compute rate of change
        double dx = (alpha * x - beta * x * y) * dt;
        double dy = (delta * x * y - gamma * y) * dt;

        // Update populations
        x += dx;
        y += dy;

        // Print time, prey, and predator counts
        printf("Time: %.2f, Prey: %.3f, Predators: %.3f\n", i * dt, x, y);
    }

    return 0;
}