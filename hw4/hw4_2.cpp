#include <iostream>
#include <string>

using namespace std;

class ContactNode
{
private:
    string contactName;
    string contactPhoneNumber;
    ContactNode *nextNodePtr;

public:
    // Constructor with parameters
    ContactNode(const string &name, const string &phoneNumber)
    {
        contactName = name;
        contactPhoneNumber = phoneNumber;
        nextNodePtr = nullptr;
    }

    // Accessors
    string GetName() const { return contactName; }
    string GetPhoneNumber() const { return contactPhoneNumber; }
    ContactNode *GetNext() const { return nextNodePtr; }

    // Modifier
    void InsertAfter(ContactNode *node)
    {
        ContactNode *tmpNext = nullptr;

        tmpNext = this->nextNodePtr; // Remember next
        this->nextNodePtr = node;    // this -- node -- ?
        node->nextNodePtr = tmpNext; // this -- node -- next
    }

    // Print contact details
    void PrintContactNode() const
    {
        cout << "Name: " << contactName << "\nPhone number: " << contactPhoneNumber << "\n\n";
    }
};

int main()
{
    string name, phoneNumber;

    // Get input for person 1
    getline(cin, name);
    getline(cin, phoneNumber);
    ContactNode person1(name, phoneNumber);

    // Get input for person 2
    getline(cin, name);
    getline(cin, phoneNumber);
    ContactNode person2(name, phoneNumber);

    // Get input for person 3
    getline(cin, name);
    getline(cin, phoneNumber);
    ContactNode person3(name, phoneNumber);

    // Build the linked list
    person1.InsertAfter(&person2);
    person2.InsertAfter(&person3);

    // Output contact details
    cout << "Person 1: ";
    cout << person1.GetName() << ", " << person1.GetPhoneNumber() << "\n";

    cout << "Person 2: ";
    cout << person2.GetName() << ", " << person2.GetPhoneNumber() << "\n";

    cout << "Person 3: ";
    cout << person3.GetName() << ", " << person3.GetPhoneNumber() << "\n\n";

    // Output contact details using a loop
    ContactNode *currentNode = &person1;

    cout << "CONTACT LIST\n";

    while (currentNode != nullptr)
    {
        currentNode->PrintContactNode();
        currentNode = currentNode->GetNext();
    }

    return 0;
}
