#include <iostream>

using namespace std;

void SelectionSort(int numbers[], int numberSize)
{
    int i, j, indexSmallest, temp;

    for (i = 0; i < numberSize - 1; i++)
    {
        indexSmallest = i;
        for (j = i + 1; j < numberSize; j++)
        {
            if (numbers[j] < numbers[indexSmallest])
            {
                indexSmallest = j;
            }
        }

        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}

int main()
{
    int numbers[] = {10, 2, 78, 4, 45, 32, 7, 11};
    int i;

    cout << "UNSORTED: ";
    for (i = 0; i < 8; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    SelectionSort(numbers, 8);

    cout << "SORTED: ";
    for (i = 0; i < 8; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}