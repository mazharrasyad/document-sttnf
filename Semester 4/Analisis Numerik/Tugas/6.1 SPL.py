# python3.7 -i file.py

def cetak(A) :
    for i in A :
        print(i)

def cetakAB(A, B) :
    for i in range(len(A)) :
        baris = ""
        for j in range(len(A)) :
            baris = baris + str(A[i][j]) + "\t"
        baris = baris + "|\t" + str(b[i])
        print(baris)

def elimGauss(A, B) : # Tanpa pivoting
    n = len(A)
    for j in range(0, n-1) : # Kolom j
        for i in range(n-1, j, -1) : # Baris i
            p = A[i][j] / A [j][j]
            # OBE baris tersebut dengan Ri - p*Rj -> Ri
            for k in range(0, n) : # Bagian rumus R0
                A[i][k] = A[i][k] - p*A[j][k]
            b[i] = b[i] - p*b[j]
            cetakAB(A,B)
            print()

def penyulihanMundur(A, B) :
    n = len(A)
    x = [0 for i in range(len(A))]        
    for i in range(n-1,-1,-1) :
        sigma = 0
        for j in range(i+1,n) :
            sigma += A[i][j] * x[j]
        x[i] = (b[i] - sigma) / A[i][i]
    print("Solusinya adalah", x)

a = [[2,3,-1],[4,4,-3],[-2,3,-1]]
b = [5,3,1]
print(len(a))
cetakAB(a, b)
print()
elimGauss(a, b)
penyulihanMundur(a, b)