#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long r1r1 = 1LL*r1*r1, r2r2 = 1LL*r2*r2;
    
    for (int i = 1; i <= r2; i++) {
        long long ii = 1LL * i * i;

        // j 최소값
        int j_min = ii < r1r1 ? ceil(sqrt(r1r1 - ii)) : 1;
        // j 최대값
        int j_max = floor(sqrt(r2r2 - ii));

        if(j_min == 0) j_min = 1;
        
        answer += j_max - j_min + 1;   
    }
    
    int line = r2 - r1 + 1;
    
    return answer * 4 + line*4;
}