#include <iostream>
using namespace std;

const int MOD = 1000000009;
const int MAX = 1000000;

int main() {
    int T;
    cin >> T;

    int arr[MAX + 1] = {0};
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for (int i = 4; i <= MAX; i++) {
        arr[i] = ((arr[i - 1] + arr[i - 2]) % MOD + arr[i - 3]) % MOD;
    }

    while (T--) {
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }

    return 0;
}