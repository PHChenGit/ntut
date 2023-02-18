#include <stdio.h>
#include <string.h>

int f1(int a, int b) {
    // printf("!b: %d, a||!b: %d, ~a: %d, ~a&b: %d\n", !b, a||!b, ~a, ~a&b);
    return (a||!b) + (~a&b);
}

float f2(int num) {
    float t = (float) num/2 + num % 2 + 1.0/num;
    return t;
}

int f3() {
    enum FOOD {fish = -1, eggs, meat = 3, milk, bean};
    return (eggs+milk)/2 > meat ? fish : bean;
}

int f4(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i < 3) {
            continue;
        }
        sum += i;
    }
    return sum;
}

int f5(char* s) {
    int i = 0, t = 0;
    while (s[i] != '\0') {
        switch (s[i])
        {
            case 's':
                t += 1;
                break;
            case 'c':
                t += 2;
                break;
            case 'e':
                t += 3;
            default:
                t += 1;
                break;
        }
        i++;
    }
    return t;
}

int f6(int x[3], int y[3][3]) {
    int t = 0, n = 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t += x[i]*y[i][j];
        }
    }
    return t;
}

char* f7(char s1[], char s2[]) {
    char s[20] = "";
    strncat(s, s1, 4);
    strcat(s, s2);
    strncpy(s1, s, 10);
    return s1;
}

int main()
{
    int a[3][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    int b[3] = {1, 2, 2};
    char s1[] = "Hello";
    char s2[] = "World!";

    printf("problem 3-1: %d\n", f1(1, 2)); // problem 3-1
    printf("problem 3-2: %3.lf\n", f2(5)); // problem 3-2
    printf("problem 3-3: %d\n", f3()); // problem 3-3
    printf("problem 3-4: %d\n", f4(5)); // problem 3-4
    printf("problem 3-5: %d\n", f5("science")); // problem 3-5
    printf("problem 3-6: %d\n", f6(b, a)); // problem 3-6
    printf("problem 3-7: %s\n", f7(s1, s2)); // problem 3-7
    return 0;
}