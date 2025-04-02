#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> p(N + 1);
    vector<int> dp(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        dp[i] = p[i];
    }

    for (int i = 1; i <= N; i++) { 
        for (int j = 1; j <= i; j++) { 
            dp[i] = min(dp[i], dp[i - j] + p[j]);
        }
    }
    
    cout << dp[N] << endl;
    return 0;
}
