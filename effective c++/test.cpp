#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
class Base{
public:
    Base(T id=2): id(id){}
    virtual ~Base(){}
    void foo(){
        cout << "base function ...." << endl;
    }
private:
    T id;
};

template<typename T>
class Derived : public Base<T>{
public:
//   Derived(T id) : Base(id){}
   void test(){
        this->foo();
        cout << "derived function ...." << endl;
   }
};

class sta{
    friend void create();

    static int a;
//public:
    static void foo(){
        cout << "sta function foo..." << endl;
    }
};

int sta::a = 1;

void create(){
    sta::foo();
    cout << "function create..." << endl;
}
int main(){
    sta s;
    create();
    return 0;
}
