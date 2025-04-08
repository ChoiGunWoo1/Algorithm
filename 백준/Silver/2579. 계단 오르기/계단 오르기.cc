#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    int stair[n];
    for(int i = 0; i < n; i++) {
        cin >> stair[i];
    }
    int num = 0;
    int score[2][n] = {0, };
    int inarow[2][n] = {0, };
    while(num < n) {
        if(num == 0) {
            score[0][num] = stair[num];
            inarow[0][num] = 1;
            score[1][num] = stair[num];
            inarow[1][num] = 1;
            num++;
            continue;
        }
        else if(num == 1) {
            score[0][num] = score[0][num-1] + stair[num];
            score[1][num] = stair[num];
            inarow[0][num] = inarow[0][num-1] + 1;
            inarow[1][num] = 1;
            num++;
            continue;
        }
        if(inarow[0][num-1] < 2) {
            if(score[0][num-1] >  score[1][num-1]) {
                score[0][num] = score[0][num-1] + stair[num];
                inarow[0][num] = 2;
            }
            else {
                score[0][num] = score[1][num-1] +stair[num];
                inarow[0][num] = 2;
            }
        }
        else {
            score[0][num] = score[1][num-1] +stair[num];
            inarow[0][num] = 2;
        }
        if(score[0][num-2] > score[1][num-2]) {
            score[1][num] = score[0][num-2] + stair[num];
            inarow[1][num] = 1;
        }
        else {
            score[1][num] = score[1][num-2] + stair[num];
            inarow[1][num] = 1;
        }
        num++;
    }
    
    

    cout << max(score[0][n-1], score[1][n-1]);

    
    

    return 0;
}