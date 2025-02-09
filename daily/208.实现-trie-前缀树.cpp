/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
    private:
        struct Info {
            array<int, 26> nxt;
            int end, pass;
            Info() {
                nxt.fill(0);
                end = pass = 0;
            }
            
        };
        vector<Info> trie;
    public:
        Trie() {
            trie.push_back(Info{});
        }
        
        void insert(string word) {
            int c = 0;
            for(auto x : word) {
                if(trie[c].nxt[x - 'a'] == 0) {
                    trie.push_back(Info{});
                    trie[c].nxt[x - 'a'] = trie.size() - 1;
                    trie.back().pass++;
                    c = trie[c].nxt[x - 'a'];
                } else {
                    trie[c].pass++;
                    c = trie[c].nxt[x - 'a'];
                }
            }
            trie[c].end++;
        }
        
        bool search(string word) {
            int c = 0;
            for(auto x : word) {
                if(trie[c].nxt[x - 'a'] == 0) {
                    return false;
                }
                c = trie[c].nxt[x - 'a'];
            }
            if(trie[c].end > 0) {
                return true;
            }
            return false;
            
        }
        
        bool startsWith(string prefix) {
            int c = 0;
            for(auto x : prefix) {
                if(trie[c].nxt[x - 'a'] == 0) {
                    return false;
                }
                c = trie[c].nxt[x - 'a'];
            }
            return true;
        }
    };

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

