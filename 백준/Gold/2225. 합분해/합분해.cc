#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1000000000;

int main() {
    int N, K;    
    cin >> N >> K;

    int dp[201][201] = {0};
    
    for(int i = 0; i<=N; i++){
        dp[1][i] = 1;
    }

    for (int k = 2; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            for (int i = 0; i <= n; i++) {
                dp[k][n] = (dp[k][n] + dp[k - 1][n - i]) % MOD;
            }
        }
    }

    cout << dp[K][N] << endl;
}