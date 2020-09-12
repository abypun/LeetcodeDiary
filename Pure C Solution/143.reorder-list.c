/*
 * @lc app=leetcode id=143 lang=c
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reorderList(struct ListNode* head){
    // struct ListNode *p1 = head, *del, *tmp1, *tmp2;
    // struct ListNode *p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    // p2->next = NULL;
    // while (p1 && p1->next) {
    //     del = p1->next;
    //     p1->next = p1->next->next;
    //     //head-insert
    //     del->next = p2->next;
    //     p2->next = del;
    //     p1 = p1->next;
    // }
    // p1 = head, p2 = p2->next;
    // while (p2) {
    //     tmp1 = p1->next;
    //     tmp2 = p2->next;
    //     p1->next = p2;
    //     p2->next = tmp1;
    //     p1 = tmp1;
    //     p2 = tmp2;
    // }
    int len = 0;
    struct ListNode *p = head, *tmp1, *tmp2, *half;
    struct ListNode *reversedHalf = (struct ListNode*)malloc(sizeof(struct ListNode));
    reversedHalf->next = NULL;
    while (p) {
        len++;
        p = p->next;
    }
    if (len < 3) return;
    half = head;
    // 移动到需要移动位置的结点前
    for (int i = 0; i < len/2; i++) half = half->next;
    p = half->next;
    half->next = NULL;
    while (p) {
        tmp1 = p->next;
        p->next = reversedHalf->next;
        reversedHalf->next = p;
        p = tmp1;
    }
    p = head;
    reversedHalf = reversedHalf->next;
    while (reversedHalf) {
        tmp1 = p->next;
        tmp2 = reversedHalf->next;
        p->next = reversedHalf;
        reversedHalf->next = tmp1;
        p = tmp1;
        reversedHalf = tmp2;
    }
}
// @lc code=end

