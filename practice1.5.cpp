#include <iostream>

using namespace std;

class Shap
{
    public:
    void setLength(int l)
    {
      length=l;
    }
    void setWight(int w)
    {
        wight=w;
    }
    protected:
    int length,wight;
};
class paitcost
{
    public:
    int getcost(int a)
    {
        return a*70;
    }
};
class Rectangle:public Shap,public paitcost
{
    public:
    int getarea()
    {
        return length*wight;
    }
};
int main()
{
    Rectangle rect;
    int area;
    rect.setLength(5);
    rect.setWight(6);
    area=rect.getarea();
    cout<<"total area:$"<<rect.getcost(area)<<endl;

return 0;
}