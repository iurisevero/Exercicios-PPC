#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;

        Node *copy = new Node(head->val);
        Node *copy_head = copy, *original_head = head;
        map<Node*, Node*> original_copy;
        
        original_copy[head] = copy;
        head = head->next;
        
        while(head != nullptr){
            copy->next = new Node(head->val);
            copy = copy->next;
            original_copy[head] = copy;
            
            head = head->next;
        }
        copy = copy_head;
        head = original_head;
        
        while(head != nullptr){
            copy->random = original_copy[head->random];
            copy = copy->next;
            head = head->next;
        }
        
        return copy_head;
    }
};