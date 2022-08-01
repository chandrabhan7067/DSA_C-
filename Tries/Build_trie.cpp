#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
        TrieNode *root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertutil(TrieNode *root,string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;


// when word is present
            if(root->children[index] != NULL){
                child = root->children[index];
            }

// when word is absent
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            insertutil(child,word.substr(1));
        }

        void insertWord(string word){
            insertutil(root,word);
        }

        bool searchUtil(TrieNode* root,string Word){
            if(Word.length() == 0){
                return root->isTerminal;
            }

            int index = Word[0] - 'A';
            TrieNode *child;

            // present
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                false;
            }
            return searchUtil(child,Word.substr(1));
        }

        bool searchWord(string word){
            return searchUtil(root,word);
        }

};

int main()
{
    Trie*t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    cout<<t->searchWord("TIME");
}