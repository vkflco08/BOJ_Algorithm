#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> rank;
    
    for (int i = 0; i < players.size(); ++i) {
        rank[players[i]] = i;
    }

    for (const string& name : callings) {
        int idx = rank[name];

        swap(players[idx], players[idx - 1]);

        rank[players[idx]] = idx;
        rank[players[idx - 1]] = idx - 1;
    }

    return players;
}