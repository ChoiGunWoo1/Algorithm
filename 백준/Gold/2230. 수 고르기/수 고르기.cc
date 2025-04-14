#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>


using namespace std;

int A[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int input;

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A, A+n);

    int ed = 0;
    int answer = INT_MAX;

    for(int st = 0; st < n; st++) { // 투 포인터 방식
        while(ed < n && A[ed] - A[st] < m) {
            ed++;
        }
        if(ed == n) {
            break;
        }
        answer = min(answer, A[ed] - A[st]);
    }
    
    cout << answer;
    
    
    return 0;

}