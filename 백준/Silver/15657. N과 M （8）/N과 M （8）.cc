#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[11] = {1};
string output; 
int tmpIndex=0;

void algorithm(int index, vector<int> inputArr){
    if(M < index) {
        for (int i = 0; i < M; i++) {
            output += to_string(arr[i]) + " ";
        }
        output += "\n";
    } else {
        for(int i = tmpIndex; i<N; i++) {
            arr[index - 1] = inputArr[i];
            tmpIndex = i;
            algorithm(index + 1, inputArr);
        }
    }
}

int main() {
    cin >> N >> M;
    fill(arr, arr + 11, 1);

    vector<int> inputArr(N);
    
    for(int i = 0; i<N; i++){
        cin >> inputArr[i];
    }

    sort(inputArr.begin(), inputArr.end());

    algorithm(1, inputArr);
    cout << output;
}
