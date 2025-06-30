#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool isprime(int input) {
    if(input <= 1) return false;
    for(int i = 2; i<= sqrt(input); i++){
        if(input % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    unordered_set<int> uniqueNumbers;
    sort(numbers.begin(), numbers.end());

    do {
        for(int len = 1; len <= numbers.size(); ++len) {
            int num = stoi(numbers.substr(0, len));
            uniqueNumbers.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    int answer = 0;
    for(int n : uniqueNumbers) {
        if(isprime(n)) answer++;
    }

    return answer;
}