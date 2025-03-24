#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int result = -10000 * 4;
int arr[11][11], N, M, K;
bool visited[11][11];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void algorithm(
    int index, int sum
) {
    if(index == K) {
        result = max(result, sum);
        return; 
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j]) continue;

            // 인접한 칸이 방문되었는지 확인
            bool canSelect = true;
            for(int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if(ni >= 0 && ni < N && nj >= 0 && nj < M && visited[ni][nj]) {
                    canSelect = false;
                    break;
                }
            }

            if(canSelect) {
                visited[i][j] = true;
                algorithm(index + 1, sum + arr[i][j]);
                visited[i][j] = false;
            }
        }    
    }
}

int main() {
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            visited[i][j] = false;
        }
    }

    algorithm(0, 0);

    cout << result << endl;
}
