#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Texture
{
private:
    string name;
    int width;
    int height;

public:
    // Constructor
    Texture(string n, int w, int h)
    {
        name = n;
        width = w;
        height = h;

        cout << "Texture Loaded" << endl;
    }

    // Destructor
    ~Texture()
    {
        cout << "Texture Released" << endl;
    }

    // Display function
    void display() const
    {
        cout << "Texture: " << name << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
    }
};

int main()
{
    // 1. Create Texture using unique_ptr
    unique_ptr<Texture> tex1 =
        make_unique<Texture>("player_sprite", 512, 512);

    // 2. Call display()
    tex1->display();

    // 3. Attempt to copy unique_ptr
    // unique_ptr<Texture> tex2 = tex1;
    // ERROR: unique_ptr cannot be copied because
    // it allows only one owner.

    // 4. Transfer ownership using move()
    unique_ptr<Texture> tex2 = move(tex1);

    if (tex1 == nullptr)
    {
        cout << "tex1 is now nullptr" << endl;
    }
}




