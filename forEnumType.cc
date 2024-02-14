#include <iostream>

using namespace std;

enum color { red, green, blue };
color c = color::blue;

class box {
    public:
        int i = 0;
};


int main(){
    cout << c << endl;
    box *boxa, *boxb;
    boxa = new box;
    boxb = boxa;
    cout << "now boxa is :" << boxa << " and boxb is: " << boxb << endl;
    boxa = new box;
    cout << "after changing boxa's value, now boxa is: " << boxa << " and boxb is: " << boxb << endl;
    return 0;
}