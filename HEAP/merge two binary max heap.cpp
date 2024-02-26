class Solution{
    public:
    void heapify(vector<int> &ans,int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && ans[largest]<ans[left]){
        largest = left;
    }
if(right<n&& ans[largest]<ans[right]){
    largest = right;
}

if(largest!=i){
    swap(ans[largest],ans[i]);
    heapify(ans,n,largest);

}
}
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
    //1: merge two arrays
        vector<int> ans;
        
        
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto j:b){
            ans.push_back(j);
        }
        
        //build tree using merge array
        
        int size = ans.size();
        for(int i = size/2-1;i>=0;i--){
            heapify(ans,size,i);
        }
    
        return ans;
    }
    
};
