#include <iostream>
#include <string>
#include <algorithm>


using namespace std;





int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    long long v[100002];
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v, v+N);
    long long answer = v[0];
    int count = 0;
    int max = 0;
    for(int i = 0; i < N; i++) {
        if(i == 0 || v[i-1] == v[i]) {
            count++;
        }
        else {
            if(count > max) {
                max = count;
                answer = v[i-1];
            }
            count = 1;
        }  
    }
    if(count > max) {
        answer = v[N-1];
    }
    cout << answer;
    
    
    return 0;
}