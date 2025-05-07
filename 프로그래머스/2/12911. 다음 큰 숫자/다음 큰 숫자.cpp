#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string toBinary(int n) {
    if (n == 0) return "0";
    string result = "";
    while(n > 0){
        result += (n%2) + '0';
        n/=2;
    }
    reverse(result.begin(), result.end());
    return result;
}

bool check(string n, string m) {
    int len = max(n.length(), m.length());
    int nNum = 0, mNum = 0;
    for(int i = 0; i<len; i++){
        if(n[i] == '1'){
            nNum++;
        }
        if(m[i] == '1'){
            mNum++;
        }
    }
    if(nNum == mNum) return true;
    else return false;
}

int solution(int n) {
    int answer = 0;
    string binaryN = toBinary(n);
    for(int i = n+1; ; i++){
        if(check(binaryN, toBinary(i))){
            return i;
        }
    }
    
    return answer;
}