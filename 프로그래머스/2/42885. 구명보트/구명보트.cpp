#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;
    int answer = 0;
    
    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            // 두 명 함께 탑승
            left++;
            right--;
        } else {
            // 무거운 사람 혼자 탑승
            right--;
        }
        answer++;
    }
    
    return answer;
}