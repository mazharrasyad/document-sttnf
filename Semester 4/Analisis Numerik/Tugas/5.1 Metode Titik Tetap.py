from math import sqrt

def g(x) :
    # return sqrt((3*x + 5) / (x + 2))
    return 5 / (x**2 + 2*x - 3)

x = 6
lastx = x + 1
count = 0
selisih = 0

print("i\tXi\t|Xi - Xi-1|")
while count <= 10:
    lastx = x
    x = g(lastx)       
    if selisih == 0 : 
        print("%d\t%.4f\t-" %(count, lastx))
    else :
        print("%d\t%.4f\t%.4f" %(count, lastx, selisih))
    selisih = lastx - x
    count += 1