#include <iostream>
#include <algorithm>

using namespace std;

int num[102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int v;
    cin >> v;
    int answer = 0;
    for(int i = 0; i < n; i++) {
        if(num[i] == v) {
            answer++;
        }
    }
    cout << answer;
    
    
    return 0;

}
