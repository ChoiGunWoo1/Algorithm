#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

char star[7000][7000];

void df(int n, int x, int y) {
    if(n == 1) {
        star[x][y] = '*';
        return;
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) {
                continue;
            }
            df(n/3, x + ((n/3) * i), y + ((n/3) * j));
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            star[i][j] = ' ';
        }
    }
    df(N, 0, 0);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << star[i][j];
        }
        cout << '\n';
    }
    


    return 0;
}
