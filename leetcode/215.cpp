/*215 Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.*/

/*build a sorted vector of size k*/

class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {
    vector<int> V(k, INT_MIN);
    if (nums.size() < k)
        return -1;
    vector<int>::iterator it;
    for(int i = 0; i < nums.size(); i++)
    {
        it = lower_bound(V.begin(), V.end(), nums[i]);
        //cout << *it<< endl;
        if (V.size() && nums[i] < V[0])
            continue;
        else
        {
            if (it == V.end())
            {
                V.push_back(nums[i]);
            }
            
            else
                V.insert(it, nums[i]);
            V.erase(V.begin());
        }
    }
    return V[0];
}
};

