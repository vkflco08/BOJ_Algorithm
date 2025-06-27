#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> q(scoville.begin(), scoville.end());
    
    while(q.size() >= 2 && q.top() < K) {
        int first = q.top(); q.pop();
        int second = q.top(); q.pop();
        
        q.push(first + (second * 2));
        answer++;
    }
    
    // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
    if(q.top() < K) return -1;
    
    return answer;
}