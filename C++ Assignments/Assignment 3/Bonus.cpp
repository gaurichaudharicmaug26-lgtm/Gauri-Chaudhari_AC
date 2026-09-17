#include <iostream>
using namespace std;

class LogBuffer
{
private:
    mutable int accessCount = 0;

public:
    void print() const
    {
        accessCount++;
        cout << "LogBuffer print called" << endl;
    }

    int getAccessCount() const
    {
        return accessCount;
    }
};

int main()
{
    const LogBuffer readonly;

    readonly.print();
    readonly.print();
    readonly.print();

    cout << "Print called: " << readonly.getAccessCount() << " times" << endl;

    /*
    accessCount is declared as mutable because print() is a const
    member function. Normally, a const member function cannot modify
    any data member of the object.

    The mutable keyword allows accessCount to be modified even inside
    a const member function. It is useful when we want to maintain
    internal information such as an access counter without changing
    the logical state of the object.

    The const keyword on print() means that print() cannot modify
    normal data members of the object. However, mutable data members
    are an exception to this rule.
    */

    return 0;
}
