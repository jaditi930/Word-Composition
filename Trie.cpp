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

void readInputFile(string filename,vector<string>& wordsList)
{
ifstream fin;
fin.open("Input_02.txt");
string word;

while (getline(fin, word)) {
    
    wordsList.push_back(word);
}
fin.close();
}

bool IsCompounded(Trie &tr,string word,int start=0)
{
// cout<<"hello";
if(start==word.size())
return 1;
for(int end=start+1;end<=word.size();end++)
{
    
// if(tr.search(word.substr(start,end-start)))
// // {cout<<start<<" "<<end<<" ";
// cout<<word.substr(start,end-start)<<endl;

if(end-start!=word.size()&&tr.search(word.substr(start,end-start))&& IsCompounded(tr,word,end))
{ 
    return 1;
}
}
return 0;
}

int main()
{
    Trie tr;
    vector<string>wordsList;
    readInputFile("Input_02.txt",wordsList);
    for(auto word:wordsList)
    tr.insert(word);

    string longestComp="",secondLongestComp="";
    // cout<<tr.search("catxdogcatsrat");
    for(auto word:wordsList)
    {
        if(IsCompounded(tr,word))
        {
            if(word.size()>longestComp.size())
            {
                secondLongestComp=longestComp;
                longestComp=word;
            }
            else if(word.size()>secondLongestComp.size())
            secondLongestComp=word;
        }
    }
    cout<<"Longest Compound Word is "<<longestComp<<endl;
    cout<<"Second Longest Compound Word is"<<secondLongestComp<<endl;
    return 0;
}