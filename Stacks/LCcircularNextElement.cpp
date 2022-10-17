class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n,-1);
        stack <int> S;
        for(int i=0;i<2*n;i++){
            int j = i%n;
            while(!S.empty()&&nums[S.top()]<nums[j]){
                ans[S.top()] = nums[j];
                S.pop();
            }
            S.push(j);
        }
        return ans;
    }
};