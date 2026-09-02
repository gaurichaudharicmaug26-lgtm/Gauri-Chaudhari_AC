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


           //STRUCT PADDING:

           //1. The sizes can be different because the order
           //   of members is different.

           //2. Padding means extra empty memory added by the
           //   compiler between members. It is added to keep
           //   data properly aligned in memory.

          // 3. Member order is important when defining network
          //    packet headers or hardware register maps because
          //    padding can change the size and memory layout
          //    of the structure.


        return 0;
}



