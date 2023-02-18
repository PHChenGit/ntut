#include <iostream>

using namespace std;

class Transportation {
    public:
        ~Transportation() {
            cout<<"~Transportation()"<<endl;
        }
        virtual void move() = 0;
};

class Car:public Transportation {
    private:
        int wheel;
    public:
        ~Car() {
            cout<<"~Car()"<<endl;
        }
        void setWheel(int value) {
            wheel = value;
        }
        int getWheel() {
            return wheel;
        }
        void move() {
            cout<<"run"<<endl;
        }
        virtual void printTopSpeed() {
            cout<<"100"<<endl;
        }
};

class Sedan: public Car {
    public:
        Sedan() {
            setWheel(4);
        }
        Sedan(Sedan& other) {
            setWheel(other.getWheel());
        }
        ~Sedan() {
            cout<<"~Sedan()"<<endl;
        }
        void move() {
            cout<<"run slow"<<endl;
        }
        void printTopSpeed() {
            cout<<"200"<<endl;
        }
};

class Coupe: public Car {
    public:
        Coupe() {
            setWheel(2);
        }
        Coupe(Coupe& other) {
            setWheel(other.getWheel());
        }
        ~Coupe() {
            cout<<"~Coupe()"<<endl;
        }
        void move() {
            cout<<"run fast"<<endl;
        }
        void printToSpeed() {
            cout<<"300"<<endl;
        }
};

class AirPlane: public Transportation {
    public:
        ~AirPlane() {
            cout<<"~AirPlane()"<<endl;
        }
        void move() {
            cout<<"fly"<<endl;
        }
        void printTopSpeed() {
            cout<<"900"<<endl;
        }
};

class Jet {
    public:
        Jet(){};
        ~Jet() {
            cout<<"~Jet()"<<endl;
        }
        void move() {
            cout<<"fly fast"<<endl;
        }
        virtual void printTopSpeed() {
            cout<<"1000"<<endl;
        }
};

class FlyingCar:public Car, public AirPlane {
    public:
        FlyingCar() {
            setWheel(4);
        }
        ~FlyingCar() {
            cout<<"~FlyingCar()"<<endl;
        }
        void move() {
            cout<<"fly slow"<<endl;
        }
        virtual void printTopSpeed() {
            cout<<"500"<<endl;
        }
};

int main() {
    Sedan sedan;
    Coupe coupe;
    Jet jet;
    FlyingCar flyingCar;

    sedan.move(); // problem 5-1
    coupe.move(); // problem 5-2
    flyingCar.move(); // problem 5-3
    jet.move(); // problem 5-4

    Car *p1, *p2;
    Sedan *p3;
    AirPlane *p4;

    p1 = new Car();
    p2 = new Sedan(sedan);
    p3 = new Sedan();
    p4 = new FlyingCar();

    p1->printTopSpeed(); // problem 5-5;
    p2->printTopSpeed(); // problem 5-6
    p3->printTopSpeed(); // problem 5-7
    p4->printTopSpeed(); // problem 5-8
    coupe.printTopSpeed(); // problem 5-9
    jet.printTopSpeed(); // problem 5-10

    printf("problem 5-11: ");
    delete p1; // problem 5-11
    printf("problem 5-12: ");
    delete p2; // problem 5-12
    printf("problem 5-13: ");
    delete p3; // problem 5-13
    printf("delete p4: ");
    delete p4;

    return 0;
}