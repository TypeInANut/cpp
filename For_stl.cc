#include<iostream>
#include<sstream>
#include<experimental/random>
// #include<ranges_algo.h>
#include<charconv>
#include<optional>
#include<variant>
#include<any>
#include<algorithm>
#include<iterator>
#include<span>
#include<ranges>
#include<numeric>
#include<concepts>
#include<queue>
#include<stack>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>

using namespace std;

class Client 
{   
    public:
    virtual void notification(string s) = 0;
};

class ComputerPlayer : public Client
{
    public:
    ~ComputerPlayer(){cout << "a computer Player object has been realsed" << endl;}
    void notification(string s){
        cout << "A computer player is notified: " << s <<  endl;
    }
};

class switchPlayer : public Client
{
    public:
    ~switchPlayer(){cout << "a switch Player object has been realsed" << endl;}
    void notification(string s){
        cout << "A switch player is notified: " << s << endl;
    }
};

class ShoppingHouse
{
    vector<Client*> Cli;

    public:

    void addClient(Client *c){
        Cli.push_back(c);
    } 

    bool checkClientList(){
        if(Cli.size() != 0)
            return true;
        else 
            return false;
    }

    void removeClient(Client *c){
        for(auto i = Cli.begin(); i <=Cli.end(); i++){
            if(*i == c){
                Cli.erase(i);   
                // delete c;  //somehow don't know why this object can't be realsed manually
                break;
            }
        }
    }

    void notificationClients(string s){
        for_each(Cli.begin(),Cli.end(),[s](Client *c){c->notification(s);});
        }
};

// class ContainerFactory
// {
//     int a[6] = 
//     public:
//     vector<int> getContainer(int in){
//         ve
//     }

// };
template<class T>
class NonModifiedTester
{
    vector<T> v;
    deque<T> d;
    // array<T> a;
    list<T> l;
    queue<T> q;
    stack<T> s;

    public:
    NonModifiedTester(vector<T> v1){
        v = v1;
    }
    NonModifiedTester(deque<T> d1){
        d = d1;
    }
    // NonModifiedTester(array a1){
    //     a = a1;
    // }
    NonModifiedTester(list<T> l1){
        l = l1;
    }
    NonModifiedTester(queue<T> q1){
        q = q1;
    }
    NonModifiedTester(stack<T> s1){
        s = s1;
    }

    // for_each();
};

template<class T>
void containerPrinter(T t){
    cout << "There are all elements of this container now: ";
    for_each(begin(t),end(t),[](int x){cout << x << " ";});
    cout << endl;
}

template<class T>
void initailizeContainer(T t){
    fill(begin(t),end(t),0);
}

template<class T>
void initailizeSortedContainer(T t){
    sort(begin(t),end(t));
}

    //classic solution 
    void foo1(char const* x){
        if(x) cout <<"This is print with pointer: " << *x <<endl;
    }
    //C++17 solution with optional container
    void foo2(optional<char> x){
        if(x) cout <<"This is print with optional: "<< *x <<endl;
    }
    tuple<double,int,int> foo3(int x){
        return {x*2,x*3,x*4};
    }
    struct A {
        double a;
        int b,c;
    };
    A foo4(int x){
        return {x*2,x*3,x*4};
    }

