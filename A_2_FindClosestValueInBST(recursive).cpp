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
    if(root == NULL){
        return closest;
    }
    if(abs(target - closest) > abs(target-root->data)){
        closest = root->data;
    }
    if(target < root->data){
        findClosestValueInBstHelper(root->left, target, closest);
    }
    else if(target > root->data) {
        findClosestValueInBstHelper(root->right, target, closest);
    }
    else return closest;
}

int findClosestValueInBst(BstNode* root, int target){
    return findClosestValueInBstHelper(root, target, numeric_limits<int>::max());
}

int closest(BstNode* root, int x, int nearest){
    int nearestValue = -1;
   if(root != NULL){
    int p = abs(root->data - x);
    if(nearest > p) {
        nearest = p;
        nearestValue = root->data;
    }
    if(nearest == 0) return nearestValue;
    else {
        if(x < root->data){
            closest(root->left, x, nearest);
        }
        else {
            closest(root->right, x, nearest);
        }

    }
   }


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
    cout << "Result is: "<< result << endl;
}
