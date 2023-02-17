#include <stdio.h>
#include <string.h>

typedef enum {dog, cat, lion=4, tiger, monkey, hippo, giraffe} animal;

void f1(int a, int b) {
    printf("%d\n", !a);
    printf("problem 1-1: %d\n", !a&&b); // problem 1-1
    printf("%d\n", ~a);
    printf("problem 1-2: %d\n", ~a&b); // problem 1-2
}

// void f2() {
//     animal a = cat + hippo;
//     printf("problem 1-3 %d\n", a); // problem 1-3
// }

void f3(int num) {
    int k;
    k = (num > 1 ? (num <= 10 ? 100 : 200) : 300);
    printf("problem 1-4 %d\n", k); // problem 1-4 
}

void f4(int num) {
    float f = 1.0;
    for (int i = 1; i <= num; i++) {
        f *= i;
    }
    printf("problem 1-5: %.2f\n", f); // problem 1-5
}

void f5(char *s1, char *s2) {
    char str1[80] = "";
    char str2[] = "a";
    int i = 0;
    while (*(s1+i) <= *(s2+i) && strlen(str1) < 80) {
        i++;
        strncat(str1, str2, 1);
    }
    printf("problem 1-6: %s\n", str1); // problem 1-6
}

void f6(int x[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        switch ((animal) x[i] + 3)
        {
            case dog:
                sum += 3;
                break;
            case cat:
                sum += 3;
                break;
            case lion:
                sum += 4;
            case tiger:
                sum += 4;
                break;
            default:
                sum += 1;
                break;
        }
    }
    printf("problem 1-7: %d\n", sum); // problem 1-7
}

void f7(int a[], int p1, int *p2) {
    a[0] = 5;
    p1 = *p2+1;
    *p2 = 1;
}

int f8(int n) {
    if (n < 2) {
        return n;
    }
    return f8(n-1)+f8(n-2);
}

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3, 4};
    char s[2][12] = {"problem", "programmer"};

    f1(16, 8);
    // f2();
    f3(5);
    f4(5);
    f5(s[0], s[1]);
    f6(a, 4);
    f7(a, a[1], &a[2]);
    printf("problem 1-8: %d\n", a[0]); // problem 1-8
    printf("problem 1-9: %d\n", a[1]); // problem 1-9
    printf("problem 1-10: %d\n", f8(6)); // problem 1-10
}