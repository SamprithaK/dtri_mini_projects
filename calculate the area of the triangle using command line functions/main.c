#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    float area = 0;
    float value1 = 0, value2 = 0, value3 = 0;

    while ((opt = getopt(argc, argv, "r:n:")) != -1) {
        switch (opt) {
            case 'r':
                if (sscanf(optarg, "%f,%f", &value1, &value2) == 2) {
                    area = 0.5 * value1 * value2;
                } else {
                    fprintf(stderr, "Invalid format for right-angled triangle. Use base,height\n");
                    return EXIT_FAILURE;
                }
                break;
            case 'n':
                if (sscanf(optarg, "%f,%f,%f", &value1, &value2, &value3) == 3) {
                    // Heron's formula calculation directly in the case
                    float s = (value1 + value2 + value3) / 2; // semi-perimeter
                    area = sqrt(s * (s - value1) * (s - value2) * (s - value3));
                } else {
                    fprintf(stderr, "Invalid format for non-right-angled triangle. Use side1,side2,side3\n");
                    return EXIT_FAILURE;
                }
                break;
            default:
                fprintf(stderr, "Invalid options\n");
                return EXIT_FAILURE;
        }
    }

    if (argc > 1) {
        printf("The area is: %.2f\n", area);
    }

    return 0;
}
