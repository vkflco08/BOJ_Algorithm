#include <iostream>
#include <queue>
using namespace std;
int arr[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[1001][1001] = {0};
int n, m;
int startX, startY;

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = 0; // 출발점의 거리 = 0

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // 범위 체크 및 방문 여부 확인
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                if (arr[newX][newY] == 1 && visited[newX][newY] == -1) {
                    visited[newX][newY] = visited[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                startX = i;
                startY = j;
            }
            if(arr[i][j] == 0){
                visited[i][j] = 0; // 장애물인 경우
            } else {
                visited[i][j] = -1; // 방문하지 않은 경우
            }
        }
    }
    visited[startX][startY] = 1;
    
    bfs(startX, startY);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}