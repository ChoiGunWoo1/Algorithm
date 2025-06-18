#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, w, l;

int truck[1002];
int bridge[102] = {0, };

int answer = 0;
int num = 0;
int endtruck = 0;

int bridgew() {
    int r = 0;
    for(int i = 0; i < w; i++) {
        r += bridge[i];
    }
    return r;
}

void move() {
    int tmpbridge[w];
    for(int i = 0; i < w; i++) {
        tmpbridge[i] = bridge[i];
    }
    if(bridge[w-1] != 0) {
        endtruck++;
    }
    for(int i = w-1; i > 0; i--) {
        bridge[i] = tmpbridge[i-1];
    }
    answer++;
    bridge[0] = 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;
    for(int i = 0; i < n; i++) {
        cin >> truck[i];
    }


    while(num < n) {
        int nowtruck = truck[num];
        bool ismoved = false;
        while(bridgew() + nowtruck > l || bridge[0] != 0) {
            ismoved = true; 
            move();
        }
        bridge[0] = nowtruck;
        if(!ismoved) {
            answer++;
        }
        num++;
    }

    while(endtruck < n) {
        move();
    }

    cout << answer;
    
    
    return 0;
}