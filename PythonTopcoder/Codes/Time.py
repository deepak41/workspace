class Time:
    def whatTime(self, seconds):
        h = seconds//3600
        r = seconds%3600
        m=r//60
        s=r%60
        
        result="%s:%s:%s" %(h, m, s)
        return result
    
t1=Time()
print t1.whatTime(86399)
        