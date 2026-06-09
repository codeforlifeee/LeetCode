class Trie {
public:
    struct TrieNode{
        TrieNode* links[26] = {nullptr};
        bool isEnd = false;

        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        TrieNode* get(char ch) {
            return links[ch - 'a'];
        }

        void put(char ch, TrieNode* node) {
            links[ch - 'a'] = node;
        }

        void setEnd(){
            isEnd = true;
        }

        bool isEndNode(){
            return isEnd;
        }
    };
        TrieNode* root;


    Trie() {
                root = new TrieNode();

    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return node->isEndNode();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
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