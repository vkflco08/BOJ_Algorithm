#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int jobNum = jobs.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> jobq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    
    for(int i = 0; i<jobs.size(); i++) {
        jobq.push({jobs[i][0], jobs[i][1]});
    }
    
    int time = 0, workTime = 0;
    pair<int, int> work;
    int done = 0;
    bool isWork = false;
    while(done != jobNum) {
        // 다른 요청이 있을 경우 대기 큐에 저장
        while (!jobq.empty() && jobq.top().first <= time) {
            // 작업시간이 짧은 요청을 먼저 실행하기 위해 작업시간을 first로 입력
            q.push({jobq.top().second, jobq.top().first}); // (작업시간, 요청시각)
            jobq.pop();
        }
        
        // 작업이 끝난 경우 확인
        if(isWork && workTime >= work.first) {
            answer += time - work.second;
            isWork = false;
            done++;
        }
        
        // 작업중이 아닐 경우 우선순위에 맞게 작업 시작
        if(!isWork && q.size() > 0) {
            isWork = true;
            workTime = 0;
            work = q.top();
            q.pop();
        }
        
        if(isWork) workTime++;
        time++;
    }
    
    return answer/jobNum;
}