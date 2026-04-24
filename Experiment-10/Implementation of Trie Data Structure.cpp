#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert word
    void insert(string word) {
        TrieNode* temp = root;

        for(char ch : word) {
            int index = ch - 'a';

            if(temp->child[index] == NULL)
                temp->child[index] = new TrieNode();

            temp = temp->child[index];
        }

        temp->isEnd = true;
    }

    // Search complete word
    bool search(string word) {
        TrieNode* temp = root;

        for(char ch : word) {
            int index = ch - 'a';

            if(temp->child[index] == NULL)
                return false;

            temp = temp->child[index];
        }

        return temp->isEnd;
    }

    // Search prefix
    bool startsWith(string prefix) {
        TrieNode* temp = root;

        for(char ch : prefix) {
            int index = ch - 'a';

            if(temp->child[index] == NULL)
                return false;

            temp = temp->child[index];
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << trie.search("apple") << endl;     // 1
    cout << trie.search("appl") << endl;      // 0
    cout << trie.startsWith("app") << endl;   // 1
    cout << trie.search("bat") << endl;       // 1

    return 0;
}
