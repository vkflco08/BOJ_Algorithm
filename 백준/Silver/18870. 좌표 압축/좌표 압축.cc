#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<int> sorted = arr; // 복사
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); // 중복 제거

    for (int i = 0; i < N; ++i) {
        int compressed = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin();
        cout << compressed << " ";
    }
    cout << '\n';

    return 0;
}
