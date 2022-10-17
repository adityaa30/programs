class Solution {
public:
//     vector <int> getNS(vector <int>& A){
//         stack <int> S;
//         vector <int> ans;
//         for(int i=0;i<A.size();i++){
//             while(!S.empty()&&A[S.top()]>=A[i]){
//                 S.pop();
//             }
//             if(S.empty())
//                 ans.push_back(S.top()+1);
//             else 
//                 ans.push_back(0);
//             S.push(i);
//         }
//         return ans;
//     }
//     vector <int> getPS(vector <int>& A){
//         stack <int> S;
//         vector <int> ans;
//         for(int i=A.size()-1;i>=0;i--){
//             while(!S.empty()&&A[S.top()]>=A[i]){
//                 S.pop();
//             }
            
//             if(S.empty())
//                 ans.push_back(S.top()-1);
//             else
//                 ans.push_back(A.size()-1);
//             S.push(i);
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        stack<int> s;
        int n=heights.size();
        //for nearest left smaller
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty()){
                left.push_back(s.top()+1);
            }
            else{
                left.push_back(0);
            }
            s.push(i);
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        //for nearest right smaller
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty()){
                right.push_back(s.top()-1);
            }
            else{
                right.push_back(n-1);
            }
            s.push(i);
        }
        reverse(right.begin(),right.end());
        
        int result=0;
        for(int i=0;i<n;i++){
            result=max(result,heights[i]*(right[i]-left[i]+1));
        }
        return result;
//         int n = heights.size();
//         vector <int> NS = getNS(heights);
//         vector <int> PS = getPS(heights);
//         for(auto i:NS){
//             cout << i << " ";
//         }
//         cout << endl;
//         for(auto i:PS){
//             cout << i << " ";
//         }
//         cout << endl;
//         int ans = 0;
//         for(int i=0;i<heights.size();i++){
// //             int l=abs(i-NS[i]),r=abs(i-PS[i]);
// //             if(NS[i]==-1)
// //                 l = 1;
// //             if(PS[i]==-1)
// //                 r = 1;
//             int l = NS[i],r=PS[i];
//             int area = heights[i]*(r-l-1);
//             ans = max(area,ans);
//         }
//         return ans;
    }
};