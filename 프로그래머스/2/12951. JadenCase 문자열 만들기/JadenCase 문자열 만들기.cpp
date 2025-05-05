#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    bool newWord = true;

    for (int i = 0; i < s.size(); i++) {
        char& ch = s[i];
        
        if (ch == ' ') {
            newWord = true;
        } else {
            if (newWord) {
                if (isalpha(ch)) ch = toupper(ch);
                newWord = false;
            } else {
                ch = tolower(ch);
            }
        }
    }
    return s;
}