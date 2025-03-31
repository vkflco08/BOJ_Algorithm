#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void printCombination(vector<int> &arr, int index, vector<int> &current) {
    if (current.size() == 6) {
        for (int num : current) cout << num << " ";
        cout << endl;
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        current.push_back(arr[i]);
        printCombination(arr, i + 1, current);
        current.pop_back();
    }
}

int main() {
    int N = 1;


    while(true){
        cin >> N;
        if(N == 0) return 0;

        vector<int> arr;
        int input;
        for(int i = 0; i<N; i++){
            cin >> input;
            arr.push_back(input);
        }

        vector<int> current;
        printCombination(arr, 0, current);
        cout << endl;
    }

    return 0;
}
