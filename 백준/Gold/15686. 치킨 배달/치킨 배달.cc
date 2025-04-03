#include <iostream>
#include <climits>


using namespace std;

int N, M;
int city[52][52]; // 도시의 형태 저장
int dis[52][52] = {0, }; // 각 위치의 치킨거리 저장
pair<int, int> chicken[13]; // 치킨집 위치 정보 저장
bool chickenused[13] = {0, }; // 치킨집을 선택했는지 여부 저장
pair<int, int> house[100]; // 집의 위치 정보 저장
int h = 0; // 집의 갯수 저장
int c = 0; // 치킨집의 갯수 저장
int answer = INT_MAX;

void CheckD(int x, int y) { // 주어진 치킨집의 위치로부터 각 집의 치킨 거리를 구함
    for(int i = 0; i < h; i++) {
        int hr = house[i].first;
        int hc = house[i].second;
        int nd = abs(hr - x) + abs(hc - y);
        if(dis[hr][hc] == 0 || dis[hr][hc] > nd) {
            dis[hr][hc] = nd; //구한 치킨거리가 아직 안구해졌거나 기존 거리보다 더 작다면 갱신
        }
    }
}

int Calchickdis() { // 도시의 치킨거리를 구하는 함수
    int d = 0;
    for(int i = 0; i < h; i++) {
        int x = house[i].first;
        int y = house[i].second;
        d += dis[x][y];
    }
    return d;
}

void Solution(int index, int n) { // 각 치킨집을 선별하고 도시 치킨 거리를 구하는 함수(백트리킹)
    if(n == M) {
        for(int i = 0; i < c; i++) {
            if(chickenused[i]) {
                CheckD(chicken[i].first, chicken[i].second);
            }
        }
        answer = min(answer, Calchickdis()); // 치킨집 M개를 뽑은후 기존 도시치킨거리보다 적으면 갱신
        for(int i = 0; i < h; i++) { // 다시 치킨 거리 초기화
            int x = house[i].first;
            int y = house[i].second;
            dis[x][y] = 0;
        }
        return;
    }
    for(int i = index; i < c; i++) { // 치킨집 M개를 선별하는 과정(조합)
        if(!chickenused[i]) {
            chickenused[i] = true;
            Solution(i, n+1);
            chickenused[i] = false;
        }
    }
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> city[i][j];
            if(city[i][j] == 1) { // 치킨집과 집의 갯수와 위치정보 저장
                house[h] = make_pair(i, j);
                h++;
            }
            else if(city[i][j] == 2) {
                chicken[c] = make_pair(i, j);
                c++;
            }
        }
    }
    Solution(0, 0);
    cout << answer;
    
    
    
    return 0;
}