#include <iostream>

using namespace std;

class Figure {
    public:
        Figure(){}
        virtual void draw(){}; // problem 4-1
};

class Line: public Figure {
    public:
        Line(){}
        void draw(){};
};

void Line::draw() {
    cout<<"draw like a line..."<<endl;
}

class Circle: public Figure {
    public:
        Circle() {}
        void draw();
};

void Circle::draw() {
    cout<<"draw like a circle..."<<endl;
}

int main() {
    Figure *p1 = new Line(); // problem 4-2
    Figure *p2 = new Circle(); // problem 4-3

    p1->draw(); // problem 4-4
    p2->draw(); // problem 4-5
    return 0;
}