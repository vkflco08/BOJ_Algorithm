#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> Ti, Pi;
int result = 0;

void algorithm(int day, int sum) {
    if (day > N) {  
        result = max(result, sum);
        return;
    }

    algorithm(day + 1, sum);

    if (day + Ti[day] - 1 <= N) {
        algorithm(day + Ti[day], sum + Pi[day]);
    }
}

int main() {
    cin >> N;

    Ti.resize(N + 1);
    Pi.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> Ti[i] >> Pi[i];
    }

    algorithm(1, 0);

    cout << result;
}
