#include <iostream>
using namespace std;
const int MOD = 9901;
int main() {
    int N;
    cin >> N;

    int arr[100001][3];
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 1;

    for(int i = 1; i < 100001; i++) {
        arr[i][0] = (arr[i-1][0] + arr[i-1][1] + arr[i-1][2]) % MOD;
        arr[i][1] = (arr[i-1][0] + arr[i-1][2]) % MOD;
        arr[i][2] = (arr[i-1][0] + arr[i-1][1]) % MOD;
    }

    cout << (arr[N-1][0] + arr[N-1][1] + arr[N-1][2]) % MOD << endl;
}
