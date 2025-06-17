#include <string>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int dp[121][121][121]; // [index][a_trace][b_trace]
int N, M;

int dfs(const vector<vector<int>>& info, int index, int a, int b) {
    if(a >= N || b >= M) {
        return INT_MAX;
    }
    if(index == info.size()) return a;
    
    int& res = dp[index][a][b];
    if (res != -1) return res;
    
    int takeByA = dfs(info, index + 1, a + info[index][0], b);
    int takeByB = dfs(info, index + 1, a, b + info[index][1]);
    
    return res = min(takeByA, takeByB);
}

int solution(vector<vector<int>> info, int n, int m) {
    N = n;
    M = m;
    
   for (int i = 0; i < 121; i++)
        for (int j = 0; j < 121; j++)
            for (int k = 0; k < 121; k++)
                dp[i][j][k] = -1;

    int answer = dfs(info, 0, 0, 0);
    
    return answer == INT_MAX ? -1 : answer;
}