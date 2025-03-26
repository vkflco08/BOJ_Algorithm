#include <iostream>
#include <vector>
using namespace std;

int K;
vector<char> arr(11);
vector<int> tmpArr(11);
vector<bool> isVisited(11);

vector<int> resultMax(11), resultMin(11);

void algorithm(int index){
    bool maxTrans = false, minTrans = false;
    if(index == K+1) {
        // 출력할 정수 크기 비교
        for(int i = 0; i<K + 1; i++){
            if(resultMax[i] < tmpArr[i]){
                maxTrans = true;
                break;
            } else if (resultMax[i] > tmpArr[i]) break;
        }
        for(int i = 0; i<K + 1; i++){
            if(resultMin[i] > tmpArr[i]) {
                minTrans = true;
                break;
            } else if (resultMin[i] < tmpArr[i]) break;
        }

        if(maxTrans){
            for(int i = 0; i<K + 1; i++){
                resultMax[i] = tmpArr[i];
            }
        }
        if(minTrans){
            for(int i = 0; i<K + 1; i++){
                resultMin[i] = tmpArr[i];
            }
        }
        return;
    }

    for(int i = 0; i<=9; i++) {
        // 이전 숫자와 겹치지 않게
        if(!isVisited[i]){
            // 첫 자리의 경우 이전이랑 비교하지 않고 탐색
            if(index == 0){
                isVisited[i] = true;
                tmpArr[index] = i;
                algorithm(index + 1);
                isVisited[i] = false;
            } else {
                // 아닐 경우 이전 숫자랑 부등호에 맞게 탐색
                if((arr[index - 1] == '<' && tmpArr[index - 1] < i) || 
                (arr[index - 1] == '>' && tmpArr[index - 1] > i)){
                    isVisited[i] = true;
                    tmpArr[index] = i;
                    algorithm(index + 1);
                    isVisited[i] = false;
                }
            }
        }
    }
}

int main(){
    cin>> K;

    for(int i = 0; i<K; i++){
        cin >> arr[i];
    }

    for(int i = 0; i<K+1; i++){
        isVisited[i] = false;
        resultMin[i] = 9;
        resultMax[i] = 0;
    }

    algorithm(0);

    for(int i = 0; i<K + 1; i++){
        cout << resultMax[i];
    }
    cout << endl;
    for(int i = 0; i<K + 1; i++){
        cout << resultMin[i];
    }
}
