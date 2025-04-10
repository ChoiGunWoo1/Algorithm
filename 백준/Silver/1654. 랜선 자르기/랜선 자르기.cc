#include <iostream>
#include <algorithm>


using namespace std;


int lan[10000];
int K, N;

long long solv(int M) {
    long long start = 1;
    long long end = M;
    long long answer = 0;
    while(start <= end) {
        long long temp = 0;
        long long mid = (start + end) / 2;
        for(int i = 0; i < K; i++) {
            temp += lan[i] / mid;
        }
        if(temp >= N) {
            start = mid + 1;
            answer = max(answer, mid);
        }
        else {
            end = mid-1;
        }
    }
    return answer;
} 




int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);
    cin >> K >> N;
    int M;
    for(int i = 0; i < K; i++) {
        cin >> lan[i];
        if(i == 0) {
            M = lan[i];
        }
        else {
            if(lan[i] > M) {
                M = lan[i];
            }
        }
    }
    int answer = solv(M);
    cout << answer;
    


    return 0;
}