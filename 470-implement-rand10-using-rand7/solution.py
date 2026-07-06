# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        
        """I will call this expanded probability matrix(mx), through this matrix
           we are expanding our values to 1-49.

           After that depending on the last digit of our expanded 
           values we return randomized values between 1-9.

           Except since there is 49 values not all digits probabilities are the same.

           To solve that issue we shrink our cluster of values from 49 to 40 since 
           40 is multiple of 10."""
        
        mx = [[0 for i in range(7)] for j in range(7)]
        value = 49

        for i in range(7):
            for j in range(7):
                mx[i][j] = ((i) * 7 + j) + 1

        while value > 40:
            value = mx[rand7() - 1][rand7() - 1] 
        
        return (value % 10) + 1
        