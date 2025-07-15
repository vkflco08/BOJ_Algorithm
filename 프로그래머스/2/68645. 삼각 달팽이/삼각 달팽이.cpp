#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> arr(n, vector<int>(n, 0));
    
    int inx = 1;
    int loopCount = 0;
    int ver = 1; // 1일때 아래로, 2일때 오른쪽으로, 3일때 좌상향 대각선으로
    int x = 0, y = 0;
    arr[x][y] = 1;
    while(loopCount < n) {
        if(ver == 1) {
            while(x + 1 < n && arr[x + 1][y] == 0) {
                x++;
                inx++;
                arr[x][y] = inx;
            }
            loopCount++;
        } else if (ver == 2) {
             while(y + 1 < n && arr[x][y + 1] == 0) {
                y++;
                inx++;
                arr[x][y] = inx;
            }
            loopCount++;
        } else if (ver == 3) {
             while(x - 1 >= 0 && y - 1 >= 0 && arr[x - 1][y - 1] == 0) {
                x--; y--;
                inx++;
                arr[x][y] = inx;
            }
            loopCount++;
        }
        
        if(ver == 3) ver = 1;
        else ver++;
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}