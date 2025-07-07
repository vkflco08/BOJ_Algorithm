#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    int answer = n - lost.size();
    
    for(int i = 0; i<lost.size(); i++) {
        for(int j = 0; j<reserve.size(); j++) {
            if(lost[i] == reserve[j] && lost[i] != -1){
                lost[i] = -1;
                reserve[j] = -1;
                answer++;
            }
        }
    }
    
    for(int i = lost.size() - 1; i >= 0; i--) {
        for(int j = reserve.size() - 1; j >= 0; j--) {
            if((lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]) && lost[i] != -1 && reserve[j] != -1) {
                answer++;
                reserve[j] = -1;
                break;
            }
        }
    }
    
    return answer;
}