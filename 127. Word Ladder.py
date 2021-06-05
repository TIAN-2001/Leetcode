class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        queue, wordset = deque([(beginWord, 1)]), set(wordList)
        wordset.discard(beginWord)
        if endWord not in wordset:
            return 0
        while queue:
            word, step = queue.popleft()
            if word == endWord:
                return step
            for i in range(len(word)):
                for ch in "qwertyuiopasdfghjklzxcvbnm":
                    newword = word[:i] + ch + word[i + 1:]
                    if newword in wordset :
                        wordset.remove(newword)
                        queue.append((newword, step + 1))
        return 0