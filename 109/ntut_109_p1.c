#include <stdio.h>
#include <string.h>

typedef enum {apple, banana, orange, pineapple, mango} fruit;

int f1(int a, int b) {
    if ((a == b) || (a > b)) {
        return a&b;
    }
    else if ((a != b) && (a < b)) {
        return a^b;
    }
    else {
        return a|b;
    }
}

int f2() {
    int x[] = {1, 2, 3};
    int n, a = 0;
    n = sizeof(x)/sizeof(x[0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a += x[i]*x[j];
        }
    }
    return a;
}

fruit f3() {
    return (banana+pineapple)/2 > orange ? apple : mango;
}

int f4(int m, int n) {
    if (n == 0) {
        return m;
    }
    else {
        return f4(n, m%n);
    }
}

int f5(int num) {
    int sum = 0;
    for (int i = num; i > 1; i--) {
        if (i%2 == 0) {
            continue;
        }
        sum += i;
    }
    return sum;
}

float f6(float x) {
    float y = 10.02;
    do {
        y -= x;
        x--;
    } while (x > 1.0);

    return y;
}

int f7(char* s) {
    int t = 0;
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i])
        {
            case 'a':
                t += 1;
            case 'n':
                t += 2;
                break;
            case 'g':
                t += 3;
                break;
            default:
                t += 1;
                break;
        }
    }
    return t;
}

int main(int argc, char *argv[]) {
    printf("problem 1-1: %d\n", f1(3, 2));
    printf("problem 1-2: %d\n", f2());
    printf("problem 1-3: %d\n", f3());
    printf("problem 1-4: %d\n", f4(18, 24));
    printf("problem 1-5: %d\n", f5(5));
    printf("problem 1-6: %3.lf\n", f6(3.5));
    printf("problem 1-7: %d\n", f7("language"));
    return 0;
}