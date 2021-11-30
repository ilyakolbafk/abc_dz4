#include <stdio.h>
#include "data.h"
#include "output.h"

void OutContainer(void *c, int len, FILE *file) {
    void *tmp = c;
    fprintf(file, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i);
        OutMatrix(tmp, file);
        tmp = (void *) (((char *) tmp) + matrixSize);
    }
}

void OutMatrix(void *s, FILE *file) {
    int k = *((int *) s);
    if (k == COMMON) {
        fprintf(file, "%s%d%s%.2f", "It is Common matrix: dimension = ", (((char *) s) + intSize), ". Average = ",
                (((char *) s) + intSize + doubleSize));
    } else if (k == DIAGONAL) {
        fprintf(file, "%s%d%s%.2f", "It is Diagonal matrix: dimension = ", (((char *) s) + intSize), ". Average = ",
                (((char *) s) + intSize + doubleSize));
    } else if (k == TRIANGULAR) {
        fprintf(file, "%s%d%s%.2f", "It is Triangular matrix: dimension = ", (((char *) s) + intSize), ". Average = ",
                (((char *) s) + intSize + doubleSize));
    } else {
        fprintf(file, "Incorrect matrix!\n");
    }

}