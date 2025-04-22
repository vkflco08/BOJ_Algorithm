#include <iostream>
using namespace std;

int main() {
    int arr[201] = {0};
    int N, V, tmp;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        arr[tmp + 100]++;
    }

    cin >> V;
    cout << arr[V + 100] << endl;

    return 0;
}