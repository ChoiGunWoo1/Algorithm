#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int visited[3002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;

    int n, d, k, c;

    cin >> n >> d >> k >> c;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;

        v.push_back(input);
    }

    int en = 0;
    visited[v[en]] = 1;
    int answer = 0;
    int t = 1;

    for(int st = 0; st < n; st++) {
        while(en + 1 < st + k) {
            en++;

            if(visited[v[en % n]] == 0) {
                t++;
            }
            visited[v[en % n]]++;
        }

        if(visited[c] == 0) {
            answer = max(answer, t + 1);
        }
        else {
            answer = max(answer, t);
        }

        visited[v[st]]--;
        if(visited[v[st]] == 0) {
            t--;
        }
    }

    cout << answer;
    

    return 0;
}