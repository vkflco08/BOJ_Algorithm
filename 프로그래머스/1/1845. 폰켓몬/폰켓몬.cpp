#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> map;
    
    for(int n: nums){
        map[n]++;
    }
        
    int answer = 0;
    for(int i = 1; i<=map.size(); i++){
        if(map[i] > 0){
            map[i]--;
            answer++;
            if(answer >= nums.size()/2){
                return answer;
            }
        }
    }

    return answer;
}