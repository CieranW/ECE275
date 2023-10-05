#include <iostream>
using namespace std;

class IntNode
{
public:
    // Constructor
    IntNode(int dataInit);

    // Get node value
    int GetNodeData();

    // Get pointer to next node
    IntNode *GetNext();

    /* Insert node after this node.
       Before: this -- next
       After:  this -- node -- next
    */
    void InsertAfter(IntNode *newNode);

private:
    int dataVal;
    IntNode *nextNodePtr;
};

// Constructor
IntNode::IntNode(int dataInit)
{
    this->dataVal = dataInit;
    nextNodePtr = nullptr;
}

// Get node value
int IntNode::GetNodeData()
{
    return this->dataVal;
}

// Get pointer to next node
IntNode *IntNode::GetNext()
{
    return this->nextNodePtr;
}

/* Insert node after this node.
   Before: this -- next
   After:  this -- node -- next
*/
void IntNode::InsertAfter(IntNode *newNode)
{
    IntNode *tempNext = this->nextNodePtr;
    this->nextNodePtr = newNode;
    newNode->nextNodePtr = tempNext;
}

// Return index of target item
int IndexOf(IntNode *headNode, int target)
{
    /* Type your code here. */
}

int main()
{
    IntNode *headNode = new IntNode(-1);
    IntNode *currNode;
    IntNode *lastNode;

    // Initiaize head node
    lastNode = headNode;

    // Add nodes to the list
    for (int i = 0; i < 20; ++i)
    {
        currNode = new IntNode(i);
        lastNode->InsertAfter(currNode);
        lastNode = currNode;
    }

    cout << IndexOf(headNode, 15) << endl;

    return 0;
}
