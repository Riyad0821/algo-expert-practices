#include <bits/stdc++.h>
using namespace std;

struct BtNod
{
    int data;
    BtNod *left;
    BtNod *right;
};

BtNod *root = NULL;

BtNod *createNod(int data)
{
    BtNod *node = new BtNod();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void buildNod(int data)
{
    if (root == NULL)
    {
        root = createNod(data);
        return;
    }

    else
    {
        BtNod *current = root;
        BtNod *parent = NULL;
        while(1)
        {
            parent = current;
            if (data < parent->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = createNod(data);
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = createNod(data);
                    return;
                }
            }
        }
    }
}
vector<int> bSums;

void branchSums(BtNod *root, int sum){
    while(1){
        if(root == NULL){
            return;
        }
        else {
            sum += root->data;
            if(root->left == NULL && root->right == NULL){
               bSums.push_back(sum);
            }
            else {
                if(root->left){
                branchSums(root->left, sum);
            }
            if(root->right){
                branchSums(root->right, sum);
            }
            }

        }
        return;
    }

}

void print(BtNod *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        print(root->left);
        print(root->right);
    }
}

int main()
{
    int n;
    cout << "Number of elements: ";
    cin >> n;
    cout << "enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        buildNod(x);
    }
    print(root);
    branchSums(root, 0);
    int branchs = bSums.size();
    cout << "Branch Sums: ";
    for (int i = 0; i < branchs; i++)
    {
        cout << bSums[i] << " ";
    }

}
