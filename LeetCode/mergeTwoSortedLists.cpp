#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        ListNode *head, *actual;
        if(list1->val < list2->val){
            head = list1;
            actual = list1;
            list1 = list1->next;
        }else{
            head = list2;
            actual = list2;
            list2 = list2->next;
        }

        // cout << "Head: " << head << " { " << head->val << ", " << head->next << " }" << endl;
        // cout << "List1: " << list1 << " { " << list1->val << ", " << list1->next << " }" << endl;
        // cout << "List2: " << list2 << " { " << list2->val << ", " << list2->next << " }" << endl;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                actual->next = list1;
                actual = list1;
                list1 = list1->next;
            }else{
                actual->next = list2;
                actual = list2;
                list2 = list2->next;
            }
        }

        if(list1 != nullptr){
            while(list1 != nullptr){
                actual->next = list1;
                actual = list1;
                list1 = list1->next;
            }
        }

        if(list2 != nullptr){
            while(list2 != nullptr){
                actual->next = list2;
                actual = list2;
                list2 = list2->next;
            }
        }
        
        return head;
    }
};