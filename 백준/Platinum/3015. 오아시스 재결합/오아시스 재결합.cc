#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int line[500001];
stack<pair<int, int>> st;
int N;
long answer = 0;

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> line[i];
    }
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        while(!st.empty() && line[i] >= st.top().first) {
            answer += st.top().second;
            if(st.top().first == line[i]) {
                cnt += st.top().second;
            }
            st.pop();
        }
        if(!st.empty()) {
            answer++;
        }
        st.push(make_pair(line[i], cnt));
    }
    cout << answer;
    

    return 0;
}