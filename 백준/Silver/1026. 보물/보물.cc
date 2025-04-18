#include <iostream>
#include <algorithm>


using namespace std;

int a[52];
int b[52];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+n, greater());
    int answer = 0;
    for(int i = 0; i < n; i++) {
        answer += a[i] * b[i];
    }
    cout << answer;
   
    
    return 0;
}