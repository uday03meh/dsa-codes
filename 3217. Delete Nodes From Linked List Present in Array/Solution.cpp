/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(), nums.end());
        
        // logn * n == nlogn
        // dummy node
        ListNode* newhead = new ListNode(0);
        ListNode* prev = newhead;
        prev -> next = head;
        ListNode* curr = head;
        // o(n)
        while(curr){
            int value = curr -> val;
            if(s.find(value) != s.end()){
                prev -> next = curr -> next;
            }
            else {
                prev = curr;
            }
            curr = curr -> next;
        }
        return newhead -> next;
    }
};
