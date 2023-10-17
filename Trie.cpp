#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
        TrieNode* children[26];
        bool EndOfWord;
        TrieNode(){
            for(int i=0;i<26;i++)
            {
                children[i]=NULL;
            }
            EndOfWord=false;
    }
};
class Trie{
    public:
        TrieNode* root;
        Trie(){
            root=new TrieNode();
        }
        void insert(string key)
        {
            TrieNode* head=root;
            for(int i=0;i<key.size();i++)
            {
                int idx=key[i]-'a';
                if(!head->children[idx])
                {
                    head->children[idx]=new TrieNode();
                }
                head=head->children[idx];
            }
            head->EndOfWord=true;
        }
        bool search(string key)
        {
            TrieNode* head=root;

            for(int i=0;i<key.size();i++)
            {  
            int idx=key[i]-'a';
            if(!head->children[idx])
            return 0;

            head=head->children[idx];
            }

            return head->EndOfWord;
        }

};
int main()
{
    Trie tr;
    tr.insert("apple");
    tr.insert("apply");
    tr.insert("bye");
    tr.insert("by");
    tr.insert("app");

    cout<<tr.search("app")<<endl;
    cout<<tr.search("art")<<endl;
    cout<<tr.search("apply")<<endl;

    return 0;
}