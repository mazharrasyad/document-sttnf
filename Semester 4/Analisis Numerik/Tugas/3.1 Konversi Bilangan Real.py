# Konversi Bilangan Real

def I2B(integer):
    integer_number = integer
    integer_number = int(integer_number)

    result = ''  
    for x in range(4) :
        r = integer_number % 2
        integer_number = integer_number // 2
        result += str(r)
    result = result[::-1]

    return result

pangkat = 7
dua = 2 ** pangkat    

while -8 <= pangkat :                
    print("2 ^ " + str(pangkat) + " = " + str(2 ** pangkat))
    pangkat -= 1

print()

tanda = input("Masukkan Tanda (+ / -) : ")
nilai = float(input("Masukkan Nilai (Positif) : "))
nilai1 = nilai
print()

import math
z = math.modf(nilai1)
z = z[1]
z = str(z).replace('.0','')
y = nilai1
x = len(str(y).replace('.','')) - len(z)

biner = []      

while(nilai != 0) :    
    cek = 0
    pangkat = 7
    dua = 2 ** pangkat    

    while nilai <= dua :                  
        dua = 2 ** pangkat        
        pangkat -= 1         

        hasil = nilai - dua        
        
        if dua == hasil :            
            print(str(nilai) + " = " + str(nilai) + " + 0")
            pangkat += 1
            cek = 1        

        if pangkat < -9 :
            cek = 2
        
    biner.append(pangkat + 1)

    if cek == 1 or cek == 2:
        break          
    
    print(str(nilai) + " = " + str(dua) + " + " + str(hasil))  
    nilai = hasil    

if cek == 2 :
    biner.pop(len(biner) - 1)

print()
print("2 Pangkat " + str(biner))

i = biner[0]

if 0 <= i :
    i = biner[0]
    negatif = 0
else :
    i = 0
    negatif = 1

mantisa = []
mantisa1 = []

while biner[len(biner) - 1] <= i :            
    if i in biner :        
        mantisa.append(1)
    else :
        mantisa.append(0)

    if i == 0 :
        mantisa.append(".")

    mantisa1.append(i)
    i -= 1    

pangkat = mantisa.index(".")
mantisa.pop(pangkat)

print()
print(mantisa1)
print(mantisa)
mantisa.insert(pangkat, ".")

print()
print(str(nilai1) + " = " + str("".join(str(x) for x in mantisa)))
mantisa.pop(pangkat)
if negatif == 0 :
    print(str(nilai1) + " = 0." + str("".join(str(x) for x in mantisa)) + " x 2 Pangkat " + str(pangkat))

if negatif == 1 :
    pangkat = 0
    for i in mantisa :
        if mantisa[0] == 0 :            
            pangkat += 1
            mantisa.pop(0)  
    pangkat -= 1

if negatif == 1 :
    print(str(nilai1) + " = 0." + str("".join(str(x) for x in mantisa)) + " x 2 Pangkat -" + str(pangkat))

print("\nFloating Poin : ")
print("Tanda : " + tanda)
if negatif == 1 :
    print("Pangkat : " + I2B(-pangkat))
else :
    print("Pangkat : " + I2B(pangkat))
print("Mantisa : " + str("".join(str(x) for x in mantisa)))
if cek == 2 :
    print("Sisa : " + str(hasil))

# 21.546875
# 0.1015625

# 27.078125
# -82.6875
# 0.234375
# -0.40625
# 5.2019