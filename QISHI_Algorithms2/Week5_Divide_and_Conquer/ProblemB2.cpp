/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        sort(nuts, bolts, compare, 0, nuts.size() - 1);
    }
    
    void sort(vector<string> &nuts, vector<string> &bolts, Comparator& compare, int l, int r) {
    	if(l < r){
    		int pl = partition(nuts[r], bolts, compare, l, r);
    		partition(bolts[pl], nuts, compare, l, r);
    		
    		sort(nuts, bolts, compare, l, pl - 1);
    		sort(nuts, bolts, compare, pl + 1, r);
    	}
    }

    int partition(string pivot, vector<string> &nuts_or_bolts, Comparator& compare, int l, int r){
        for(int i = l; i <= r; i++){
            if(compare.cmp(nuts_or_bolts[i], pivot) == 0){
                iter_swap(nuts_or_bolts.begin() + i, nuts_or_bolts.begin() + r);
                break;
            }
        }
        pivot = nuts_or_bolts[r];
        int i = l;
        for(int j = l; j < r; j++){
            if(compare.cmp(nuts_or_bolts[i], pivot) == -1){
                iter_swap(nuts_or_bolts.begin() + i, nuts_or_bolts.begin() + j);
                i++;
            }
        }
        iter_swap(nuts_or_bolts.begin() + i, nuts_or_bolts.begin() + r);
        return i;
    }
};
