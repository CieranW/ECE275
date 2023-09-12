#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num = 0, max = 0;
    double avg, temp = 0, count = -1;

    while (num >= 0)
    {
        cin >> num;

        if (num > max)
        {
            max = num;
        }
        temp += num;
        count += 1;
    }
    temp -= num;
    avg = temp / count;

    cout << fixed << setprecision(2);
    cout << count << " " << temp << endl;
    cout << "Avg: " << avg << endl;
    cout << "Max : " << max << endl;

    return 0;
}