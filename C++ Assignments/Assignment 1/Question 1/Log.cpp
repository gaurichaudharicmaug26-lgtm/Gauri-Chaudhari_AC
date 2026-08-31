#include <iostream>
using namespace std;

int main()
{
    int n;
    float a[100];

    cout << "Readings entered: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int error = 0;
    int normal = 0, warning = 0, critical = 0, shutdown = 0;

    float min, max, sum = 0;
    int first = -1;

    cout << "Valid readings: ";

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            error++;
            continue;
        }

        cout << a[i] << " ";

        if (first == 0)
        {
            min = max = a[i];
            first = 0;
        }
        else
        {
            if (a[i] < min)
                min = a[i];

            if (a[i] > max)
                max = a[i];
        }

        sum = sum + a[i];

        if (a[i] < 30)
            normal++;
        else if (a[i] < 45)
            warning++;
        else if (a[i] < 60)
            critical++;
        else
            shutdown++;
    }

    cout << "\nSkipped (errors): " << error;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 45)
        {
            cout << "\nFirst CRITICAL : Index "
            		<< i - 1 << " = " << a[i] << " C"<<endl;
            break;
        }
    }

    float average = sum / (n - error);

    cout << "\n\nMin : " << min << " C";
    cout << "\tMax : " << max << " C";
    cout << "\tAvg : " << average << " C";

    cout << "\n\nNormal: " << normal;
    cout << "\tWarning: " << warning;
    cout << "\tCritical: " << critical;
    cout << "\tShutdown: " << shutdown;

    return 0;
}
