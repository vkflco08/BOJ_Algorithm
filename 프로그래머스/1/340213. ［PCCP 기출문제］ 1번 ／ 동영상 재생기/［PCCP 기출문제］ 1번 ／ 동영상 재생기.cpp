#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int timeToSeconds(const string& timeStr) {
    int minutes = stoi(timeStr.substr(0, 2));
    int seconds = stoi(timeStr.substr(3, 2));
    return minutes * 60 + seconds;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int videoLenSec = timeToSeconds(video_len);
    int currentPos = timeToSeconds(pos);
    int opStart = timeToSeconds(op_start);
    int opEnd = timeToSeconds(op_end);
    
    if (currentPos >= opStart && currentPos <= opEnd) {
        currentPos = opEnd;
    }
    
    for (int i = 0; i < commands.size(); i++) {
        string command = commands[i];

        if (command == "prev") {
            currentPos = max(0, currentPos - 10);
        } else if (command == "next") {
            currentPos = min(videoLenSec, currentPos + 10);
        }
        
        if (currentPos >= opStart && currentPos <= opEnd) {
            currentPos = opEnd;
        }
    }
    
    int minutes = currentPos / 60;
    int seconds = currentPos % 60;
    stringstream ss;
    ss << setfill('0') << setw(2) << minutes << ":" << setw(2) << seconds;
    
    return ss.str();
}