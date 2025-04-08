#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int house[1001][3];





int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(false);
    int n;
    int red;
    int green;
    int blue;
    cin >> n;
    cin >> house[0][0] >> house[0][1] >> house[0][2];
    for(int i = 1; i < n; i++) {
        cin >> red >> green >> blue;
        house[i][0] = min(house[i-1][1] + red, house[i-1][2] + red);
        house[i][1] = min(house[i-1][0] + green, house[i-1][2] + green);
        house[i][2] = min(house[i-1][0] + blue, house[i-1][1] + blue);
    }
    cout << min(min(house[n-1][0], house[n-1][1]),house[n-1][2]);
    

    return 0;
}