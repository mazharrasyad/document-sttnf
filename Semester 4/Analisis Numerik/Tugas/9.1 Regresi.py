from math import sqrt

# 1. Memasukkan Data 

# Soal Nomor 2 di Halaman 16
x = [0.1, 0.4, 0.5, 0.7, 0.7, 0.9]
y = [0.61, 0.92, 0.99, 1.52, 1.47, 2.03]
# x = [2, 2.4, 3, 4, 4.7, 5, 5.5]
# y = [2.1, 3.0, 2.0, 5.3, 8.0, 11.0, 10.9]

# 2. Menghitung Data
n = len(x)
x2 = []
xy = []
fx = []
fxy = 0

for i in range(0, n) :
    x2.append(x[i] * x[i])
    xy.append(x[i] * y[i])

m = ((n * sum(xy)) - (sum(x) * sum(y))) / ((n * sum(x2)) - (sum(x)**2))
c = (sum(y) - (m * sum(x))) / (n)

for i in range(0, n) :
    fx.append((m * x[i]) + c)

# 3. Menampilkan Tabel Data
print("===== Tabel Data =====")
print()
print("i\tx\ty\tx2\txy\tfx\tfx - y\t(fx - y)2")
print("~\t~\t~\t~\t~\t~\t~\t~")
for i in range(0, n) :
    print(f"{i}\t{round(x[i], 4)}\t{round(y[i], 4)}\t{round(x2[i], 4)}\t{round(xy[i], 4)}\t{round(fx[i], 4)}\t{round(fx[i] - y[i], 4)}\t{round((fx[i] - y[i])**2, 4)}")
    fxy = (fxy) + (fx[i] - y[i])**2
print("~\t~\t~\t~\t~\t~\t~\t~")
print(f"{n}\t{round(sum(x), 4)}\t{round(sum(y), 4)}\t{round(sum(x2), 4)}\t{round(sum(xy), 4)}\t\t\t{round(fxy, 4)}")

print()
print(f"m = {round(m, 4)}")
print(f"c = {round(c, 4)}")
print(f"RMS = {round(sqrt(fxy / n), 4)}")