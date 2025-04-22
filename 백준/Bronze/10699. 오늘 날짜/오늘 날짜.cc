#include <iostream>
#include <iomanip> 
#include <ctime>   
using namespace std;

int main() {
    time_t t = time(nullptr);        // 현재 시간 가져오기
    tm* now = localtime(&t);         // 지역 시간으로 변환

    // 출력 형식: yyyy dd mm
    cout << (now->tm_year + 1900) << "-"
        << setw(2) << setfill('0') << (now->tm_mon + 1) << "-"
        << setw(2) << setfill('0') << now->tm_mday
        << endl;

    return 0;
}