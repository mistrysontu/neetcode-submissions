class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char,int> umap1;

        for(int i=0; i < s.size(); i++){
            umap1[s[i]]++;
        }

        for(auto elem: umap1){
            cout << elem.first << " " << elem.second << endl;
        }

        for(int i = 0; i < t.size(); i++){
            if(umap1.count(t[i]) == 0){
                // one char which is in t but not in s,
                // so s and t can't be anagram
                cout << t[i] << " is not present in s" << endl;
                return false;
            }
            else{
                umap1[t[i]]--;
            }
        }

        cout << endl;

        for(auto elem: umap1){
            if(elem.second != 0) return false;
            cout << elem.first << " " << elem.second << endl;
        }



        
        return true;

    }
};


/*

    umap['j']
    uamp['k']

*/
