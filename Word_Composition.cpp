#include<bits/stdc++.h>
using namespace std;

// To calculate the execution time of the code
clock_t start, stop;

//This class creates a node in a trie. A node points to multiple children nodes.
class TrieNode{
    public:
        // The number of children are taken to be 26 since there are only lowercase english alaphabets
        // in the words present in the input file.
        TrieNode* children[26];

        // End of Word determines whether current node marks the end of a word or not. This is used for searching words.
        bool EndOfWord;

        TrieNode(){
            for(int i=0;i<26;i++)
            {
                children[i]=NULL;
            }
            EndOfWord=false;
    }
};

//This class creates a trie and initializing the root node. It provides functions such as: 
//void insert(string key) --> To insert a key into the trie
//bool search(string key) --> Searches the given key in the trie and returns true if found, otherwise false
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

//This function reads the input file consisting of words (seperated by newline) and stores them in a vector
void readInputFile(vector<string>& wordsList,int choice)
{

string input_file;

input_file=(choice==1)?"Input_01.txt":"Input_02.txt";

//start the timer
start=clock();

ifstream fin;

//read the input file
fin.open(input_file);

if(!fin)
{
    cout<<"Cannot read file";
    exit(0);
}

string word;

//read line from input until end of file is reached
while (getline(fin, word)) {
    
    //push words into the vector
    wordsList.push_back(word);
}
fin.close();
}

// Recursive function that returns true if the given word is a compounded word and false if it is not
bool IsCompounded(Trie &tr,string word,int start=0)
{

// if we have reached the end of the string,then return true since empty string is present in the trie.
if(start==word.size())
return 1;

// Finds all substrings of the word starting from index start
for(int end=start+1;end<=word.size();end++)
    {
    
    // if the length of current substring equals the length of the word, that means that the word is composed 
    //of itself and not of the others words present in the word list so return false
    if(end-start==word.size()) 
    continue;

    //if the substring from word[start] to word[end-1] is present in the trie and the substring 
    //from word[end] to word[word.size()-1] is compounded then the word is a compounded word so return true
    if (tr.search(word.substr(start,end-start))&& IsCompounded(tr,word,end))
        return 1;
    }

return 0;
}

int main()
{
    Trie tr;
    vector<string>wordsList;

    int choice;
    cout<<"Enter 1 to execute Input_01.txt or 2 to execute Input_02.txt : ";
    cin>>choice;

    //transfer all words from input file to a vector
    readInputFile(wordsList,choice);

    //insert all words into trie for efficient searching
    for(auto word:wordsList)
    tr.insert(word);

    string firstCompWord="",secondCompWord="";

    //iterate over the wordList and find the longest and second longest compounded words
    for(auto word:wordsList)
    {
        if(IsCompounded(tr,word))
        {   
            // if the current word is compounded word and its length is greater than the length of longest compounded word
            // then update the longest and second longest compounded words
            if(word.size()>firstCompWord.size())
            {
                secondCompWord=firstCompWord;
                firstCompWord=word;
            }
            // else if its length is greater than the second longest compounded word, then update it
            else if(word.size()>secondCompWord.size())
            secondCompWord=word;
        }
    }
    // Program execution is done, so stop the timer
    stop = clock();

    //Print the result
    cout<<"Longest Compounded Word : "<<firstCompWord<<endl;
    cout<<"Second Longest Compounded Word is : "<<secondCompWord<<endl;
    cout<<"Time taken to process file Input_0"<<choice<<".txt : "<<double(stop - start)<<" milliseconds"<<endl;
    return 0;
}