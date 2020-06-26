#include <iostream>
using namespace std;

class A
{ 
 public:
    A() {cout << "A" << endl;} 
    virtual void f() {cout << "f in A";}
    ~A() {cout << "~A" << endl;}
};

class B : public A
{ 
 public:
    B() {cout << "B" << endl;} 
    void f() {cout << "f in B"; }
    ~B() {cout << "~B" << endl;}
};

int main()
{ 
    //A *a = new A; 
    //B *b = new B;
    A *c = new B; 
    //delete b; 
    //delete a;
    c->f();
    delete c; 
    return 0;
}
