#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    for(int height = 3; height <= total / 3; height++) {
        if (total % height != 0) continue;
        int width = total / height;

        if ((width - 2) * (height - 2) == yellow) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }
    return answer;
}