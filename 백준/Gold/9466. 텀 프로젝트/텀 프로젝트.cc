#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

int student[100002];
int checked[100002];

const int Not_visited = 0;
const int Cycle_in = -1;


void run(int x) {
    int cur = x;
    while(true) {
        checked[cur] = x;
        cur = student[cur];
        if(checked[cur] == x) {
            while(checked[cur] != Cycle_in) {
                checked[cur] = Cycle_in;
                cur = student[cur];
            }
            return;
        }
        else if(checked[cur] != 0) return;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> student[i];
        }
        fill(checked+1, checked+n+1, 0);
        for(int i = 1; i <= n; i++) {
            if(checked[i] == Not_visited) {
                run(i);
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(checked[i] != Cycle_in) {
                cnt++;
            }
        }
        cout << cnt << '\n';
            

    }

    
    
    


    return 0;
}
