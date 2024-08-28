#define SPECIFICATORTYPE "d"

#include <cstdio>
#include <cmath>

#include "customAssert.h"

typedef int matrixType;

struct Matrix {
    size_t sizeX = 0;
    size_t sizeY = 0;

    matrixType *array = NULL;
};

// FUNCTION PROTOTYPES //
int rectangularMatrixInitialize(Matrix *matrix, size_t sizeX, size_t sizeY);
int rectangularMatrixFill(Matrix *matrix);
int rectangularMatrixDestruct(Matrix *matrix);
int printMatrix(const Matrix *matrix);
int rectangularMatrixSum(const Matrix *firstMatrix, const Matrix *secondMatrix, Matrix *thirdMatrix);
int rectangularMatrixTranspose(const Matrix *firstArray, Matrix *firstArrayTransposed);
int ladderMatrixInitialize(Matrix *matrix, size_t ladderMatrixLineNumber);
int ladderMatrixFill(Matrix *matrix);
int ladderMatrixPrint(const Matrix *matrix);
int ladderMatrixDestruct(Matrix *matrix);
int rectangularMatrixMultiply(const Matrix *firstArray, const Matrix *secondArray, Matrix *thirdArray);
// FUNCTION PROTOTYPES //

int rectangularMatrixInitialize(Matrix *matrix, size_t sizeX, size_t sizeY) {
    customAssert(matrix != NULL, 1);

    matrix->sizeX = sizeX;
    matrix->sizeY = sizeY;
    
    matrix->array = (matrixType *)calloc(matrix->sizeX * matrix->sizeY, sizeof(matrixType));

    return 0;
}

int rectangularMatrixFill(Matrix *matrix) {
    customAssert(matrix != NULL, 1);

    for (size_t row = 0; row < matrix->sizeY; row++) {
        for (size_t column = 0; column < matrix->sizeX; column++) {
            scanf("%" SPECIFICATORTYPE, matrix->array + row * matrix->sizeX + column);
        }
    }

    return 0;
}

int rectangularMatrixDestruct(Matrix *matrix) {
    customAssert(matrix != NULL, 1);

    matrix->sizeX = 0;
    matrix->sizeY = 0;

    free(matrix->array);

    return 0;
}

int printMatrix(const Matrix *matrix) {
    customAssert(matrix != NULL, 1);

    for (size_t row = 0; row < matrix->sizeY; row++) {
        for (size_t column = 0; column < matrix->sizeX; column++) {
            printf("%" SPECIFICATORTYPE "\t", *(matrix->array + row * matrix->sizeX + column));
        }
        printf("\n");
    }

    return 0;
}

int rectangularMatrixSum(const Matrix *firstMatrix, const Matrix *secondMatrix, Matrix *thirdMatrix) {
    customAssert(firstMatrix != NULL, 1);
    customAssert(secondMatrix != NULL, 1);
    customAssert(thirdMatrix != NULL, 1);

    for (size_t row = 0; row < thirdMatrix->sizeY; row++) {
        for (size_t column = 0; column < thirdMatrix->sizeX; column++) {
            *(thirdMatrix->array + row * thirdMatrix->sizeX + column) =
            *(firstMatrix->array + row * firstMatrix->sizeX + column) + *(secondMatrix->array + row * secondMatrix->sizeX + column);
        }
    }
    return 0;
}

int rectangularMatrixTranspose(const Matrix *firstArray, Matrix *firstArrayTransposed) {
    customAssert(firstArray != NULL, 1);
    customAssert(firstArrayTransposed != NULL, 1);

    for (size_t row = 0; row < firstArray->sizeY; row++) {
        for (size_t column = 0; column < firstArray->sizeX; column++) {
            *(firstArrayTransposed->array + column * firstArrayTransposed->sizeX + row) = *(firstArray->array + row * firstArray->sizeX + column);
        }
    }

    return 0;
}

int rectangularMatrixMultiply(const Matrix *firstArray, const Matrix *secondArray, Matrix *thirdArray) {
    customAssert(firstArray != NULL, 1);
    customAssert(secondArray != NULL, 1);
    customAssert(thirdArray != NULL, 1);

    customAssert(firstArray->sizeX == secondArray->sizeY, 1);

    matrixType currentSum = 0;

    for (size_t firstArrayRow = 0; firstArrayRow < firstArray->sizeY; firstArrayRow++) {
        for (size_t secondArrayColumn = 0; secondArrayColumn < secondArray->sizeX; secondArrayColumn++) {
            for (size_t secondArrayRow = 0; secondArrayRow < secondArray->sizeY; secondArrayRow++) { 
                currentSum = *(firstArray->array + firstArrayRow * firstArray->sizeX + secondArrayRow) *
                              *(secondArray->array + secondArrayRow * secondArray->sizeX + secondArrayColumn);
                *(thirdArray->array + firstArrayRow * thirdArray->sizeY + secondArrayColumn) += currentSum;   
            }
        }
    }

    return 0;
}

int ladderMatrixInitialize(Matrix *matrix, size_t ladderMatrixLineNumber) {
    customAssert(matrix != NULL, 1);

    matrix->sizeX = ladderMatrixLineNumber;
    matrix->sizeY = ladderMatrixLineNumber;

    matrix->array = (matrixType*)calloc((matrix->sizeX * (matrix->sizeX + 1))/2, sizeof(matrixType));

    return 0; 
}

int ladderMatrixFill(Matrix *matrix) {
    customAssert(matrix != NULL, 1);

    for (size_t shift = 0; shift < (matrix->sizeX * (matrix->sizeX + 1))/2; shift++) {
        scanf("%" SPECIFICATORTYPE, matrix->array + shift);
    }

    return 0;
}

