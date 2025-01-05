#include <iostream>
#include <map>
using namespace std;

bool canConstruct(string ransomNote, string magazine);

int main() {
    // test 1
    cout << "canConstruct(\"a\", \"b\")";
    if (!canConstruct("a", "b")) {
        cout << " success" << endl;
    } else {
        cout << " fail" << endl;
    }

    // test 2
    cout << "canConstruct(\"aa\", \"aab\")";
    if (canConstruct("aa", "aab")) {
        cout << " success" << endl;
    } else {
        cout << " fail" << endl;
    }
    return 0;
}

bool canConstruct(string ransomNote, string magazine) {
    // false when ransomNote has more letters than magazine
    if (ransomNote.length() > magazine.length()) {
        return false;
    }

    // create an array with a counter for every letter
    int letterCount[26] = {0};

    // count how often every letter occure in magazine
    for (auto letter: magazine) {
        letterCount[letter - 'a']++;
    }

    // go throug every letter in ransomNote
    for (auto letter: ransomNote) {
        // letter counter is 0 means not enough letters in the magazine
        if (letterCount[letter - 'a'] == 0) {
            return false;
        }
        
        // decrease letter counter to keep track if there
        // enough letters for the ransomNote
        letterCount[letter - 'a']--;
    }

    return true;
}
