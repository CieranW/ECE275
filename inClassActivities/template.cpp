#include <string>
#include <iostream>
using namespace std;
// TODO: Define a generic method called CheckOrder() that
template <typename T>
//       takes in four variables of generic type as arguments.
//       The return type of the method is integer
// Check the order of the input: return -1 for ascending,
// 0 for neither, 1 for descending
int CheckOrder(T a, T b, T c, T d)
{
    if (a < b && b < c && c < d)
    {
        return -1;
    }
    else if (a > b && b > c && c > d)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4; // Read in four strings
    // Check order of four strings
    cout << "Order: " << CheckOrder(str1, str2, str3, str4) << endl;
    double d1, d2, d3, d4;
    cin >> d1 >> d2 >> d3 >> d4; // Read in four doubles
    // Check order of four doubles
    cout << "Order: " << CheckOrder(d1, d2, d3, d4) << endl;
    return 0;
}
