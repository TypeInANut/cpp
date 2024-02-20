#include <iostream>
 
using namespace std;
 
// 基类
class Shape 
{
public:
   // 提供接口框架的纯虚函数
   virtual int getArea() = 0;
   void setWidth(int w)
   {
      width = w;
   }
   void setHeight(int h)
   {
      height = h;
   }
protected:
   int width;
   int height;
};
 
// 派生类
class Rectangle: public Shape
{
public:
   int getArea()
   { 
      return (width * height); 
   }
};
class Triangle: public Shape
{
public:
   int getArea()
   { 
      return (width * height)/2; 
   }
};
 
int main(void)
{
   Rectangle Rect;
   Triangle  Tri;
 
 Shape *sha;
 
 sha = &Rect;
   sha->setWidth(5);
   sha->setHeight(7);
   // 输出对象的面积
   cout << "Total Rectangle area: " << sha->getArea() << endl;
 
 sha = &Tri;
   sha->setWidth(5);
   sha->setHeight(7);
   // 输出对象的面积
   cout << "Total Triangle area: " << sha->getArea() << endl; 
 
   return 0;
}