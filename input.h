#ifndef ABC_DZ4_INPUT_H
#define ABC_DZ4_INPUT_H

//------------------------------------------------------------------------------
// Container.h - contains data type that represents simple Container.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Container based on 1-dimension array.

// Input data.
void InContainer(void *s, FILE *file);

int InMatrix(void *s, FILE *file);

void InCommon(void *f, FILE *file);

void InDiagonal(void *f, FILE *file);

void InTriangular(void *f, FILE *file);

// Random input.
void InRndContainer(void *c, int *len, int size);

int InRndMatrix(void *s);

void InRndCommon(void *f);

void InRndDiagonal(void *f);

void InRndTriangular(void *f);
// Shaker sort for container.

#endif //ABC_DZ4_INPUT_H
