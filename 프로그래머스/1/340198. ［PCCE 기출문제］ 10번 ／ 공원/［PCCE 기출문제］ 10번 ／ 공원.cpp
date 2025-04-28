#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(int mat, vector<vector<string>> park, int i, int j) {
        if (i + mat > park.size() || j + mat > park[0].size()) {
        return false;
    }
    
    for(int k = i; k < i + mat; k++){
        for(int l = j; l < j + mat; l++){
            if(park[k][l] != "-1") return false;
        }
    }    
    return true;
}

bool travel(int mat, vector<vector<string>> park) {
    
    if (mat > park.size() || mat > park[0].size()) return false;
    
    for(int i = 0; i <= park.size() - mat; i++){
        for(int j = 0; j <= park[0].size() - mat; j++){
            if(park[i][j] == "-1") {
                if(check(mat, park, i, j)) {
                    return true;                
                }
            }
        }
    }    
    return false;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    for(int i = 0; i < mats.size(); i++){
        if(travel(mats[i], park)){
            answer = max(answer, mats[i]);
        }
    }
    return answer;
}