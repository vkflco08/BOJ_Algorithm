#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;
        arr[i] = arr[i - 1] + input;
    }

    while (M--) {
        int L, R;
        cin >> L >> R;
        cout << arr[R] - arr[L - 1] << '\n';
    }
    return 0;
}