int main()
{
    cout << "This is a practicing file for standard container library" << endl;

    int a = 1 , b = 2;
    int *p1 = &a, *p2 = &b;

    cout << "The number of p1 is " << p1 << ". The number of p2 is " << p2 << endl;

    p2 = p1;

    bool bl = p1!=p2; 

    cout << "After changing p2's number. The number of p2 is " << p2 <<
     " And we will find if they are equal. The result is " << bl << endl;

    switchPlayer sw1, sw2, sw3;
    ComputerPlayer cp1, cp2 , cp3;

    ShoppingHouse Shop;

    Shop.addClient(&sw1);
    Shop.addClient(&sw2);
    Shop.addClient(&sw3);

    Shop.addClient(&cp1);
    Shop.addClient(&cp2);
    Shop.addClient(&cp3);

    Shop.notificationClients("The first notification");

    cout << "--After changing--" << endl;

    Shop.removeClient(&cp2); 

    Shop.notificationClients("The second notification");

    int capicity = std::experimental::fundamentals_v2::randint(9,12);
    //Initial all the containers 
    vector<int> V,V2,V3;
    deque<int> D,D2,D3;
    list<int> L,L2,L3;
    forward_list<int> FL1,FL2;
    set<int> S,S2;

    for(int i = 0 ; i <= capicity; i++)
    {V.push_back(rand()%100);
    D.push_back(rand()%100);
    L.push_back(rand()%100);
    FL1.push_front(rand()%100);
    S.insert(rand()%100);}
    // map<int> V {2,4,3,6,7,1,8};

    V2.resize(V.size());
    D2.resize(D.size());
    L2.resize(L.size());
    // S2.resize(S.size());
    // FL2.resize(FL1.size());

    V3.resize(2*V.size());
    D3.resize(2*D.size());
    L3.resize(2*L.size());

    //Printing all elements of container with traserval method
    cout << "Those are all elements of vector: ";
    for(auto i = begin(V);i < end(V);i++){
        cout << *i << " ";
    };
    cout  << endl << "Those are all elements of deque: ";
    for_each(begin(D),end(D),[](int x){cout << x << " ";});
    cout  << endl << "Those are all elements of list: ";
    for_each_n(begin(L),7,[](int x){cout << x  << " "; });
    cout  << endl << "Those are all reversed sorted elements of forward list: ";
    for_each(begin(FL1),end(FL1),[](int x){cout << x  << " ";});
    cout  << endl << "Those are all elements of set: ";
    for_each(begin(S),end(S),[](int x){cout << x  << " ";});

/*Finding elements residing in container and qurying the existence of elements in specified container*/
    //If you want to find the last element it find you can call find_lat()/find_last_if()/find_last_if_not().The find method only return the first element that it find or it will return the end(). 
    cout<< "Can we find a value from the container V:" << *find(begin(V),end(V),9) << endl; 
    cout<< "Can we find a value from the container D:" << *find(begin(D),end(D),9) << endl; 
    cout<< "Can we find a value from the container L:" << *find(begin(L),end(L),9) << endl; 
     //If you call find method in algorithm with the paraments of method begin() and end() somehow it can't work like other sequence containers
    cout<< "Can we find a value from the container S:" << *find(begin(S),end(S),9) << endl; 

    cout<< "Can we find_if a value from the container V:" << *find_if(begin(V),end(V),[](int x){if(x < 9) return true; else return false;}) << endl; 
    cout<< "Can we find_if a value from the container D:" << *find_if(begin(D),end(D),[](int x){if(x < 9) return true; else return false;}) << endl; 
    cout<< "Can we find_if a value from the container L:" << *find_if(begin(L),end(L),[](int x){if(x < 9) return true; else return false;}) << endl; 
    // cout<< "Can we find_if a value from the container FL1:" << *find_if(begin(FL1),end(FL1),[](int x){if(x < 9) return true; else return false;}) << endl; 
    // cout<< "Can we find_if a value from the container S:" << *S.find_if(9) << endl; //There is no find_if method in container set

    //We don't have to show how the find_if_not works

    cout<< "Can we find any value from a set from the container V:" << *find_first_of(begin(V),end(V),begin(V)+4,end(V)) << endl; 
    cout<< "Can we find any value from a set from the container D:" << *find_first_of(begin(D),end(D),begin(D)+4,end(D)) << endl; 
    // cout<< "Can we find any value from a set from the container L:" << *find_first_of(begin(L),end(L),begin(L)+4,end(L)) << endl; 
    // cout<< "Can we find any value from a set from the container S:" << *find_first_of(begin(S),end(S),begin(S)+4,end(S)) << endl; 

    //Different from find_first_of(),search() can match a range of a container and return the first element location of the matched range
    cout<< "Can we find any value from a set from the container V:" << *search(begin(V),end(V),begin(V)+4,end(V)) << endl; 
    cout<< "Can we find any value from a set from the container D:" << *search(begin(D),end(D),begin(D)+4,end(D)) << endl; 
    // cout<< "Can we find any value from a set from the container L:" << *search(begin(L),end(L),begin(L)+4,end(L)) << endl; 
    // cout<< "Can we find any value from a set from the container S:" << *search(begin(S),end(S),begin(S)+4,end(S)) << endl; 

    //we don't have to show how the find_end() works because it is search() that find the subrange from tail

    //starts_with() from c++23 find the subrange begin with it. Same as ends_with();

    cout<< "Can we find adjacent element from the container V:" << *adjacent_find(begin(V),end(V)) << endl; 
    cout<< "Can we find adjacent element from the container D:" << *adjacent_find(begin(D),end(D)) << endl; 
    cout<< "Can we find adjacent element from the container L:" << *adjacent_find(begin(L),end(L)) << endl; 
    cout<< "Can we find adjacent element from the container S:" << *adjacent_find(begin(S),end(S)) << endl; 

    //To find out numbers of adjacent Specified elements 
    cout<< "Can we find adjacent element from the container V:" << *search_n(begin(V),end(V),3,2) << endl; 
    cout<< "Can we find adjacent element from the container D:" << *search_n(begin(D),end(D),3,2) << endl; 
    cout<< "Can we find adjacent element from the container L:" << *search_n(begin(L),end(L),3,2) << endl; 
    cout<< "Can we find adjacent element from the container S:" << *search_n(begin(S),end(S),3,2) << endl; 

    //qurying existence with method any_of / all_of / none_of()
    cout<< "Can we find adjacent element from the container V:" << all_of(begin(V),end(V),[](int x){if(x>=1) return true; else return false;}) << endl; 
    cout<< "Can we find adjacent element from the container D:" << all_of(begin(D),end(D),[](int x){if(x>=1) return true; else return false;}) << endl; 
    cout<< "Can we find adjacent element from the container L:" << all_of(begin(L),end(L),[](int x){if(x>=1) return true; else return false;}) << endl; 
    cout<< "Can we find adjacent element from the container S:" << all_of(begin(S),end(S),[](int x){if(x>=1) return true; else return false;}) << endl; 

    //count()    
    cout<< "Can we count the nember of element satifying the condition from the container V:" << count_if(begin(V),end(V),[](int x){if(x>=1) return true; else return false;}) << endl; 
    cout<< "Can we count the nember of element satifying the condition from the container D:" << count_if(begin(D),end(D),[](int x){if(x>=1) return true; else return false;}) << endl; 
    cout<< "Can we count the nember of element satifying the condition from the container L:" << count_if(begin(L),end(L),[](int x){if(x>=1) return true; else return false;}) << endl; 
    cout<< "Can we count the nember of element satifying the condition from the container S:" << count_if(begin(S),end(S),[](int x){if(x>=1) return true; else return false;}) << endl; 

    cout<< "Can we count the nember of specified element from the container V:" << count(begin(V),end(V),4) << endl; 
    cout<< "Can we count the nember of specified element from the container D:" << count(begin(D),end(D),4) << endl; 
    cout<< "Can we count the nember of specified element from the container L:" << count(begin(L),end(L),4) << endl; 
    cout<< "Can we count the nember of specified element from the container S:" << count(begin(S),end(S),4) << endl; 

/*minimum/maximum and we can add our modified function as a argument in the third place of min/max/minmax()*/
    
    cout<< "Can we find the minimum nember:" << min(*begin(V),*end(V)) << endl; 
    cout<< "Can we find the minimum nember:" << min(*begin(D),*end(D)) << endl; 
    cout<< "Can we find the minimum nember:" << min(*begin(L),*end(L)) << endl; 
    cout<< "Can we find the minimum nember:" << min(*begin(S),*end(S)) << endl; 


    cout<< "Can we find the max nember from V:" << max(*begin(V),*end(V)) << endl; 
    cout<< "Can we find the max nember from D:" << max(*begin(D),*end(D)) << endl; 
    cout<< "Can we find the max nember from L:" << max(*begin(L),*end(L)) << endl; 
    cout<< "Can we find the max nember from S:" << max(*begin(S),*end(S)) << endl; 


    cout<< "Can we find the minmax nember from V:" << minmax(*begin(V),*end(V)).first <<" "<< minmax(*begin(V),*end(V)).second << endl; 
    cout<< "Can we find the minmax nember from D:" << minmax(*begin(D),*end(D)).first <<" "<< minmax(*begin(D),*end(D)).second << endl; 
    cout<< "Can we find the minmax nember from L:" << minmax(*begin(L),*end(L)).first <<" "<< minmax(*begin(L),*end(L)).second << endl; 
    cout<< "Can we find the minmax nember from S:" << minmax(*begin(S),*end(S)).first <<" "<< minmax(*begin(S),*end(S)).second << endl; 


    cout<< "Can we find the clamp nember from the container V:" << clamp(*begin(V),*end(V),4) << endl; 
    cout<< "Can we find the clamp nember from the container D:" << clamp(*begin(D),*end(D),4) << endl; 
    cout<< "Can we find the clamp nember from the container L:" << clamp(*begin(L),*end(L),4) << endl; 
    cout<< "Can we find the clamp nember from the container S:" << clamp(*begin(S),*end(S),4) << endl; 


    cout<< "Can we find the min_elementimum nember:" << *min_element(begin(V),end(V)) << endl; 
    cout<< "Can we find the min_elementimum nember:" << *min_element(begin(D),end(D)) << endl; 
    cout<< "Can we find the min_elementimum nember:" << *min_element(begin(L),end(L)) << endl; 
    cout<< "Can we find the min_elementimum nember:" << *min_element(begin(S),end(S)) << endl; 


    cout<< "Can we find the max_element nember from V:" << *max_element(begin(V),end(V)) << endl; 
    cout<< "Can we find the max_element nember from D:" << *max_element(begin(D),end(D)) << endl; 
    cout<< "Can we find the max_element nember from L:" << *max_element(begin(L),end(L)) << endl; 
    cout<< "Can we find the max_element nember from S:" << *max_element(begin(S),end(S)) << endl; 


    cout<< "Can we find the minmax_element nember from V:" << *minmax_element(begin(V),end(V)).first <<" "<< *minmax_element(begin(V),end(V)).second << endl; 
    cout<< "Can we find the minmax_element nember from D:" << *minmax_element(begin(D),end(D)).first <<" "<< *minmax_element(begin(D),end(D)).second << endl; 
    cout<< "Can we find the minmax_element nember from L:" << *minmax_element(begin(L),end(L)).first <<" "<< *minmax_element(begin(L),end(L)).second << endl; 
    cout<< "Can we find the minmax_element nember from S:" << *minmax_element(begin(S),end(S)).first <<" "<< *minmax_element(begin(S),end(S)).second << endl; 

/*Comparison a range of elements*/
    //equal() method support to type in the only begin(), or a pair of begin(),end() from the subrange
    cout<< "Can we find the completely equal range to V:" << equal(begin(V),end(V),begin(V)+3) << endl; 
    cout<< "Can we find the completely equal range to D:" << equal(begin(D),end(D),begin(D)+3) << endl; 
    cout<< "Can we find the completely equal range to L:" << equal(begin(L),end(L),begin(V)+3) << endl;  //there is no matched + operation for container List
    cout<< "Can we find the completely equal range to S:" << equal(begin(S),end(S),begin(D)+3) << endl;  //there is no matched + operation for container Set

    //mismatch() method  support to type in the only begin(), or a pair of begin(),end() from the subrange
    cout<< "Can we find the mismatch element in V:" << *mismatch(begin(V),end(V),begin(V)+3).first << " " << *mismatch(begin(V),end(V),begin(V)+3).second << endl; 
    cout<< "Can we find the mismatch element in D:" << *mismatch(begin(D),end(D),begin(D)+3).first << " " << *mismatch(begin(D),end(D),begin(D)+3).second << endl; 
    cout<< "Can we find the mismatch element in L:" << *mismatch(begin(L),end(L),begin(V)+3).first << " " << *mismatch(begin(L),end(L),begin(V)+3).second << endl;  //there is no matched + operation for container List
    cout<< "Can we find the mismatch element in S:" << *mismatch(begin(S),end(S),begin(D)+3).first << " " << *mismatch(begin(S),end(S),begin(D)+3).second << endl;  //there is no matched + operation for container Set

    cout<< "Can we find the lexicographical_compare result in V:" << lexicographical_compare(begin(V),end(V),begin(V)+3,end(V)) << endl; 
    cout<< "Can we find the lexicographical_compare result in D:" << lexicographical_compare(begin(D),end(D),begin(D)+3,end(D)) << endl; 
    cout<< "Can we find the lexicographical_compare result in L:" << lexicographical_compare(begin(L),end(L),begin(V)+3,end(V)) << endl;  //there is no matched + operation for container List
    cout<< "Can we find the lexicographical_compare result in S:" << lexicographical_compare(begin(S),end(S),begin(D)+3,end(D)) << endl;  //there is no matched + operation for container Set

    //lexicographical_compare_three_way() is available in c++20 somehow it is not available in there;
    // cout<< "Can we find the completely lexicographical_compare_three_way range to V:" << lexicographical_compare_three_way(begin(V),end(V),begin(V)+3,end(V)) << endl; 
    // cout<< "Can we find the completely lexicographical_compare_three_way range to D:" << lexicographical_compare_three_way(begin(D),end(D),begin(D)+3,end(D)) << endl; 
    // cout<< "Can we find the completely lexicographical_compare_three_way range to L:" << lexicographical_compare_three_way(begin(L),end(L),begin(V)+3,end(V)) << endl;  //there is no matched + operation for container List
    // cout<< "Can we find the completely lexicographical_compare_three_way range to S:" << lexicographical_compare_three_way(begin(S),end(S),begin(D)+3,end(D)) << endl;  //there is no matched + operation for container Set

/*Modifying elements: Copying and moving the element in container*/
    containerPrinter(V2);
    cout<< "Copying the element in V to V2:" << *copy(begin(V),end(V),begin(V2)) << endl; 
    containerPrinter(V2);
    containerPrinter(D2);
    cout<< "Copying the element in D to D2:" << *copy(begin(D),end(D),begin(D2)) << endl; 
    containerPrinter(D2);
    containerPrinter(L2);
    cout<< "Copying the element in L to L2:" << *copy(begin(L),end(L),begin(L2)) << endl;  //there is no matched + operation for container List
    containerPrinter(L2);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);


    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    containerPrinter(V2);
    cout<< "Copying the element in V to V2:" << *copy(begin(V),end(V),begin(V2)) << endl; 
    containerPrinter(V2);
    containerPrinter(D2);
    cout<< "Copying the element in D to D2:" << *copy(begin(D),end(D),begin(D2)) << endl; 
    containerPrinter(D2);
    containerPrinter(L2);
    cout<< "Copying the element in L to L2:" << *copy(begin(L),end(L),begin(L2)) << endl;  //there is no matched + operation for container List
    containerPrinter(L2);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);

    //we don't have to show how copy_n(begin,n,target_begin) works

    //we don't have to show how copy_backward(begin,end,target_end) works begin with the @end location not reserve

    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    containerPrinter(V2);
    cout<< "Copying the element satifying specified condition in V to V2:" << *copy_if(begin(V),end(V),begin(V2),[](int x){if(x>=1) return true; else return false;}) << endl; 
    containerPrinter(V2);
    containerPrinter(D2);
    cout<< "Copying the element satifying specified condition in D to D2:" << *copy_if(begin(D),end(D),begin(D2),[](int x){if(x>=1) return true; else return false;}) << endl; 
    containerPrinter(D2);
    containerPrinter(L2);
    cout<< "Copying the element satifying specified condition in L to L2:" << *copy_if(begin(L),end(L),begin(L2),[](int x){if(x>=1) return true; else return false;}) << endl;  //there is no matched + operation for container List
    containerPrinter(L2);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);

    
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    // auto const seed = std::random_device{}();
    // auto reng = std::mt19937{seed};

    containerPrinter(V2);
    cout<< "Copying the element satifying specified condition in V to V2:" << *sample(begin(V),end(V),begin(V2),4,std::mt19937 {std::random_device{}()}) << endl; 
    containerPrinter(V2);
    containerPrinter(D2);
    cout<< "Copying the element satifying specified condition in D to D2:" << *sample(begin(D),end(D),begin(D2),4,std::mt19937 {std::random_device{}()}) << endl; 
    containerPrinter(D2);
    containerPrinter(L2);
    cout<< "Copying the element satifying specified condition in L to L2:" << *sample(begin(L),end(L),begin(L2),4,std::mt19937 {std::random_device{}()}) << endl;  //there is no matched + operation for container List
    containerPrinter(L2);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);
    
    
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    // auto const seed = std::random_device{}();
    // auto reng = std::mt19937{seed};

    containerPrinter(V);
    reverse(begin(V),end(V) ) ; 
    containerPrinter(V);
    containerPrinter(D);
    reverse(begin(D),end(D)) ; 
    containerPrinter(D);
    containerPrinter(L);
    reverse(begin(L),end(L));  
    containerPrinter(L);
    // containerPrinter(S);
    // reverse(begin(S),end(S)) ;  //there is no reverse() for container set operation for container List
    // containerPrinter(S);

    //we don't have to show reverse_copy(@begin,@end,@out) output  @out_end
    
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    // auto const seed = std::random_device{}();
    // auto reng = std::mt19937{seed};

    containerPrinter(V);
    cout<< "rotating the container V :" << *rotate(begin(V),begin(V)+3,end(V) ) << endl; 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "rotating the container D :" << *rotate(begin(D),begin(D)+3,end(D)) << endl; 
    containerPrinter(D);
    containerPrinter(L);
    cout<< "rotating the container L :" << *rotate(begin(L),end(L),end(L)) << endl;  //there is no matched + operation for container List
    containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);

    //we don't have to show reverse_copy(@begin,@new_begin,@end,@out) output  @out_end
   
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    // containerPrinter(V);
    // cout<< "shift_righting the container V :" << *shift_right(begin(V),end(V),2) << endl; 
    // containerPrinter(V);
    // containerPrinter(D);
    // cout<< "shift_righting the container D :" << *shift_right(begin(D),end(D),2) << endl; 
    // containerPrinter(D);
    // containerPrinter(L);
    // cout<< "shift_righting the container L :" << *shift_right(begin(L),end(L),2) << endl;  
    // containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "shift_righting the container S :" << *shift_right(begin(S),end(S),2) << endl;  //there is no shift_right() for container set
    // containerPrinter(S2);
   
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    containerPrinter(V);
    cout<< "shuffling the container V :" << endl;
    shuffle(begin(V),end(V),std::mt19937 {std::random_device{}()}); 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "shuffling the container D :" << endl;
    shuffle(begin(D),end(D),std::mt19937 {std::random_device{}()}); 
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "shuffling the container L :"  << endl;
    // shuffle(begin(L),end(L),std::mt19937 {std::random_device{}()});  //Due to shuffle() was implemented with operator-, there is no matched operator- for container List 
    // containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);
   
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    //in sort() you can add your own modified method at the last parameter lacation
    containerPrinter(V);
    cout<< "sorting the container V :" << endl;
    sort(begin(V),end(V),[](int x,int y){if(x <= y) return true; else return false;}); 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "sorting the container D :" << endl;
    sort(begin(D),end(D)); 
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "sorting the container L :" << endl;
    // sort(begin(L),end(L));  //Due to sort() was implemented with operator-, there is no matched operator- for container List 
    // containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);

    //stable_sort() has same parameters as sort() but "stable" = preserves the relative order of equivalent elements

    //is_sorted(@begin,@end,@compare(o,o)) the function parameter is optional and this method can check if your container is sorted

    //is_sorted_until(@begin,@end,@compare(o,o)) almost same as is_sorted() but return @sorted_end
   
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    //in partial_partial_sort() you can add your own modified method at the last parameter lacation
    containerPrinter(V);
    cout<< "partial_sorting the container V :" << endl;
    partial_sort(begin(V),begin(V)+4,end(V),[](int x,int y){if(x <= y) return true; else return false;}); 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "partial_sorting the container D :" << endl;
    partial_sort(begin(D),begin(D)+4,end(D)); 
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "sorting the container L :" << endl;
    // sort(begin(L),end(L));  //Due to sort() was implemented with operator-, there is no matched operator- for container List 
    // containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);

    //we don't have to show partial_partial_sort(@begin,@end,@out_begin,@out_end) output  @out_end

    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    //in nth_element() you will get the number is less than @nth and in the right side number is bigger than @nth
    containerPrinter(V);
    cout<< "nth_elementing the container V :" << endl;
    nth_element(begin(V),begin(V)+4,end(V)); 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "nth_elementing the container D :" << endl;
    nth_element(begin(D),begin(D)+4,end(D)); 
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "sorting the container L :" << endl;
    // sort(begin(L),end(L));  //Due to sort() was implemented with operator-, there is no matched operator- for container List 
    // containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);

    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    //in partition() the first block in the returning container is satified with the condition
    containerPrinter(V);
    cout<< "partitioning the container V :" << endl;
    partition(begin(V),end(V),[](int x){if(x%2) return true; else return false;}); 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "partitioning the container D :" << endl;
    partition(begin(D),end(D),[](int x){if(x%2) return true; else return false;}); 
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "sorting the container L :" << endl;
    // sort(begin(L),end(L));  //Due to sort() was implemented with operator-, there is no matched operator- for container List 
    // containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);

    //we don't have to show partition_copy(@begin,@end,@out_true,@out_false,f(o)) output  {@out_true,@out_false}

    //we don't have to show stable_partition(@begin,@end,f(o)) output  @true_end

    //we don't have to show is_partitioned(@begin,@end,f(o)) output  bool

    //we don't have to show partition_point(@begin,@end,f(o)) output  @f_true_end

    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    containerPrinter(V);
    cout<< "prev_permutationing the container V :" << prev_permutation(begin(V),end(V)) << endl;
    containerPrinter(V);
    containerPrinter(D);
    cout<< "prev_permutationing the container D :" << prev_permutation(begin(D),end(D)) <<endl;
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "sorting the container L :" << endl;
    // sort(begin(L),end(L));  //Due to sort() was implemented with operator-, there is no matched operator- for container List 
    // containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << *copy(begin(S),end(S),begin(S2)) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);

    //we don't have to show next_permutation(@begin,@end) output  bool

    //we don't have to show is_permutation(@begin,@end,@out_begin) output  bool

    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

