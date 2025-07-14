#include <string>
#include <vector>
#include <climits>
#include <deque>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 0};
    
    int sum = sequence[0], start = 0, end = 0;
    int seqlen = INT_MAX;
    
    while (end < sequence.size()) {
        if (sum < k) {
            end++;
            if (end < sequence.size()) sum += sequence[end];
        } 
        if (sum > k) {
            sum -= sequence[start];
            start++;
        } 
        if (sum == k) {
            if (end - start < seqlen) {
                seqlen = end - start;
                answer = {start, end};
            }
            sum -= sequence[start];
            start++;
        }
    }
    
    return answer;
}