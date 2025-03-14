#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> state;
stack<char> laser;
stack<char> bar;

int solution(string input) {
    int answer = 0;
    for(int i = 0; i < input.length(); i++) {
        state.push(input[i]);
    }
    while(!state.empty()) {
        char out = state.top();
        state.pop();
        if(out == ')') {
            if(laser.empty()) {
                laser.push(out);
            }
            else {
                laser.pop();
                bar.push(out);
                laser.push(out);
                answer++;
            }
        }
        else {
            if(laser.empty()) {
                bar.pop();
            }
            else {
                laser.pop();
                answer += bar.size();
            }
        }
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string i;
    cin >> i;
    cout << solution(i);

    

    return 0;
}