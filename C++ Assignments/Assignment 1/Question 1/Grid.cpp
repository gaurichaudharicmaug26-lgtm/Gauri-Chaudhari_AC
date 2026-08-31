#include <iostream>
using namespace std;

int main()
{
    float a[3][3];
    float sum, avg;
    float max;
    int floor, room;
    int warning = 0;

    cout << "Enter 9 room temperatures:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "\n\tRoom1\tRoom2\tRoom3\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "Floor " << i + 1 << "\t";

        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << "\t";
        }

        cout << endl;
    }

    max = a[0][0];
    floor = 0;
    room = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
                floor = i;
                room = j;
            }
        }
    }

    float highestAvg = 0;
    int hotFloor = 0;

    for (int i = 0; i < 3; i++)
    {
        sum = 0;

        for (int j = 0; j < 3; j++)
        {
            sum = sum + a[i][j];
        }

        avg = sum / 3;

        if (avg > highestAvg)
        {
            highestAvg = avg;
            hotFloor = i;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] >= 30)
                warning++;
        }
    }

    cout << "\nHottest Room: Floor " << floor + 1
         << ", Room " << room + 1
         << " -> " << max << " C";

    cout << "\nHottest Floor: Floor " << hotFloor + 1
         << " (Avg " << highestAvg << " C)";

    cout << "\nRooms at WARNING or above: " << warning;

    return 0;
}




