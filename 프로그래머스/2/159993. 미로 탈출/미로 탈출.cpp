#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

pair<int, int> S, E, L;
vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

int algorithm(pair<int, int> start, char target, vector<string> maps) {
    int xlen = maps.size(), ylen = maps[0].size();
    vector<vector<int>> count (xlen, vector<int> (ylen, -1));
    queue<pair<int, int>> q;
    q.push(start);
    count[start.first][start.second] = 0;
        
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        if(maps[current.first][current.second] == target){
            return count[current.first][current.second];
        }
        
        for(int i = 0; i<4; i++) {
            int x = current.first + dx[i];
            int y = current.second + dy[i];
            if(0 <= x && x < xlen && 0 <= y && y < ylen) {
                if(count[x][y] == -1 && maps[x][y] != 'X') {
                    count[x][y] = count[current.first][current.second] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;

    for(int i = 0; i<maps.size(); i++) {
        for(int j =0; j<maps[0].size(); j++) {
            if(maps[i][j] == 'S'){
                S = {i, j};
            }
            if(maps[i][j] == 'E'){
                E = {i, j};
            }
            if(maps[i][j] == 'L'){
                L = {i, j};
            }
        }
    }
    
    int dist1 = algorithm(S, 'L', maps);
    if(dist1 == -1) return -1;
    
    int dist2 = algorithm(L, 'E', maps);
    if(dist2 == -1) return -1;
    
    return dist1 + dist2;
}