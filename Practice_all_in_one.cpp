#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <thread>
#include <array>
#include <vector>
#include <list>
#include <iterator>
#include <span>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdexcept>
#include <csignal>
#include <windows.h>
#include <utility>
#include <chrono>
#include <functional>
#include <atomic>
#include <source_location>
#include <cstdarg>
// #include <mdsapn>
// #include <coroutine>


// #include <spanstream>

using namespace std;

#define CONSTANT "Funny noise"
#define MIN(a,b) (a<b? a:b)
#ifdef NULL
   #define FULL 0
#endif

#ifdef DEBUG
   cerr << "Variables  x = " << x <<endl;
#endif

#define MKSTR(x) #x
#define CONCAT(x,y) x ## y

std::byte b{67};


// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}
// 第二个命名空间
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}
using namespace first_space;

double division(int a, int b)       //division zero exception throw 
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}

class Box
{
   public:
   static int objectCounter;
   static void staticPrinter(Box b)
   {
      cout << "It is printed from a static function, The value is :" << b.box << endl;
   }
      Box(int i) { 
         cout << "调用构造函数！" <<endl; 
         box = i;
      }

      Box() { 
         cout << "调用构造函数！" <<endl; 
      }
      ~Box() { 
         cout << "调用析构函数！" <<endl; 
      }

      friend void printBoxVolum(Box b);

   private:
      int box;
};

void printBoxVolum(Box b)
{
   cout << "This output is from a friend function， The value of the Box :" << b.box << endl;
}

template<typename T>
inline T const& Max(T const& a, T const& b)
{
   return a < b ?  b:a;
}

template<class T>
class Stack{
   private:
    vector<T> elems; 

   public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const {
      return elems.empty();
    }
};

template<class T>
void Stack<T>::push(T const& elem)
{
   elems.push_back(elem);
}
 
template<class T>
void Stack<T>::pop(void)
{
   if(elems.empty()){
      throw out_of_range("Stack<>::pop(): empty stack");
   };
   elems.pop_back();
}

template <class T>
T Stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
    // 返回最后一个元素的副本 
    return elems.back();      
} 

void signalHandler(int signum)
{
   cout << "Interrupt signal (" << signum << ") received.\n";
   // 清理并关闭
   // 终止程序 
   exit(signum);  
}

std::ostream& operator<<(std::ostream& os, std::byte b)
{
    return os << std::bitset<8>(std::to_integer<int>(b));
}

void vardic_printer(const char* marg ...)
{
   va_list args;
   va_start(args, marg);

   while(*marg != '\0')
   {
         if (*marg == 'd')
        {
            int i = va_arg(args, int);
            std::cout << i << '\n';
        }
        else if (*marg == 'c')
        {
            // note automatic conversion to integral type
            int c = va_arg(args, int);
            std::cout << static_cast<char>(c) << '\n';
        }
        else if (*marg == 'f')
        {
            double d = va_arg(args, double);
            std::cout << d << '\n';
        }
        marg++;
   }

   va_end(args);
}

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    for (--n; n > 0; n -= 2)
    {
        typename std::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
}

class chair{
   int legsNum;
   public:
   virtual void toSit() = 0; 
   virtual void hasLegs() = 0;
};

class modernChair : public chair {
   int legsNum = 0;
   void toSit(){
      cout << "You already sit on a modern chair." << endl;
   }

   void hasLegs(){
      cout << "The number of legs of modern chair is: " << legsNum << endl;
   }
};

class vitorianChair : public chair {
   int legsNum = 4;
   void toSit(){
      cout << "You already sit on a vitorian chair." << endl;
   }

   void hasLegs(){
      cout << "The number of legs of vitorian chair is: " << legsNum << endl;
   }
};

class table{
   int legsNum;
   public:
   virtual void toPut() = 0;
   virtual void hasLegs() = 0;
};

class modernTable : public table {
   int legsNum = 4;
   void toPut(){
      cout << "You already Put on a modern table." << endl;
   }

   void hasLegs(){
      cout << "The number of legs of modern table is: " << legsNum << endl;
   }
};

class vitorianTable : public table {
   int legsNum = 4;
   void toPut(){
      cout << "You already Put on a vitorian table." << endl;
   }

