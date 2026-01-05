class Solution {
    unordered_map<string, vector<string>> wildToString;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // endWord not in wordList
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        // add first word to wordList
        wordList.push_back(beginWord);

        // construct adjacency list
        for (string word : wordList)
        {
            for (int i = 0; i < word.size(); i++)
            {
                string wild = word;
                wild[i] = '*';
                wildToString[wild].push_back(word);
            }
        }

        set<string> visited({beginWord});
        deque<string> bfsQ({beginWord});
        int ladderLen = 1;

        while (!bfsQ.empty())
        {
            int bfsQLen = bfsQ.size();
            for (int i = 0; i < bfsQLen; i++)
            {
                string word = bfsQ.front();
                if (word == endWord) return ladderLen;
                bfsQ.pop_front();
                visited.insert(word);
                for (int i = 0; i < word.size(); i++)
                {
                    string wild = word;
                    wild[i] = '*';
                    for (string nextWord : wildToString[wild])
                    {
                        if (visited.find(nextWord) != visited.end()) continue;
                        bfsQ.push_back(nextWord);
                    }
                }
            }
            ladderLen++;
        }
        return 0;
    }
};
