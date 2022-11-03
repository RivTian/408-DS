#include "ds.h"
using namespace std;

void reverse(int R[], int l, int r) {
    for (int i = 0; i < (r - l + 1) / 2; i ++)
        swap(R[l + i], R[r - i]);
}

void reverse_all(int R[], int p, int n) {
    reverse(R, 0, p - 1);
    reverse(R, p, n - 1);
    reverse(R, 0, n - 1);
}