   void hasLegs(){
      cout << "The number of legs of vitorian table is: " << legsNum << endl;
   }
};

class sofa{
   int legsNum;
   public:
   virtual void toLie() = 0;
   virtual void hasLegs() = 0;
};

class modernSofa : public sofa {
   int legsNum = 0;
   void toLie(){
      cout << "You already Lie on a modern sofa." << endl;
   }

   void hasLegs(){
      cout << "The number of legs of modern sofa is: " << legsNum << endl;
   }
};

class vitorianSofa : public sofa {
   int legsNum = 4;
   void toLie(){
      cout << "You already Lie on a vitorian sofa." << endl;
   }

   void hasLegs(){
      cout << "The number of legs of vitorian sofa is: " << legsNum << endl;
   }
};


// The design pattern of abstract factory.
class factory{   
   public:
      virtual chair *createChair() = 0;
      virtual table *createTable() = 0;
      virtual sofa *createSofa() = 0;
   ~factory(){
      cout << "The factory object has been realsed." << endl;
   }
};

class modernStyleFactory : public factory {
 
   public:
      chair *createChair(){
         return new modernChair;
      }

      sofa *createSofa(){
         return new modernSofa();
      }

      table *createTable(){
         return new modernTable();
      }
};

class vitorianStyleFactory : public factory {
 
   public:
      chair *createChair(){
         return new vitorianChair();
      }

      sofa *createSofa(){
         return new vitorianSofa();
      }

      table *createTable(){
         return new vitorianTable();
      }
};

class builder;
class houseBuilder;
class castleBuilder;
class palaceBuilder;

class construction {

   int numOfDoor, numOfWall, numOfWindow;
   string typ;
   public:

      friend builder;
      friend houseBuilder;
      friend castleBuilder;
      friend palaceBuilder;

      construction(string s){
         typ = s;
      }

      void getDetailOfTheHouse(){
         cout << "The " << typ << " house has " << this->numOfWall << " wall, " << this->numOfWindow <<
         " window and " << this->numOfDoor << " door" << endl; 
      }
      
};

class builder {
   public:
      virtual bool reset() = 0;
      virtual bool buildDoor(int doo) = 0;
      virtual bool buildWindow(int win) = 0;
      virtual bool buildWall(int wal) = 0;
      virtual construction* getTheConstruction() = 0;
};

class houseBuilder : public builder 
{
   construction *result = new construction("wood");

   public:
      bool reset() {
         result = new construction("wood");
         return true;
      }

      bool buildDoor(int doo){
         result->numOfDoor = doo;
         return true;
      }

      bool buildWindow(int win){
         result->numOfWindow = win;
         return true;
      }

      bool buildWall(int wal){
         result->numOfWall = wal;
         return true;
      }

      construction* getTheConstruction(){
         return result;
      }

};

class castleBuilder : public builder 
{
   construction *result = new construction("stone");

   public:
      bool reset() {
         result = new construction("stone");
         return true;
      }

      bool buildDoor(int doo){
         result->numOfDoor = doo;
         return true;
      }

      bool buildWindow(int win){
         result->numOfWindow = win;
         return true;
      }

      bool buildWall(int wal){
         result->numOfWall = wal;
         return true;
      }

      construction* getTheConstruction(){
         return result;
      }

};


class palaceBuilder : public builder 
{
   construction *result = new construction("diamand");

   public:
      bool reset() {
         result = new construction("diamand");
         return true;
      }

      bool buildDoor(int doo){
         result->numOfDoor = doo;
         return true;
      }

      bool buildWindow(int win){
         result->numOfWindow = win;
         return true;
      }

      bool buildWall(int wal){
         result->numOfWall = wal;
         return true;
      }

      construction* getTheConstruction(){
         return result;
      }

};

class director {
   builder *Builder;

   public:

      director (builder *bui){
         Builder = bui;
      }

      bool changeBuilder(builder *bui){
         Builder = bui;
         return true;
      }

      bool make(int doo, int win, int wal){
         Builder->buildDoor(doo);
         Builder->buildWall(wal);
         Builder->buildWindow(win);
         return true;
      }
};

