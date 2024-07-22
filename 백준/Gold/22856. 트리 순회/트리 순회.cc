#include <iostream>
#include <vector>

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct Node{
    int num;
    Node* right;
    Node* left;

    Node(int x) : num(x), right(NULL), left(NULL) {}
};

int lastNum, answer;
int p[100001];
vector<Node *> tree;

bool visited[100001];

void Inorder(Node* node){
    if(node == NULL){ return; }

    Inorder(node->left);
    lastNum = node->num;
    Inorder(node->right);
}

void Sol(Node* node){
    if(node->left != NULL && !visited[node->left->num]){
        answer += 1;
        visited[node->left->num] = true;
        Sol(node->left);
    }
    else if(node->right != NULL && !visited[node->right->num]){
        answer += 1;
        visited[node->right->num] = true;
        Sol(node->right);
    }
    else if(node->num == lastNum){
        return;
    }
    else{
        answer += 1;
        Sol(tree[p[node->num]]);
    }
}

int main() {
    FastIO();

    int n;
    cin >> n;

    
    for(int i = 0 ; i <= n ; i++){
        tree.push_back(new Node(0));
        p[i] = i;
    }

    for(int i = 0 ; i < n ; i++){
        int a, b, c;
        cin >> a >> b >> c;

        tree[a]->num = a;

        if(b == -1){
            tree[a]->left = NULL;
        }else{
            tree[a]->left = tree[b];
            p[b] = a; 
        }

        if (c == -1){
            tree[a]->right = NULL;
        }
        else{
            tree[a]->right = tree[c];
            p[c] = a;
        }
    }

    Inorder(tree[1]);
    Sol(tree[1]);

    cout << answer << '\n';

    return 0;
}