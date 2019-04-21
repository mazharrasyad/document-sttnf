a = -1
b = 7
c = 0
fa = 0
fb = 0
fc = 0
i = 0

def fx(x) :
    return (x ** 2) - 4

print("Iterasi\ta\tf(a)\tb\tf(b)\tc\tf(c)")

while True :    
    fa = fx(a)
    fb = fx(b)
    # Metode Bagi Dua
    c = a + ((b - a) / 2)
    # Metode Posisi Palsu
    # c = b - ((fb / (fb - fa)) * (b - a))
    fc = fx(c)

    print("%d\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f\t%0.5f" %(i,a,fa,b,fb,c,fc))
        
    if i == 8 :
        break

    if (fa < 0 and fc < 0) or (0 < fa and 0 < fc) :
        a,c = c,a
        fa,fc = fc,fa
    elif (fb < 0 and fc < 0) or (0 < fb and 0 < fc) :
        b,c = c,b
        fb,fc = fc,fb
    i += 1
