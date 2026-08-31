#include <iostream>
using namespace std;

int main1()
{
    double temp, fahrenheit;
    int statusCode;

    cout << "Enter temperature in Celsius: ";
    cin >> temp;

    statusCode = (temp < 0) ? -1 :
                 (temp <= 29) ? 0 :
                 (temp <= 44) ? 1 :
                 (temp <= 59) ? 2 : 3;

    if (statusCode == -1)
        cout << "Status: SENSOR_ERROR" << endl
             << "Action: Sensor fault - check wiring" << endl;
    else if (statusCode == 0)
        cout << "Status: NORMAL" << endl
             << "Action: No action required" << endl;
    else if (statusCode == 1)
        cout << "Status: WARNING" << endl
             << "Action: Alert sent to supervisor" << endl;
    else if (statusCode == 2)
        cout << "Status: CRITICAL" << endl
             << "Action: Cooling system triggered" << endl;
    else
        cout << "Status: SHUTDOWN" << endl
             << "Action: Emergency shutdown initiated" << endl;


    fahrenheit = (temp * 9 / 5) + 32;
    cout << "Temperature in Fahrenheit: " << fahrenheit << " F" << endl;

    cout << "Operating range: "
         << ((temp > 25) ? "Above 25 C" : "25 C or below") << endl;

    return 0;
}


