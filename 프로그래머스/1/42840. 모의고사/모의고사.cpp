#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> num = {0, 0, 0};
    vector<int> A = {1, 2, 3, 4, 5}, B = {2, 1, 2, 3, 2, 4, 2, 5}, C = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i<answers.size(); i++) {
        int Ainx, Binx, Cinx;
        if(i == 0){
            Ainx = 0;
            Binx = 0;
            Cinx = 0;
        } else {
            Ainx = i % A.size();
            Binx = i % B.size();
            Cinx = i % C.size();
        }
        
        if(answers[i] == A[Ainx]){
            num[0]++;
        }
        if(answers[i] == B[Binx]){
            num[1]++;
        }
        if(answers[i] == C[Cinx]){
            num[2]++;
        }
    }
    
    int maxNum = num[0];
    maxNum = max(max(num[0], num[1]), num[2]);
    
    for(int i = 0; i<num.size(); i++){
        if(num[i] == maxNum) answer.push_back(i+1);
    }
    
    return answer;
}