#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct linkdata {
    struct linkdata *link; // problem 2-1
    char name[10];
    int data[4][4];
} LinkData;

void f1(int d[][4]) {
    int k,c,r;
    int a[][3]={{1,1,1},{2,2,2},{1,1,2}};
    int b[][3]={{1,2,3},{2,3,4},{3,4,5}};

    // Matrix multiplication
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            d[c][r]=0; // problem 2-2
            for ( k = 0; k < 3; k++) {
                d[c][r] += a[c][k]*b[k][r]; // problem 2-3
            }
        }
    }
    printf("%d,%d,%d\n",d[0][0],d[0][1],d[0][2]);
}

void f2(LinkData **topp,char *s) {
    LinkData *x;
    x = (LinkData *)topp; //problem 2-4
    strncpy(x->name,s,10);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            x->data[i][j] = i+j;
    }

    x->link=(*topp); // problem 2-5
    (*topp)=x;
}

int main(){
    char *array[] = {"dog", "lion", "hippo", "giraffe"};
    LinkData a, *top=NULL;

    f1(a.data);
    for(int i = 0; i < 4; i++)
        f2(&top, array[i]);

    printf("%s\n",top->link->name);
    return 0;
}

