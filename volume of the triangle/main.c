#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    int opt;
    float volume = 0;
    float value1 = 0, value2 = 0, value3 = 0;

    while ((opt = getopt(argc, argv, "r:n:")) != -1) {
        switch (opt) {
            case 'r':
                if (sscanf(optarg, "%f,%f,%f", &value1, &value2, &value3) == 3) {
                    volume = (1.0/6.0) * value1 * value2 * value3;
                }
                break;
            case 'n':
                if (sscanf(optarg, "%f,%f,%f", &value1, &value2, &value3) == 3) {
                    float s = (value1 + value2 + value3) / 2; // semi-perimeter
                    float areaBase = sqrt(s * (s - value1) * (s - value2) * (s - value3));
                    float height = sqrt(2 * areaBase / value1); // Simple approximation
                    volume = (1.0/3.0) * areaBase * height;
                }
                break;
            default:
                fprintf(stderr, "Invalid options\n");
                return EXIT_FAILURE;
        }
    }
    if (argc > 1) {
        printf("The volume is: %.2f\n", volume);
    }
return 0;
}
