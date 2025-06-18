#include <string>
#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

int check[100][100];
int W, H;

void travel(int x, int y, int cnt, const vector<string>& board) {
    if (check[x][y] <= cnt) return;
    check[x][y] = cnt;

    // 상
    int ny = y;
    while (ny > 0 && board[x][ny - 1] != 'D') ny--;
    if (ny != y) travel(x, ny, cnt + 1, board);

    // 하
    ny = y;
    while (ny + 1 < H && board[x][ny + 1] != 'D') ny++;
    if (ny != y) travel(x, ny, cnt + 1, board);

    // 좌
    int nx = x;
    while (nx > 0 && board[nx - 1][y] != 'D') nx--;
    if (nx != x) travel(nx, y, cnt + 1, board);

    // 우
    nx = x;
    while (nx + 1 < W && board[nx + 1][y] != 'D') nx++;
    if (nx != x) travel(nx, y, cnt + 1, board);
}

int solution(vector<string> board) {
    int answer = 0;
    W = board.size();
    H = board[0].size();
    
    for(int i = 0; i<W; i++){
        for(int j = 0; j<H; j++){
            check[i][j] = INT_MAX;
        }
    }
    
    int startX, startY, endX, endY;
    for(int i = 0; i<W; i++){
        for(int j = 0; j<H; j++){
            if(board[i][j] == 'R') {
                startX = i;
                startY = j;
            }
            if(board[i][j] == 'G') {
                endX = i;
                endY= j;
            }
        }
    }
    
    travel(startX, startY, 0, board);
    
    for(int i = 0; i<W; i++){
        for(int j = 0; j<H; j++){
            cout << check[i][j] << " ";
        }
        cout << endl;
    }
    
    return check[endX][endY] == INT_MAX ?  -1 : check[endX][endY];
}