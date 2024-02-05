// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


class Solution {
  public:
    
    int countnodes(struct Node* tree){
    if(tree == NULL){
        return 0;
    }
    int ans = 1+countnodes(tree->left)+countnodes(tree->right);
    return ans;
}


bool isMaxorder(struct Node* tree){
    if(tree->left == NULL && tree->right == NULL){
        return true;
    }
    if(tree->right == NULL){
        return (tree->data > tree->left->data);
    }
    else{
        bool left = isMaxorder(tree->left);
        bool right = isMaxorder(tree->right);
        
        return (left && right && (tree->data > tree->left->data && tree->data > tree->right->data));
    }
    
}

bool isCBT(struct Node* tree,int index,int cnt){
    if(tree==NULL){
        return true;
    }
    if(index>=cnt){
        return false;
    }
    
    
    else{
        bool left = isCBT(tree->left,2*index+1,cnt);
        bool right = isCBT(tree->right,2*index+2,cnt);
        return (left&&right);
    }
    
}
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int totalcount = countnodes(tree);
        if(isCBT(tree,index,totalcount) && isMaxorder(tree)){
            return true;
        }
        else{
            return false;
        }
}
};