class prototype
{  public:
      virtual prototype* clone() = 0;
};

// class prototypeRegistry
// {
//    prototype *items = new cloner[5];

//    void additem(string id , prototype typ){}
//    // prototype getById(string id){
//    //    return cloner
//    // }

// };

class cloner : public prototype
{  
   int data1;
   string str1 = "your string";

   public:
      cloner(){}
      cloner(cloner* pro){
      this->data1 = pro->data1;
      this->str1 = pro->str1;
      }

      prototype* clone(){
         return new cloner(this);
      }
};

class sington
{
   static sington *instance;

   sington(){}

   public:
      sington* getInstance(){
         if(instance == NULL)
            instance = new sington;
         
         return this->instance;
      }
};

class device
{
   public:
      virtual bool isEnable() = 0;
      virtual void enable() = 0;
      virtual void disable() = 0;
      virtual int getVolum() = 0;
      virtual void setVolum(int percent) = 0;
      virtual int getChannel() = 0;
      virtual void setChannel(int cha) = 0;
};

class radio : public device 
{  
   int channel = 0, volum = 20;
   bool enablility = false;

   public:
      bool isEnable(){
         return this->enablility;
      }
      void enable(){
         this->enablility = true;
      }
      void disable(){
         this->enablility = false;
      }
      int getVolum(){
         return this->volum;
      }
      void setVolum(int percent){
         this->volum = percent;
      }
      int getChannel(){
         return this->channel;
      }
      void setChannel(int cha){
         this->channel = cha;
      }
};

class TV : public device 
{  
   int channel = 0, volum = 20;
   bool enablility = false;

   public:
      bool isEnable(){
         return this->enablility;
      }
      void enable(){
         this->enablility = true;
      }
      void disable(){
         this->enablility = false;
      }
      int getVolum(){
         return this->volum;
      }
      void setVolum(int percent){
         this->volum = percent;
      }
      int getChannel(){
         return this->channel;
      }
      void setChannel(int cha){
         this->channel = cha;
      }
};

class remote
{
   device *dev = new radio;

   public:
      void togglePower(){
         if(dev->isEnable()){
            dev->disable();
         }
         else
         dev->enable();
      }
      void volumDown(){
         dev->setChannel(dev->getVolum() - 1);
      }
      void volumUp(){
         dev->setChannel(dev->getVolum() + 1);
      }
      void channelUp(){
         dev->setChannel(dev->getChannel() + 1);
      }
      void channelDown(){
         dev->setChannel(dev->getChannel() - 1);
      }
};

class client {
   public:
      void useChair(chair *cha){
         cha->toSit();
      }

      void useSofa(sofa *sof){
         sof->toLie();
      }

      void useTable(table *tab){
         tab->toPut();
      }

      template<class T>
      void countLegs(T *t){
         t->hasLegs();
      }

      void callDirectorMake(int i, int j, int k, director *d){
         d->make(i,j,k);
      }

      void getYourConstruction(builder *b){
         b->getTheConstruction()->getDetailOfTheHouse();
      }

};

class industry;
class sightseeing;
class hospital;

class visitor 
{  
   public:
      virtual void visit(sightseeing *s) = 0 ;

      virtual void visit(industry *i) = 0 ;

      virtual void visit(hospital *h) = 0 ;

};

class geoData
{  
   public:

      string name;

      virtual void accept(visitor* v) = 0;
};

class industry : public geoData
{
   public:
      string name = "industry";

      void accept(visitor* vis){
         vis->visit(this);
      }
};

class hospital : public geoData
{
   public:
      string name = "hospital";

      void accept(visitor* vis){
         vis->visit(this);
      }
};

class sightseeing : public geoData
{
   public:
      string name = "sightseeing";

      void accept(visitor* vis){
         vis->visit(this);
      }
};

class visitorImp : public visitor 
{  
   public:
      void visit(sightseeing *s){
         cout << "This is a sightseeing object." << s->name <<endl;
      }

      void visit(industry *i){
         cout << "this is a industry." << i->name <<endl;
      }

      void visit(hospital *h){
         cout << "this is a " << h->name <<endl;
      }

};

class application;

class editor
{
   public:

      editor(string s){
         text = s ;
      }

