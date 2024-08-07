class Solution:
    def isNumber(self, s: str) -> bool:

        integer1 = re.compile("(\+|-)?[0-9]+((e|E)(\+|-)?[0-9]+|[0-9]*)")
        decimal1 = re.compile("(\+|-)?[0-9]+\.[0-9]*((e|E)(\+|-)?[0-9]+|[0-9]*)")
        decimal2 = re.compile("(\+|-)?[0-9]*\.[0-9]+((e|E)(\+|-)?[0-9]+|[0-9]*)")

        sol1 = re.match(integer1, s)
        sol2 = re.match(decimal1, s)
        sol3 = re.match(decimal2, s)

        if(sol1 != None):
            if(sol1.span()[1] == len(s)):
                return True
        
        if(sol2 != None):
            if(sol2.span()[1] == len(s)):
                return True

        if(sol3 != None):
            if(sol3.span()[1] == len(s)):
                return True
        
        return False
        
        