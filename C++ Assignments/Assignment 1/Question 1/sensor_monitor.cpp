#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int warning, critical, readings;
    int normal = 0, warn = 0, crit = 0;

    if (argc != 4)
    {
        cout << "Usage: sensor_monitor <warning> <critical> <readings>" << endl;
        cout << "Error: Missing arguments." << endl;
        return 1;
    }

    warning = stoi(argv[1]);
    critical = stoi(argv[2]);
    readings = stoi(argv[3]);

    if (warning >= critical)
    {
        cout << "Error: Warning must be less than Critical." << endl;
        return 1;
    }

    if (readings <= 0)
    {
        cout << "Error: Readings must be greater than 0." << endl;
        return 1;
    }

    cout << "Config: Warning=" << warning
         << " Critical=" << critical
         << " Readings=" << readings << endl;

    int temperature[] = {25, 28, 29, 27, 30, 35, 40, 42, 45, 50};

    for (int i = 0; i < readings; i++)
    {
        if (temperature[i] >= critical)
            crit++;
        else if (temperature[i] >= warning)
            warn++;
        else
            normal++;
    }

    cout << "Results: Normal=" << normal
         << " Warning=" << warn
         << " Critical=" << crit
         << " Simulated" << endl;

    return 0;
}
