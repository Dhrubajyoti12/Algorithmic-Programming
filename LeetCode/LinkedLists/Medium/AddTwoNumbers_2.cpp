// Problem Link : https://leetcode.com/problems/add-two-numbers/
// Author : Himanshu Mundhra

/*************************************************************************************************************
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 *      Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *      Output: 7 -> 0 -> 8
 *      Explanation: 342 + 465 = 807.
 *
*************************************************************************************************************/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;

        while(1){
            int temp = carry;
            if (l1) {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                temp += l2->val;
                l2 = l2->next;
            }

            carry = temp/10;
            tmp->val = temp%10;

            if (carry or l1 or l2) {
                tmp->next = new ListNode(0);
                tmp = tmp->next;
            } else {
                break;
            }
        }
        return head;
    }
};
