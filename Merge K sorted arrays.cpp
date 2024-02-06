#include <bits/stdc++.h>
#include <queue>
class node{
    public:
    int data;
    int i;
    int j;

    node(int data,int row,int column){
        this->data = data;
        i = row;
        j = column;
    }
};

class compare{
    public:
    bool operator()(node*a,node*b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*,vector<node*>,compare> pq;
      
    //step 1
    for(int i = 0;i<k;i++){
        node* temp = new node(kArrays[i][0],i,0);
        pq.push(temp);
    }
    vector<int> ans;
    while(pq.size()>0){
         node* tmp = pq.top();
         ans.push_back(tmp->data);
         pq.pop();
        int i = tmp->i;
        int j = tmp->j;

        if(j+1<kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            pq.push(next);
        
        }

    
    }
    return ans;

}
