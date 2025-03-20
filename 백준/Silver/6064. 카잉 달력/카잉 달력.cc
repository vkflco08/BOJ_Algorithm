#include <iostream>
using namespace std;

// 1 ≤ M, N ≤ 40,000
// 1 ≤ x ≤ M, 1 ≤ y ≤ N

int calendar(int M, int N, int x, int y) {
    // 0 based index
    x--;
    y--;

    int loopSize = M*N;
    for(int i = x; i<loopSize; i+=M) {
        if (i % N == y) {
            // return 1 based index
            return i + 1;
        }
    }
    return -1;
}

int main() {
    int testCase, M, N, x, y;

    cin >> testCase;

    for(int i = 0; i<testCase; i++){
        cin >> M >> N >> x >> y;

        cout << calendar(M, N, x, y) << endl;
    }
}