#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = INT_MAX;
    int xlen = maps.size();
    int ylen = maps[0].size();
    vector<vector<bool>> isVisited(xlen, vector<bool> (ylen, false));
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    isVisited[0][0] = true;
    
    int count = 1;
    while(!q.empty()) {
        pair<int, int> topq;
        
        topq = q.front();
        q.pop();
        
        for(int i = 0; i<4; i++) {
            int nx = topq.first + dx[i];
            int ny = topq.second + dy[i];
            
            if(0 <= nx && nx < xlen && 0 <= ny && ny < ylen) {
                if(!isVisited[nx][ny] && maps[nx][ny] != 0){
                    isVisited[nx][ny] = true;
                    maps[nx][ny] = maps[topq.first][topq.second] + 1;
                    q.push(pair(nx, ny));   
                }
            }
        }
        
        count++;
    }
    
    if(maps[xlen - 1][ylen - 1] == 1) {
        return -1;
    } else return maps[xlen - 1][ylen - 1];
}