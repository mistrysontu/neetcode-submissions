class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> umap;
        unordered_set<string> wordMap;
        wordMap.insert(beginWord);
        for(auto word: wordList){
            wordMap.insert(word);
        }
        for(auto word: wordList){
            for(int i = 0; i < word.size(); i++){
                for(char j = 'a'; j <= 'z'; j++){
                    if(word[i] != j){
                        string temp = word;
                        temp[i] = j;
                        if(wordMap.count(temp)){
                            umap[word].push_back(temp);
                            umap[temp].push_back(word);
                        }
                    }
                }
            }
        }
        unordered_set<string> visited;
        if(umap.count(beginWord) == 0 || umap.count(endWord) == 0) return 0;
        if(beginWord == endWord) return 0;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int cnt = 1;
        while(q.size()){
            int len = q.size();
            cnt++;
            for(int i = 0; i < len; i++){
                auto curr = q.front();
                q.pop();
                // if(curr == endWord) return cnt;
                for(auto nei: umap[curr]){
                    if(nei == endWord) return cnt;
                    if(visited.count(nei) == 0){
                        visited.insert(nei);
                        q.push(nei);
                    }
                }
            }
        }
        return 0;
    }
};
