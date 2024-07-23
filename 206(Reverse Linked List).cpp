/* QUESTION
Given the head of a singly linked list, 
reverse the list, and return the reversed list.
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // Previous node
        ListNode* curr = head;    // Current node
        ListNode* next = nullptr; // Next node
        
        while (curr != nullptr) {
            next = curr->next; // Save the next node
            curr->next = prev; // Reverse the link
            prev = curr;       // Move prev to current
            curr = next;       // Move to the next node
        }
        
        return prev; // New head of the reversed list
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        temp = temp->next;
        if (temp != nullptr) {
            cout << " -> ";
        }
    }
    cout << endl;
}

// Example usage
int main() {
    Solution sol;
    
    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Original list: ";
    printList(head);
    
    ListNode* reversedHead = sol.reverseList(head);
    
    cout << "Reversed list: ";
    printList(reversedHead);
    
    // Free the allocated memory
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }
    
    return 0;
}
