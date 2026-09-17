#include <iostream>
#include<String>
#include <vector>
using namespace std;

// Type aliases using using keyword
using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

// Traditional typedef alias
typedef unsigned long long RequestId;

// Function to print all headers
void printHeaders(const HeaderList& headers)
{
    cout << "Headers:" << endl;

    for (const Header& header : headers)
    {
        cout << "  " << header.first
             << " : " << header.second << endl;
    }
}

int main()
{
    // Create HeaderList with 3 headers
    HeaderList headers =
    {
        {"Content-Type", "application/json"},
        {"Authorization", "Bearer eyJhbGci..."},
        {"Accept-Language", "en-US"}
    };

    // Server port
    Port serverPort = 8080;

    // Request ID
    RequestId requestId = 1748293847;

    cout << "Request ID   : " << requestId << endl;
    cout << "Server Port  : " << serverPort << endl;
    cout << endl;

    // Print headers
    printHeaders(headers);

    return 0;
}





