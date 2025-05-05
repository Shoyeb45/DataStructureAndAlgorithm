#include <cctype>
# include<iostream>
# include <string>
using namespace std;


class TrieNode {
public:

    /// Character in the node
    char data;

    /// Children nodes
    TrieNode* children[26];

    /// flag to indicate is it terminal node or not
    bool isTerminal;

    /// constructor to initialise trie node
    TrieNode(char ch) {
        data = ch;
        for (auto &x: children) {
            x = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {

private:
    void insertUtil(string word, int index, TrieNode *root) {
        if (index >= word.size()) {
            root -> isTerminal = true;
            return;
        }

        // Assuming string to be lowercase
        int charIndex = tolower(word[index]) - 'a';
        TrieNode *child = root -> children[charIndex];

        // It's not present
        if (child == nullptr) {
            child = new TrieNode(word[index]);
        }

        insertUtil(word, index + 1, child);
    }
public:
    /// root node of the trie
    TrieNode *root;

    Trie() {
        root = new TrieNode('\0');
    }
    /// Method to insert in tries data structure
    void insert(string word) {
        insertUtil(word, 0, root);
    }
};

int main() {
    Trie *t = new Trie();

    t -> insert("abcd");
    return 0;
}
