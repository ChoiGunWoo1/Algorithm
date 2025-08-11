#include <iostream>
#include <algorithm>

using namespace std;

int num[100002];
int visited[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    long long answer = 0;
    int en = 0;
    for(int st = 0; st < n; st++) {
        while(en < n && !visited[num[en]]) {
            visited[num[en]] = true;
            en++;
        }
        answer += en - st;
        visited[num[st]] = false;
    }

    cout << answer;
    

    

    return 0;
}