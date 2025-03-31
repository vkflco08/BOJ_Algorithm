#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[10][10];
bool isVisited[10];
int result = 10000000;

void algorithm(int index, int start, int current, int sum) {
    if (index == N) {  
        // 마지막 도착 도시에서 출발점으로 돌아오는 길이 있어야 함
        if (arr[current][start] != 0) {  
            result = min(result, sum + arr[current][start]);  
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!isVisited[i] && arr[current][i] != 0) {  
            isVisited[i] = true;
            algorithm(index + 1, start, i, sum + arr[current][i]);
            isVisited[i] = false;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        fill(isVisited, isVisited + N, false); 
        isVisited[i] = true;
        algorithm(1, i, i, 0);
    }

    cout << result;
}