/*Replacing and transforming elements in specified container*/

    containerPrinter(V);
    cout<< "filling the container V :" << endl;
    fill(begin(V),end(V),3); 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "filling the container D :" << endl;
    fill(begin(D),end(D),3); 
    containerPrinter(D);
    containerPrinter(L);
    cout<< "filling the container L :" << endl;
    fill(begin(L),end(L),3);  //Due to fill() was implemented with operator-, there is no matched operator- for container List 
    containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << endl;
    // fill(begin(S),end(S),3);  //there is no matched + operation for container Set
    // containerPrinter(S2);

    //we don't have to show fill_n(@begin,n,value) output  @fill_end

    
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    auto gen = [i=0]() mutable { i += 2; return i; };
    //     init-^^^    ^^^^^^^⇒ member 'i' changeable

    containerPrinter(V);
    cout<< "generateing the container V :" << endl;
    generate(begin(V),end(V),gen); 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "generateing the container D :" << endl;
    generate(begin(D),end(D),gen); 
    containerPrinter(D);
    containerPrinter(L);
    cout<< "generateing the container L :" << endl;
    generate(begin(L),end(L),gen);  //Due to generate() was implemented with operator-, there is no matched operator- for container List 
    containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << endl;
    // generate(begin(S),end(S),gen);  //there is no matched + operation for container Set
    // containerPrinter(S2);

    //we don't have to show generate_n(@begin,n,generator()) output  @generated_end

    
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    containerPrinter(V);
    cout<< "transform the container V :" << *transform(begin(V),end(V),begin(V2),[](int x){return x*2;}) << endl;
    containerPrinter(V2);
    containerPrinter(D);
    cout<< "transform the container D :" << *transform(begin(D),end(D),begin(D2),[](int x){return x*2;}) <<endl;
    containerPrinter(D2);
    containerPrinter(L);
    cout<< "sorting the container L :" << *transform(begin(L),end(L),begin(L2),[](int x){return x*2;}) << endl;  //Due to sort() was implemented with operator-, there is no matched operator- for container List 
    containerPrinter(L2);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << *transform(begin(S),end(S),begin(S2),[](int x){return x*2;}) << endl;  //there is no matched + operation for container Set
    // containerPrinter(S2);

    
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    containerPrinter(V);
    cout<< "replaceing the container V :" << endl;
    replace(begin(V),end(V),3,14); 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "replaceing the container D :" << endl;
    replace(begin(D),end(D),3,14); 
    containerPrinter(D);
    containerPrinter(L);
    cout<< "replaceing the container L :" << endl;
    replace(begin(L),end(L),3,14);    
    containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << endl;
    // replace(begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S2);

    //we don't have to show replace(@begin,@end,f(o)->bool,new_value) output @out_begin

    //we don't have to show replace_copy(@begin,@end,@out,old_value,new_value) output @out_end

    //we don't have to show replace_copy_if(@begin,@end,@out,f(o)->bool,new_value) output @out_end

