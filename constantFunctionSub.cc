#include <iostream>

class MyClass
{
private:
    mutable int counter;
public:

    MyClass() : counter(0) {}

    void Foo()
    {
        counter++;
        std::cout << "Foo" << std::endl;    
    }

    void Foo() const
    {
        counter++;    // This works because counter is `mutable`
        std::cout << "Foo const" << std::endl;
    }

    int GetInvocations() const
    {
        return counter;
    }
};

int main(void)
{
    MyClass cc;
    const MyClass& ccc = cc;
    cc.Foo();
    ccc.Foo();
    std::cout << "Foo has been invoked " << ccc.GetInvocations() << " times" << std::endl;
}