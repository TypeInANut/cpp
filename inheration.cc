#include<iostream>
using namespace std;

class A
{ 
 protected: int x;
 public: A(int a=0){ x=a; }
};

class B: virtual public A 
{
 protected: int y;
 public: B(int a=0, int b=0) { y=b; }
};

class C: public virtual A
{
 protected: int z;
 public: C(int a=0, int c=0) { z=c; }
};

class D: public B, public C
{ 
protected: int k; 
public: D(int a1=0, int a2=0, int b=0, int c=0, int d=0) : B(a1, b), C(a2, c), k(d) { } 
// A, D类的构造函数不直接给A的构造函数传值，系统自动调用A类的缺省构造函数，输出x=0。
void Show( )
 { cout << "x=" << x << ", "; 
 cout << "y=" << y << ", ";
 cout << "z=" << z << ", ";
 cout << "k=" << k << endl;
 }
};

class E: public B, public C
{ 
protected: int k; 
public: E(int a1=0, int a2=0, int b=0, int c=0, int d=0) : B(a1, b), C(a2, c), A(a1), k(d) { } 
// A, D类的构造函数不直接给A的构造函数传值，系统自动调用A类的缺省构造函数，输出x=0。
void Show( )
 { cout << "x=" << x << ", "; 
 cout << "y=" << y << ", ";
 cout << "z=" << z << ", ";
 cout << "k=" << k << endl;
 }
};

int main(void)
{
 D obj(1, 1, 2, 3, 4);
 obj.Show( );

 E obj1(1, 1, 2, 3, 4);
 obj1.Show();

 return 0;
}