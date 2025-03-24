#include <iostream>
#include <string>
using namespace std;

int N, M;
int arr[11] = {0};
bool visited[11] = {false};
string output; 

void algorithm(int index){
    if(M < index) {
        for (int i = 1; i <= M; i++) {
            output += to_string(arr[i]) + " ";
        }
        output += "\n";
    } else {
        for(int i = arr[index - 1] + 1; i<=N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[index] = i;
                algorithm(index+1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    algorithm(1);
    cout << output;
}