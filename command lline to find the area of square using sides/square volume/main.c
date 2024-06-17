#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int opt;
    float volume = 0;
    float side = 0, diagonal = 0, perimeter = 0;
    while ((opt = getopt(argc, argv, "s:d:p:")) != -1) {
        switch (opt) {
            case 's':
                side = atof(optarg);
                volume = pow(side, 3);
                break;
            case 'd':
                diagonal = atof(optarg);
                volume = (1.0/3.0) * pow(diagonal, 3);
                break;
            case 'p':
                perimeter = atof(optarg);
                volume = (1.0/6.0) * pow(perimeter, 3);
                break;
            default:
                fprintf(stderr, "Invalid options\n");
                return EXIT_FAILURE;
        }
    }
if (argc > 1) {
        printf("The volume of the cube: %.2f\n", volume);
    } else {
        fprintf(stderr, "Please provide necessary inputs.\n");
        return EXIT_FAILURE;
    }
return 0;
}
