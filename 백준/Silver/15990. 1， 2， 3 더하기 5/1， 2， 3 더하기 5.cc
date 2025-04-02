#include <iostream>
#include <vector>

#define MOD 1000000009  // 값이 너무 커지지 않도록 MOD 사용
using namespace std;

int main() {
	int T;
	cin >> T;

	vector<vector<long long>> dp(100001, vector<long long>(4, 0));
    int result[100001];
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;


	for (int i = 4; i<=100000; i++) {
		dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
	}

    int n;
    for(int i = 0; i<T; i++) {    
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD << endl;
    }
}
