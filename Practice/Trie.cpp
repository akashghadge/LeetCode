/*

*/
class Node
{
    public:
    int end;
    Node*child[26]={NULL};
    Node()
    {
        end=false;
    }
};
class Trie
{
    public:
    Node* head=NULL;
    Trie(vector<string> &strs)
    {
        head=new Node();
        for(auto str:strs)
        {
            Node* temp=head;
            for(auto ch:str)
            {
                if(!temp->child[ch-'a'])
                {
                    temp->child[ch-'a']=new Node();
                }
                temp=temp->child[ch-'a'];
            }
            temp->end=1;
        }
    }
    void dfs(Node* root,string curr,vector<string>&ans)
    {
        if(!root || ans.size()>=3)
            return;
        if(root->end)
            ans.push_back(curr);
        for(char i='a';i<='z';i++)
        {
            dfs(root->child[i-'a'],curr+i,ans);
        }
    }
    vector<string> find(string str)
    {
        Node* temp=head;
        vector<string> ans;
        for(auto ch:str)
        {
            if(temp->child[ch-'a'])
                temp=temp->child[ch-'a'];
            else
                return ans;
        }
        dfs(temp,str,ans);
        sort(ans.begin(),ans.end());
        if(ans.size()<=3)
            return ans;
        else
        {
            vector<string> res;
            for(int i=0;i<3;i++)
                res.push_back(ans[i]);
            return res;
        }
    }
};
#include <bits/stdc++.h>
using namespace std;

int main()
{
}