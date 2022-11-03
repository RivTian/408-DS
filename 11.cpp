#include "ds.h"

int find_mid(int A[], int B[], int len) {
    int i = 0, j = 0;
    while (i + j < len - 1) {
        if (A[i] <= B[j]) i ++;
        else j ++;
    }
    return A[i] <= B[j] ? A[i] : B[j];
}