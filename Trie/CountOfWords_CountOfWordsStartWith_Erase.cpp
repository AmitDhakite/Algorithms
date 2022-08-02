// Problem Link: https://leetcode.com/problems/implement-trie-ii-prefix-tree/

#include<bits/stdc++.h>
using namespace std;
#define ll long long


struct Node {
    Node *link[26];
    int end = 0, cont = 0;
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
        for(auto &it: word)
        {
            int c = it - 'a';
            if(node->link[c] == NULL)
                node->link[c] = new Node();
            
            node = node->link[c];
            node->cont++;
        }
        node->end++;
    }
    
    int countWordsEqualTo(string word) 
    {
        Node *node = root;
        for(auto &it: word)
        {
            int c = it - 'a';
            if(node->link[c] == NULL)
                return 0;
            
            node = node->link[c];
        }
        return node->end;
    }
    
    int countWordsStartingWith(string prefix) 
    {
        Node *node = root;
        for(auto &it: prefix)
        {
            int c = it - 'a';
            if(node->link[c] == NULL)
                return 0;
            
            node = node->link[c];
        }
        return node->cont;    
    }
    
    void erase(string word) 
    {
        Node *node = root;
        for(auto &it: word)
        {
            int c = it - 'a';
            if(node->link[c] == NULL)
                return;
            
            node = node->link[c];
            node->cont--;
        }
        node->end--;    
    }
};
