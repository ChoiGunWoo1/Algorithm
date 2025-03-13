#include <iostream>
#include <vector>
#include <string>

using namespace std;

int alp[26] = {0, };

int main(void) {

    string S;

    cin >> S;

    for(int i = 0; i < S.length() ; i++) {
        int alnum = S[i] - 'a';
        alp[alnum]++;
    }
    for(int j = 0; j < 26; j++) {
        cout << alp[j] << " ";
    }

    return 0;
}