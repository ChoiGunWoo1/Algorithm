#include <iostream>
#define Maxnum 1000000


using namespace std;

int N;

int num[2000002];
int d[2000002] = {0, };

void Solution() {
    for(int i = 0; i < N; i++) {
        int index = num[i] + Maxnum;
        d[index]++;
    }
    for(int i = 0; i < 2000002; i++) {
        for(int j = 0; j < d[i]; j++) {
            cout << i - Maxnum << '\n';
        }
    }
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    Solution();
    
    
    return 0;
}