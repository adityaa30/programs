class Solution {
public:
    vector <int> nxtGEl(vector <int>& nums){
        vector <int> ans(nums.size(),-1);
        stack <int> S;
        for(int i=0;i<nums.size();i++){
            while(!S.empty()&&nums[S.top()]<nums[i]){
                ans[S.top()] = nums[i];
                S.pop();
            }
            S.push(i);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> GL = nxtGEl(nums2);
        map <int,int> M;
        for(int i=0;i<nums2.size();i++){
            M[nums2[i]] = i;
        }
        vector <int> ans;
        for(auto i:nums1){
            ans.push_back(GL[M[i]]);
        }
        return ans;
    }
};