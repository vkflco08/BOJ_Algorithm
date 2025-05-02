#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1, right = 100000;
    int answer = right;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        long long timeLimit = 0;

        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] <= mid) {
                timeLimit += times[i];
            } else {
                int mistakes = diffs[i] - mid;
                int time_prev = (i == 0) ? 0 : times[i - 1];
                timeLimit += (long long)(times[i] + time_prev) * mistakes + times[i];
            }
            
            if(timeLimit > limit) break;
        }

        if (timeLimit <= limit) {
            answer = mid;
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }

    return answer;
}
