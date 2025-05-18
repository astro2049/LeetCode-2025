#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class TrieNode {
public:
    bool isEndOfWord = false;
    TrieNode *children[26] = {};
};

class Trie {
public:
    TrieNode *root = new TrieNode();

    Trie() {

    }

    void insert(string word) {
        TrieNode *n = root;
        for (const char &c: word) {
            if (!n->children[getHash(c)]) {
                n->children[getHash(c)] = new TrieNode();
            }
            n = n->children[getHash(c)];
        }
        n->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode *n = root;
        for (const char &c: word) {
            if (!n->children[getHash(c)]) {
                return false;
            }
            n = n->children[getHash(c)];
        }
        return n->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode *n = root;
        for (const char &c: prefix) {
            if (!n->children[getHash(c)]) {
                return false;
            }
            n = n->children[getHash(c)];
        }
        return true;
    }

    int getHash(const char &c) {
        return c - 'a';
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
