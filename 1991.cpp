#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    char val;
    Node(char val='.' , Node* left = NULL , Node* right = NULL){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

void preorder(Node* root){
    if(root != NULL) {
        cout << (*root).val;
        preorder (root -> left); 
        preorder (root -> right);
    }
}

void inorder(Node* root){
    if(root != NULL){ 
        inorder(root->left);
        cout << root->val;
        inorder(root->right);
    }
}

void postorder(Node* root){
    if(root != NULL){ 
        postorder(root->left);
        postorder(root->right);
        cout << root->val;
    }
}

int main(){
    int depth;
    char val,l,r;
    cin >> depth;
    
    Node* root = new Node[100];
    for(int i=0 ; i<depth ; i++){
        cin >> val >> l >> r;
        root[(val-'A')].val = val;

        if(l == '.'){ root[(val-'A')].left = NULL; }
        else{ 
            root[(val-'A')].left = &root[(l - 'A')]; 
        }

        if(r == '.'){ root[(val-'A')].right = NULL; }
        else{ 
            root[(val-'A')].right = &root[(r - 'A')]; 
        }
    }

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
    return 0;
}