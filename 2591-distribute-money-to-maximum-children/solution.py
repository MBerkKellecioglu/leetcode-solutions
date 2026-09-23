class Solution:
    def distMoney(self, money: int, children: int) -> int:

        if children > money:
            return -1
        
        ans = 0

        for i in range(1,children + 1):
            if money >= i * 8:
                remaining_money = money - i * 8
                remaining_child = children - i

                if (remaining_money == 4 and remaining_child == 1) or (remaining_money < remaining_child) or (remaining_child == 0 and remaining_money > 0):
                    continue
                
                ans = i
            else:
                break


        return ans