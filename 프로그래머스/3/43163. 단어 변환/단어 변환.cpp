#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

bool isValid(string words, string tmp) {
    int strlen = words.length();
    int count = 0;
    for(int i = 0; i<strlen; i++) {
        if(words[i] == tmp[i]) count++;
    }
    
    if(strlen - 1 == count) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = INT_MAX;
    queue<pair<string, int>> q;
    vector<bool> isVisited (words.size(), false);
    
    q.push({begin, 0});
    
    int loopCount = 1;
    while(!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();
        
        if(current == target) return steps;
        
        for(int i = 0; i<words.size(); i++) {
            if(!isVisited[i]) {
                if(isValid(words[i], current)) {
                    isVisited[i] = true;
                    q.push({words[i], loopCount});
                }
            }
        }   

        loopCount++;
    }
    
    if(answer == INT_MAX) return 0;
    return answer;
}