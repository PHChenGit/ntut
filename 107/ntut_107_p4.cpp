#include <iostream>

using namespace std;

class Compute {
    public:
        virtual bool lessThan() = 0; // problem 4-1
        virtual void print() = 0;
};

class Data {
    public:
        Data(int size) {
            _size = size;
            _score = new int[_size];
            for (int i = 0; i < _size; i++)
                _score[i] = 80 + 2*i;
        }
        int mean() {
            int mValue = 0;
            for (int i = 0; i < _size; i++)
                mValue += _score[i];
            return (mValue/_size); // problem 4-2
        }
    private:
        int *_score; // problem 4-3
        int _size;
};

template<class T>
class AbstractData {
    public:
        AbstractData(int size, int score[]) { // problem 4-4
            _size = size;
            _score = new T[size];
            for (int i = 0; i < size; i++) {
                _score[i] = score[i];
            }
        }
        T mean() {
            int mValue = 0;
            for (int i=0; i < _size; i++)
                mValue += _score[i];
            return (mValue/_size);
        }
    private:
        T *_score;
        int _size;
};

class Group:public Compute {
    public:
        Group(int size, int score[]) {
            data1 = new AbstractData<int>(size, score);
            data2 = new Data(size);
        }
        bool lessThan() {
            if (data1->mean() > data2->mean()) {
                return false;
            }
            else {
                return true;
            }
        }
        void print() {
            cout<<"data set 1: "<<data1->mean()<<endl;
            cout<<"data set 2: "<<data2->mean()<<endl;
        }
    private:
        AbstractData<int> *data1;
        Data *data2;
};

void test05() {
    int size = 5;
    int score[] = {90, 80, 85, 88, 86};
    Group g(5, score);
    Data data(8);

    cout<<"problem 4-6: "<<data.mean()<<endl;
    g.print(); // problem 4-7
    cout<<g.lessThan()<<endl; // problem 4-8
}

int main() {
    test05();
    return 0;
}