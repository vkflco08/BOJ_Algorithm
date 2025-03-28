#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int N;
vector<int> arr;
int result = -2100000000;

void algorithm() {
    int sum = 0;
    for(int i = 0; i<N - 1; i++){
        sum += abs(arr[i] - arr[i + 1]);
    }
    result = max(result, sum);
}

int main() {
    cin >> N;
    arr.resize(N);

    for(int i = 0; i<N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    do {
        algorithm();
    } while (next_permutation(arr.begin(), arr.end()));

    cout << result;

    return 0;
}