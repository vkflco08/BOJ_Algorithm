#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int dh[4] = {0, 1, -1, 0}, dw[4] = {1, 0, 0, -1};
    int count = 0;
    for(int i = 0; i<4; i++){
        if(0 <= h + dh[i] && h + dh[i] < board.size() && 0 <= w + dw[i] && w + dw[i] < board.size()) {
            if(board[h][w] == board[h + dh[i]][w + dw[i]]) {
                count++;
            }
        }
    }

    return count;
}