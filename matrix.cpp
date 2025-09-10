#include <stdio.h>
#include "errors.h"

#define kill_main(err) if (err != NOTHING) return 0;

using namespace std;

ERRORS print(int* a, int n, int m) {
    my_assert(!a, NULLPTR);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", *(a + m * i + j));
        }
        printf("\n");
    }

    return NOTHING;
}

ERRORS sum(int* a, int* b, int* ans, int n, int m) {
    my_assert(!a, NULLPTR);
    my_assert(!b, NULLPTR);
    my_assert(!ans, NULLPTR);

    int* start = ans;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            *ans++ = *(a + m * i + j) + *(b + m * i + j);
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

    ERRORS err = sum((int*)a, (int*)b, (int*)c, 3, 2); 
    
    kill_main(err);

    err = print((int*)c, 3, 2);

    kill_main(err);
}