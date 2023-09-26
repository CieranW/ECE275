#include "MileageTrackerNode.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
    MileageTrackerNode *headNode;
    MileageTrackerNode *currNode;
    MileageTrackerNode *lastNode;
    double miles;
    string date;
    int i;
    // Front of nodes list
    headNode = new MileageTrackerNode();
    lastNode = headNode;
    // TODO: Read in the number of nodes
    // TODO: For the just-read-in number of nodes, read
    //   	in data and insert into the linked list
    // TODO: Call the PrintNodeData() method
    //   	to print the entire linked list
    // MileageTrackerNode Destructor deletes all following nodes
    delete headNode;
}