/*Removing elements in specified container*/
    
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    /* remove() and remove_if() only move the remaining elements to the front of the input 
    range and don't resize containers or deallocate memory.
    If you want to also modify the containing object, e.g., resize/shrink it*/
    containerPrinter(V);
    cout<< "remove the container V :" << *remove(begin(V),end(V),2)<< endl; 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "remove the container D :" << *remove(begin(D),end(D),2)<< endl; 
    containerPrinter(D);
    containerPrinter(L);
    cout<< "remove the container L :" << *remove(begin(L),end(L),2)<< endl;   
    containerPrinter(L);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // remove(begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    //we don't have to show remove_if(@begin,@end,f(o)->bool) output @remaining_end

    //we don't have to show remove_copy(@begin,@end,@out,value) output @out_end 
    //but The output target must be able to receive as many elements as there are in the input range.

    //we don't have to show remove_copy_if(@begin,@end,@out,f(o)->bool) output @out_end

 
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    /*unique() and unique_copy() only move the remaining elements to the front of the input 
    range and don't resize containers or deallocate memory.
    If you want to also modify the containing object, e.g., resize/shrink it*/
    containerPrinter(V);
    cout<< "unique the container V :" << *unique(begin(V),end(V))<< endl; 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "unique the container D :" << *unique(begin(D),end(D))<< endl; 
    containerPrinter(D);
    containerPrinter(L);
    cout<< "unique the container L :" << *unique(begin(L),end(L))<< endl;   
    containerPrinter(L);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // unique(begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    //we don't have to show unique_copy(@begin,@end,@out) output @out_end 

    
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    //erase() will resize the cantainer
    // containerPrinter(V);
    // cout<< "the number of elements erased in the container V :" << erase(V,4)<< endl; 
    // containerPrinter(V);
    // containerPrinter(D);
    // cout<< "the number of elements erased in the container D :" << erase(D,4)<< endl; 
    // containerPrinter(D);
    // containerPrinter(L);
    // cout<< "the number of elements erased in the container L :" << erase(L,4)<< endl;   
    // containerPrinter(L);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // erase(begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

