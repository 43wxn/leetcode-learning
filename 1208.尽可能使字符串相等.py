class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        '''
        只能s的第i个变到t的第i个
        维护一个动态的滑动窗口，right端加入变化的字母，在cost大于maxcost的时候left端减少
        记录窗口的最大长度
        '''
        window_len=0
        max_window=0
        right=0
        while right<len(s) :
            if abs(ord(s[right])-ord(t[right]))<=maxCost :
                window_len=window_len+1
                maxCost=maxCost-abs(ord(s[right])-ord(t[right]))
                right=right+1
                #print(right)
            else :
                if window_len>0 :
                    maxCost=maxCost+abs(ord(s[right-window_len])-ord(t[right-window_len]))
                    window_len=window_len-1
                else :
                    right=right+1
    
            max_window=max(max_window,window_len)
        return max_window