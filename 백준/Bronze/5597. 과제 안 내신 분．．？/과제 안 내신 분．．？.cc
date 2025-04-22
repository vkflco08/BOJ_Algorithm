#include <iostream>
using namespace std;

int main() {
    int arr[31] = {0};
    int tmp;

    for(int i = 0; i < 28; i++) { 
        cin >> tmp;
        arr[tmp]++;
    }

    for(int i = 1; i <= 30; i++) {
        if(arr[i] == 0) {
            cout << i << endl;
        }
    }

    return 0;
}