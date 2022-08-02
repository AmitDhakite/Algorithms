// Problem Link: https://leetcode.com/problems/implement-trie-prefix-tree/

#include<bits/stdc++.h>
using namespace std;
#define ll long long


struct Node {
    Node* link[26];
    bool end = false;
};

class Trie {
public:
    Node *root;
    
    Trie() 
    {
        root = new Node();
    }
    
    void insert(string word) 
    {
        Node *node = root;
        int n = word.length();
        for(int i = 0; i < n; i++)
        {
            int c = word[i] - 'a';
            if(node->link[c] == NULL)
                node->link[c] = new Node();
            
            node = node->link[c];
        }
        node->end = true;
    }
    
    bool search(string word) 
    {        
        Node *node = root;
        int n = word.length();
        for(int i = 0; i < n; i++)
        {
            int c = word[i] - 'a';
            if(node->link[c] == NULL)
                return false;
            
            node = node->link[c];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) 
    {
        Node *node = root;
        int n = prefix.length();
        for(int i = 0; i < n; i++)
        {
            int c = prefix[i] - 'a';
            if(node->link[c] == NULL)
                return false;
            
            node = node->link[c];
        }
        return true;
    }
};