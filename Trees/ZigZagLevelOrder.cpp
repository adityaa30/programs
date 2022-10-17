#include<bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
//  */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector <vector <int> > V;
        if(!root) return V;
        queue <TreeNode*> Q;
        Q.push(root);
        bool flag = true;
        while(!Q.empty()){
            int sz = Q.size();
            vector <int> v;
            stack <TreeNode*> S; 
            for(int i=0;i<sz;i++){
                TreeNode* tp = Q.front();
                S.push(tp);
                Q.pop();
            }
            while(!S.empty()){
                TreeNode* tp = S.top();
                v.push_back(tp->val);
                if(flag){
                    if(tp->left)
                        Q.push(tp->left);
                    if(tp->right)
                        Q.push(tp->right);
                }else{
                    if(tp->right)
                        Q.push(tp->right);
                    if(tp->left)
                        Q.push(tp->left);
                }
                S.pop();
            }
            flag = !flag;
            V.push_back(v);
        }
        return V;
    }
};
int main(){
    return 0;
}
//         1
//     2       3
// 4      5   6  7