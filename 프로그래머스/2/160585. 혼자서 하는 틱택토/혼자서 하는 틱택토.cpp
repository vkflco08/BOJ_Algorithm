#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isWin(char c, vector<string>& board) {
    // 가로, 세로
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
    }
    // 대각선
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
    return false;
}

int solution(vector<string> board) {
    int answer = -1;
    int oNum = 0, xNum = 0;
    
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            if(board[i][j] == 'O') oNum++;
            if(board[i][j] == 'X') xNum++;
        }
    }
    
    // O가 먼저 시작하기 때문에 항상 X와 같거나 1크다
    if(oNum < xNum) return 0;
    if(oNum > xNum + 1) return 0;

    bool oWin = isWin('O', board);
    bool xWin = isWin('X', board);

    if (oWin && xWin) return 0; // 둘 다 승리? 불가능
    if (oWin && oNum != xNum + 1) return 0; // O가 이겼는데 숫자 안 맞음
    if (xWin && oNum != xNum) return 0; // X가 이겼는데 숫자 안 맞음

    return 1;
}