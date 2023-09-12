#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Declared variables
    const double SQUARE_FPG = 350.0;
    const double TAX_PCT = 0.07;
    double wallHeight;
    double wallWidth;
    double wallArea;
    double paintCost;
    double paintNeeded;
    double salesTax;
    double totalCost;
    int cansNeeded;

    // Step #1: Read height, width, and paint can cost
    cout << "Enter the wall height: ";
    cin >> wallHeight;
    cout << "Enter the wall width: ";
    cin >> wallWidth;
    cout << "Enter the paint cost: ";
    cin >> paintCost;
    cout << endl;

    // Step #2: Perform various calculations
    wallArea = wallHeight * wallWidth;
    paintNeeded = wallArea / SQUARE_FPG;
    cansNeeded = ceil(paintNeeded);
    paintCost = paintCost * cansNeeded;
    salesTax = TAX_PCT * paintCost;
    totalCost = paintCost + salesTax;

    // Step #3: Output with various fixed decimal places
    cout << fixed << setprecision(1);
    cout << "Wall Area: " << wallArea << " sq ft" << endl;

    cout << fixed << setprecision(3);
    cout << "Paint Needed: " << paintNeeded << " gallons" << endl;

    cout << fixed << setprecision(2);
    cout << "Cans Needed: " << cansNeeded << " can(s)" << endl;
    cout << "Paint Cost: $" << paintCost << endl;
    cout << "Sales Tax: $" << salesTax << endl;
    cout << "Total Cost: $" << totalCost << endl;

    return 0;
}