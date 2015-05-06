#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

template<class T>
class base{
public:
    virtual void foo(){
        printf("base\n");
    }
    base(){
        foo();
    }
    virtual ~base(){
//        T* p = static_cast<T*>(this);
//        p->foo();
        this->foo();
    }
    void func(){
//        T* p = static_cast<T*>(this);
//        p->foo();
        this->foo();
    }
};

class derived : public base<derived>{
public:
    virtual void foo(){
        printf("derived\n");
    }
    derived(){
        foo();
    }
    virtual ~derived(){

    }
};

int main(){
    derived* p = new derived();
//    p->func();
    delete p;
}

