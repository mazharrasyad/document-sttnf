# from scipy.interpolate import lagrange

# Polinom Lagrange
def Lagrange(x, y, n, nx) :
    L = 0
    for i in range(0, n) :        
        pi = 1        
        for j in range(0, n) :
            if i != j :
                pi = pi * (nx - x[j]) / (x[i] - x[j])                    
        L = L + y[i] * pi        
        Lagrange = L    
    return round(Lagrange, 4)
    
# Polinom Newton
def Newton(x, y, n, nx) :
    ST = [[0] * n for i in range(0, n)]    

    for k in range(0, n) :
        ST[k][0] = y[k]

    for k in range(1, n) :
        for i in range(0, n-k) :
            ST[i][k] = (ST[i+1][k-1] - ST[i][k-1]) / (x[i+k] - x[i])

    jumlah = ST[0][0]
    for i in range(1, n) :
        suku = ST[0][i]
        for k in range(0, i) :
            suku = suku * (nx - x[k])        
        jumlah = jumlah + suku
    Newton = jumlah    
    # print()

    return round(Newton, 4)

# Contoh Lagrange
x = [0, 0.4, 0.8, 1.2]
y = [1, 0.9211, 0.6967, 0.3624]
nx = 0.5
# p3(0.5) = 0.8773

# Contoh Lagrange
# x = [8, 9, 9.5, 11]
# y = [2.0794, 2.1972, 2.2513, 2.3979]
# nx = 9.2
# p3(9.2) = 0.8773

# Contoh Excel
# x = [1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3, 3.2, 3.4, 3.6, 3.8, 4, 4.2]
# y = [0.1823, 0.3365, 0.4700, 0.5678, 0.6931, 0.7885, 0.8755, 0.9555, 1.0296, 1.0986, 1.1632, 1.2238, 1.2809, 1.3350, 1.3863, 1.4351]
# nx = 2.9

n = len(x)
print(f"p{n-1}({nx}) Lagrange = {Lagrange(x, y, n, nx)}")
print(f"p{n-1}({nx}) Newton =  {Newton(x, y, n, nx)}")