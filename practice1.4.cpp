#include<iostream>
using namespace std;

class Line//定义类
{
  public:
  double Length;
  double getLength(void);
  void setLength(double len);
};
double Line::getLength(void)//外部定义函数1
{
    return Length;
}
void Line::setLength(double len)//外部定义函数2
{
    Length=len;
}
int main()
{
  Line line;
  line.setLength(6.0);//用类内部的函数可以定义内部任意性质变量成员，而外部只能修改（调用）public成员
  cout<<"长度为:"<<line.Length<<endl;
  line.Length=10.0;       //这一步是可行的因为Length是共有成员
  cout<<"Length of line:"<<line.Length<<endl;
  return 0;
}
