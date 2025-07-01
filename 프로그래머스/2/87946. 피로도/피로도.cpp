#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> index;
    
    for(int i = 0; i<dungeons.size(); i++) {
        index.push_back(i);
    }
    
    do {
        int num = 0, tmpK = k;
        for(int i = 0; i<index.size(); i++){
            if(dungeons[index[i]][0] > tmpK) break;
            tmpK -= dungeons[index[i]][1];
            num++;
        }
        answer = max(answer, num);
    } while(next_permutation(index.begin(), index.end()));
    
    return answer;
}