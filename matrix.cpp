#include <stdio.h>
#include "errors.h"

#define kill_main(err) if (err != NOTHING) return 0;

using namespace std;

struct sizes {
    int n, m;
};

ERRORS print(int* a, sizes* sz) {
    my_assert(!a, NULLPTR);
    my_assert(!sz, NULLPTR);

    for (int i = 0; i < sz->n; ++i) {
        for (int j = 0; j < sz->m; ++j) {
            printf("%d ", *(a + sz->m * i + j));
        }
        printf("\n");
    }

    return NOTHING;
}

ERRORS sum(int* a, int* b, int* ans, sizes* sz) {
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

ERRORS sub(int* a, int* b, int* ans, sizes* sz) {
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

int main() {
    int a[3][2] = {{1, 2},
                   {3, 4},
                   {5, 6}};
    int b[3][2] = {{1, 2},
                   {3, 4},
                   {5, 6}};
    int c[3][2] = {{0}};

    sizes sz;
    sz.n = 3;
    sz.m = 2;

    kill_main(sum((int*)a, (int*)b, (int*)c, &sz));

    kill_main(print((int*)c, &sz));

    kill_main(sub((int*)a, (int*)b, (int*)c, &sz));

    kill_main(print((int*)c, &sz));
}