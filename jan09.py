'''
Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest 
transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Return 0 if there is no such transformation sequence.
'''

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        word_map = collections.defaultdict(list)
        L = len(beginWord)

        for word in wordList:
            for i in range(L):
                word_map[word[:i] + '*' + word[i + 1:]].append(word)

        q = [beginWord]
        transformations = 1
        visited = set([beginWord])

        while q:
            transformations += 1
            new_q = []
            for w1 in q:
                for i in range(L):
                    for w2 in word_map[w1[:i] + '*' + w1[i + 1:]]:
                        if w2 in visited:
                            continue
                        if w2 == endWord:
                            return transformations
                        new_q.append(w2)
                        visited.add(w2)

            q = new_q
        return 0