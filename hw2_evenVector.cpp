#include <iostream>
#include <vector>
using namespace std;

vector<int> RemoveEvens(vector<int> nums)
{
    /* Type your code here */
}

int main()
{

    vector<int> input(9);
    input.at(0) = 1;
    input.at(1) = 2;
    input.at(2) = 3;
    input.at(3) = 4;
    input.at(4) = 5;
    input.at(5) = 6;
    input.at(6) = 7;
    input.at(7) = 8;
    input.at(8) = 9;

    vector<int> result = RemoveEvens(input); // Should return [1, 3, 5, 7, 9]

    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result.at(i);
    }
    cout << endl;

    return 0;
}
