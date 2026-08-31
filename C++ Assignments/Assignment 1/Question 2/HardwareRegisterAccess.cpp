#include <iostream>
using namespace std;

int main()
{
    int statusReg  = 0b11010011;   // Read-only from firmware side
    int controlReg = 0b00000000;   // Firmware writes here
    int dataReg    = 0b10101010;   // For reassignment demo

    // 1. const int* : pointer to read-only data
    const int* statusPtr = &statusReg;

    cout << "Status Register: " << *statusPtr << endl;

    // *statusPtr = 10;
    // ERROR: Cannot change value through a const int pointer.

    // statusPtr = &controlReg;
    // This is allowed because statusPtr itself is not const.


    // 2. int* const : constant pointer to writable data
    int* const controlPtr = &controlReg;

    *controlPtr = 25;

    cout << "Control Register: " << *controlPtr << endl;

    // controlPtr = &dataReg;
    // ERROR: Cannot change the address of a constant pointer.


    // 3. const int* const : constant pointer to read-only data
    const int* const romPtr = &dataReg;

    cout << "ROM Config: " << *romPtr << endl;

    // *romPtr = 50;
    // ERROR: Cannot change the value through a const pointer.

    // romPtr = &statusReg;
    // ERROR: Cannot change the address of a constant pointer.

    return 0;
}



