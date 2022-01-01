/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* first = (struct ListNode*)malloc(sizeof(struct ListNode));
    first->next = head;
    struct ListNode* second = first;
    for (int i = 0; i < n-1; i++) {
        second = second->next;
    }
    while (second->next && second->next->next) {
        first = first->next;
        second = second->next;
    }
    if (first->next == head) {
        return head->next;
    } else if (first->next) {
        first->next = first->next->next;
        return head;
    } else {
        return NULL;
    }
}
// @lc code=end

