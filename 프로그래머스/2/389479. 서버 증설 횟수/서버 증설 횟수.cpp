#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> active(24, 0); 

    for (int i = 0; i < 24; i++) {
        int need = players[i] / m;
        int running = active[i];

        if (need > running) {
            int toAdd = need - running;
            answer += toAdd;

            for (int j = i; j < min(24, i + k); j++) {
                active[j] += toAdd;
            }
        }
    }

    return answer;
}