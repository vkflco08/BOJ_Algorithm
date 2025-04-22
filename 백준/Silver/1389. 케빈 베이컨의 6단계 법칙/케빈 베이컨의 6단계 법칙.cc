#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, M;
vector<vector<int>> graph;

int bfs(int start) {
    vector<int> visited(N + 1, -1);
    queue<int> q;

    visited[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int next : graph[cur]) {
            if (visited[next] == -1) {
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += visited[i];
    }
    return sum;
}

int main() {
    cin >> N >> M;
    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int minBacon = INT_MAX;
    int answer = 0;

    for (int i = 1; i <= N; i++) {
        int sum = bfs(i);
        if (sum < minBacon) {
            minBacon = sum;
            answer = i;
        }
    }

    cout << answer << endl;
    return 0;
}