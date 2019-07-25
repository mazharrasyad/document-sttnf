import math

# 1. Memasukkan Data

# Soal Nomor 2 di Halaman 16
x = [0.1, 0.4, 0.5, 0.7, 0.7, 0.9]
y = [0.61, 0.92, 0.99, 1.52, 1.47, 2.03]
# x = [2, 2.4, 3, 4, 4.7, 5, 5.5]
# y = [2.1, 3.0, 2.0, 5.3, 8.0, 11.0, 10.9]

# 2. Menghitung Data

n = len(x)
lnx = []
lny = []
lnx2 = []
lnxy = []
fx = []
fxy = 0

for i in range(0, n) :
    lnx.append(math.log(x[i]))    
    lny.append(math.log(y[i]))

for i in range(0, n) :
    lnx2.append(lnx[i] ** 2)    
    lnxy.append(lnx[i] * lny[i])

# 3. Menghitung Rumus

m = ((n * sum(lnxy)) - (sum(lnx) * sum(lny))) / ((n * sum(lnx2)) - (sum(lnx)**2))
c = (sum(lny) - (m * sum(lnx))) / (n)
a = math.exp(c)

for i in range(0, n) :
    fx.append(a * (x[i] ** m))

# 4. Menampilkan Tabel Data

print("===== Tabel Data Pangkat Sederhana =====")
print()
print("i\tx\ty\tlnx\tlny\tlnx2\tlnxy\tfx\tfx - y\t(fx - y)2")
print("~\t~\t~\t~\t~\t~\t~\t~\t~\t~")
for i in range(0, n) :
    print(f"{i}\t{round(x[i], 4)}\t{round(y[i], 4)}\t{round(lnx[i], 4)}\t{round(lny[i], 4)}\t{round(lnx2[i], 4)}\t{round(lnxy[i], 4)}\t{round(fx[i], 4)}\t{round(fx[i] - y[i], 4)}\t{round((fx[i] - y[i])**2, 4)}")
    fxy = (fxy) + (fx[i] - y[i])**2
print("~\t~\t~\t~\t~\t~\t~\t~\t~\t~")
print(f"{n}\t{round(sum(x), 4)}\t{round(sum(y), 4)}\t{round(sum(lnx), 4)}\t{round(sum(lny), 4)}\t{round(sum(lnx2), 4)}\t{round(sum(lnxy), 4)}\t\t\t{round(fxy, 4)}")

# 5. Menghitung RMS

print()
print(f"m = {round(m, 4)}")
print(f"c = {round(c, 4)}")
print(f"a = {round(a, 4)}")
print(f"RMS = {round(math.sqrt(fxy / n), 4)}")