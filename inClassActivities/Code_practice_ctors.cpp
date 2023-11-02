#include <iostream>
#include <vector>

using namespace std;

// doing things in OOP style:
// constructor/destructor
// copy-ctor, copy-assignment
// move-ctor, move-assignment

struct Vector
{
    size_t size;
    int *values;

    // default c-tor
    Vector() : size(0), values(nullptr) {} // fill in

    // c-tor #1
    Vector(size_t size) : size(size), values(new int[size])
    {
        for (size_t i = 0; i < size; i++)
        {
            values[i] = int();
        }
    } // fill in

    // d-tor
    ~Vector() { delete[] values; } // fill in

    // copy c-tor
    Vector(const Vector &other) : size(other.size), values(new int[other.size])
    {
        for (size_t i = 0; i < other.size; i++)
        {
            values[i] = other.values[i];
        }
    } // fill in

    // move c-tor
    // Vector(Vector &&other) // fill in

    // copy assignment (operator overloading)
    Vector &
    operator=(const Vector &other)
    {
        size = other.size;
        // values(size);
        for (size_t i = 0; i < other.size; i++)
        {
            values[i] = other.values[i];
        }
    } // fill in

    // move assignment (operator overloading)
    Vector &
    operator=(Vector &&other) // fill in

        int &at(size_t index) // fill in

        // below we separated operator[] for read and write
        // although this operator is symmetric in its behavior during read and write
        // that is not always the case. Consider accessing a node of a linked list like this
        // reading a node's value is very simple function, but writing to a node can be complex
        // they are in fact two different functions. in the example below difference is not reflected
        // but dividing them into two different functions is indeed necessary

        // subscript operator that writes to values
        int &
        operator[](size_t index)
    {
        return values[index];
    }

    // subscript operator that promises read-only access
    int &operator[](size_t index) const { return values[index]; }
};

int main(int argc, char *argv[])
{

    auto v1 = Vector(10);

    v1.at(0) = 1000;
    v1[1] = 2000;

    auto v2 = Vector();
    auto v3 = Vector();

    v2 = v1; // copy assignment: why? v2 already exists, has been constructed. we assign on top of it

    v3 = v2 = v1; // chained copy assignment

    auto v4 = Vector(v1); // copy c-tor: why? v4 is being constructed right now from v1

    auto v5 = (Vector &&)v4;
    auto v6 = move(v4); // move c-tor: why? v5 is being constructed right now stealing from v4

    cout << v1.at(1) << endl;

    return 0;
}