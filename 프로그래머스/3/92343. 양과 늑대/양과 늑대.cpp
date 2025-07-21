#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
void algorithm(vector<int> &info, vector<vector<int>> &edges, int node, int sheep, int wolf, vector<int> &nextNodes) {
    if(info[node] == 0) sheep++;
    else if(info[node] == 1) wolf++;
    
    if(wolf >= sheep) return;
    
    answer = max(answer, sheep);
    
    for(int i = 0; i<edges.size(); i++) {
        if(edges[i][0] == node) {
            nextNodes.push_back(edges[i][1]);
        }
    }
    
     for (int i = 0; i < nextNodes.size(); i++) {
        int nextNode = nextNodes[i];
        vector<int> next = nextNodes;
        next.erase(next.begin() + i); // 방문할 노드는 제거하고 넘김

        algorithm(info, edges, nextNode, sheep, wolf, next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<int> nextNodes = {};
    algorithm(info, edges, 0, 0, 0, nextNodes);
    
    return answer;
}