class Solution(object):
    def areSentencesSimilar(self, words1, words2, pairs):
        """
        :type words1: List[str]
        :type words2: List[str]
        :type pairs: List[List[str]]
        :rtype: bool
        """
        if len(words1) != len(words2):
            return False
        for word_idx in range(0, len(words1)):
            if words1[word_idx] == words2[word_idx]:
                continue

            foundPair = False
            for x in pairs:
                if words1[word_idx] in x and words2[word_idx] in x: #similar words
                    foundPair = True
                    break

            if not foundPair:
                return False

        return True

def stringToStringArray(input):
    return json.loads(input)

def stringToString2dArray(input):
    return json.loads(input)

def main():
    import sys
    def readlines():
        for line in sys.stdin:
            yield line.strip('\n')
    lines = readlines()
    while True:
        try:
            line = lines.next()
            words1 = stringToStringArray(line)
            line = lines.next()
            words2 = stringToStringArray(line)
            line = lines.next()
            pairs = stringToString2dArray(line)

            ret = Solution().areSentencesSimilar(words1, words2, pairs)

            out = (ret)
            print out
        except StopIteration:
            break

if __name__ == '__main__':
    main()
