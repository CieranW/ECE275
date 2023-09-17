#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a1, a2, b1, b2, c1, c2;
    int x, y;

    bool eqn1Solved = false, eqn2Solved = false;

    cin >> a1;
    cin >> b1;
    cin >> c1;

    cin >> a2;
    cin >> b2;
    cin >> c2;

    for (int i = -10; i < 10; i++)
    {
        for (int j = -10; j < 10; j++)
        {
            if (a1 * i + b1 * j == c1 && a2 * i + b2 * j == c2)
            {
                eqn1Solved = true;
                eqn2Solved = true;
                x = i;
                y = j;
            }
        }
    }

    if (x > 10 || x < 10 || y > 10 || y < 10)
    {
        cout << "No solution" << endl;
    }
    else
    {
        cout << "x = " << x << " and y = " << y << endl;
    }

    return 0;
}