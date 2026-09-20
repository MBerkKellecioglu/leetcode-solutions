class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        
        # first and last occurence
        occurence = {}

        ans = []

        for i,c in enumerate(s):
            if c not in occurence:
                occurence[c] = [i,i]
            else:
                occurence[c][1] = i
        
        valid_intervals = []

        # check every unique letter intervals and see if its valid 
        for letter in occurence:
            first, last = occurence[letter]

            idx = first

            valid = True

            # checking all other characters inside the substring(interval) of letter 
            while idx <= last:
                curr_letter = s[idx]

                curr_first, curr_last = occurence[curr_letter]

                # if curr_letter starting point is before our letter starting point it is not valid
                # no way to make it valid -> we cant expand it to left because we are already coming from there
                # we would get duplicate intervals
                if curr_first < first:
                    valid = False
                    break
                
                # if curr_letter end point is further we need to expand the interval to make it valid
                last = max(last, curr_last)

                idx += 1
            
            if valid:
                valid_intervals.append([first,last])

        # sort intervals according endpoint to greedily select early ending intervals to maximize number of substrings
        valid_intervals.sort(key = lambda x : x[1])

        # last valid interval end point
        last_end = valid_intervals[0][1]

        # add first interval to ans array
        ans.append(s[valid_intervals[0][0] : last_end + 1])

        for idx in range(1, len(valid_intervals)):
            curr_start, curr_end = valid_intervals[idx]

            # if our current valid interval does not overlap with last interval we add it to our ans array
            if curr_start > last_end:
                ans.append(s[curr_start : curr_end + 1])
                last_end = curr_end
        
        return ans