/*numberic operations*/

    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    //iota() will fills the range [first, last) with sequentially increasing values, starting with value and repetitively evaluating ++value 
    containerPrinter(V);
    cout<< "iotaing the container V :" << endl;
    iota(begin(V),end(V),3); 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "iotaing the container D :" << endl;
    iota(begin(D),end(D),3); 
    containerPrinter(D);
    containerPrinter(L);
    cout<< "iotaing the container L :" << endl;
    iota(begin(L),end(L),3);    
    containerPrinter(L);
    // containerPrinter(S2);
    // cout<< "Copying the element in S to S2:" << endl;
    // iota(begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S2);

    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    containerPrinter(V);
    cout<< "get the sum of container V :" << reduce(begin(V),end(V)) << endl; 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "get the sum of container D :" << reduce(begin(D),end(D),3) << endl; 
    containerPrinter(D);
    containerPrinter(L);
    cout<< "get the sum of container L :" << reduce(begin(L),end(L),5,std::multiplies<>{}) << endl;   
    containerPrinter(L);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // reduce(begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    //we don't have to show transform_reduce(@begin,@end,w,binary_op,f(o)) output Rf. you will get the result of the ranges under the operation after transformation

    //accumulate() almsotly equal to reduce() and inner_product almost equal to tranfom_reduce() but they are too old-fashion and no parallel execution possible 

    
    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    /*adjacent_difference() will fill the target container with the difference of two adjacent elements 
    in source container by default minus operation. 
    and you can add your modified binary operator which can't have side effects and can't be stateful. */
    containerPrinter(V);
    cout<< "adjacent_difference  the container V :" << *adjacent_difference (begin(V),end(V),begin(V2))<< endl; 
    containerPrinter(V2);
    containerPrinter(D);
    cout<< "adjacent_difference  the container D :" << *adjacent_difference (begin(D),end(D),begin(D2),plus<>{})<< endl; 
    containerPrinter(D2);
    containerPrinter(L);
    cout<< "adjacent_difference  the container L :" << *adjacent_difference (begin(L),end(L),begin(L2),multiplies<>{})<< endl;   
    containerPrinter(L2);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // adjacent_difference (begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    containerPrinter(V);
    cout<< "inclusive_scan  the container V :" << *inclusive_scan (begin(V),end(V),begin(V2))<< endl; 
    containerPrinter(V2);
    containerPrinter(D);
    cout<< "inclusive_scan  the container D :" << *inclusive_scan (begin(D),end(D),begin(D2),plus<>{})<< endl; 
    containerPrinter(D2);
    containerPrinter(L);
    cout<< "inclusive_scan  the container L :" << *inclusive_scan (begin(L),end(L),begin(L2),multiplies<>{},3)<< endl;   
    containerPrinter(L2);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // inclusive_scan (begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    //we don't have to show transform_inclusive_scan(@begin,@end,@out_begin,⊕,f(o),w) output @out_end.

    //partial_sum() almsotly equal to inclusive_scan() but is too old-fashion and no parallel execution possible 


    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    //The binary operation ⊕ must be associative because the order in which it is applied is not guaranteed.
    containerPrinter(V);
    cout<< "exclusive_scan  the container V :" << *exclusive_scan (begin(V),end(V),begin(V2),3)<< endl; 
    containerPrinter(V2);
    containerPrinter(D);
    cout<< "exclusive_scan  the container D :" << *exclusive_scan (begin(D),end(D),begin(D2),3,plus<>{})<< endl; 
    containerPrinter(D2);
    containerPrinter(L);
    cout<< "exclusive_scan  the container L :" << *exclusive_scan (begin(L),end(L),begin(L2),3,multiplies<>{})<< endl;   
    containerPrinter(L2);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // exclusive_scan (begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    //we don't have to show transform_exclusive_scan(@begin,@end,@out_begin,w,⊕,f(o)) output @out_end.

