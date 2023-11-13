#include <iostream>
using namespace std;

// Read size numbers from cin into a new array and return the array.
int *ReadNums(int size)
{
    int *nums = new int[size]; // Create array
    for (int i = 0; i < size; ++i)
    { // Read the numbers
        cin >> nums[i];
    }
    return nums;
}

// Print the numbers in the array, separated by spaces
// (No space or newline before the first number or after the last.)
void PrintNums(int nums[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << nums[i];
        if (i < size - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

// Exchange nums[j] and nums[k].
void Swap(int nums[], int j, int k)
{
    int temp;
    temp = nums[j];
    nums[j] = nums[k];
    nums[k] = temp;
}

// Sort numbers
// TODO: Count comparisons and swaps. Output the array at the end of each iteration.
void InsertionSort(int numbers[], int size)
{
    int i;
    int j;
    int swaps = 0;
    int comparisons = 0;

    for (i = 1; i < size; ++i)
    {
        j = i;
        while (j > 0)
        {
            if (numbers[j] < numbers[j - 1])
            {
                Swap(numbers, j, j - 1);
                swaps += 1;
            }
            else
            {
                comparisons += 1;
                break;
            }
            comparisons += 1;
            --j;
        }
        PrintNums(numbers, size);
    }
    cout << endl
         << "comparisons: " << comparisons << endl;
    cout << "swaps: " << swaps;
}

int main()
{
    // Step 1: Read numbers into an array
    int size;
    cin >> size;                   // Read array size
    int *numbers = ReadNums(size); // Read numbers

    // Step 2: Output the numbers array
    PrintNums(numbers, size);
    cout << endl;

    // Step 3: Sort the numbers array
    InsertionSort(numbers, size);
    cout << endl;

    // Step 4: Output the number of comparisons and swaps
    // TODO: Output the number of comparisons and swaps performed by InsertionSort

    return 0;
}
