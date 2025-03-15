#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> row;
stack<int> value;


int solution(string input) {
    
    int answer = 0;

    int tmp = 1;

    for(int i = 0; i < input.length(); i++) {
        char now = input[i];
        if(input[i] == '(') {
            tmp = tmp * 2;
            value.push(now);
        }
        else if(input[i] == '[') {
            tmp = tmp * 3;
            value.push(now);
        }
        else if(input[i] == ')') {
            if(value.empty() || value.top() != '(') {
                answer = 0;
                break;
            }
            if(input[i-1] == '(') {
                answer += tmp;
                tmp = tmp / 2;
                value.pop();
            }
            else {
                tmp = tmp / 2;
                value.pop();

            }
        }
        else if(input[i] == ']') {
            if(value.empty() || value.top() != '[') {
                answer = 0;
                break;
            }
            if(input[i-1] == '[') {
                answer += tmp;
                tmp = tmp / 3;
                value.pop();
            }
            else {
                tmp = tmp / 3;
                value.pop();
            }
        }
    }
    if(!value.empty()) {
        answer = 0;
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