from math import sqrt

# 1. Memasukkan Data (Pilih Salah Satu)

# Contoh Soal
# x = [5, 10, 15, 20, 25, 30, 35, 40]
# y = [40, 30, 25, 40, 18, 20, 22, 15]

# Soal Nomor 1
# x = [1.0, 1.5, 2.0, 2.5, 3.0]
# y = [2.0, 3.2, 4.1, 4.9, 5.9]

# Soal Nomor 2
# x = [0.1, 0.4, 0.5, 0.7, 0.7, 0.9]
# y = [0.61, 0.92, 0.99, 1.52, 1.47, 2.03]

# Percobaan
x = [2, 2.4, 3, 4, 4.7, 5, 5.5]
y = [2.1, 3.0, 2.0, 5.3, 8.0, 11.0, 10.9]

# 2. Menghitung Data
n = len(x)
x2 = []
xy = []

for i in range(0, n) :
    x2.append(x[i] * x[i])
    xy.append(x[i] * y[i])

m = ((n * sum(xy)) - (sum(x) * sum(y))) / ((n * sum(x2)) - (sum(x)**2))
c = (sum(y) - (m * sum(x))) / (n)

# 3. Menampilkan Tabel Data
print("===== Tabel Data =====")
print()
print("i\tx\ty\tx2\txy")
print("~\t~\t~\t~\t~")
for i in range(0, n) :
    print(f"{i}\t{repr(x[i]):.6}\t{repr(y[i]):.6}\t{repr(x2[i]):.6}\t{repr(xy[i]):.6}".format(1 / 4))
print("~\t~\t~\t~\t~")
print(f"{n}\t{repr(sum(x)):.6}\t{repr(sum(y)):.6}\t{repr(sum(x2)):.6}\t{repr(sum(xy)):.6}")

print()
print(f"m = {repr(m):.6}")
print(f"c = {repr(c):.6}")
print()

# 4. Menghitung RMS
fx = []
fxy = 0

for i in range(0, n) :
    fx.append((m * x[i]) + c)

# 5. Menampilkan Tabel RMS
print("===== Tabel RMS =====")
print()
print("i\tfx\tfx - y\t(fx - y)2")
print("~\t~\t~\t~")
for i in range(0, n) :
    print(f"{i}\t{repr(fx[i]):.6}\t{repr(fx[i] - y[i]):.6}\t{repr((fx[i] - y[i])**2):.6}")
    fxy = (fxy) + (fx[i] - y[i])**2
print("~\t~\t~\t~")
print(f"\t\t\t{repr(fxy):.6}")

# 6. Menghitung RMS
print()
print(f"RMS = {repr(sqrt(fxy / n)):.6}")