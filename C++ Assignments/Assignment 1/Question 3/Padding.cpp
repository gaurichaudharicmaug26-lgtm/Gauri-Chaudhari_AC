#include <iostream>
using namespace std;

struct Layout1
{
    char c1;
    int i;
    char c2;
};

struct Layout2
{
    int i;
    char c1;
    char c2;
};

int main()
{
    cout << "Size of Layout1 : " << sizeof(Layout1) << " bytes" << endl;
    cout << "Size of Layout2 : " << sizeof(Layout2) << " bytes" << endl;

    /*
       STRUCT PADDING:

       1. The sizes can be different because the order
          of members is different.

       2. Padding means extra empty memory added by the
          compiler between members. It is added to keep
          data properly aligned in memory.

       3. Member order is important when defining network
          packet headers or hardware register maps because
          padding can change the size and memory layout
          of the structure.
    */

    return 0;
}

// explanation

//Layout1:
//char → int → char
//The compiler adds padding around the int, so its size is usually 12 bytes.

//Layout2:
//int → char → char
//The members fit more efficiently, so its size is usually 8 bytes.
//The exact size can depend on the compiler and platform, but with a typical 32-bit/64-bit C++ compiler using 4-byte int alignment, the
