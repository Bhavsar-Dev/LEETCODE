/**
 * @param {string[]} words
 */
var StreamChecker = function(words) {
    this.trie = {};
    this.history = [];
    for(const word of words) {
        let node = this.trie;
        for(let i = word.length - 1; i >= 0; i--) {
            const char = word[i];
            if(!node[char]) {
                node[char] = {};
            }
            node = node[char];
        }
        node.isWord = true;
    }
};

/** 
 * @param {character} letter
 * @return {boolean}
 */
StreamChecker.prototype.query = function(letter) {
    this.history.push(letter);
    let node = this.trie;
    for(let i = this.history.length - 1; i >= 0; i--) {
        const char = this.history[i];
        if(!node[char]) {
            return false; 
        }
        node = node[char];
        if(node.isWord) {
            return true; 
        }
    }
    return false;
};

/** 
 * Your StreamChecker object will be instantiated and called as such:
 * var obj = new StreamChecker(words)
 * var param_1 = obj.query(letter)
 */