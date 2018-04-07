from datetime import datetime
import time

# t contains timestamp for current pc time
t = int(time.time())

# a contains time in normal format
a = datetime.fromtimestamp(t)


# EXAMPLES
# p contains 2015-11-07 02:37:04
p = datetime.fromtimestamp(1446844024)

# prints day i.e 07
print p.strftime("%d")

# prints month i.e 11
print p.strftime("%m")
# prints name(abbr) of the month i.e Nov
print p.strftime("%b")

# prints year i.e 15
print p.strftime("%y")
# prints year i.e 2015
print p.strftime("%Y")

# prints hour (24-hour clock) i.e 02
print p.strftime("%H")

# prints minute i.e 37
print p.strftime("%M")

# prints seconds i.e 04
print p.strftime("%S")
