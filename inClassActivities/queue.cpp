#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    string line;
    bool result = true;
    deque<char> characters;

    getline(cin, line);

    for (unsigned int i = 0; i < line.size(); i++) {
        if (isalpha(line[i])){
            characters.push_back(line[i]);
        }
    }

    while (characters.size() > 1) {
        if (characters.front() != characters.back()) {
            result = false;
            break;
        }
        else {
            characters.pop_front();
            characters.pop_back();
        }
    }

    cout << characters.size() << endl;
    cout << (result ? "Yes" : "No") << endl;

    return 0;
}