#include <iostream>
#include <string>
using namespace std;

int N, M;
int arr[11] = {1};
string output; 

void algorithm(int index){
    if(M < index) {
        for (int i = 1; i <= M; i++) {
            output += to_string(arr[i]) + " ";
        }
        output += "\n";
    } else {
        for(int i = arr[index - 1]; i<=N; i++) {
            arr[index] = i;
            algorithm(index + 1);
        }
    }
}

int main() {
    cin >> N >> M;
    fill(arr, arr + 11, 1);

    algorithm(1);
    cout << output;
}