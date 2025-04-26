#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int attacksIndex = 0;
    int healIndex = 0;
    int curHealth = health;
    for (int i = 0; i <= 1000; i++) {
        
        if (attacksIndex < attacks.size() && i == attacks[attacksIndex][0]) {  // 공격 시작
            curHealth -= attacks[attacksIndex][1];
            healIndex = 0;
            if (curHealth <= 0) {  // 죽었을 경우
                return -1;
            }
            attacksIndex++;
            
            
        // cout << i << " " << curHealth << " " << endl;
        }
        else if (attacksIndex < attacks.size()) {
            curHealth += bandage[1];
            healIndex++;
            if (healIndex == bandage[0]) {  // 붕대 성공
                curHealth += bandage[2];
                healIndex = 0;
            }
            curHealth = min(curHealth, health); // 최대체력을 넘지 않도록
            
            
        // cout << i << " " << curHealth << " " << endl;
        }
    }
    return curHealth;
}
