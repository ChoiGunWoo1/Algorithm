#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

stack<char> st;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    int answer = 0;
    cin >> n;

    while(n--) {
        cin >> s;
        for(int i = 0; i < s.length(); i++) {
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }
            if(st.top() == s[i]) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }

        }
        if(st.empty()) {
            answer++; 
        }
        else {
            while(!st.empty()) {
                st.pop();
            }
        }
    }
    cout << answer;
    
    
    return 0;

}
