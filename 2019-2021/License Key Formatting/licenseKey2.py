class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        count = 0
        S = S.replace('-', '')
        S = S.upper()
        for char_idx in range(len(S) - 1, -1, -1):
            if count < K:
                count +=1
            else:
                S = S[:char_idx+1] + '-' + S[1+char_idx:]
                count = 1
        return S
        
def stringToString(input):
    import json

    return json.loads(input)

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            S = stringToString(line);