      string text;
      void print(){
         cout << this->text << endl;
      }

      void repalace(string s){
         this->text = s;
      }
};

class command
{
   public:
      application *app;
      editor *edi;
      string s;

      command(application *a, editor *e){
         this->app = a;
         this->edi = e;
      }

      command(application *a, editor *e, string s1){
         this->app = a;
         this->edi = e;
         s = s1;
      }

      virtual void excute() = 0;

};

class printCommand : public command
{
   public:
      printCommand(application *a, editor *e) : command(a, e){}
      
      void excute(){
         edi->print();
      }
};

class replaceCommand : public command 
{  
   public:

      replaceCommand(application *a, editor *e, string s1) : command(a, e, s1){}

      void excute(){
         edi->repalace(s);
      }
};

class application
{
   public:

      editor *edi;
      command *com;

      void sendACommand(command *c){
         com = c;
      }

      void excuteCommand(){
         com->excute();
      }
   
};

class mediator;

class conponent{
   public:
   mediator *med;
   virtual void excute(){}
};

class concreteConponentA : private conponent
{
   public:
   concreteConponentA(mediator *m){
      med = m;
   }
   void excute(){
      cout << "this is concreteConponentA" << endl;
   }
};

class concreteConponentB : private conponent
{
   public:
   concreteConponentB(mediator *m){
      med = m;
   }
   void excute(){
      cout << "this is concreteConponentB" << endl;
   }
};

class concreteConponentC : private conponent
{
   public:
   concreteConponentC(mediator *m){
      med = m;
   }
   void excute(){
      cout << "this is concreteConponentC" << endl;
   }
};

class concreteConponentD : private conponent
{
   public:
   
concreteConponentD(mediator *m){
      med = m;
   }

   void excute(){
      cout << "this is concreteConponentD" << endl;
   }
};

class mediator
{

   public:
      virtual void notify(conponent *c) = 0;
};

class concreteMediator1 : public mediator
{
   concreteConponentA *A;
   concreteConponentB *B;
   concreteConponentC *C;
   concreteConponentD *D;



   // public:
   //    void notify(conponent *c){
   //       if(c == A)

   //    }

};

class subscriber{
   public:
      virtual void update() = 0;
};


class publisher
{
   list<subscriber *> subscribers;
   int mainState;

   public:
      void subscribe(subscriber *s){
         this->subscribers.push_back(s);
      }

      void unsubscribe(subscriber *s){
         subscribers.remove(s);
      }

      void notifySubscribers(){
         for_each(subscribers.begin(), subscribers.end(), [](subscriber *s){s->update();});
      };

      void mainBusinessLogic(){};

};

class strategy
{
   public:
   virtual void excute(string s) = 0;
};

class strategy1 : public strategy{
   public:
      void excute(string s){
         cout << "This sentence is printed by strategy1: " << s << endl;
      }
};

class strategy2 : public strategy{
   public:
      void excute(string s){
         cout << "This sentence is printed by strategy2: " << s << endl;
      }
};

class strategy3 : public strategy{
   public:
      void excute(string s){
         cout << "This sentence is printed by strategy3: " << s << endl;
      }
};

class context
{
   strategy *stra;

   public:

      context(strategy *s){setStrategy(s);}

      ~context(){cout << "this object has been deleted." << endl;}

      void setStrategy(strategy *s){
         stra = s;
      }

      void doSomething(string data){
         stra->excute(data);
      }
};

class contextForState;

class state
{
   protected:

   contextForState *con;

   public:
   virtual void doThis() = 0;
   virtual void doThat() = 0;

   virtual void setContext(contextForState *con){
         cout << "This initial method is from super class." << endl;
      }

   virtual void setState(){
      cout << "This state changing method is from super class." << endl;
   }
};

class contextForState
{
   state *s;

   public:
      contextForState(state *st){
         this->s = st;
         this->s->setContext(this);
      }
      void changeState(state *st){
         if(this->s != NULL)
            delete this->s;
         this->s = st;
         this->s->setContext(this);
      }

};

class stateA;
class stateB;
class stateC;
class stateD;

class stateA : public state
{
   public:

   void setState() override;
   void doThis(){
      cout << "this state has done something" << endl;
   }

