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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        // Merging Loop
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Append any remaining elements if there is
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};
        // if (!list1 && !list2)
        //     return nullptr;

        // vector<int> sortedElementsOfBothLists;

        // // Sorting Loop
        // while (true) {
        //     if (!list1 && list2) {
        //         sortedElementsOfBothLists.push_back(list2->val);
        //         break;
        //     }
        //     if (list1 && !list2) {
        //         sortedElementsOfBothLists.push_back(list1->val);
        //         break;
        //     }

        //     if (list1 != nullptr && list2 != nullptr) {
        //         if (list1->val <= list2->val) {
        //             sortedElementsOfBothLists.push_back(list1->val);
        //             sortedElementsOfBothLists.push_back(list2->val);
        //         } else {
        //             sortedElementsOfBothLists.push_back(list2->val);
        //             sortedElementsOfBothLists.push_back(list1->val);
        //         }
        //     }

        //     if (list1 != nullptr && list2 == nullptr) {
        //         sortedElementsOfBothLists.push_back(list1->val);
        //     } else {
        //         sortedElementsOfBothLists.push_back(list2->val);
        //     }

        //     if (list1->next == nullptr && list2->next != nullptr) {
        //         list1 = nullptr;
        //         list2 = list2->next;
        //     } else if (list1->next != nullptr && list2->next == nullptr) {
        //         list1 = list1->next;
        //         list2 = nullptr;
        //     } else {
        //         break;
        //     }
        // }

        // ListNode* headOfTheResultedList =
        //     new ListNode(sortedElementsOfBothLists[0]);
        // ListNode* current = headOfTheResultedList;

        // // Build Loop
        // for (size_t i = 1; i < sortedElementsOfBothLists.size(); i++) {
        //     ListNode* newNode = new ListNode(sortedElementsOfBothLists[i]);

        //     current->next = newNode;

        //     current = newNode;
        // }

        // return headOfTheResultedList;
