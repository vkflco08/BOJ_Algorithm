#include <iostream>
#include <vector>
#include <cstdlib> // exit() 함수 사용을 위해 필요
using namespace std;

int N;
vector<vector<char>> inputArr(10, vector<char>(10));
vector<int> arr(10);

bool checkAlgorithm(int index) {
    int sum = 0;
    for (int i = index; i >= 0; i--) {
        sum += arr[i];
        if ((sum == 0 && inputArr[i][index] != '0') ||
            (sum > 0 && inputArr[i][index] != '+') ||
            (sum < 0 && inputArr[i][index] != '-')) {
            return false;
        }
    }
    return true;
}

void algorithm(int index) {
    if (index == N) {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        exit(0); // 정답 하나만 출력 후 종료
    }

    for (int i = -10; i <= 10; i++) {
        arr[index] = i;
        if (checkAlgorithm(index)) {
            algorithm(index + 1);
        }
    }
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            cin >> inputArr[i][j];
        }
    }

    algorithm(0);
}
