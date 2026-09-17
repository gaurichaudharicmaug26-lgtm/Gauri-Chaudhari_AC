#include <iostream>
#include <cstring>
using namespace std;

class LogBuffer
{
private:
    char* buffer;          // Dynamically allocated character array
    int capacity;          // Maximum number of characters
    int size;              // Current number of characters stored

    static int instanceCount;   // Total live LogBuffer objects

public:

    // Constructor
    LogBuffer(int cap)
    {
        capacity = cap;
        size = 0;

        buffer = new char[capacity];

        instanceCount++;

        cout << "LogBuffer created, capacity=" << capacity << endl;
    }

    // Copy Constructor - Deep Copy
    LogBuffer(const LogBuffer& other)
    {
        capacity = other.capacity;
        size = other.size;

        buffer = new char[capacity];

        // Copy actual contents
        memcpy(buffer, other.buffer, size);

        instanceCount++;

        cout << "LogBuffer deep copied" << endl;
    }

    // Copy Assignment Operator
    LogBuffer& operator=(const LogBuffer& other)
    {
        // Check self-assignment
        if (this != &other)
        {
            // Delete existing memory
            delete[] buffer;

            capacity = other.capacity;
            size = other.size;

            // Allocate new memory
            buffer = new char[capacity];

            // Copy contents
            memcpy(buffer, other.buffer, size);
        }

        return *this;
    }

    // Append a message
    void append(const char* message)
    {
        int len = strlen(message);

        if (size + len < capacity)
        {
            memcpy(buffer + size, message, len);
            size += len;
        }
    }

    // Print log contents
    void print() const
    {
        cout.write(buffer, size);
        cout << endl;
    }

    // Static function
    static int getInstanceCount()
    {
        return instanceCount;
    }

    // Destructor
    ~LogBuffer()
    {
        delete[] buffer;

        instanceCount--;

        cout << "LogBuffer destroyed" << endl;
    }
};

// Initialize static member
int LogBuffer::instanceCount = 0;


int main()
{
    // Objective 1: Basic usage
    LogBuffer log1(256);

    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");

    log1.print();


    // Objective 2: Deep copy using copy constructor
    LogBuffer log2 = log1;

    log2.append(" | Cached response sent");

    cout << "log1 : ";
    log1.print();

    cout << "log2 : ";
    log2.print();


    // Objective 3: Copy assignment operator
    LogBuffer log3(128);

    log3 = log1;

    log3.print();


    // Objective 4: Self-assignment
    log1 = log1;

    log1.print();


    // Objective 5: Static object count
    cout << "Live LogBuffer objects = "
         << LogBuffer::getInstanceCount()
         << endl;

    return 0;
}


