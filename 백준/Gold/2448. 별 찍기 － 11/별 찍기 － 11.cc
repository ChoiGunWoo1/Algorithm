#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

const int Max = 3100;

char star[Max][Max*2];

void basicstar(int x, int y) {
    star[x][y] = '*';
    star[x+1][y-1] = '*'; star[x+1][y+1] = '*';
    for(int i = y-2; i <= y+2; i++) {
        star[x+2][i] = '*';
    }
}


void df(int n, int x, int y) {
    
    if(n == 3) {
        basicstar(x, y);
        return;
    }
    int newn = n/2;
    df(newn, x, y);
    df(newn, x+newn, y+newn);
    df(newn, x+newn, y-newn);
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    df(N, 0, N-1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N * 2 - 1; j++) {
            if(star[i][j] == '*') 
            {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    


    return 0;
}
