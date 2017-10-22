//trie insert, search and delete

#include <iostream>
#include <string>
#include <cassert>

#define CHARS_MAX 256

using namespace std;

struct TrieNode {
    private:
        TrieNode *chars[CHARS_MAX];
        bool endOfWord;

    public:
        TrieNode() {
            for (int i = 0; i < CHARS_MAX; i++)
				
                chars[i] = NULL;
            endOfWord = false;
        }

        TrieNode *getChar(int ch) {
            return chars[ch];
        }
        void setChar(TrieNode *node, int ch) {
            chars[ch] = node;
        }
        bool isSet(int ch) {
            if (chars[ch] == NULL)
                return false;
            else
                return true;
        }
        bool isEndOfWord() {
            return endOfWord;
        }
        void setEndOfWord(bool val) {
            endOfWord = val;
        }
};

class Trie {
    private:
        TrieNode *root;
        int numWords;
    public:
        void insertWord(string word);
        bool searchWord(string word);
		//TODO
        bool deleteWord(string word);
        //TODO
        void deleteTrie() {}

        Trie() {
            root = new TrieNode;
            if (!root) assert(0);
            numWords = 0;
        }
        ~Trie() {
            deleteTrie();
        }
};

void Trie::insertWord(string word) {
    TrieNode *traverse = root;

    if (word.length() == 0) return;

    for (int i = 0; i < word.length(); i++) {
        if (!traverse->isSet(word[i])) {
            TrieNode *newNode = new TrieNode;
            if (!newNode) assert(0);
            traverse->setChar(newNode, word[i]);
        }
        traverse = traverse->getChar(word[i]);
    }
    traverse->setEndOfWord(true);
    numWords++;
}

bool Trie::searchWord(string word) {
    TrieNode *traverse = root;

    if (word.length() == 0) return true;

    for (int i = 0; i < word.length(); i++) {
        if (!traverse->isSet(word[i]))
            return false;
        traverse = traverse->getChar(word[i]);
    }
    if (traverse->isEndOfWord())
        return true;
    return false;
}

// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    Trie T;
 
    // Construct trie
    for (int i = 0; i < n; i++)
        T.insertWord(keys[i]);
 
    // Search for different keys
    T.searchWord("the")? cout << "Yes\n" :
                         cout << "No\n";
    T.searchWord("these")? cout << "Yes\n" :
                           cout << "No\n";
    T.searchWord("there")? cout << "Yes\n" :
                           cout << "No\n";
    T.searchWord("their")? cout << "Yes\n" :
                           cout << "No\n";
    T.searchWord("by")? cout << "Yes\n" :
                           cout << "No\n";
    T.searchWord("ghee")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
}
