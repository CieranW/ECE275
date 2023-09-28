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
    int i, numNodes = 0;
    // Front of nodes list
    headNode = new MileageTrackerNode();
    lastNode = headNode;
    // TODO: Read in the number of nodes
    cin >> numNodes;
    // TODO: For the just-read-in number of nodes, read in data and insert into the linked list
    for (i = 0; i < numNodes; i++)
    {
        cin >> miles;
        cin >> date;

        currNode = new MileageTrackerNode(miles, date);
        lastNode->InsertAfter(currNode);
        lastNode = currNode;
    }
    // TODO: Call the PrintNodeData() method to print the entire linked list
    currNode = headNode->GetNext();
    while (currNode != nullptr)
    {
        currNode->PrintNodeData();
        currNode = currNode->GetNext();
    }

    cin >> miles;
    cin >> date;
    MileageTrackerNode *temp;
    temp = new MileageTrackerNode(miles, date);
    currNode = headNode->GetNext();
    currNode->InsertAfter(temp);

    currNode = headNode->GetNext();
    while (currNode != nullptr)
    {
        currNode->PrintNodeData();
        currNode = currNode->GetNext();
    }

    // MileageTrackerNode Destructor deletes all following nodes
    delete headNode;
}
