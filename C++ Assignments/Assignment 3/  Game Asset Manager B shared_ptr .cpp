#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Shader
{
private:
    string name;

public:
    // Constructor
    Shader(string n)
    {
        name = n;
        cout << "Shader Compiled: " << name << endl;
    }

    // Destructor
    ~Shader()
    {
        cout << "Shader Destroyed: " << name << endl;
    }

    void display() const
    {
        cout << "Shader: " << name << endl;
    }
};

int main()
{
    // 1. Create a Shader using shared_ptr
    shared_ptr<Shader> shader1 =
        make_shared<Shader>("basic_shader");

    // 2. Create another shared_ptr sharing the same object
    shared_ptr<Shader> shader2 = shader1;

    cout << "Reference count: "
         << shader1.use_count() << endl;

    shader1->display();
    shader2->display();

    // 3. Reset first pointer
    shader1.reset();

    cout << "After shader1.reset():" << endl;
    cout << "Reference count: "
         << shader2.use_count() << endl;

    // Object is still alive because shader2 owns it

    // 4. Reset second pointer
    shader2.reset();

    // Now the Shader object is destroyed

    return 0;
}


