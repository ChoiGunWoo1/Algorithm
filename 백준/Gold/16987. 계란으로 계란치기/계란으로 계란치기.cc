#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> egg; // {내구도, 무게}

int num;
int answer = 0;

void df(int idx, int break_eggs) {
    if(idx == num) {
        answer = max(break_eggs, answer);
        return;
    }
    if(egg[idx].first <= 0) {
        df(idx+1, break_eggs);
        return;
    }
    int curdur = egg[idx].first;
    int curweight = egg[idx].second;
    bool hit = false;
    for(int i = 0; i < num; i++) {
        if(i == idx || egg[i].first <= 0) {
            continue;
        }
        hit = true;
        int nowbreak = break_eggs;
        int nxtdur = egg[i].first;
        int nxtweight = egg[i].second;
        int aftercurdur = curdur - nxtweight;
        int afternxtdur = nxtdur - curweight;
        if(afternxtdur <= 0) {
            nowbreak += 1;
        }
        if(aftercurdur <= 0) {
            nowbreak += 1;
        }
        egg[idx].first = aftercurdur;
        egg[i].first = afternxtdur;
        df(idx+1, nowbreak);
        egg[idx].first = curdur;
        egg[i].first = nxtdur;
    }
    if(!hit) {
        df(idx+1, break_eggs);
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;
    for(int i = 0; i < num; i++) {
        int S, W;
        cin >> S >> W;
        egg.push_back({S, W});
    }
    df(0, 0);

    cout << answer;
    return 0;
}
