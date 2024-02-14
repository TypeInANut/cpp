#include<iostream>
#include<cstring>

using namespace std;

void printbooks(struct Books *book);
struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int id;
};
int main()
{
    struct Books *pointer1,*pointer2;
    struct Books book1;
    struct Books book2;
    pointer1=&book1;
    pointer2=&book2;
                            //给book2赋值
    strcpy(book2.title,"Learn c++ Programming");
    strcpy(book2.author,"Laozhang");
    strcpy(book2.subject,"telecom");
    book2.id=102;
                             //给book1赋值
    strcpy(book1.title,"Telecom Billing");
    strcpy(book1.author,"yeshiLaozhang");
    strcpy(book1.subject,"Telecom");
    book1.id=2062;
    printbooks(pointer1);
    printbooks(pointer2);
    return 0;
}
void printbooks(struct Books *book)
{
    cout << "Book Title:" << book->title <<endl;
    cout << "Book author:" <<book->author <<endl;
    cout << "Book subject:" <<book->subject <<endl;
    cout << "Book Id:" <<book->id <<endl;
}
//输出两本书的名称等信息