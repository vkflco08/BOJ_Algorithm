#include <iostream>
#include <vector>
using namespace std;

int N, result = 1000000000;
vector<vector<int>> arr(20, vector<int>(20));
vector<bool> isVisited(20); // 백트래킹 T, F를 통해 팀을 나눔

void calculate(){
    vector<int> s, l;
    int sIndex = 0, lIndex = 0;
    for(int i = 0; i<N; i++){
        if(isVisited[i]) {
            s.push_back(i);
        }
        else {
            l.push_back(i);
        }
    }

    if(s.empty() || l.empty()) return;
        
    int sScore = 0, lScore = 0;

    // 능력치 계산
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            sScore += arr[s[i]][s[j]];
        }
    }
    for (int i = 0; i < l.size(); i++) {
        for (int j = 0; j < l.size(); j++) {
            lScore += arr[l[i]][l[j]];
        }
    }

    result = min(result, abs(sScore - lScore)); 
}

void algorithm(int index) {
    if(index == N) {
        calculate();
        return;
    }

    isVisited[index] = true;
    algorithm(index + 1);

    isVisited[index] = false;
    algorithm(index + 1);
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
        isVisited[i] = false;
    }

    algorithm(0);

    cout << result;
}
