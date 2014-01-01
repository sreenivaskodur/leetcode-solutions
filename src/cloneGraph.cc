/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    map<int,UndirectedGraphNode*> lookup;
    map<int,bool> explored;
    
    UndirectedGraphNode *cloneGraphHelper(UndirectedGraphNode *node) {
        if(lookup.find(node->label) == lookup.end()){
            lookup[node->label] = new UndirectedGraphNode(node->label);
        }
        
        explored[node->label] = true;
        
        for(int i = 0; i < node->neighbors.size(); i++){
            UndirectedGraphNode *nbr = node->neighbors[i];
            
            if(explored.find(nbr->label) == explored.end()){
                nbr = cloneGraphHelper(nbr);
            }
            
            lookup[node->label]->neighbors.push_back(lookup[nbr->label]);
        }
        
        return lookup[node->label];
    }
    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        lookup.clear(); explored.clear();
        
        if(node == NULL) return NULL;
        
        return cloneGraphHelper(node);
    }
};
