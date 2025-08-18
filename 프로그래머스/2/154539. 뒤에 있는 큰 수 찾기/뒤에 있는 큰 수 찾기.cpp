#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> answer(n, -1);
    
    stack<int> s;
    
    for(int i = 0; i<n; ++i) {
        while(!s.empty() && numbers[s.top()] < numbers[i]) {
            int index = s.top();
            s.pop();
            answer[index] = numbers[i];
        }
        s.push(i);
    }
    
    return answer;
}