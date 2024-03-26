#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<utility>
#include<initializer_list>

using namespace std;

int i1 = 5;  //storing the data in stack 

auto i2 = make_unique<int>(i1);   //allocating a block of memory in heap and keep the variable in stack and point to the address in heap

auto i3 = make_shared<int>(i1);   //data allocating is same as make_unique but the address of data in heap can be pointed by multiple variable 

//It is a good way to construct a tempory circular referencing;
weak_ptr<int> i4 = i3;   //the weak_ptr can be assigned into shared_ptr; if no other pointer point to the address of data, weak_ptr will realse the resource of this data

template<typename T>
void pointer_printer(T t){
    cout << "Printing the pointer: " << t << endl;
}

/*Special class members */

class BinarySearchTree
{
    public:

    BinarySearchTree() = default; //needed
            
            BinarySearchTree(BinarySearchTree const& source) : root_{nullptr}
            {
                if(source.root_)
                    root_ = make_unique<Node>(*source.root_);
            }
        
    BinarySearchTree& operator = (BinarySearchTree const& source)
    {
        if(&source == this) return *this;

        BinarySearchTree tmp(source);

        swap(tmp.root_, root_);

        return *this;
    }

    class Node {  // The nested class in this class
        public:
            explicit Node(int v = 0);
            int value_;
            unique_ptr<Node> left_;
            unique_ptr<Node> right_;

            Node(Node const& source):  //node copy constructor 
                value_{source.value_},left_{nullptr},right_{nullptr}  
                {
                    //copy subtrees recursively
                    if(source.left_) left_ = make_unique<Node>(*source.left_);
                    if(source.right_) right_ = make_unique<Node>(*source.right_);
                }

                Node& operator = (Node const& source){  // Node copy assignment operator 

                    if(&source == this) return *this;

                    Node tmp(source);

                    swap(tmp.value_,value_);
                    swap(tmp.left_,left_);
                    swap(tmp.right_,right_);
 
                    return *this;
                }
    };
    
    void insert(int){
        cout << "pretend to insert"<< endl;
    }
    bool empty(){
        return false;
    }
    bool contains(int) const{
        return true;
    }

    private:
        unique_ptr<Node> root_;       
};

/*the moving constructor:
    T(T&&)              move constructor 
    T& operator = (T&&) move assignment operator*/

class ascending_sequence
{
    vector<int> num_;

    public:
    ascending_sequence(initializer_list<int> il): num_{} //intializer_list can take a container of paramaters 
    {
        num_.resize(il.size());

        copy(begin(il), end(il),begin(num_));

        sort(begin(num_),end(num_));
    }
};

int main(){
    cout << "This topic is created to dicuss about memory in cpp." << endl;

    pointer_printer(*i2);

    BinarySearchTree t1;
    
    BinarySearchTree t2 = t1; //deeply copyable now, after we overload constructor and assignment operator

    ascending_sequence a1 {1,4,5,6,7,3,6,3}; //{} brace always call initializer_list constructor 

    ascending_sequence a2();   // ()parenthese never call an initializer_list contructor   //if you define an initializer_list constructor => don't provide constructor with similar, easy to confuse parameter lists!


    return 0;
}