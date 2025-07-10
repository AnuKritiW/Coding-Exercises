class Solution:
    def calculate(self, s: str) -> int:
        
        if not s:
            return False
        
        stack = []
        curr_num = ""
        operation = "+"
        
        for i, char in enumerate(s):
            if char.isdigit():
                curr_num += char
            if (not char.isdigit() and not char.isspace()) or (i == len(s)-1):
                int_curr_num = int(curr_num)
                if operation == "-":
                    stack.append(-int_curr_num)
                elif operation == "+":
                    stack.append(int_curr_num)
                elif operation == "*":
                    stack.append(stack.pop() * int_curr_num)
                elif operation == "/":
                    division = (stack.pop() / int_curr_num)
                    if division < 0:
                        division = math.ceil(division)
                    else:
                        division = math.floor(division)
                    stack.append(division)
                
                operation = char
                curr_num = ""
        
        result = 0
        while stack:
            result += stack.pop()
        
        return result
        