/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;

        ListNode *current = head;
        while(head != nullptr && current->next != nullptr) {
            st.insert(current);

            if(st.find(current->next) != st.end()) 
                return true;

            current = current->next;
        }

        return false;
    }
};