/*Sorted Sequence Operations*/

    //Precondition: Input sequences must be sorted. This is not checked by any of the sorted sequence algorith

    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method
    initailizeSortedContainer(V);
    initailizeSortedContainer(D);
    // initailizeSortedContainer(L); //no match for 'operator-' (operand types are 'std::_List_iterator<int>' and 'std::_List_iterator<int>')

    containerPrinter(V);
    cout<< "binary_search  the container V :" << binary_search(begin(V),end(V),3)<< endl; 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "binary_search  the container D :" << binary_search(begin(D),end(D),3,[](int x,int y){if(x < y) return true; else return false;})<< endl; 
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "binary_search  the container L :" << binary_search(begin(L),end(L),3,[](int x){if(x < 9) return true; else return false;})<< endl;   
    // containerPrinter(L2);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // binary_search (begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    containerPrinter(V);
    cout<< "lower_bound  the container V :" << *lower_bound(begin(V),end(V),3)<< endl; 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "lower_bound  the container D :" << *lower_bound(begin(D),end(D),3)<< endl; 
    containerPrinter(D);

    containerPrinter(V);
    cout<< "upper_bound  the container V :" << *upper_bound(begin(V),end(V),3)<< endl; 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "upper_bound  the container D :" << *upper_bound(begin(D),end(D),3)<< endl; 
    containerPrinter(D);

    containerPrinter(V);
    cout<< "equal_range  the container V :" << *equal_range(begin(V),end(V),3).first<<" "<< *equal_range(begin(V),end(V),3).second<< endl; 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "equal_range  the container D :" << *equal_range(begin(D),end(D),3).first <<" "<<*equal_range(begin(D),end(D),3).second<< endl; 
    containerPrinter(D);

    containerPrinter(V);
    cout<< "includes  the container V :" << includes(begin(V),end(V),begin(V2),end(V2))<< endl; 
    containerPrinter(V2);
    containerPrinter(D);
    cout<< "includes  the container D :" << includes(begin(D),end(D),begin(D2),end(D2))<< endl; 
    containerPrinter(D2);

    //Two sorted sequences can be merged into one sorted sequence in linear time.
    containerPrinter(V);
    containerPrinter(V2);
    cout<< "merge  the container V and v2:" << *merge(begin(V),end(V),begin(V2),end(V2),begin(V3))<< endl; 
    containerPrinter(V3);
    containerPrinter(D);
    containerPrinter(D2);
    cout<< "merge  the container D and D2:" << *merge(begin(D),end(D),begin(D2),end(D2),begin(D3))<< endl; 
    containerPrinter(D3);

    containerPrinter(V);
    cout<< "inplace_merge  the container V :" << endl; 
    inplace_merge(begin(V),begin(V)+3,end(V));
    containerPrinter(V2);
    containerPrinter(D);
    cout<< "inplace_merge  the container D :"<< endl; 
    inplace_merge(begin(D),begin(D)+3,end(D),[](int x,int y){if(x>=y) return true; else return false;}); 
    containerPrinter(D2);

    //Set operations like union, intersection, etc. can be performed in linear time on sorted lists and thus faster than on unsorted lists.
    containerPrinter(V);
    containerPrinter(V2);
    cout<< "set_union  the container V and v2:" << *set_union(begin(V),end(V),begin(V2),end(V2),begin(V3))<< endl; 
    containerPrinter(V3);
    containerPrinter(D);
    containerPrinter(D2);
    cout<< "set_union  the container D and D2:" << *set_union(begin(D),end(D),begin(D2),end(D2),begin(D3),[](int x,int y){if(x>=y) return true; else return false;})<< endl; 
    containerPrinter(D3);

    //we don't have to show set_intersection(@begin,@end,@begin2,@end2,@out_begin,f(o,o)->bool(optinal)) output @out_end.

    //we don't have to show set_difference(@begin,@end,@begin2,@end2,@out_begin,f(o,o)->bool(optinal)) output @out_end.

    //we don't have to show set_symmetric_difference(@begin,@end,@begin2,@end2,@out_begin,f(o,o)->bool(optinal)) output @out_end.

