#ifndef MILEAGETRACKERNODEH
#define MILEAGETRACKERNODEH
#include <string>
using namespace std;
class MileageTrackerNode
{
public:
    // Constructor
    MileageTrackerNode();
    // Destructor
    ~MileageTrackerNode();
    // Constructor
    MileageTrackerNode(double milesInit, string dateInit);
    // Constructor
    MileageTrackerNode(double milesInit, string dateInit, MileageTrackerNode *nextLoc);
    /* Insert node after this node.
    Before: this -- next
    After:  this -- node -- next
    */
    void InsertAfter(MileageTrackerNode *nodeLoc);
    // Get location pointed by nextNodeRef
    MileageTrackerNode *GetNext();
    void PrintNodeData();

private:
    double miles;                    // Node data
    string date;                     // Node data
    MileageTrackerNode *nextNodeRef; // Reference to the next node
};
#endif
