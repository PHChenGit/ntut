#include <iostream>

using namespace std;

class B {
    private:
        int a;
    public:
        void f();
        virtual void g();
        ~B();
        int get() {
            return a;
        }
        void set(int v) {
            a = v;
        }
};

B::~B() {
    cout << "66" << endl;
}

void B::f() {
    cout << "11" << endl;
}

void B::g() {
    cout << "22" << endl;
}

class D: public B {
    private:
        int b;
    public:
        void f();
        void g();
        ~D();
        D() {
            set(1);
            b = 2;
        }
        int getA() {
            return get();
        }
        int getB() {
            return b;
        }
};

D::~D() {
    cout << "99" <<endl;
}

void D::f() {
    cout << "33" << endl;
}

void D::g() {
    cout << "44" << endl;
}

void f(B& p) {
    p.f();
}

void g(B& p) {
    p.g();
}

int main() {
    B b;
    D d;

    cout<<"problem 3-1: ";
    b.f(); // problem 3-1

    cout<<"problem 3-2: ";
    d.f(); // problem 3-2

    cout<<"problem 3-3: ";
    f(d);

    cout<<"problem 3-4: ";
    g(d);

    B *b1, *b2;
    b1 = new B;
    b2 = new D;

    cout<<"problem 3-5: ";
    b1->f(); // problem 3-5

    cout<<"problem 3-6: ";
    b2->f(); // problem 3-6

    cout<<"problem 3-7: ";
    b1->g(); // problem 3-7

    cout<<"problem 3-8: ";
    b2->g(); // problem 3-8

    cout<<"problem 3-9: ";
    delete b1; // problem 3-9

    cout<<"problem 3-10: ";
    delete b2; // problem 3-10
}