// lecture 79

#include <iostream>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int index = 0; index < 26; index++)
            children[index] = nullptr;
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode *root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insert(TrieNode *root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return ;
        }
        int index = word[0] - 'A';
        TrieNode *child;
        if(root->children[index] != nullptr)
            child = root->children[index];
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insert(child, word.substr(1));
    }

    bool search(TrieNode *root, string word) {
        if(word.length() == 0)
            return root->isTerminal;
        int index = word[0] - 'A';
        TrieNode *child;
        if(root->children[index] != nullptr)
            child = root->children[index];
        else
            return false;
        return search(child, word.substr(1));
    }

    void insertWord(string word) {
        insert(root, word);
    }

    bool searchWord(string word) {
        return search(root, word);
    }
};

int main() {
    Trie *t = new Trie();
    
    t->insertWord("KARTIK");
    t->insertWord("AGRAWAL");
    t->insertWord("DEV");
    t->insertWord("RIZZARIYA");
    t->insertWord("ARNAVV");

    cout << "Found: " << t->searchWord("AGRAWAL") << endl;

    return 0;
}