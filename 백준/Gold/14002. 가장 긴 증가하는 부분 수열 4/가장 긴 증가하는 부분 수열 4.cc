#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    vector<int> dp(N, 1);
    vector<int> prev(N, -1);
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int maxLen = 1, lastIndex = 0;
    
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(A[j] < A[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if(dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    vector<int> LIS;
    for(int i = lastIndex; i != -1; i = prev[i]) {
        LIS.push_back(A[i]);
    }
    reverse(LIS.begin(), LIS.end());

    cout << maxLen << endl;
    for(int num : LIS) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}