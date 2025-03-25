#include <iostream>
#include <vector>
using namespace std;

int N, result = 1000000000;
vector<vector<int>> arr(20, vector<int>(20));
vector<bool> isVisited(20); // 백트래킹 T, F를 통해 팀을 나눔

void calculate(){
    vector<int> s(10), l(10);
    int sIndex = 0, lIndex = 0;
    for(int i = 0; i<N; i++){
        if(isVisited[i]) {
            s[sIndex] = i;
            sIndex++;
        }
        else {
            l[lIndex] = i;
            lIndex++;
        }
    }
        
    int sScore = 0, lScore = 0;

    // 능력치 계산
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            if (i == j) continue;  // 자기 자신은 제외
            sScore += arr[s[i]][s[j]];
            lScore += arr[l[i]][l[j]];
        }
    }

    result = min(result, abs(sScore - lScore)); 
}

void algorithm(int start, int index) {
    if(index == N / 2) {
        calculate();
        return;
    }

    for(int i = start; i < N; i++) {
        if(!isVisited[i]) {
            isVisited[i] = true;
            algorithm(i + 1, index + 1);
            isVisited[i] = false;
        }
    }
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
        isVisited[i] = false;
    }

    algorithm(0, 0);

    cout << result;
}
