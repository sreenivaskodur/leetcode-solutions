/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if(head == NULL) return NULL;
        
        RandomListNode *h = head;
        map<RandomListNode*,RandomListNode*> lookup;
        
        while(head != NULL){
            if(lookup.find(head) == lookup.end()){
                lookup[head] = new RandomListNode(head->label);
            }
            
            if(head->next != NULL){
                if(lookup.find(head->next) == lookup.end()){
                    lookup[head->next] = new RandomListNode(head->next->label);
                }
                    
                lookup[head]->next = lookup[head->next];
            }
                
            if(head->random != NULL){
                if(lookup.find(head->random) == lookup.end()){
                    lookup[head->random] = new RandomListNode(head->random->label);
                }
                    
                lookup[head]->random = lookup[head->random];
            }
            
            head = head->next;
        }
        
        return lookup[h];
    }
};
