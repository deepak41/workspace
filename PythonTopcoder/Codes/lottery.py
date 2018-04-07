'''
Created on Dec 3, 2015

@author: Messi
'''


from math import factorial as fact

class Lottery:
    def sortByOdds(self, rules):
        if rules[2]==True and rules[3]==True:
            total=fact(rules[0])/(fact(rules[1])*(fact(rules[0]-rules[1])))
        elif rules[2]==False and rules[3]==False:
            total=rules[0]**rules[1]
        elif rules[2]==False and rules[3]==True:
            total=fact(rules[0])/fact(rules[0]-rules[1])
        else:
            pass
        return total
        


x=[99,8,True,True]
y=[75,6,False, False]
l=Lottery()
print l.sortByOdds(x)
print l.sortByOdds(y)          