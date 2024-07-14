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
        map<int,int>m;
        for(auto it : nums){
            m[it]++;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nn = head->next;

        while(curr != NULL){
            if(m.find(curr->val) != m.end()){
                if(prev != NULL){
                    prev->next = nn;
                    curr->next = NULL;
                    curr = nn;
                    if(nn != NULL) nn = nn->next;
                }
                else{
                    curr->next = NULL;
                    head = nn;
                    curr = head;
                    if(head != NULL)nn = head->next;
                }
            }
            else{
                prev = curr;
                curr = nn;
                if(nn != NULL) nn = nn->next;
            }
        }
        return head;
    }
};