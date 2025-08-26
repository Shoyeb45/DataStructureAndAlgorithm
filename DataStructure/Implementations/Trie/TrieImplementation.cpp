#include <cctype>
# include<iostream>
# include<unordered_map>
# include <string>
using namespace std;


class TrieNode {
public:


    /// Children nodes
    // TrieNode* children[26];
    unordered_map<char, TrieNode*> children;

    /// flag to indicate is it terminal node or not
    bool isTerminal;

    /// constructor to initialise trie node
    TrieNode() {
        // for (auto &x: children) {
        //     x = nullptr;
        // }
        isTerminal = false;
    }
};

class Trie {
private:
    void insertUtil(string word, int index, TrieNode *root) {
        if (index >= word.size()) {
            root->isTerminal = true;
            return;
        }

        TrieNode *child = root->children[word[index]];

        if (child == nullptr) {
            child = new TrieNode();
            root->children[word[index]] = child;  // ✅ Link the new node
        }

        insertUtil(word, index + 1, child);
    }

    void visualizeUtil(TrieNode* node, string prefix) {
        if (node->isTerminal) {
            cout << prefix << " [END]" << endl;
        }

        for (auto &x: node -> children) {
            if (x.second != nullptr) {
                visualizeUtil(x.second, prefix + x.first);
            }
        }
    }

    bool searchUtil(string &word) {

        TrieNode* node = root;
        for (auto ch: word) {
            if (node -> children.find(ch) != node -> children.end()) {
                node = node -> children[ch];
            } else {
                return false;
            }
        }

        return true;
    }

public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        insertUtil(word, 0, root);
    }

    void visualize() {
        cout << "Trie Visualization:\n";
        visualizeUtil(root, "");
    }

    bool search(string word) {
        return this -> searchUtil(word);
    }
};


int main() {
    Trie *t = new Trie();

    t -> insert("abcd");
    t -> insert("abce");
    t -> visualize();

    cout << t -> search("abcd") << "\n";
    return 0;
}
