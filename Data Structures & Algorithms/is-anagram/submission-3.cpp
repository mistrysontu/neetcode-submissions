class Solution {
public:
    bool isAnagram(string s, string t) {
//create a hashmap named umap1. 
        unordered_map<char,int> umap1;
//get the frequencies of each character in string1 i.e., in "S"
//example: s = "carrace"
//in hashmap, it tracks data like :
// (key) r - 2 times it occurred (therefore, value is 2)
//key a     - 2 times
//key c     - 2 times
//key e     - 2 times
        for(int i=0; i < s.size(); i++){
            umap1[s[i]]++; //increment the freq of each char to store in hashmap data.
            //increments the value (freq. occurance of each character)
        }

        for(auto elem: umap1){
            cout << elem.first << " " << elem.second << endl;
        }
//lets say string t = "mracecar"
        for(int i = 0; i < t.size(); i++){
            if(umap1.count(t[i]) == 0){ //
            //here, t[i] is each char in string t. 
            //== 0 means that string is not present in hashmap's key.
            //in above example, char "m" - key is not available.
            //so, s and t can't be same as keys are not matching.

                // one char which is in t but not in s,
                // so s and t can't be anagram
                cout << t[i] << " is not present in s" << endl;
                return false;
            }
            else{
                //if key (string)  is present in hashmap, then decrement the value.
                // decrements the "value" for each key (unique char), so that to check if it nulnifies to see if its anagram
                umap1[t[i]]--; //decrements the "value" for each character in string t
            }
        }

        cout << endl;

        for(auto elem: umap1){
            cout << elem.first << " " << elem.second << endl;            
            if(elem.second != 0) { //if it nullnifies, means both string's number of unique characters (keys) and its frequencies (values) are same.
                //if its not nullnifying, (have any less/more no. of char for same key) 
                //if its not equal zero, then its not anagram, so return false.
                return false;
            }
        }
        
        return true;

    }
};


/*

    umap['j']
    uamp['k']

*/
