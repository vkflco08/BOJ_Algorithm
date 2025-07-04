#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int beforeInx = 0;
    for(int i = 100; i>= 1; i--){
        int maxInx = -1;
        for(int j = 0; j < priorities.size(); j++){
            if(priorities[j] == i){
                maxInx = j;
            }
        }
        if(maxInx == -1) continue;
        
        int tmpInx;
        for(int j = beforeInx; j < priorities.size(); j++){
            if(priorities[j] == i) {
                tmpInx = j;
                answer++;
                priorities[j] = -1;
                if(j == location) return answer;
            }
        }
        
        for(int j = 0; j< beforeInx; j++){
            if(priorities[j] == i) {
                tmpInx = j;
                answer++;
                priorities[j] = -1;
                if(j == location) return answer;
            }
        }
        beforeInx = tmpInx;
    }
    return answer;
}