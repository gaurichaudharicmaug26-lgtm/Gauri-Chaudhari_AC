#include <iostream>
#include <cmath>
using namespace std;

// Returns sqrt(sum of each element squared / n)
double computeRMS(double* signal, int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + (*(signal + i) * *(signal + i));
    }

    return sqrt(sum / n);
}

// Divides every element by the maximum absolute value
void normalise(double* signal, int n)
{
    double max = 0;

    // Find maximum absolute value
    for (int i = 0; i < n; i++)
    {
        if (fabs(*(signal + i)) > max)
            max = fabs(*(signal + i));
    }

    // Divide every element by max
    for (int i = 0; i < n; i++)
    {
        *(signal + i) = *(signal + i) / max;
    }
}

// Counts positions where adjacent elements have opposite signs
int countZeroCrossings(double* signal, int n)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if ((*(signal + i) < 0 && *(signal + i + 1) > 0) ||
            (*(signal + i) > 0 && *(signal + i + 1) < 0))
        {
            count++;
        }
    }

    return count;
}

// Multiplies every element by gain
void applyGain(double* signal, int n, double gain)
{
    for (int i = 0; i < n; i++)
    {
        *(signal + i) = *(signal + i) * gain;
    }
}

int main()
{
    double signal[] = {2, -4, 6, -8, 4};
    int n = 5;
    double gain = 2;

    cout << "Array before processing: ";

    for (int i = 0; i < n; i++)
        cout << signal[i] << " ";

    cout << endl;

    double rms = computeRMS(signal, n);
    cout << "RMS = " << rms << endl;

    normalise(signal, n);

    cout << "After normalise: ";
    for (int i = 0; i < n; i++)
        cout << signal[i] << " ";

    cout << endl;

    int crossings = countZeroCrossings(signal, n);
    cout << "Zero crossings = " << crossings << endl;

    applyGain(signal, n, gain);

    cout << "After gain: ";
    for (int i = 0; i < n; i++)
        cout << signal[i] << " ";

    cout << endl;

    return 0;
}
