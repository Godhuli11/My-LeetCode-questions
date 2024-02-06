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
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if(head==NULL) return NULL;
//         ListNode* midN=head;
//         ListNode * prev = NULL;
//         ListNode* temp= head;
//         int size=0;
        
//         while(temp && temp->next){
//             temp = temp->next;
//             size++;
//         }
        
//         int mid = size/2;
        
//         while(mid--){
//             prev = midN;
//             midN = midN->next;
//         }
//         if(prev!=NULL){
//             prev->next = midN->next;
//             delete midN;
//         }else{
//             head = head->next;
//         }
        
           
        
//         return head;
//     }
// };
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL; // No middle element to delete
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev != NULL) {
            prev->next = slow->next;
            delete slow;
        } else {
            // If there are only two nodes, delete the head
            head = head->next;
            delete slow;
        }

        return head;
    }
};