/*Binary Heap Operations*/

    /*Supported operations typically include
    get maximum usually in O(1) (constant time)
    remove maximum usually in O(log N) (logarithmic time)
    insert new key usually in O(1) or O(log N)
    increase/decrease key change value of a key, usually in O(1) or O(log N)*/

    initailizeContainer(V2);
    initailizeContainer(D2);
    initailizeContainer(L2);
    initailizeContainer(FL2);
    // initailizeContainer(S2); //The set container doesn't have fill method

    //initialize the heap
    containerPrinter(V);
    cout<< "make_heap the container V :" << endl; 
    make_heap (begin(V),end(V));
    containerPrinter(V);
    containerPrinter(D);
    cout<< "make_heap the container D :" << endl; 
    make_heap (begin(D),end(D),[](int x,int y){if(x>=y) return true; else return false;}); 
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "make_heap the container L :" << endl; 
    // make_heap (begin(L),end(L),[](int x,int y){if(x>=y) return true; else return false;});   
    // containerPrinter(L);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // make_heap (begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    containerPrinter(V);
    cout<< "pop_heap the container V :" << endl; 
    pop_heap (begin(V),end(V));
    containerPrinter(V);
    containerPrinter(D);
    cout<< "pop_heap the container D :" << endl; 
    pop_heap (begin(D),end(D),[](int x,int y){if(x>=y) return true; else return false;}); 
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "pop_heap the container L :" << endl; 
    // pop_heap (begin(L),end(L),[](int x,int y){if(x>=y) return true; else return false;});   
    // containerPrinter(L);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // pop_heap (begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    containerPrinter(V);
    cout<< "push_heap the container V :" << endl; 
    push_heap (begin(V),end(V));
    containerPrinter(V);
    containerPrinter(D);
    cout<< "push_heap the container D :" << endl; 
    push_heap (begin(D),end(D),[](int x,int y){if(x>=y) return true; else return false;}); 
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "push_heap the container L :" << endl; 
    // push_heap (begin(L),end(L),[](int x,int y){if(x>=y) return true; else return false;});   
    // containerPrinter(L);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // push_heap (begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    containerPrinter(V);
    cout<< "sort_heap the container V :" << endl; 
    sort_heap (begin(V),end(V));
    containerPrinter(V);
    containerPrinter(D);
    cout<< "sort_heap the container D :" << endl; 
    sort_heap (begin(D),end(D),[](int x,int y){if(x>=y) return true; else return false;}); 
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "sort_heap the container L :" << endl; 
    // sort_heap (begin(L),end(L),[](int x,int y){if(x>=y) return true; else return false;});   
    // containerPrinter(L);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // sort_heap (begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);
    
    containerPrinter(V);
    cout<< "is_heap the container V :" << is_heap (begin(V),end(V))<< endl; 
    containerPrinter(V);
    containerPrinter(D);
    cout<< "is_heap the container D :" << is_heap (begin(D),end(D),[](int x,int y){if(x>=y) return true; else return false;})<< endl;
    containerPrinter(D);
    // containerPrinter(L);
    // cout<< "is_heap the container L :" << endl; 
    // is_heap (begin(L),end(L),[](int x,int y){if(x>=y) return true; else return false;});   
    // containerPrinter(L);
    // containerPrinter(S);
    // cout<< "Copying the element in S to S2:" << endl;
    // is_heap (begin(S),end(S),2);  //there is no matched + operation for container Set
    // containerPrinter(S);

    //We don't have to show how the is_heap_until(@begin,@end,compare(o,o)->bool(optional)) output @heap_end

