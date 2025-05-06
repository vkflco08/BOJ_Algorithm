#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int arr[10001] = {0};
    
    for(int i = 1; i<=10000; i++) {
        int sum = 0;
        for(int j = i; sum + j<=10000; j++) {
            sum += j;
            arr[sum]++;    
        }
    }
    return arr[n];
}