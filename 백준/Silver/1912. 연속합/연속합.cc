#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int dp[size];
    dp[0] = arr[0];
    int maxSum = dp[0];

    for (int i = 1; i < size; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        maxSum = max(maxSum, dp[i]);
    }

    cout << maxSum << endl;
    return 0;
}