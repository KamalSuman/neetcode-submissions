class Node{
    public:
    bool exist = false;
    vector<Node*> next = vector<Node*>(26, nullptr);
    void put(char c, Node* node){
        next[c-'a'] = node;
    }
    Node* get(char c){
        return next[c-'a'];
    }
};


class WordDictionary {
public:
    Node* node;

    WordDictionary() {
        node = new Node();
    }
    
    void addWord(string word) {
        Node* curr = node;
        for(int i = 0; i<word.size(); i++){
            if (curr->get(word[i]) == nullptr) {
                curr->put(word[i], new Node());
            }

            curr = curr->get(word[i]);
        }
        curr->exist = true;
    }
    bool help(string word, Node* curr, int idx){
        if(idx == word.size()){
            return curr->exist;
        }
        if(word[idx] != '.'){
            if(curr->get(word[idx]) == nullptr) return false;
            return help(word, curr->get(word[idx]), idx+1);
        } else {
            bool flag = false;
            for(char c = 'a'; c<='z'; c++){
               Node* nextNode = curr->get(c);
                if(nextNode != nullptr &&
                help(word, nextNode, idx + 1)) {
                    return true;
                }
            }
            return flag;
        }
    }
    bool search(string word) {
        return help(word, node, 0);
    }
};
