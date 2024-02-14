#include <iostream>
#include <limits> //Data types length denpendens package
#include <string> 
#include <vector>

using namespace std;

//This is a note
/*This is a note too*/

//Global Vairables if a variable is defined in the function, global variable will be overwritten by the latter variable
bool VairableBoolVoid , VairableBool = false;
char VairableCharVoid , VairableChar = '\3';
int VairableIntVoid , VairableInt = 1;
float VairableFloatVoid , VairableFloat =   0.0f;
double VairableDoubleVoid , VairableDouble = 0.0;
wchar_t VairableWcharVoid , VairableWchar = '\7';

enum enumVairable { five , garbage , trash } ;
enumVairable u = { five };

static int count = 0;
// mutable int;
extern int exVariables; 

// objects
class Box
{
   public:
      double length;   // 盒子的长度
      double breadth;  // 盒子的宽度
      double height;   // 盒子的高度
      // 成员函数声明
      double get(void);
      void set( double len, double bre, double hei );
      Box( double len, double bre, double hei);  // 这是构造函数
      ~Box();  // 这是析构函数
      virtual double getArea()  //virtual function
      {
        cout << "geting area from parent virtual function " << endl;
        return length*breadth; //get the area
      }; 
      virtual double getArea2() = 0;    //pure virtual function shall be implemented when this class is inherited 


};
// 成员函数定义
double Box::get(void)
{
    return length * breadth * height;
}
 
void Box::set( double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}

Box::Box( double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
    cout << "The " << this << " class is constructed" << endl;
}

Box::~Box(void)
{
    cout << "The " << this << " class is deleted" << endl;
}

class giftBox : public Box
{
    public:
     double getArea()            //Implementation of the virual function
     {
        cout << "Getting the area form child implemented virtual function " << endl;
        return length*breadth;
     };
     double getArea2() //Implementation of the pure virtual function
     {
        cout << "Getting the area form child implemented pure virtual function " << endl;
        return length*breadth;
     };
     bool lossenTies();
     bool lossenTies(int input);
     bool lossenTies(double input);
     giftBox(double len, double bre, double hei);
     ~giftBox();
};

bool giftBox::lossenTies(void)
{
    cout << "The ties are already loosened" << endl;
    return true;
} 

bool giftBox::lossenTies(int input)
{
    cout << "The ties are already loosened (int message)" << endl;
    return true;
} 

bool giftBox::lossenTies(double input)
{
    cout << "The ties are already loosened (double message)" << endl;
    return true;
} 

giftBox::giftBox( double len, double bre, double hei) : Box(len, bre, hei)
{
    length = len;
    breadth = bre;
    height = hei;
    cout << "The " << this << " class is constructed" << endl;
}

giftBox::~giftBox(void)
{
    cout << "The " << this << " giftbox class is deleted" << endl;
}

int main()
{
    cout << "VairableBoolVoid:" << VairableBoolVoid << endl;
    cout << "VairableBool:" << VairableBool << endl;
    cout << "VairableCharVoid:" << VairableCharVoid << endl;    
    cout << "VairableChar:" << VairableChar << endl;
    cout << "VairableIntVoid:" << VairableIntVoid << endl;
    cout << "VairableInt:" << VairableInt << endl;
    cout << "VairableFloatVoid:" << VairableFloatVoid << endl;
    cout << "VairableFloat:" << VairableFloat << endl;
    cout << "VairableDoubleVoid:" << VairableDoubleVoid << endl;
    cout << "VairableDouble:" << VairableDouble << endl;
    cout << "VairableWcharVoid:" << VairableWcharVoid << endl;
    cout << "VairableWchar:" << VairableWchar << endl;

    // /*********************print out all types of datatypes**********************************/
    // cout << "type: \t\t" << "************size**************"<< endl;  
    // cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);  
    // cout << "\t最大值：" << (numeric_limits<bool>::max)();  
    // cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;  
    // cout << "char: \t\t" << "所占字节数：" << sizeof(char);  
    // cout << "\t最大值：" << (numeric_limits<char>::max)();  
    // cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;  
    // cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);  
    // cout << "\t最大值：" << (numeric_limits<signed char>::max)();  
    // cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;  
    // cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);  
    // cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();  
    // cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;  
    // cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);  
    // cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();  
    // cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;  
    // cout << "short: \t\t" << "所占字节数：" << sizeof(short);  
    // cout << "\t最大值：" << (numeric_limits<short>::max)();  
    // cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;  
    // cout << "int: \t\t" << "所占字节数：" << sizeof(int);  
    // cout << "\t最大值：" << (numeric_limits<int>::max)();  
    // cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;  
    // cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);  
    // cout << "\t最大值：" << (numeric_limits<unsigned>::max)();  
    // cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;  
    // cout << "long: \t\t" << "所占字节数：" << sizeof(long);  
    // cout << "\t最大值：" << (numeric_limits<long>::max)();  
    // cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;  
    // cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);  
    // cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();  
    // cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;  
    // cout << "double: \t" << "所占字节数：" << sizeof(double);  
    // cout << "\t最大值：" << (numeric_limits<double>::max)();  
    // cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;  
    // cout << "long double: \t" << "所占字节数：" << sizeof(long double);  
    // cout << "\t最大值：" << (numeric_limits<long double>::max)();  
    // cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;  
    // cout << "float: \t\t" << "所占字节数：" << sizeof(float);  
    // cout << "\t最大值：" << (numeric_limits<float>::max)();  
    // cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;  
    // cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);  
    // cout << "\t最大值：" << (numeric_limits<size_t>::max)();  
    // cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;  
    // cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;  
    // // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;  
    // cout << "type: \t\t" << "************size**************"<< endl;  

    cout << "enumeration: \t\t" << u << endl;

    // operators 

    // object
    // Box Box1(5.0,6.0,7.0);        // 声明 Box1，类型为 Box
    // Box Box2(10.0,11.0,12.0);        // 声明 Box2，类型为 Box
    // Box Box3(13.0,14.0,15.0);        // 声明 Box3，类型为 Box
    giftBox giftBoxBox1(1.0,2.0,3.0);  //derived from Box
    // cout << "The volume of box1：" << Box1.get() << endl;

    Box *BoxPointer = &giftBoxBox1;  
    cout << "The area of box is : " << BoxPointer->getArea() << endl;
    cout << "The area of box is : " << BoxPointer->getArea2() << endl;

    // derived classes
    cout << "The volume of giftBoxBox1：" << giftBoxBox1.get() << endl;
    giftBoxBox1.lossenTies(); 
    giftBoxBox1.lossenTies(1); 
    giftBoxBox1.lossenTies(1.0); 

    return 0;  

    
}

