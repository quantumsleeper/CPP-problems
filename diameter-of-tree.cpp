/**********************************************************************************************
                            DIAMETER OF A TREE
                        =========================

 There may be 3 cases that need to be considered for the tree's diameter:
    1. The diameter might pass through the root; in which case, 
                diameter = (height of LST) + (height of RST)
    2. The diameter might lie entirely in the LST itself (e.g. in cases where LST is very deep 
        but RST is v.v. shallow); in which case,
                diameter of the tree = whatever is the dia. of its LST
    3. Similarly, the diameter might lie entirely in the RST itself; in which case,                          
                diameter of the tree = whatever is the dia. of its RST

 Ultimately, the resulting diameter would be whatever is the max. out of these 3 cases.

 TIME COMPLEXITY: 
 ================
 Let's assume we're at the root of the tree. Then, 

 (i) op1 would make a call on all nodes => O(N)
 (ii) op2 & op3 together would make a call on all nodes => O(N)
 (iii) So, (i) & (ii) add up to O(N). And (i) and (ii) would happen for all N nodes. 

 So, time complexity = N*O(N) = O(N^2)   

 Sample Input: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 Answer: 6
***********************************************************************************************/

#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int op1 = height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(max(op1, op2), op3);
}

int main(){
    cout << "Enter the tree: ";
    node* root = buildTree();
    cout << diameter(root) << endl;

    return 0; 
}
