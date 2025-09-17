class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //shortest = bfs
        //tle bcz vector wordList me dhundhna is costly so set me dal do
        unordered_set<string> words(wordList.begin(), wordList.end()); 

        queue<string> q;
        unordered_set<string> vis;

        q.push(beginWord);
        vis.insert(beginWord);  
        int level = 1;  //idhar bola

        while(!q.empty()){
            int n =q.size();
            while(n--){
                string str = q.front();
                if(str==endWord)
                    return level;
                q.pop();

                for(char it: "abcdefghijklmnopqrstuvwxyz"){
                    for(int i=0;i<str.length();i++){
                        string curr = str;
                        curr[i] = it;

                        if(words.find(curr) != words.end() && vis.find(curr)==vis.end()){
                            q.push(curr);
                            vis.insert(curr);
                        }
                    }
                }
            }
            level++;
        }

        return 0;   //not possible

    }
};