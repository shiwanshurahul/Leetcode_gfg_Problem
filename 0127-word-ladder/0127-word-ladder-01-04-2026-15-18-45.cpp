class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //shortest = bfs
        //tle bcz vector wordList me dhundhna is costly so set me dal do
        unordered_set<string> words(wordList.begin(), wordList.end()); 

        queue<string> q;
        unordered_set<string> vis;  //jo v mile usko dalte jao warna revert hoke beginWord na bn jaye

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

                for(char it: "abcdefghijklmnopqrstuvwxyz"){  //sbse replace krke dekho
                    for(int i=0;i<str.length();i++){  //har str pe sare char check kro
                        string curr = str;   // 0      1      2      0      1       2    0
                        curr[i] = it;  //hit ->ait -> hat -> hia -> bit -> hbt -> hib -> cit ..
                        if(words.find(curr) != words.end() && vis.find(curr)==vis.end()){  //visited me ni hai 
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