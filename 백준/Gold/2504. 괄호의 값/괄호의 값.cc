#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


stack<char> comp;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int answer = 0;
    int temp = 1;
    for(int i = 0; i < s.length(); i++) {
        char now = s[i];
        if(now == '(') {
            temp *= 2;
            comp.push(now);
        }
        else if(now == '[') {
            temp *= 3;
            comp.push(now);
        }
        else if(now == ')') {
            if(comp.empty() || comp.top() != '(') {
                answer = 0;
                break;
            }
            if(s[i-1] == '(') {
                answer += temp;
                temp /= 2;
            }
            else {
                temp /=2;
            }
            comp.pop();
        }
        else if(now == ']') {
            if(comp.empty() || comp.top() != '[') {
                answer = 0;
                break;
            }
            if(s[i-1] == '[') {
                answer += temp;
                temp /= 3;
            }
            else {
                temp /= 3;
            }
            comp.pop();
        }
        
    }
    if(!comp.empty()) {
        answer = 0;
    }
    
    cout << answer;
    


    return 0;
}
