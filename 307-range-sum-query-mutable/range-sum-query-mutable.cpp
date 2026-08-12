class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 0,0, n-1);
        
    }
    void build (vector<int>& nums, int index, int left, int right) {
        if(left == right) {
            tree[index] = nums[left];
            return;
        }
        int mid = (left + right) / 2;

        build(nums, 2 * index + 1, left, mid);
        build(nums, 2 * index + 2, mid+1, right);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];   
        }
    
    void update(int index, int val) {
        updateHelper(0, 0, n-1, index, val);
    }
    void updateHelper(int treeIndex, int left, int right, int index, int val) {

        if(left == right) {
            tree[treeIndex] = val;
            return;
        }

        int mid = (left + right) / 2;

        if(index <= mid) {
            updateHelper(2* treeIndex + 1, left, mid, index, val);
        }

        else{
            updateHelper(2 * treeIndex + 2, mid+1, right, index, val);
        }

        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
    int query(int treeIndex, int left, int right, int queryLeft, int queryRight) {

        if(queryLeft <= left && right <= queryRight) {
            return tree[treeIndex];
        }

        if(right < queryLeft || left > queryRight) {
            return 0;
        }

        int mid = (left + right)/ 2;

        int leftSum = query(2 * treeIndex + 1, left, mid , queryLeft, queryRight);
        int rightSum = query( 2 * treeIndex + 2, mid + 1, right, queryLeft, queryRight);

        return leftSum + rightSum;


    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */