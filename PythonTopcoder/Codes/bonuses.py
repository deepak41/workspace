'''
Created on Dec 2, 2015

@author: Messi
'''


class Bonuses:
    def getDivision (self, points):
        pointsList = list(points)
        totalPts = sum(pointsList)
        bonus = []
        
        for p in pointsList:
            bon = (p*100)//totalPts
            bonus.append(bon)
        
        xtraPoints = 100 - sum(bonus)
        
        for i in range(xtraPoints):
            max_value = max(pointsList)
            max_index = pointsList.index(max_value)
            bonus[max_index] += 1
            pointsList[max_index] = None
        
        bonusTuple = tuple(bonus)
        return bonusTuple
        
    



x = (485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470)
b = Bonuses()
print b.getDivision(x)