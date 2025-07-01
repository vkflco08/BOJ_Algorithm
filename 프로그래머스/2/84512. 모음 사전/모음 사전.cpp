#include <string>
#include <vector>

using namespace std;
vector<string> bruteforce;

void dfs(string current, int depth) {
    if(depth > 5) return;
    
    if(!current.empty()) {
        bruteforce.push_back(current);
    }
    
    string words = "AEIOU";
    for(int i = 0; i<5; i++){
        dfs(current + words[i], depth + 1);    
    }
}

int solution(string word) {
    int answer = 0;
    
    dfs("", 0);
    
    for(int i = 0; i<bruteforce.size(); i++) {
        if(bruteforce[i] == word) return i+1;
    }
    
    return answer;
}