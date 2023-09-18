#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

///////////////// Before submitting your code
// 1) uncomment this part since zyBooks use it to test your code
// int main(int argc, const char *argv[])
// {
//    if (argc != 3)
//    {
//       std::cout << "./hw2 inputFile outputFile" << std::endl;
//       return EXIT_FAILURE;
//    }
//    string inFilename = argv[1];
//    string outFilename = argv[2];
///////////////////// uncomment above befofre submitting on zyBooks /////////////////
// 2) Comment the next 3 lines below

int main(void)
{
   string inFilename = "TestFile3.txt"; // Do NOT change the name "inFilename" since used above
   string outFilename = "OutFile1.txt"; // Do NOT change the name "outFilename" since used above

   /* Type your code here. */
   ifstream inFile;
   ofstream outFile;

   inFile.open(inFilename);
   if (!inFile.is_open())
   {
      cout << "File unable to open\n";
      return 1;
   }

   // Variables
   vector<double> data;
   int filterStart, filterEnd, filterWidth;
   double temp, sum = 0.0;

   // If else reads in filter width then loops through till the end of the file, pushing the data into the vector
   if (inFile >> filterWidth)
   {
      while (inFile >> temp)
      {
         data.push_back(temp);
      }

      // Process the data as needed
      cout << "Filter Width: " << filterWidth << "\n";
      cout << "Data: ";
      for (size_t i = 0; i < data.size(); ++i)
      {
         cout << data[i] << " ";
      }
      cout << "\n";
   }
   else
   {
      cout << "Failed to read filter width.\n";
   }

   inFile.close(); // Close the file

   // Calculating the window we'll need for the filter avg
   filterStart = filterWidth / 2;
   filterEnd = data.size() - filterStart;

   // Additional variables declared later once we've got more info from reading the file
   double filter = filterWidth;
   int size = data.size();
   vector<double> filteredData(size);

   // Performing calculations to turn data into filtered data given the parameters
   for (int i = 0; i < size; ++i)
   {
      // Filters the data by the elements within the desired range so that there are no errors/unaccessible data points
      if (i >= filterStart && i < filterEnd)
      {
         sum = 0.0;
         // At a certain element position, accesses all the data points within the filter width to add towards the sum for avg calc
         for (int j = (i - filterStart); j <= (i + filterStart); j++)
         {
            sum += data.at(j);
         }
         filteredData.at(i) = sum / filter;
      }
      else
      {
         filteredData.at(i) = data.at(i);
      }
   }

   // Outputting new filtered data to file
   outFile.open(outFilename);
   outFile << fixed << setprecision(4);
   for (int i = 0; i < size; ++i)
   {
      outFile << filteredData.at(i);
      if (i != size - 1)
      {
         outFile << ", ";
      }
   }

   outFile.close();

   return 0;
}