   void doThat(){
      cout << "this state has done something else." << endl;
   }

   void setContext(contextForState *con){
         this->con = con;
      }
};

class stateB : public state
{
   public:

   void setState() override;

   void doThis(){
      cout << "this state has done something" << endl;
   }

   void doThat(){
      cout << "this state has done something else." << endl;
   }

   void setContext(contextForState *con){
         this->con = con;
      }

   
};

class stateC : public state
{
   public:
   void setState() override;

   void doThis(){
      cout << "this state has done something" << endl;
   }

   void doThat(){
      cout << "this state has done something else." << endl;
   }

   void setContext(contextForState *con){
         this->con = con;
      }
   
};

class stateD : public state
{
   public:
   void doThis(){
      cout << "this state has done something" << endl;
   }

   void doThat(){
      cout << "this state has done something else." << endl;
   }

   void setContext(contextForState *con){
         this->con = con;
      }

   void setState() override {
      con->changeState( new stateA);
   }
};

void stateA::setState(){
   con->changeState( new stateB);
}

void stateB::setState(){
      if(true)
      con->changeState( new stateC);
      else
      con->changeState( new stateD);
   }

void stateC::setState(){
      con->changeState( new stateD);
   }

class component
{
   public:
   virtual void excute() = 0;
};

class leaf : public component
{
   public:
   void excute(){
      cout << "this is the end of the composite." << endl;
   }
};

class composite : public component
{
   list<component*> children;

   public:
   void excute(){
      for(auto i = children.begin(); i != children.end(); i++)
         (*i)->excute();
   }

   void add(component* con){
      children.push_back(con);}

   void remove(component* con){
      children.remove(con);
   }

   list<component*> getChildren(){
      return children;
   }

};

void span_print (vector<int> in)
{
   if(in.empty() == false)
   cout << in[0] << endl;
}

class pl{
   public:

   int q;
   char p;
};

bool less_q (pl const& x, pl const& y)
{
   return x.q < y.q;
}
 