/*Special Containers*/
    pair<int, double> pa {3,3.2};
    cout <<"Those are elements residing  in pair: "<< pa.first << " "<< pa.second<< endl;

    tuple<int,double,char,long> tu {5,3.1,'T',3421435};
    cout<< "Those are elements residing in tuple:" << get<0>(tu)<<" " << get<1>(tu)<<" "
    << get<2>(tu)<<" "<< get<3>(tu)<<endl;

    /*represents a value that might be available 
      intent clearly expressed as opposed to raw pointer (non-availablity indicated by nullptr)
      replace ptr in input parameter of a function or returning value of a function*/
    optional<char> op;
    char i = 1;
    
    foo1(&i);
    foo2(op);

    double dou1;
    int in1,in2;
    tie(dou1,in1,in2) = foo3(4);
    cout<< dou1 << " " << in1 << " " << in2 <<endl;
    auto [dou2,in3,in4] = foo3(5);
    cout<< dou2 << " " << in3 << " " << in4 <<endl;
    auto [dou3,in5,in6] = foo4(6);
    cout<< dou3 << " " << in5 << " " << in6 <<endl;

    /*can contain object of either T1 or T2 or T3
      has memory footprint of the largest type
      list of values of different types*/
    variant<int, double, vector<int>,char> var = 1;

    //I don't know how to tranversal it
    vector<variant<int, double, vector<int>,char>> vv {1, 3.2,vector<int>{1,2,5,2}};
    cout << "This is the container that contain many types of elements:" << get<0>(var);

    /*can contain object of any type
      actual type changeable at runtime*/
    std::any an = 1;
    vector<std::any> vec{1, 23.2, vector<double> {3.2,12.3}};

/*Special Iterator*/

    containerPrinter(V);
    insert_iterator<vector<int>> viit {V,begin(V)+1};
    *viit = 4;
    cout<< "using insert_iterator for container V :"<< endl; 
    back_insert_iterator<vector<int>> vbit {V};
    *vbit = 6;
    cout<< "using back_insert_iterator for container V :"<< endl; 
    // front_insert_iterator<vector<int>> vfit {V};
    // *vfit = 7;
    // cout<< "using front_insert_iterator for container V :"<< endl;  //'class std::set<int>' has no member named 'push_back'
    containerPrinter(V);
    containerPrinter(D);
    insert_iterator<deque<int>> diit {D,begin(D)+1};
    *diit = 4;
    cout<< "using insert_iterator for container D :"<< endl; 
    back_insert_iterator<deque<int>> dbit {D};
    *dbit = 6;
    cout<< "using back_insert_iterator for container D :"<< endl; 
    front_insert_iterator<deque<int>> dfit {D};
    *dfit = 7;
    cout<< "using front_insert_iterator for container D :"<< endl; 
    containerPrinter(D);
    containerPrinter(L);
    insert_iterator<list<int>> liit {L,begin(L)};
    *liit = 4;
    cout<< "using insert_iterator for container L :"<< endl; 
    back_insert_iterator<list<int>> lbit {L};
    *lbit = 6;
    cout<< "using back_insert_iterator for container L :"<< endl; 
    front_insert_iterator<list<int>> lfit {L};
    *lfit = 7;
    cout<< "using front_insert_iterator for container L :"<< endl;   
    containerPrinter(L);
    containerPrinter(S);
    insert_iterator<set<int>> siit {S,begin(S)};
    *siit = 4;
    cout<< "using insert_iterator for container S :"<< endl; 
    // back_insert_iterator<set<int>> sbit {S};
    // *sbit = 6;
    // cout<< "using back_insert_iterator for container S :"<< endl; //'class std::set<int>' has no member named 'push_back'
    // front_insert_iterator<set<int>> sfit {S};
    // *sfit = 7;
    // cout<< "using front_insert_iterator for container S :"<< endl;//'class std::set<int>' has no member named 'push_front'
    containerPrinter(S);  

    cout<< "using ostream_iterator for container V :";
    copy(begin(V),end(V),ostream_iterator<int>{cout});
    copy(begin(V),end(V),ostream_iterator<int>{cout," "});
    copy(begin(V),end(V),ostream_iterator<int>{cout,"/"});
    cout<< endl;
    cout<< "using ostream_iterator for container D :";
    copy(begin(D),end(D),ostream_iterator<int>{cout});
    copy(begin(D),end(D),ostream_iterator<int>{cout," "});
    copy(begin(D),end(D),ostream_iterator<int>{cout,"/"});
    cout<< endl;
    cout<< "using ostream_iterator for container L :";
    copy(begin(L),end(L),ostream_iterator<int>{cout});
    copy(begin(L),end(L),ostream_iterator<int>{cout," "});
    copy(begin(L),end(L),ostream_iterator<int>{cout,"/"});
    cout<< endl;
    cout<< "using ostream_iterator for container S :";
    copy(begin(S),end(S),ostream_iterator<int>{cout});
    copy(begin(S),end(S),ostream_iterator<int>{cout," "});
    copy(begin(S),end(S),ostream_iterator<int>{cout,"/"});
    cout<< endl;

    std::istringstream str {"8 7 3 5 4"};

    containerPrinter(V);
    cout<< "using istream_iterator for container V :";
    copy(std::istream_iterator<int>{str},  // src begin
    std::istream_iterator<int>{},     // src end
    back_inserter(V) );               // tgt begin
    containerPrinter(V);
    containerPrinter(D);
    cout<< "using istream_iterator for container D :";
    copy(std::istream_iterator<int>{str},  // src begin
    std::istream_iterator<int>{},     // src end
    back_inserter(D) );               // tgt begin
    containerPrinter(D);
    containerPrinter(L);
    cout<< "using istream_iterator for container L :";
    copy(std::istream_iterator<int>{str},  // src begin
    std::istream_iterator<int>{},     // src end
    back_inserter(L) );               // tgt begin
    containerPrinter(L);
    containerPrinter(S);
    cout<< "using istream_iterator for container S :";
    copy(std::istream_iterator<int>{str},  // src begin
    std::istream_iterator<int>{},     // src end
    inserter(S,begin(S)) );               // tgt begin
    containerPrinter(S);

    return 0;
}