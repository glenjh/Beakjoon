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

    Node(int n) : num(n), right(NULL), left(NULL){}
};

int idx;
vector<int> v;

Node* Insert(Node* node, int key){
    if(node == NULL){ 
        return new Node(key);
    }

    if(node->num > key){
        node->left = Insert(node->left, key);
    }else{
        node->right = Insert(node->right, key);
    }

    return node;
}

void PostOrder(Node* node){
    if(node == NULL){ return; }
    PostOrder(node->left);
    PostOrder(node->right);
    cout << node->num << '\n';
}

int main() {
    FastIO();

    int input;
    while(cin >> input){
        v.push_back(input);
    }

    Node* tree = new Node(v[0]);

    for(int i = 1 ; i < v.size() ; i++){
        Insert(tree, v[i]);
    }

    PostOrder(tree);
    
    return 0;
}