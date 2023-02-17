#include <iostream>

using namespace std;

class Number {
    private:
        int a;
    public:
        Number(): a(7) {}
        int getA() {
            return a;
        }
        int get() {
            return a;
        }
        int* getAaddress() {
            return &a;
        }
        void setA(int v) {
            a = v;
        }
};

class Complex: public Number {
    private:
        int *b;
    public:
        Complex() {
            setA(4);
            b = new int(5);
        }
        Complex(int x, int y) {
            setA(x);
            b = new int(y);
        }
        int *getB() {
            return b;
        }
        int get() {
            return b[0];
        }
        void setB() {
            b = getAaddress();
        }
        void setB(int v) {
            b[0] = v;
        }
        int getSum() {
            return getA() + *b;
        }
        Complex *foo() {
            return new Complex(6, 7);
        }
        void foo(Complex &c) {
            c = Complex(8, 9);
        }
        Complex foo(Complex *c1, Complex &c2) {
            printf("c1 A: %d, c2 A: %d, c1 B: %d, c2 B: %d\n", c1->getA(), c2.getA(), *c1->getB(), *c2.getB());
            return Complex(c1->getA()+c2.getA(), *c1->getB()+*c2.getB());
        }
};

int main() {
    Complex c1(1, 2);
    cout<< "Problem 3-1: "<< c1.getSum() <<endl;

    Complex c2(3, 4);
    c2.setB();
    cout<< "Problem 3-2: "<< c2.getSum() <<endl;

    Complex c3;
    cout<< "Problem 3-3: "<< c3.getSum() <<endl;

    Complex *p;
    p = c3.foo();
    cout<< "Problem 3-4: "<< p->getSum() <<endl;

    Complex c4;
    c3.foo(c4);
    cout<< "Problem 3-5: "<< c4.getSum() <<endl;

    Complex c5;
    c5 = c5.foo(&c3, c4);
    cout<< "Problem 3-6: "<< c5.getSum() <<endl;

    Number c6;
    c6.setA(5);
    cout<< "Problem 3-7: "<< c6.get() <<endl;

    Complex c7;
    c7.setB(6);
    cout<< "Problem 3-8: "<< c7.get() <<endl;

    Number *q = new Number();
    cout << "Problem 3-9: "<<  q->get() << endl;

    Number *r = new Complex(8, 9);
    cout << "Problem 3-10: "<< r->get() << endl;

    return 0;
}