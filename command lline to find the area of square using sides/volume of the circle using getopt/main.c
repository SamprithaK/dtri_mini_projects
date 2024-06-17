#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int opt;
    float volume = 0;
    float radius = 0, diameter = 0, circumference = 0;

    while ((opt = getopt(argc, argv, "r:d:c:")) != -1) {
        switch (opt) {
            case 'r':
                radius = atof(optarg);
                volume = (4.0 / 3.0) * 3.1415* pow(radius, 3);
                break;
            case 'd':
                diameter = atof(optarg);
                radius = diameter / 2;
                volume = (4.0 / 3.0) * 3.1415* pow(radius, 3);
                break;
            case 'c':
                circumference = atof(optarg);
                radius = circumference / (2 * 3.1415);
                volume = (4.0 / 3.0) * 3.1415 * pow(radius, 3);
                break;
            default:
                fprintf(stderr, "Invalid options\n");
                return EXIT_FAILURE;
        }
    }

    if (volume > 0) {
        printf("The volume of the sphere: %.2f\n", volume);
    } else {
        fprintf(stderr, "Please provide necessary inputs.\n");
        return EXIT_FAILURE;
    }

    return 0;
}
