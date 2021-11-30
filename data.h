#ifndef ABC_DZ4_DATA_H
#define ABC_DZ4_DATA_H

// Константа, определяющая размер целого числа
int const intSize = sizeof(int);
// Константа, определяющая размер символа
int const charSize = sizeof(char);
// Константа, определяющая размер булевого числа
int const boolSize = sizeof(int);
// Константа, определяющая размер числа с плавающей точкой
int const doubleSize = sizeof(double);

int const matrixSize = doubleSize * 500;
// Константа, задающая признак обычной матрицы
int const COMMON = 1;
// Константа, задающая признак диагональной матрицы
int const DIAGONAL = 2;
// Константа, задающая признак верхнетреугольной матрицы
int const TRIANGULAR = 3;
#endif //ABC_DZ4_DATA_H
