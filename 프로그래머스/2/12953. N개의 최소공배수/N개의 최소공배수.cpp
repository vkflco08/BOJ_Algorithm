#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    int index = 2;
    while(index < arr[arr.size() - 1]) {
        int checkNum = arr[arr.size() - 1] * index;
        for(int i = 0; i<arr.size(); i++) {
            if(checkNum % arr[i] != 0) break;
            else if(i == arr.size() - 1) return checkNum;
        }    
        index++;
    }
}