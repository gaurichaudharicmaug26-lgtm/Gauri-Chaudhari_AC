#include <iostream>
#include <cmath>
using namespace std;

// Calculate distance between two points
inline double distanceBetween(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Convert degrees to radians
inline double toRadians(double degrees)
{
    return degrees * (M_PI / 180.0);
}

// Keep value between minimum and maximum
inline double clamp(double value, double minVal, double maxVal)
{
    if (value < minVal)
        return minVal;
    if (value > maxVal)
        return maxVal;
    return value;
}

// Check point is inside safe zone
inline bool isInSafeZone(double x, double y, double cx, double cy, double radius)
{
    return distanceBetween(x, y, cx, cy) <= radius;
}

int main()
{
    // Home position
    double homeX = 0.0;
    double homeY = 0.0;

    // Safe zone radius
    double radius = 50.0;

    // Three waypoints
    double x[3] = {10.0, 30.0, 60.0};
    double y[3] = {20.0, 40.0, 20.0};

    // Test each waypoint
    for (int i = 0; i < 3; i++)
    {
        double distance = distanceBetween(homeX, homeY, x[i], y[i]);

        cout << "Waypoint " << i + 1 << endl;
        cout << "Distance from Home : " << distance << endl;

        if (isInSafeZone(x[i], y[i], homeX, homeY, radius))
            cout << "Inside Safe Zone : Yes" << endl;
        else
            cout << "Inside Safe Zone : No" << endl;

        cout << endl;
    }

    return 0;
}
