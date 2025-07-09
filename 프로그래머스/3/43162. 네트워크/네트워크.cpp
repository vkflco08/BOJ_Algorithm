#include <string>
#include <vector>
#include <iostream>

using namespace std;

void bfs(int node, vector<vector<int>> &computers, vector<bool> &isVisited) {
    isVisited[node] = true;
    for(int i = 0; i<computers.size(); i++) {
        if(!isVisited[i] && computers[node][i] == 1) {
            bfs(i, computers, isVisited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> isVisited(n, false);
    
    for(int i = 0; i<computers.size(); i++) {
        if(!isVisited[i]) {
            bfs(i, computers, isVisited);
            answer++;
        }
    }
    
    return answer;
}