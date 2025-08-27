#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int visited[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;

    int n, k;

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;

        v.push_back(input);
    }

    int en = 0;
    int answer = 1;
    visited[v[en]]++;

    for(int st = 0; st < n; st++) {
        while(en < n-1 && visited[v[en+1]] < k) {
            en++;
            visited[v[en]]++;
        }

        answer = max(answer, en - st + 1);
        if(en == n) {
            break;
        }

        visited[v[st]]--;
        
    }
    
    cout << answer;

    return 0;
}