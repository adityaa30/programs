// https://leetcode.com/problems/search-suggestions-system/

#include<bits/stdc++.h>
using namespace std;
class TrieNode{
public:
    TrieNode* next[26];
    bool end;
    
    TrieNode(){
        memset(next,NULL,sizeof(next));
        end = false;
    }
    
};
class Solution {
public:
    void addString(TrieNode* root,string s){
        for(int i=0;i<s.length();i++){
            if(!root->next[s[i]-'a'])
                root->next[s[i]-'a'] = new TrieNode();
            root = root->next[s[i]-'a'];
        }
        root->end = true;
    }
    
    void findString(TrieNode* root,vector<string> &v,string &temp){
        if(v.size()>=3)
            return;
        if(root->end){
            v.push_back(temp);
            // temp = "";
        }
        for(int i=0;i<26;i++){
            if(root->next[i]){
                char c = 'a'+i;
                temp = temp+c;
                findString(root->next[i],v,temp);
                temp.pop_back();
            }
        }
        
        return;
    }
    void findSuggested(TrieNode* root,string s,vector <string> &v){
        for(int i=0;i<s.length();i++){
            int ind = s[i]-'a';
            if(!root->next[ind])
                return;
            root = root->next[ind];
        }
        string temp = "";
        findString(root,v,temp);
        for(int i=0;i<v.size();i++){
            v[i] = s+v[i];
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        for(auto i:products){
            addString(root,i);
        }
        vector<vector<string>> ans;
        string temp = "";
        for(auto i:searchWord){
            temp = temp+i;
            vector <string> v;
            findSuggested(root,temp,v);
            ans.push_back(v);
        }
        return ans;
    }
};

int main(){
    return 0;
}