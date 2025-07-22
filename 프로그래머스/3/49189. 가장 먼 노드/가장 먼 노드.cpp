#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> isVisited(n + 1);
    vector<int> route;
    
    route.push_back(1);
    isVisited[1] = 1;
    
    while(!route.empty()) {
        int node = route.front();
        route.erase(route.begin());
        
        for(int i = 0; i<edge.size(); i++) {
            if(edge[i][0] == node && isVisited[edge[i][1]] == 0) {
                route.push_back(edge[i][1]);
                isVisited[edge[i][1]] = isVisited[node] + 1;
            } else if(edge[i][1] == node && isVisited[edge[i][0]] == 0) {
                route.push_back(edge[i][0]);
                isVisited[edge[i][0]] = isVisited[node] + 1;
            }
        }
    }
    
    int maxDistance = 0;
    for(int i = 1; i < isVisited.size(); i++) {
        maxDistance = max(maxDistance, isVisited[i]);
    }

    for(int i = 1; i < isVisited.size(); i++) {
        if(isVisited[i] == maxDistance) {
            answer++;
        }
    }
    
    return answer;
}