#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> combinationCount;

void makeCombination(string order, string comb, int index, int count) {
    if(comb.size() == count) {
        combinationCount[comb]++;
    }    
    for(int i = index; i<order.size(); i++) {
        makeCombination(order, comb + order[i], i+1, count);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int c : course) {
        combinationCount.clear();
        
        for(string s : orders) {
            sort(s.begin(), s.end());
            makeCombination(s, "", 0, c);
        }
        
        int maxCount = 0;
        for(auto& it : combinationCount) {
            if(it.second > maxCount) {
                maxCount = it.second;
            }
        }
        
        if(maxCount >= 2) {
            for(auto& it : combinationCount) {
                if(it.second == maxCount) {
                    answer.push_back(it.first);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}