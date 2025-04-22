#include <iostream>
#include <iomanip> 
#include <ctime>   
using namespace std;

int main() {
    long long result = 0, tmp;
    for(int i = 0; i<3; i++){
        cin >> tmp;
        result += tmp;
    }
    cout << result;
    return 0;
}