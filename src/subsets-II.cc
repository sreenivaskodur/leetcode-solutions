struct Element{
    int element;
    Element *prev;
    
    Element(int element, Element *prev):element(element),prev(prev){}
};

bool compare(vector<int> one, vector<int> two){
    if(one.size() > 0 and two.size() > 0){
        return one[0] > two[0];
    }
    
    return one.size() > two.size();
}

class Solution {
private:
    vector<int> numbers;
    vector<vector<int> > all_subsets;
    
    void subSets_helper(int curr, Element *prevset){
        
        if(curr == numbers.size()){
            vector<int> subset;
            
            while(prevset != NULL){
                subset.push_back(prevset->element);
                prevset = prevset->prev;
            }
            
            reverse(subset.begin(),subset.end());
            all_subsets.push_back(subset);
        } else{
            
            int final = curr;
            while(final < numbers.size() and numbers[final] == numbers[curr]){
                final ++;
            }
            
            subSets_helper(final,prevset);
            
            while(curr < final){
                Element *c = new Element(numbers[curr++],prevset);
                subSets_helper(final,c);
                prevset = c;
            }
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
     
        all_subsets.clear();
        sort(S.begin(),S.end());
        numbers = S;
        
        subSets_helper(0,NULL);
        
        sort(all_subsets.begin(),all_subsets.end(),compare);
        return all_subsets;
    }
};
