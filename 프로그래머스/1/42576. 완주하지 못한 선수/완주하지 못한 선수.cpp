#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> map;
    
    for(auto name : completion) {
        map[name]++;
    }
    
    for(auto name : participant) {
        map[name]--;
        if(map[name] < 0) return name;
    }
        
    for(auto p : map){
        if(p.second != 0) return p.first;
    }
    
    return "";
}