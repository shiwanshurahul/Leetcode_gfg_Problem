class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //beginword se endword banan ha using wordlist
        //shortes = bfs
        //tle bcz vector wordList me dhundhn is costly so set me dal do
        unordered_set<string> words(wordList.begin(), wordList.end()); 

        queue<string> q;
        unordered_set<string> vis;  //jo v mile usko dalt jao warna revert hoke 
        // beginWord na bn jay

        q.push(beginWord);
        vis.insert(beginWord);  

        int level = 1;  //idhr bola

        while(!q.empty()){
            int n = q.size();
            while(n--){
                string str = q.front();
                if(str == endWord)
                    return level;
                q.pop();

                for(char ch: "abcdefghijklmnopqrstuvwxyz"){  //sbse replace krke dekh
                    for(int i=0;i<str.length();i++){  //str ke sar digit pe ch dalke chk
                        string curr = str;   // 0      1      2      0      1       2    0
                        curr[i] = ch;  //hit ->ait -> hat -> hia -> bit -> hbt -> hib -> cit ..
                        if(words.find(curr) !=words.end() && vis.find(curr)==vis.end()){
                            //visited me ni ha 
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