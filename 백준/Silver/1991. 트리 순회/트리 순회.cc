#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int binary_tree[28][2];

void preordered_print(int node) {
    if(node == -1) {
        return;
    }
    char alp = node + 'A';
    cout << alp;
    preordered_print(binary_tree[node][0]);
    preordered_print(binary_tree[node][1]);
}

void inordered_print(int node) {
    if(node == -1) {
        return;
    }
    char alp = node + 'A';
    inordered_print(binary_tree[node][0]);
    cout << alp;
    inordered_print(binary_tree[node][1]);
}

void postordered_print(int node) {
    if(node == -1) {
        return;
    }
    char alp = node + 'A';
    postordered_print(binary_tree[node][0]);
    postordered_print(binary_tree[node][1]);
    cout << alp;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    char input1, input2, input3;
    while(n--) {
        cin >> input1 >> input2 >> input3;
        int parent, left, right;
        parent = input1 - 'A';
        if(input2 == '.') {
            left = -1;
        }
        else {
            left = input2 - 'A';
        }
        if(input3 == '.') {
            right = -1;
        }
        else {
            right = input3 - 'A';
        }
        binary_tree[parent][0] = left;
        binary_tree[parent][1] = right;
    }
    preordered_print(0);
    cout << '\n';
    inordered_print(0);
    cout << '\n';
    postordered_print(0);
    
    
    
    
    

    return 0;

}
