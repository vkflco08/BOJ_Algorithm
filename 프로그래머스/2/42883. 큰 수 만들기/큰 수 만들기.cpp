#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> stack;
    int removeNum = k;
    
    for(int i = 0; i<number.length(); i++) {
        char tmpNum = number[i];
        while(!stack.empty() && stack.back() < tmpNum && removeNum > 0) {
            stack.pop_back();
            removeNum--;
        }
        stack.push_back(tmpNum);
    }
    
    while (removeNum > 0) {
        stack.pop_back();
        removeNum--;
    }
    
    for(char c : stack) answer += c;
    
    return answer;
}