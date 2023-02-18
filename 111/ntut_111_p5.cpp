#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template <class T> // problem 5-1
string print(T x) {
    return x.getName();
}

class Pet {
    protected: // problem 5-2
        double _weight;
        string _name;
    public:
        Pet(double weight, string name) {
            _weight = weight;
            _name = name;
        }
        double getWeight() {
            return _weight;
        }
        virtual string getName() const = 0;
        virtual ~Pet() {} // problem 5-3
};

class Cat: public Pet {
    private:
        vector<string> _toy;
        static bool sortedByAlph(string a, string b) { // problem 5-4
            return a[0] > b[0];
        }
    public:
        Cat(double weight, string name): Pet(weight, name) {} // problem 5-5
        ~Cat() override{}
        void addToy(string toy) {
            _toy.push_back(toy);
            sort(_toy.begin(), _toy.begin()+_toy.size(), sortedByAlph); // problem 5-6
        }
        string getToy(int index) {
            return "cat's toy::"+_toy.at(index);
        }
        string getName() const override { // problem 5-7
            return "cat::"+_name;
        }
};

class Bird: public Pet {
    private:
        double _canFly;
    public:
        Bird(double weight, string name, bool canFly): Pet(weight, name) { // Problem 5-5
            _canFly = canFly; // Problem 5-8
        }
        ~Bird() override {}
        string getName() const override { // problem 5-7
            return "bird::"+_name;
        }
};

int main() {
    Cat diang(8.0, "diang");
    Cat* siang = new Cat(5.0, "siang");
    Bird spar(0.6, "loudly", true);

    diang.addToy("tshirt");
    diang.addToy("ball");
    diang.addToy("human");
    siang->addToy("cockroach");
    siang = &diang;

    cout<<print<Cat>(diang)<<endl;
    cout<<siang->getToy(0)<<endl; // problem 5-9
    cout<<print<Cat>(*siang)<<endl; // problem 5-10
    return 0;
}