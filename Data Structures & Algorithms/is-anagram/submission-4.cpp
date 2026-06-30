class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> umap;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(umap.find(ch) == umap.end()) {
                // we got this char ch for the first time, so set it's freq to 1
                umap[ch] = 1;
            }
            else {
                // you already have see the char before
                umap[ch] = umap[ch] + 1;
                // umap[ch]++;
            }
        }

        for(char ch : t) { // for element (char) in string t
            if(umap.find(ch) == umap.end()) {
                // t has some char, which is not in s, so it can't be anagram.
                return false;
            }
            else {
                umap[ch]--;
                if(umap[ch] < 0) {
                    // t has more occurance of ch than s.
                    return false;
                }
            }
        }


        for(pair<char, int> elem : umap) {
            /*
                elem = {.first, .second}
            */
            if(elem.second != 0) {
                // occurance of char elem.first is uneven
                return false;
            }
        }

        return true;
    }
};

/*

r = 2
a = 2
c = 1
e = 1
x = 1

{key, value}

idx, value

arr[idx] => value

umap[key] => value


s[i] = 


arr[0] = 10

arr[0] = arr[0] + 2
arr[0]++;

a = -1
b = 0
c = 0



1. all char or s is in t => true;
2. t has more char than s => false;  (aab, bcd) => done
3. t has more occurance of ch than s :(abc, cac) => false
4. t has less occurance of ch than s : (aabc, cab) => false;

*/
