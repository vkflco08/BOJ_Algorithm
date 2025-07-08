#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;

void bfs(vector<int>& numbers, int index, int sum, int target) {
    if(numbers.size() == index){
        if(sum == target){
            answer++;
        };  
        return;
    }
    
    bfs(numbers, index + 1, sum + numbers[index], target);
    bfs(numbers, index + 1, sum - numbers[index], target);
}

int solution(vector<int> numbers, int target) {
    bfs(numbers, 0, 0, target);
    return answer;
}