int main ()
{
    
   char data[100];
 
   // 以写模式打开文件
   ofstream outfile;
   outfile.open("afile.dat");
 
   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);
 
   // 向文件写入用户输入的数据
   outfile << data << endl;
 
   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // 再次向文件写入用户输入的数据
   outfile << data << endl;
 
   // 关闭打开的文件
   outfile.close();
 
   // 以读模式打开文件
   ifstream infile; 
   infile.open("Text_in_it.txt"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 
 
   // 在屏幕上写入数据
   // while(data)
   // {
      infile >> data; 
      cout << data << endl;
   // };
   
   // 再次从文件读取数据，并显示它
   // infile >> data; 
   // cout << data << endl; 
 
   // 关闭打开的文件
   infile.close();

   try
   {
      cout << division(1,0) << endl;
   }
   catch(const char* msg)
   {
      cerr << msg << endl;
   };

       int i,j,k;   // p[2][3][4]
    
    int ***p;
    p = new int **[2]; 
    for(i=0; i<2; i++) 
    { 
        p[i]=new int *[3]; 
        for(j=0; j<3; j++) 
            p[i][j]=new int[4]; 
    }
    
    //输出 p[i][j][k] 三维数据
    for(i=0; i<2; i++)   
    {
        for(j=0; j<3; j++)   
        { 
            for(k=0;k<4;k++)
            { 
                p[i][j][k]=i+j+k;
                cout<<p[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    // 释放内存
    for(i=0; i<2; i++) 
    {
        for(j=0; j<3; j++) 
        {   
            delete [] p[i][j];   
        }   
    }       
    for(i=0; i<2; i++)   
    {       
        delete [] p[i];   
    }   
    delete [] p;  

   Box* myBoxArray = new Box[4];  //object allocate and delete from the dynamic ram space

   Box Box1(2);
   Box Box3 = Box1;

   printBoxVolum(Box1);
   Box::staticPrinter(Box1);  
 
   delete [] myBoxArray; // 删除数组

   func();
   second_space::func();

   // put variery vanrity to template types 
   int i1 = 2,i2 = 3;
   cout << "Max(i1, i2) : " << Max(i1, i2) << endl; 

   double f1 = 14.5, f2 = 15.2;
   cout << "Max(f1, f2): " << Max(f1, f2) << endl;

   string s1 = "world", s2 = "hello@";
   cout << "Max(s1, s2): " << Max(s1, s2) << endl; 

       try { 
        Stack<int>         intStack;  // int 类型的栈 
        Stack<string> stringStack;    // string 类型的栈 
 
        // 操作 int 类型的栈 
        intStack.push(7); 
        cout << intStack.top() <<endl; 
 
        // 操作 string 类型的栈 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
      //   stringStack.pop(); 
      //   stringStack.pop(); 
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 

   cout << "A constant was defined by user:" << CONSTANT <<endl;

   cout << "MKSTR() convert the vantarible to string" << MKSTR(Hello world!) <<endl;

   cout << "CONCAT() makes two strings conbined into one :" << MKSTR(CONCAT(your,ash)) <<endl;

   cout << "Value of __LINE__ : " << __LINE__ << endl;
   cout << "Value of __FILE__ : " << __FILE__ << endl;
   cout << "Value of __DATE__ : " << __DATE__ << endl;
   cout << "Value of __TIME__ : " << __TIME__ << endl;

   // // 注册信号 SIGINT 和信号处理程序
   // signal(SIGINT, signalHandler);  
 
   // // while(1){
   // //    cout << "Going to sleep...." << endl;
   // //    Sleep(1000);
   // // };

   // while(++i){
   //    cout << "Going to sleep...." << endl;
   //    if( i == 3 ){
   //       raise( SIGINT);
   //    }
   //    Sleep(1000);
   // };

   // int n = 0;
   // thread t1; // t1 is not a thread
   // thread t2(f1, n + 1); // pass by value
   // thread t3(f2, std::ref(n)); // pass by reference
   // thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
   // t2.join();
   // t4.join();
   // std::cout << "Final value of n is " << n << '\n';

   std::cout << "1. " << b << '\n';

   vardic_printer("dcff", 3, 'a', 1.999, 42.5);

   std::vector<int> v{1, 2, 3, 4, 5};
   my_reverse(v.begin(), v.end());
   for (int n : v)
       std::cout << n << ' ';
   std::cout << '\n';

   std::list<int> l{1, 2, 3, 4, 5};
   my_reverse(l.begin(), l.end());
   for (int n : l)
       std::cout << n << ' ';
   std::cout << '\n';

   int a[]{1, 2, 3, 4, 5}; 
   my_reverse(a, a + std::size(a));
   for (int n : a)
       std::cout << n << ' ';
   std::cout << '\n';
   

   cout << "Abstarct factory pattern test :" << endl;

   client cli;

   factory *fac = new vitorianStyleFactory;

   chair *aChair  = fac->createChair();

   cli.useChair(aChair);

   cli.countLegs(aChair);

   delete fac;

   fac = new modernStyleFactory;

   aChair = fac->createChair();

   cli.useChair(aChair);

   cli.countLegs(aChair);

   houseBuilder houB;

   director dir(&houB);

   cli.callDirectorMake(2,4,5,&dir);

   cli.getYourConstruction(&houB);

   visitorImp vis;

   industry in;

   in.accept(&vis);

   hospital hos;

   hos.accept(&vis);

   sightseeing sig;

   sig.accept(&vis);

   editor editor1("This is the default text.");

   application aplication1;

   printCommand printCommand1(&aplication1, &editor1);

   printCommand1.excute();

   replaceCommand replaceCommand1(&aplication1, &editor1, "Those texts are replaced.");

   replaceCommand1.excute();

   printCommand1.excute();

   vector<int> sp {1,2,34,5};

   vector<pl> pl1 {{2,'c'},{1,'b'},{3,'a'}};

   auto i12 = min_element(begin(pl1),end(pl1),less_q);
   auto q1 = i12 ->q;
   auto c1 = i12 ->p;
   cout << q1 <<"this is p: " << c1 << endl;

   // span_print(sp);

   // if (const char* env_p = std::getenv("PATH"))
   //    std::cout << "Your PATH is: " << env_p << '\n';

   // std::system("dir");

   return 0;  //for the test
   

}