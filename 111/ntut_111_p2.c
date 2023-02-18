#include <stdio.h>
#include <string.h>

int f1() {
    int a = 2, b = 1;
    unsigned int c = 1, d = 6;
    printf("%d, %d, %d\n", a&&!b, c<<2, c|d);
    return (a&&!b)+(c<<2)+(c|d);
}

float f2(int num) {
    float t = num/2*num%2+2+1.0/num;
    return t;
}

int f3() {
    enum direction {North, South, East, West};
    enum direction d = South;
    d = (North+East)/2 > d ? East : West;
    return d;
}

int f4(int w[4][3]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (i > 0) {
                w[0][j] = w[0][j] + w[i][j];
            }
        }
    }
    return w[0][2];
}

void f5(int x[5], char *s) {
    for (int i = 0; i < 5; i++) {
        switch (x[i]%2 + x[i]%3)
        {
            case 0:
                strcat(s, "a");
                break;
            case 1:
                strcat(s, "b");
                break;
            case 2:
                strcat(s, "c");
                break;
            case 3:
                strcat(s, "d");
            default:
                strcat(s, "e");
                break;
        }
    }
}

void f6(int a, int *b, int *c) {
    a = 7;
    *b = 5;
    c = &a;
}

int main(int argc, char *argv[]) {
    int w[4][3] = {{4,2,1}, {3,4,2}, {2,3,3}, {1,1,4}};
    int x[5] = {5, 4, 3, 2, 1};
    char s[6] = "";
    int a = 0, b = 1, c = 6;

    printf("problem 2-1: %d\n", f1()); // problem 2-1
    printf("problem 2-2: %3.lf\n", f2(5)); // problem 2-2
    printf("problem 2-3: %d\n", f3()); // problem 2-3
    printf("problem 2-4: %d\n", f4(w)); // problem 2-4

    f5(x, s);
    printf("problem 2-5: %s\n", s); // problem 2-5

    f6(a, &b, &c);
    printf("problem 2-6: %d, %d, %d\n", a, b, c); // problem 2-6
    return 0;
}