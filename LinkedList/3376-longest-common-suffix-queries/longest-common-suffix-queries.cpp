class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // 定義 Trie 節點
        struct TrieNode {
            int children[26];
            int best_idx;
            // 建構子：初始化子節點為 -1，並記錄當前最佳索引
            TrieNode(int idx) : best_idx(idx) {
                fill(begin(children), end(children), -1);
            }
        };
        
        int n = wordsContainer.size();
        
        // 1. 尋找全域最佳解 (空後綴時的預設答案)
        int global_best_idx = 0;
        for (int i = 1; i < n; ++i) {
            if (wordsContainer[i].length() < wordsContainer[global_best_idx].length()) {
                global_best_idx = i;
            }
        }
        
        // 宣告連續記憶體的 Trie，並推入根節點 (Index 0)
        vector<TrieNode> trie;
        trie.emplace_back(global_best_idx); 
        
        // 2. 將 wordsContainer 反向建構入 Trie
        for (int i = 0; i < n; ++i) {
            const string& word = wordsContainer[i];
            int curr = 0; // 從 root 開始
            
            // 由後往前讀取字元
            for (int j = word.length() - 1; j >= 0; --j) {
                int c = word[j] - 'a';
                
                // 如果路徑不存在，開啟新節點
                if (trie[curr].children[c] == -1) {
                    trie[curr].children[c] = trie.size();
                    trie.emplace_back(i); // 新節點的初始 best_idx 為 i
                } else {
                    // 如果路徑存在，判斷是否需要更新 best_idx
                    int next_node = trie[curr].children[c];
                    int existing_idx = trie[next_node].best_idx;
                    
                    if (word.length() < wordsContainer[existing_idx].length() || 
                       (word.length() == wordsContainer[existing_idx].length() && i < existing_idx)) {
                        trie[next_node].best_idx = i;
                    }
                }
                // 往下層移動
                curr = trie[curr].children[c];
            }
        }
        
        // 3. 處理查詢
        vector<int> ans;
        ans.reserve(wordsQuery.size()); // 預先配置記憶體以提升效能
        
        for (const string& q : wordsQuery) {
            int curr = 0;
            for (int j = q.length() - 1; j >= 0; --j) {
                int c = q[j] - 'a';
                if (trie[curr].children[c] == -1) {
                    break; // 匹配中斷，停在當前節點
                }
                curr = trie[curr].children[c];
            }
            // 取出匹配到最深處節點的 best_idx
            ans.push_back(trie[curr].best_idx);
        }
        
        return ans;
    }
};