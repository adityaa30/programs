//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums, int n){
        // Your code here
        stack <long long> S;
        vector <long long> ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            if(S.empty()){
                ans[i] = -1;
            }else{
                if(S.top()>nums[i]){
                    ans[i] = S.top();
                }else{
                    while(!S.empty()&&S.top()<nums[i]){
                        S.pop();
                    }
                    if(S.empty())
                        ans[i] = -1;
                    else
                        ans[i] = S.top();
                }
            }
            S.push(nums[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends