#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<pair<int, int>> seq;
    vector<double> size;
    
    // 그래프 값 계산
    int x = 0;
    seq.push_back({x, k});
    while(k != 1) {
        x++;
        if(k%2 == 0) {
            k = k/2;
        } else if(k%2 == 1) {
            k = k*3 + 1;
        }
        seq.push_back({x, k});
    }
    
    // 각 구간 넓이 계산
    for(int i = 1; i<seq.size(); i++) {
        double hy = max(seq[i - 1].second, seq[i].second), ly = min(seq[i - 1].second, seq[i].second);
        size.push_back(hy - ((hy - ly) / 2.0));
    }
    
    double sum;
    for(int i = 0; i<ranges.size(); i++) {
        sum = 0;
        int start = ranges[i][0];
        int end = (int)size.size() + ranges[i][1];
        
        cout << start << " " << end << endl;

        if (start > end) {
            answer.push_back(-1.0);
            continue;
        }

        for (int j = start; j < end; j++) {
            sum += size[j];
        }
        
        answer.push_back(sum);
    }
    
    return answer;
}