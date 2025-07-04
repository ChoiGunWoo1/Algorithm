#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

int N;
int status[20][20];
bool isused[20];
int linkteam[10];
int startteam[10];
int linkpower = 0;
int startpower = 0;
int diff = 20 * 100;




void check(int start, int cnt) {
    if(cnt == N/2) {
        int a = 0;
        for(int i = 0; i < N; i++) {
            if(!isused[i]) {
                for(int j = 0; j < a; j++) {
                    startpower += status[i][startteam[j]] + status[startteam[j]][i];
                }
                startteam[a] = i;
                a++;
            }
        }
        int answer = abs(linkpower - startpower);
        if(answer  < diff) {
            diff = answer;
        }
        startpower = 0;
        return;
    }
    for(int i = start; i < N; i++) {
        if(!isused[i]) {
            isused[i] = true;
            int temp = linkpower;
            for(int j = 0; j < cnt; j++) {
                linkpower += status[i][linkteam[j]] + status[linkteam[j]][i];
            }
            linkteam[cnt] = i;
            check(i+1, cnt+1);
            linkpower = temp;
            isused[i] = false;
        }
    }
}


int main()
{
    cin.tie(0); cout.tie(0);
    cin.sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> status[i][j];
        }
    }
    check(0, 0);
    cout << diff;
    

    return 0;
}