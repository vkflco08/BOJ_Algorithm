#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    return ab > ba;
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);

    string answer = "";
    for (int n : numbers) {
        answer += to_string(n);
    }

    if (answer[0] == '0') return "0";

    return answer;
}