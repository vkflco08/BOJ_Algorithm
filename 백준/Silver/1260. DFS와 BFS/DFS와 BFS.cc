#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001][1001];
bool visited[1001]; // DFS
bool isVisit[1001]; // BFS
int N, M, V;

void DFS(int start) {
    visited[start] = true;
    cout << start << " ";

    for (int i = 1; i <= N; i++) {
        if (arr[start][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    isVisit[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i = 1; i <= N; i++) {
            if (arr[cur][i] == 1 && !isVisit[i]) {
                isVisit[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    DFS(V);
    cout << "\n";
    BFS(V);
    cout << "\n";

    return 0;
}
