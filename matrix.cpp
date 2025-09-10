#include <stdio.h>
#include "errors.h"

#define kill_main(err) if (err != NOTHING) return 0;

using namespace std;

struct SIZE {
    int n, m;
};

ERRORS print(int* a, SIZE* sz) {
    my_assert(!a, NULLPTR);
    my_assert(!sz, NULLPTR);

    for (int i = 0; i < sz->n; ++i) {
        for (int j = 0; j < sz->m; ++j) {
            printf("%2d  ", *(a + sz->m * i + j));
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
            *ans++ = *(a + sz->m * i + j) + *(b + sz->m * i + j);
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
            *ans++ = *(a + sz->m * i + j) - *(b + sz->m * i + j);
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

ERRORS change_tr(int* a, int n, int i, int j, int x) {
    my_assert(!a, NULLPTR);
    my_assert((i >= n || j > i), INDEX_ERR);

    int real_index = i * (i + 1) / 2 + j;
    *(a + real_index) = x;

    return NOTHING;
}

int main() {
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

    int p[100] = {0};
    change_tr(p, 5, 4, 4, 10);

    for (int i = 0; i < 6 * 5 / 2; ++i) {
        printf("%d ", p[i]);
    }
}