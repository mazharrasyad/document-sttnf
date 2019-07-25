from interpolasi import lagrange, newton

print("===== Interpolasi =====\n")

derajat = int(input("Masukkan Derajat : "))

x = []
y = []

print()
for i in range(0, derajat+1) :
    x.append(float(input(f"Masukkan Nilai X-{i} : ")))
    y.append(float(input(f"Masukkan Nilai Y-{i} : ")))
    print()

nilai = float(input("Masukkan Nilai : "))

print("\n===== Metode : =====")
print("1. Lagrange")
print("2. Newton")
pilihan = int(input("\nMasukkan Pilihan : "))

if pilihan == 1 :    
    lagrange(nilai, x, y)
elif pilihan == 2 :
    newton(nilai, x, y)
else :
    print("\n===== Pilihan Tidak Ada =====")

# Contoh Lagrange
# x = [0, 0.4, 0.8, 1.2]
# y = [1.0000, 0.9211, 0.6967, 0.3624]
# Nilai = 0.5

# Contoh Newton
# x = [8, 9, 9.5, 11]
# y = [2.0794, 2.1972, 2.2513, 2.3979]
# Nilai = 9.2