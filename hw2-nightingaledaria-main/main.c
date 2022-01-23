#include <stdio.h>

typedef struct {
    int arr[35];
} uint1024_t;

uint1024_t from_uint(unsigned int x) {

    uint1024_t number;

    number.arr[0] = x % 1000000000;
    number.arr[1] = x / 1000000000;

    for (int i = 2; i < 35; i++) {
        number.arr[i] = 0;

    }
    return number;
}

uint1024_t add_op(uint1024_t x, uint1024_t y) {

    uint1024_t sum;
    sum = from_uint(0);
    int res;
    for (int i = 0; i < 34; i++) {
        res = x.arr[i] + y.arr[i];
        sum.arr[i] += res % 1000000000;
        sum.arr[i + 1] += res / 1000000000;

    }
    sum.arr[34] += res % 1000000000;
    return sum;
}

uint1024_t subr_op(uint1024_t x, uint1024_t y) {

    uint1024_t difference;
    difference = from_uint(0);
    int res;
    for (int i = 0; i < 34; i++) {

        res = x.arr[i] - y.arr[i];
        if (res >= 0) {
            difference.arr[i] += res;
        } else {
            difference.arr[i] += 1000000000 + res;
            difference.arr[i + 1] += -1;
        }
    }
    difference.arr[34] += x.arr[34] - y.arr[34];

    return difference;
}

uint1024_t mult_op(uint1024_t x, uint1024_t y) {
    uint1024_t multiplication;

    multiplication = from_uint(0);

    long long res;
    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 35; j++) {
            res = (long long) y.arr[i] * (long long) x.arr[j];
            if (i + j < 35) {
                multiplication.arr[i + j] += (int) (res % 1000000000);
            }
            if (i + j + 1 < 35) {
                multiplication.arr[i + j + 1] += (int) (res / 1000000000);

            }
        }
    }
    return multiplication;
}

void printf_value(uint1024_t x) {

    int flag = 0;
    for (int i = 34; i >= 0; i--) {

        if (flag == 0 && x.arr[i] != 0) {
            flag = 1;
            printf("%d", x.arr[i]);
        } else if (flag == 1) {
            printf("%09d", x.arr[i]);
        }
    }
}


void scanf_value(uint1024_t *x) {
    *x = from_uint(0);
    char c;
    while ((c = getchar()) != '\n') {
        *x = add_op(mult_op(*x, from_uint(10)), from_uint(c - '0'));
    }
}

int main(void) {
    uint1024_t x;
    scanf_value(&x);
    uint1024_t z;
    scanf_value(&z);
    uint1024_t y = from_uint(3);
    printf_value(mult_op(x, z));

}