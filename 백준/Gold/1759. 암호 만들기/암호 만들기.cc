#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int L, C;
vector<char> vec(16);
vector<char> tmpArr(16);
string result;

bool isValid() {
    int vowel = 0, consonant = 0;
    for(int i = 0; i<L; i++){
        if (tmpArr[i] == 'a' || tmpArr[i] == 'e' || tmpArr[i] == 'i' || tmpArr[i] == 'o' || tmpArr[i] == 'u') vowel++;
        else consonant++;
    }
    return (vowel >= 1 && consonant >= 2);
}

void algorithm(int index, int start) {
    if (index == L) {
        if (isValid()) {
            for(int i = 0; i<L; i++){
                result += tmpArr[i];
            }
            result += "\n";
        }
        return;
    }

    for (int i = start; i < C; i++) {
        tmpArr[index] = vec[i];  
        algorithm(index + 1, i + 1);  // 다음 문자 선택
    }
}

int main() {
    cin >> L >> C;

    for(int i = 0; i < C; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.begin() + C);

    algorithm(0, 0);

    cout << result;
}