#include <iostream>
#include <string>

using namespace std;

class Fruit {
    private:
        string color;
    public:
        void setColor(string value) {
            color = value;
        }
        string getColor() const {
            return color;
        }
        virtual void taste() =0; // problem 4-1, 4-2
        void printInfo() {
            cout << color << endl;
        }
        virtual void printData() { // problem 4-3
            cout << color << endl;
        }
};

class Apple: public Fruit {
    private:
        string cultivar;
    public:
        Apple(string co = "red", string cu = "Fuji"): cultivar(cu) {
            setColor(co);
        }
        Apple(const Apple& a) { // problem 4-4
            setColor(a.getColor()); // problem 4-5
            cultivar = a.cultivar; // problem 4-6
        }
        ~Apple(){}; // problem 4-7
        void taste() {
            cout << "sweet" << endl;
        }
        void setCultivar(string cu) {
            cultivar = cu;
        }
        void setCultivar(string cu, string co) {
            cultivar = cu;
            setColor(co);
        }
        void printInfo() {
            cout << cultivar << endl;
        }
        void printData() {
            cout << cultivar << endl;
        }
};

int main() {
    Apple apple;
    apple.setCultivar("McIntosh", "green");
    Fruit *p1 = new Apple();
    Fruit *p2 = new Apple(apple);
    Apple *p3 = new Apple();

    p3->setColor("yellow");
    p3->setCultivar("McIntosh");
    p1->printInfo(); // problem 4-8
    p2->printInfo(); // problem 4-9
    p3->printInfo(); // problem 4-10
    p1->printData(); // problem 4-11
    p2->printData(); // problem 4-12
    p3->printData(); // problem 4-13
    return 0;
}