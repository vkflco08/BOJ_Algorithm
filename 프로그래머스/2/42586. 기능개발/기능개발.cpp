#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int progressIndex = 0;
    while(progressIndex < progresses.size()){
        for(int i = 0; i<progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        
        int sum = 0;
        for(int j = progressIndex; j<progresses.size(); j++) {
            if(progresses[j] < 100) break;
            else sum++;
        }
        
        if(sum > 0) {
            progressIndex += sum;
            answer.push_back(sum);
        }
    }
    
    return answer;
}