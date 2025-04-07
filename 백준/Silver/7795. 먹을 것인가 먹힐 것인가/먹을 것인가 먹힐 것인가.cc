#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int A[20002];
int B[20002];



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N, M;
    cin >> T;
    while(T--) {
        int answer = 0;
        cin >> N >> M;
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for(int i = 0; i < M; i++) {
            cin >> B[i];
        }
        sort(A, A+N);
        sort(B, B+M);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(B[j] >= A[i]) {
                    answer += j;
                    break;
                }
                if(j == M-1) {
                    answer += M;
                }
            }
        }\
        cout << answer << '\n';
    }

    
    
    
    return 0;
}