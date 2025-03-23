#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    int result = 0;
    int count = 1; // 몇자리수까지 있는지 확인
        

    for(int i = 10; i<=100000000; i *= 10) {
        if(N/i == 0){
            break;
        }
        count++;
    }

    // 1 - 9 1자리 9개 = 9
    // 10 - 99 2자리 90개 = 180
    // 100 - 999 3자리 900개

    for(int i = 1; i<count; i++){
        result += 9 * pow(10, i-1) * i;
        N -= 9 * pow(10, i-1);
    }
    
    result += count * N;

    cout << result << endl;
}