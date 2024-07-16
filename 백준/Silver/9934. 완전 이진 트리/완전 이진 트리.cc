#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int k, idx;
vector<int> v;

struct Node{
    int num;
    Node* left;
    Node* right;

    Node(int val) : num(val), left(NULL), right(NULL) {}
};

void Inorder(Node* node){
    if(node == NULL){ return; }

    Inorder(node->left);
    node->num = v[idx];
    idx++;
    Inorder(node->right);
}

vector<Node*> tree;

int main() {
    FastIO();

    cin >> k;
    for(int i = 0 ; i < pow(2, k) - 1 ; i++){
        int input;
        cin >> input;
        v.push_back(input);
        tree.push_back(new Node(0));
    }

    for (int i = 0; i < pow(2, k) - 1 / 2; i++){
        if (2 * i + 1 < pow(2, k) - 1){
            tree[i]->left = tree[2 * i + 1];
        }
        if (2 * i + 2 < pow(2, k) - 1){
            tree[i]->right = tree[2 * i + 2];
        }
    }

    Inorder(tree[0]);

    int iter = 0;
    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < pow(2, i) ; j++){
            cout << tree[iter]->num;
            if(j != pow(2, i) - 1){
                cout << ' ';
            }
            iter++;
        }
        cout << '\n';
    }

    return 0;
}