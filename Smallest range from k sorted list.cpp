#include <limits.h>
#include <queue>
#include <vector>
class Node
{
public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c) {
      data = d;
      row = r;
      col = c;
    }
};

class compare {
  public:
    bool operator()(Node*a,Node*b){
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<Node*,vector<Node*>,compare> pq;
    
    for(int i = 0;i<k;i++){
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        pq.push(new Node(element,i,0));
    }

    int start = mini;
    int end = maxi;

    while(pq.size()>0){
        Node*temp = pq.top();
        pq.pop();
        mini = temp->data;
        

        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }
        if(temp->col+1 < n){
            maxi = max(maxi,a[temp->row][temp->col+1]);
            pq.push(new Node(a[temp->row][temp->col +1],temp->row,temp->col+1));
        }
        else{
            break;
        }

    }
    return end-start+1;
}
