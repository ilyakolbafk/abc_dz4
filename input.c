//------------------------------------------------------------------------------
// Container.cpp - Container handling functions.
//------------------------------------------------------------------------------

#include "input.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------
// Input Container's data.
void InContainer(void *c, int *len, FILE *file) {
    void *tmp = c;
    while (!feof(file)) {
        if (InMatrix(tmp, file)) {
            tmp = (void *) (((char *) tmp) + matrixSize);
            (*len)++;
        }
    }
    *(double *) ((void *) ((char *) c) + intSize + doubleSize) = Average(c + intSize, ((int *) c));
}

int InMatrix(void *s, FILE *file) {
    int k;
    fscanf(file, "%d", &k);
    if (k == 1) {
        *((int *) s) = COMMON;
        InCommon((void *) (((char *) s) + intSize), file);
        return 1;
    } else if (k == 2) {
        *((int *) s) = DIAGONAL;
        InDiagonal((void *) (((char *) s) + intSize), file);
        return 1;
    } else if (k == 3) {
        *((int *) s) = TRIANGULAR;
        InTriangular((void *) (((char *) s) + intSize), file);
        return 1;
    } else {
        printf("ERROR: Unknown matrix type: %d\n", k);
        return 0;
    }
}

void InCommon(void *f, FILE *file) {
    fscanf(file, "%d", f);
    int *dimension = ((int *) f);
    int c = 2;
    while (c - 1 <= (*dimension) * (*dimension)) {
        fscanf(file, "%lf", (void *) (((char *) f) + c * doubleSize));
        ++c;
    }

}

void InDiagonal(void *f, FILE *file) {
    fscanf(file, "%d", f);
    int *dimension = ((int *) f);
    int c = 2;
    while (c - 1 <= (*dimension)) {
        fscanf(file, "%lf", (void *) (((char *) f) + c * doubleSize));
        ++c;
    }

}

void InTriangular(void *f, FILE *file) {
    fscanf(file, "%d", f);
    int *dimension = ((int *) f);
    int c = 2;
    while (c - 1 <= (*dimension) * ((*dimension) + 1) / 2) {
        fscanf(file, "%lf", (void *) (((char *) f) + c * doubleSize));
        ++c;
    }

}

// Random input to Container.
void InRndContainer(void *c, int *len, int size) {
    void *tmp = c;
    while (*len < size) {
        if (InRndMatrix(tmp)) {
            tmp = (void *) (((char *) tmp) + matrixSize);
            (*len)++;
        }
    }
    *(double *) ((void *) ((char *) c) + intSize + doubleSize) = Average(c + intSize, ((int *) c));
}

int InRndMatrix(void *s) {
    int k = rand() % 3 + 1;
    if (k == 1) {
        *((int *) s) = COMMON;
        InRndCommon((void *) (((char *) s) + intSize));
        return 1;
    } else if (k == 2) {
        *((int *) s) = DIAGONAL;
        InRndDiagonal((void *) (((char *) s) + intSize));
        return 1;
    } else if (k == 3) {
        *((int *) s) = TRIANGULAR;
        InRndTriangular((void *) (((char *) s) + intSize));
        return 1;
    } else {
        return 0;
    }
}

void InRndCommon(void *f) {
    int dimension = rand() % 20 + 1;
    *(double *) (f) = dimension;
    int c = 2;
    while (c - 1 <= dimension * dimension) {
        *(double *) ((void *) (((char *) f) + c * doubleSize)) = (rand() % 200001 - 100000) / 1000.0;
        ++c;
    }
}

void InRndDiagonal(void *f) {
    int dimension = rand() % 20 + 1;
    *(double *) (f) = dimension;
    int c = 2;
    while (c - 1 <= dimension) {
        *(double *) ((void *) (((char *) f) + c * doubleSize)) = (rand() % 200001 - 100000) / 1000.0;
        ++c;
    }
}

void InRndTriangular(void *f) {
    int dimension = rand() % 20 + 1;
    *(double *) (f) = dimension;
    int c = 2;
    while (c - 1 <= dimension * (dimension + 1) / 2) {
        *(double *) ((void *) (((char *) f) + c * doubleSize)) = (rand() % 200001 - 100000) / 1000.0;
        ++c;
    }
}

double Average(void *f, int m) {
    int dimension = ((int *) f);
    int max;
    if (m == COMMON) {
        max = dimension * dimension;
    } else if (m == DIAGONAL) {
        max = dimension;
    } else {
        max = dimension * (dimension + 1) / 2;
    }
    double sum = 0;
    int c = 2;
    while (c - 1 <= max) {
        sum += *(double *) ((void *) (((char *) f) + c * doubleSize));
        ++c;
    }
    return sum / (dimension * dimension);
}


//------------------------------------------------------------------------------
// Shaker sort for container.
//void ShakerSort(Container &c, int size) {
//    bool swapped = true;
//    int start = 0;
//    int end = size - 1;
//    while (swapped) {
//        swapped = false;
//        for (int i = start; i < end; ++i) {
//            if (Average(*c.cont[i]) < Average(*c.cont[i + 1])) {
//                Swap(*c.cont[i], *c.cont[i + 1]);
//                swapped = true;
//            }
//        }
//        if (!swapped)
//            break;
//        swapped = false;
//        --end;
//        for (int i = end - 1; i >= start; --i) {
//            if (Average(*c.cont[i]) < Average(*c.cont[i + 1])) {
//                Swap(*c.cont[i], *c.cont[i + 1]);
//                swapped = true;
//            }
//        }
//        ++start;
//    }
//}