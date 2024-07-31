/* QUESTION
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by
splicing together the nodes of the first two lists.
Return the head of the merged linked list.
Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/
#include <iostream>

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
        // Create a dummy node to act as the starting point of the merged list
        ListNode dummy;
        ListNode* current = &dummy;

        // Iterate through both lists and merge them
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Attach the remaining elements
        current->next = list1 ? list1 : list2;

        // Return the merged list starting from the node after dummy
        return dummy.next;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        head = head->next;
        if (head != nullptr) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Create first sorted linked list: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // Create second sorted linked list: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    printList(mergedList);

    // Free the allocated memory
    ListNode* temp;
    while (mergedList != nullptr) {
        temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
