#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <climits> 

using namespace std;

string solution(string s) {
    string answer = "";
    int num;
    int max_val = INT_MIN;
    int min_val = INT_MAX;

    stringstream ss(s);  // 문자열 스트림 생성
    while (ss >> num) {
        max_val = max(max_val, num);
        min_val = min(min_val, num);
    }

    answer = to_string(min_val) + " " + to_string(max_val);
    return answer;
}