int ladderMatrixPrint(const Matrix *matrix) {
    customAssert(matrix != NULL, 1);

    for (size_t row = 0; row < matrix->sizeY; row++) {
        for (size_t column = 0; column <= row; column++) {
            printf("%" SPECIFICATORTYPE "\t", *(matrix->array + row*(row+1)/2 + column));
        }
        printf("\n");
    }

    return 0;
}

int ladderMatrixDestruct(Matrix *matrix) {
    customAssert(matrix != NULL, 1);

    matrix->sizeX = 0;
    matrix->sizeY = 0;

    free(matrix->array);

    return 0;
}


int main() {

    // INITIALIZE AND PRINT - FIRST TASK //
    size_t sizeX = 0, sizeY = 0;
    
    printf("Input sizeX and sizeY of matrix: ");
    scanf("%lu %lu", &sizeX, &sizeY);

    Matrix array = {};
    rectangularMatrixInitialize(&array, sizeX, sizeY);

    rectangularMatrixFill(&array);

    printMatrix(&array);

    rectangularMatrixDestruct(&array);

    printf("=====================================\n");
    // INITIALIZE AND PRINT - FIRST TASK //

    // SUM OF MATRIX - SECOND TASK //
    sizeX = 0, sizeY = 0;
    printf("Input sizeX and sizeY of first matrix: ");
    scanf("%lu %lu", &sizeX, &sizeY);

    Matrix firstArray = {};
    rectangularMatrixInitialize(&firstArray, sizeX, sizeY);

    rectangularMatrixFill(&firstArray);

    sizeX = 0, sizeY = 0;
    printf("Input sizeX and sizeY of second matrix: ");
    scanf("%lu %lu", &sizeX, &sizeY);

    Matrix secondArray = {};
    rectangularMatrixInitialize(&secondArray, sizeX, sizeY);

    customAssert(firstArray.sizeX == secondArray.sizeX, 1);
    customAssert(firstArray.sizeY == secondArray.sizeY, 1);

    rectangularMatrixFill(&secondArray);

    Matrix thirdArray = {};
    rectangularMatrixInitialize(&thirdArray, sizeX, sizeY);
    
    rectangularMatrixSum(&firstArray, &secondArray, &thirdArray);
    printMatrix(&thirdArray);

    rectangularMatrixDestruct(&firstArray);
    rectangularMatrixDestruct(&secondArray);
    rectangularMatrixDestruct(&thirdArray);

    printf("=====================================\n");
    // SUM OF MATRIX - SECOND TASK // 

    // LADDER OUTPUT (SQUARE MATRIX) - THIRD TASK //

    size_t ladderMatrixLineNumber = 0;
    printf("Input line number in ladder matrix: ");
    scanf("%lu", &ladderMatrixLineNumber);

    Matrix ladderMatrix = {};
    ladderMatrixInitialize(&ladderMatrix, ladderMatrixLineNumber);

    ladderMatrixFill(&ladderMatrix);

    ladderMatrixPrint(&ladderMatrix);
    
    ladderMatrixDestruct(&ladderMatrix);

    printf("=====================================\n");
    // LADDER OUTPUT (SQUARE MATRIX) - THIRD TASK //
    
    // MATRIX TRANSPOSE - FOURTH TASK //
    sizeX = 0, sizeY = 0;
    
    printf("Input sizeX and sizeY of matrix to transpose it: ");
    scanf("%lu %lu", &sizeX, &sizeY);
    Matrix firstMatrixToTranspose = {};

    rectangularMatrixInitialize(&firstMatrixToTranspose, sizeX, sizeY);
    rectangularMatrixFill(&firstMatrixToTranspose);

    Matrix firstMatrixTransposed = {};

    rectangularMatrixInitialize(&firstMatrixTransposed, firstMatrixToTranspose.sizeY, firstMatrixToTranspose.sizeX);

    rectangularMatrixTranspose(&firstMatrixToTranspose, &firstMatrixTransposed);

    printMatrix(&firstMatrixTransposed);
    rectangularMatrixDestruct(&firstMatrixToTranspose);
    rectangularMatrixDestruct(&firstMatrixTransposed);

    printf("=====================================\n");
    // MATRIX TRANSPOSE - FOURTH TASK //

    // MATRIX MULTIPLY - FIFTH TASK //
    size_t firstArraySizeX = 0, firstArraySizeY = 0, secondArraySizeX = 0, secondArraySizeY = 0;

    Matrix firstArrayToMultiply = {};
    printf("Input size of first array to multiply: ");
    scanf("%lu %lu", &firstArraySizeX, &firstArraySizeY);
    rectangularMatrixInitialize(&firstArrayToMultiply, firstArraySizeX, firstArraySizeY);
    rectangularMatrixFill(&firstArrayToMultiply);


    Matrix secondArrayToMultiply = {};
    printf("Input size of second array to multiply: ");
    scanf("%lu %lu", &secondArraySizeX, &secondArraySizeY);
    rectangularMatrixInitialize(&secondArrayToMultiply, secondArraySizeX, secondArraySizeY);
    rectangularMatrixFill(&secondArrayToMultiply);


    Matrix matrixOfMultiply = {};
    rectangularMatrixInitialize(&matrixOfMultiply, firstArraySizeY, secondArraySizeX);

    rectangularMatrixMultiply(&firstArrayToMultiply, &secondArrayToMultiply, &matrixOfMultiply);

    printMatrix(&matrixOfMultiply);

    rectangularMatrixDestruct(&firstArrayToMultiply);
    rectangularMatrixDestruct(&secondArrayToMultiply);
    rectangularMatrixDestruct(&matrixOfMultiply);

    printf("=====================================\n");
    
    return 0;
    // MATRIX MULTIPLY - FIFTH TASK //
}



