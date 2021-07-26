#include <bits/stdc++.h>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* createNode(int x){
    BstNode* node = new BstNode();
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

BstNode* buildBst(BstNode* root, int x){
    if(root == NULL){
        return createNode(x);

    }
    else if(x <= root->data){
            root->left = buildBst(root->left, x);
        }
    else{
        root->right = buildBst(root->right, x);
    }
    return root;
}

void print(BstNode* root){
    if(root != NULL)
        {
        cout << root->data << endl;
        print(root->left);
        print(root->right);
        }
}

int findClosestValueInBstHelper(BstNode* root, int target, int closest){
    BstNode* currentNode = root;
    while(currentNode != NULL){
    if(abs(target - closest) > abs(target-currentNode->data)){
        closest = currentNode->data;
    }
    if(target < root->data){
        currentNode = currentNode->left;
    }
    else if(target > currentNode->data) {
        currentNode = currentNode->right;
    }
    else break;
    }
    return closest;
}

int findClosestValueInBst(BstNode* root, int target){
    return findClosestValueInBstHelper(root, target, numeric_limits<int>::max());
}


int main(){
    BstNode* root = NULL;
    int n, target;
    cout << "Number of Elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = buildBst(root, x);
    }
    cout << "Enter the target to find closest value: ";
    cin >> target;
    print(root);
    int result = findClosestValueInBst(root, target);
    cout << "Closest value is: "<< result << endl;
}
