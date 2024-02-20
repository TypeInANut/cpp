#include <iostream>
using namespace std;//在对象中引入函数(类函数的使用)^0^ 
class Box
{
    public:
    double length;
    double breadth;
    double height;
    //函数
    double getVolume(void);
    void setLength(double len);
    void setHeight(double hei);
    void setBreadth(double bre);

};
//函数定义
double Box::getVolume(void)
{
    return length*breadth*height;
}
void Box::setBreadth(double bre)
{
    breadth=bre;
}
void Box::setHeight(double hei)
{
    height=hei;
}
void Box::setLength(double len)
{
    length=len;
}
int main()
{
    Box box1,box2;
    double volume=0.0;
    //box1详述
    box1.setLength(6.0);
    box1.setBreadth(7.0);
    box1.setHeight(5.0);
    //详述box2
    box2.setLength(12.0);
    box2.setBreadth(13.0);
    box2.setHeight(10.0);
    //box1体积
    volume=box1.getVolume();
    cout<<"box1的体积："<<volume<<endl;
    //box2的体积
    volume=box2.getVolume();
    cout<<"box2的体积："<<volume<<endl;
    return 0;
}