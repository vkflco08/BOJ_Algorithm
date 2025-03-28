#include <iostream>
#include <vector>
#include <algorithm> // next_permutation 사용

using namespace std;

int N;
vector<int> inputArr;
vector<bool> isVisited(N+1);
vector<int> tmpArr(N);

int main() {
    cin >> N;   //N(1 ≤ N ≤ 10,000)

    int tmpInput;
    for(int i = 0; i<N; i++){
        cin >> tmpInput;
        inputArr.push_back(tmpInput);
        tmpArr.push_back(i+1);
    }

    // 이전 순열이 존재하면 출력, 없으면 -1 출력
    if(prev_permutation(inputArr.begin(), inputArr.end())) {
        for(int num : inputArr) {
            cout << num << " ";
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}