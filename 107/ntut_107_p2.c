#include <stdio.h>
#include <string.h>

float test01() {
    int a = 5;
    int b = 2;
    return a/b;
}

int test02() {
    enum {SPRING, SUMMER, FALL=5, WINTER} Season;
    int season = SPRING + SUMMER + FALL + WINTER;
    return season;
}

int test03() {
    int n = 1;
    for (;;) {
        n *= 5;
        if (n > 55) {
            break;
        }
    }
    return n;
}

int test04() {
    struct
    {
        char str1[10], str2[10];
    } s;
    strcpy(s.str1, "yahoo");
    strcpy(s.str2, "google");
    strcat(s.str1, strcat(s.str2, "adobe"));
    return strcmp(s.str1, s.str2);
}

int test05() {
    int a[] = {10, 20, 30, 40, 50};
    int *p = &a[sizeof(a)/sizeof(int)-1];
    int *q = a;
    return (p-q);
}

int test06() {
    int n = 12345;
    int digits = 0;

    do {
        n /= 10;
        digits++;
    } while (n > 0);

    return digits;
}

int test07() {
    int grade = 3;
    int ans;
    switch (grade)
    {
        case 4:
            ans = 4;
        case 3:
            ans = 3;
        case 2:
            ans = 2;
        case 1:
            ans = 1;
        default:
            ans = 0;
    }
    return ans;
}

int test08() {
    int n = 0, sum = 0;
    while (n < 5) {
        n++;
        if (n < 3) continue;
        sum += n;
    }
    return sum;
}

unsigned char test09() {
    unsigned char a[] = {0xFF, 0x00, 0x01, 0x08};
    a[0] &= 1;
    a[1] |= 1;
    a[2] <<= 3;
    a[3] >>= 3;
    return (a[0] + a[1] + a[2] + a[3]);
}

int test10() {
    int a[][3] = {{6, 7, 8}, {9, 10, 11}, {12, 13, 14}};
    return *&a[1][1];
}

int main() {
    printf("Hello NUTU\n");

    printf("Problem2-1: %3.lf\n", test01());
    printf("Problem2-2: %d\n", test02());
    printf("Problem2-3: %d\n", test03());
    printf("Problem2-4: %d\n", test04());
    printf("Problem2-5: %d\n", test05());
    printf("Problem2-6: %d\n", test06());
    printf("Problem2-7: %d\n", test07());
    printf("Problem2-8: %d\n", test08());
    printf("Problem2-9: %d\n", test09());
    printf("Problem2-10: %d\n", test10());

    return 0;
}