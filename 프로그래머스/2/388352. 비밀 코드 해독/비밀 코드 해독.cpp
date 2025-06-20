#include <string>
#include <vector>

using namespace std;

int check(vector<int> test, vector<vector<int>> q, vector<int> ans){
    for(int i = 0; i<q.size(); i++){
        int same = 0;
        for(int j = 0; j<q[0].size(); j++) {
            for(int t = 0; t < test.size(); t++) {
                if(test[t] == q[i][j]){
                    same++;
                    break;
                }
            }
        }
        if(same != ans[i]){
            return 0;
        }
    }
    return 1;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    for(int i = 1; i<=n - 4; i++){
        for(int j = i+1; j<=n - 3; j++){
            for(int k = j+1; k<=n - 2; k++){
                for(int l = k+1; l<=n - 1; l++){
                    for(int m = l+1; m<=n; m++){
                        vector<int> test = {i, j, k, l, m};
                        answer += check(test, q, ans);
                    }   
                }   
            }   
        }   
    }
    
    return answer;
}