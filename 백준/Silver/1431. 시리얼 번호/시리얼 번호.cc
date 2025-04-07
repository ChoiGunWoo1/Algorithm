#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

bool comp(string A, string B) {
    int alen = A.length();
    int blen = B.length();
    if(alen != blen) {
        return alen < blen;
    }
    int asum = 0;
    int bsum = 0;
    for(int i = 0; i < alen; i++) {
        int a = A[i] - '0';
        int b = B[i] - '0';
        if(a >= 0 && a < 10) {
            asum += a;
        }
        if(b >= 0 && b < 10) {
            bsum += b;
        }
    }
    if(asum == bsum) {
        return A < B;
    }
    return asum < bsum;
}



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string input;
    string v[50];
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v, v+N, comp);
    for(int i = 0; i < N; i++) {
        cout << v[i] << '\n';
    }
    
    
    return 0;
}