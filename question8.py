#Implement Trie (Prefix Tree)
class treeNode(object):
    def __init__(self):
        self.children=collections.defaultdict(treeNode)
        self.isword=False
class Trie(object):

    def __init__(self):
        self.root=treeNode()
        """
        Initialize your data structure here.
        """
        

    def insert(self, word):
        current=self.root
        for ch in word:
            current=current.children[ch]
        current.isword=True
        
        
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        

    def search(self, word):
        current=self.root
        for ch in word:
            current=current.children.get(ch)
            if current==None:
                return False
        return current.isword
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        

    def startsWith(self, prefix):
        current=self.root
        for ch in prefix:
            current=current.children.get(ch)
            if current==None:
                return False
        return True
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)