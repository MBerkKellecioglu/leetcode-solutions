class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        
        transformed = []

        perimeter, n = 4 * side, len(points)

        # Transforming points according to their distance to bottom left corner along square perimeter
        # Imagine we are starting from bottom left corner and traversing square going up -> right -> down ->left
        # Distance we are mentioning here is calculated this way. Not Euiclidan
        for x, y in points:
            dist = 0

            if x == 0:
                dist = y
            elif y == side:
                dist = side + x 
            elif x == side:
                dist = (2 * side) + (side - y)
            else:
                dist = (3 * side) + (side - x)
            
            transformed.append(dist)
            # We are doing this because our transformation array is circular
            # This will allow us to check distance between first and last element
            transformed.append(dist + perimeter)

        transformed.sort()

        def validate(dist):
            
            for start_ind in range(n):
                count, curr = 1, transformed[start_ind]

                for i in range(k - 1):
                    # Finding minimum element sthat satisfies our distance constraint
                    # Element we found can be bigger than curr + dist 
                    ind = bisect_left(transformed, curr + dist)

                    if ind >= start_ind + n:
                        break
                    
                    count += 1
                    curr = transformed[ind]

                # This is for checking distance between last and first element 
                if count >= k and transformed[start_ind] + perimeter - curr >= dist:
                    return True

            return False

        l, r = 1, side
        ans = 0

        while l <= r:
            mid = (l + r) // 2

            if validate(mid):
                ans = mid 
                l = mid + 1
            else:
                r = mid - 1
        
        return ans
        
                
