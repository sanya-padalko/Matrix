#include <stdio.h>
#include "errors.h"

#define kill_main(err) if (err != NOTHING) return 0;

using namespace std;

struct SIZE {
    int n, m;
};

int get(int* a, const SIZE* const sz, int i, int j) {
    return *(a + sz->m * i + j);
}

void add(int* a, const SIZE* const sz, int i, int j, int x) {
    (*(a + sz->m * i + j)) += x;
}

ERRORS print(int* a, SIZE* sz) {
    my_assert(!a, NULLPTR);
    my_assert(!sz, NULLPTR);

    int* start = a;

    for (int i = 0; i < sz->n; ++i) {
        for (int j = 0; j < sz->m; ++j) {
            printf("%2d  ", *start++);
        }
        printf("\n");
    }

    printf("\n");

    return NOTHING;
}

ERRORS sum(int* a, int* b, int* ans, SIZE* sz) {
    my_assert(!a, NULLPTR);
    my_assert(!b, NULLPTR);
    my_assert(!ans, NULLPTR);
    my_assert(!sz, NULLPTR);

    int* start = ans;

    for (int i = 0; i < sz->n; ++i) {
        for (int j = 0; j < sz->m; ++j) {
            *ans++ = get(a, sz, i, j) + get(b, sz, i, j);
        }
    }

    ans = start;

    return NOTHING;
}

ERRORS sub(int* a, int* b, int* ans, SIZE* sz) {
    my_assert(!a, NULLPTR);
    my_assert(!b, NULLPTR);
    my_assert(!ans, NULLPTR);
    my_assert(!sz, NULLPTR);

    int* start = ans;


    for (int i = 0; i < sz->n; ++i) {
        for (int j = 0; j < sz->m; ++j) {
            *ans++ = get(a, sz, i, j); - get(b, sz, i, j);
        }
    }

    ans = start;

    return NOTHING;
}

ERRORS mul(int* a, SIZE* sz, int k) {
    my_assert(!a, NULLPTR);
    my_assert(!sz, NULLPTR);
    
    int* start = a;

    for (int i = 0; i < sz->n; ++i) {
        for (int j = 0; j < sz->m; ++j) {
            int new_a = *a * k;
            *a++ = new_a;
        }
    }

    a = start;

    return NOTHING;
}

ERRORS matrix_mul(int* a, int* b, int* ans, const SIZE* const sz1, const SIZE* const sz2) {
    my_assert(!a, NULLPTR);
    my_assert(!b, NULLPTR);
    my_assert(!sz1, NULLPTR);
    my_assert(!sz2, NULLPTR);
    my_assert(!ans, NULLPTR);

    SIZE sz;
    sz.n = sz1->n;
    sz.m = sz2->m;

    for (int i = 0; i < sz1->n; ++i) {
        int* stb = b;
        for (int j = 0; j < sz2->n; ++j) {
            for (int k = 0; k < sz2->m; ++k) {
                int x = (*a) * (*b++);
                *(ans + sz.m * i + k) += x;
            }
            ++a;
        }
        b = stb;
    }

    return NOTHING;
}

ERRORS change_tr(int* a, int n, int i, int j, int x) {
    my_assert(!a, NULLPTR);
    my_assert((i >= n || j > i), INDEX_ERR);

    int real_index = i * (i + 1) / 2 + j;
    *(a + real_index) = x;

    return NOTHING;
}

int main() { // СДЕЛАТЬ ТРАНСПОНИРОВАНИЕ МАТРИЦЫ !!!!!
    int a[3][2] = {{1, 2},
                   {3, 4},
                   {5, 6}};
    int b[3][2] = {{1, 2},
                   {3, 4},
                   {5, 6}};
    int c[3][2] = {{0}};

    SIZE sz;
    sz.n = 3;
    sz.m = 2;

    /*
    
    kill_main(sum((int*)a, (int*)b, (int*)c, &sz));

    kill_main(print((int*)c, &sz));

    kill_main(sub((int*)a, (int*)b, (int*)c, &sz));

    kill_main(print((int*)c, &sz));

    kill_main(mul((int*)a, &sz, 5));

    kill_main(print((int*)a, &sz));
    
    */

    /*

    int p[100] = {0}; // треугольная матрица на n строк имеет размер n * (n + 1) / 2
    kill_main(change_tr(p, 5, 4, 4, 10));

    for (int i = 0; i < 6 * 5 / 2; ++i) {
        printf("%d ", p[i]);
    }

    */

    int A[2][2] = {{1, 1},
                   {2, 0}};
    SIZE szA;
    szA.n = szA.m = 2;

    int B[2][3] = {{1, 2, 1},
                   {2, 3, 0}};
    SIZE szB;
    szB.n = 2;
    szB.m = 3;

    int C[2][3] = {{0, 0, 0}, {0, 0, 0}};
    kill_main(matrix_mul((int*)A, (int*)B, (int*)C, &szA, &szB));
    print((int*)C, &szB);
}