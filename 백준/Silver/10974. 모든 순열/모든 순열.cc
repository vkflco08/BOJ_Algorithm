#include <iostream>
#include <vector>
#include <algorithm> // next_permutation 사용
#include <string>

using namespace std;

int N;
vector<int> arr;

int main() {
    cin >> N;   //N(1 ≤ N ≤ 10,000)

    int tmpInput;
    for(int i = 0; i<N; i++){
        arr.push_back(i + 1);
    }

    string result = "";
    do{
        for(int i = 0; i<N; i++){
            result += to_string(arr[i]) + " ";
        }
        result += "\n";
    } while(next_permutation(arr.begin(), arr.end()));

    cout << result;
    
    return 0;
}