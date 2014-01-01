/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct Compare{
    bool operator()(const ListNode *one, const ListNode *two) const{
        return one->val > two->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(lists.size() == 0) return NULL;
        
        int K = lists.size();
        priority_queue<ListNode*, vector<ListNode *>, Compare> min_heap;

        for(int i = 0; i < K; i++){
            if(lists[i] != NULL){
                min_heap.push(lists[i]);
            }
        }
        
        if(min_heap.size() == 0) return NULL;

        ListNode *result = min_heap.top(), *prev = min_heap.top();

        if(min_heap.top()->next != NULL)
            min_heap.push(min_heap.top()->next);

        min_heap.pop();

        while(min_heap.size() > 0){
            prev->next = min_heap.top();

            if(min_heap.top()->next != NULL)
                min_heap.push(min_heap.top()->next);

            min_heap.pop();
            prev = prev->next;
        }

        prev->next = NULL;

        return result;
    }
};
