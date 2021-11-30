//------------------------------------------------------------------------------
// main.c - contains main function for testing functional.
//------------------------------------------------------------------------------

#include <stdlib.h> // For rand().
#include <time.h>   // For time().
#include <string.h>
#include <stdio.h>

#include "data.h"
#include "output.c"
#include "input.c"

void errMessage() {
    printf("incorrect!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    clock_t start = clock(); // Start time.

    if(argc != 5) {
        errMessage();
        return 1;
    }

    printf("Start\n");
    unsigned char cont[15000];
    int len = 0;
    FILE *file;
    if(!strcmp(argv[1], "-f")) {
        file = fopen(argv[2], "r");
        InContainer(cont, &len, file);
        fclose(file);
    }
    else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 15000)) {
            printf("incorrect number of matrices = ");
            return 3;
        }
        // Random data for container.
        InRndContainer(cont, &len, size);
    }
    else {
        errMessage();
        return 2;
    }

    // Output container data.
    FILE* file1 = fopen(argv[3], "w");
    fprintf(file1, "Filled container:\n");
    OutContainer(cont, len, file1);
    fclose(file1);

    // The 2nd part of task
    FILE* file2 = fopen(argv[4], "w");
    SnakeSort(cont, len);
    // OutContainer(cont, len, stdout);
    OutContainer(cont, len, file2);
    fclose(file2);

    clock_t end = clock(); // End time.
    double total_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    printf("%s %lf %s \n", "Total time for program:", total_time, "seconds");
    printf("Stop");
    return 0;
}