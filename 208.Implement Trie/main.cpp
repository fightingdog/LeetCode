//
//  main.cpp
//  Implement Trie (Prefix Tree)
//
//  Created by 刘昭 on 2019/11/26.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

static const int kMAX = 26;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        this->is_str = false;
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *cur = this;
        for (char c : word) {
            if (cur->next[c - 'a'] == NULL) {
                Trie *newNode = new Trie();
                cur->next[c - 'a'] = newNode;
            }
            cur = cur->next[c - 'a'];
        }
        cur->is_str = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *cur = this;
        for (char c : word) {
            if (cur != NULL) {
                cur = cur->next[c - 'a'];
            }
        }
        return (cur != NULL && cur->is_str);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *cur = this;
        for (char c : prefix) {
            if (cur != NULL) {
                cur = cur->next[c - 'a'];
            }
        }
        return cur != NULL;
    }
private:
    bool is_str;
    Trie* next[kMAX];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, const char * argv[]) {
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple");   // 返回 true
    cout << trie->search("app");     // 返回 false
    cout << trie->startsWith("app");
    trie->insert("app");
    cout << trie->search("app");     // 返回 true
    return 0;
}
