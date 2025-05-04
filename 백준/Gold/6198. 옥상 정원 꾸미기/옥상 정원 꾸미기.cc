#include <iostream>
#include <algorithm>
#include <stack>


using namespace std;

stack<int> st;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long answer = 0;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if(st.empty()) {
            st.push(input);
            continue;
        }
        while(!st.empty() && st.top() <= input) {
            st.pop();
        }
        answer += (long long)st.size();
        st.push(input);
    }
    cout << answer;
    
    
    return 0;

}
