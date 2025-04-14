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

    int answer = INT_MAX;

    for(int i = 0; i < n-1; i++){ // 차이가 m이상인 값중 최솟값을 이분탐색
        int left = i;
        int right = n; 
        while(left + 1 < right) {
            int mid = (left + right) / 2;
            if(A[i] + m <= A[mid]) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        if(A[right] >= A[i] + m) {
            answer = min(answer, A[right] - A[i]);
        }
    }
    cout << answer;
    
    
    return 0;

}