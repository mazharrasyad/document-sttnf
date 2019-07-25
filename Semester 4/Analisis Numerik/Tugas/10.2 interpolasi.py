def lagrange(nx, ax, ay) :    
    x = ax
    y = ay

    z = []
    xi = []
    ai = []
    bi = []
    zi = []
    ci = []
    ei = []

    # Derajat Polinom
    p = len(x)-1

    # Langkah 1
    print("\n=== Langkah 1 ===")
    print(f"x {x}")
    print(f"y {y}")
    print(f"Polinom Derajat {p}")
    print()

    # Langkah 2
    print("=== Langkah 2 ===")       
    print(f"p{p}(x) =")  
    for i in range(0, len(y)) :
        print(f"y{i} (", end = ' ')        
        for j in range(0, len(x)) :                                                               
            if i != j :   
                print(f"(x - x{j}) / ", end = '')                                              
                print(f"(x{i} - x{j}) ", end = '')                       
                if j == len(x)-1 :
                    print(")")     

    # Langkah 3
    print(")")
    print()    
    print("=== Langkah 3 ===")       
    print(f"p{p}(x) =")  
    for i in range(0, len(y)) :
        print(f"{y[i]} (", end = ' ')        
        for j in range(0, len(x)) :                                                               
            if i != j :   
                print(f"(x - {x[j]}) / ", end = '')                                              
                print(f"({x[i]} - {x[j]}) ", end = '')                       
                if j == len(x)-1 :
                    print(")")     

    # Langkah 4
    print(")")
    print()    
    print("=== Langkah 4 ===")
    print(f"p{p}(x) =")  
    hasil = 1    
    for i in range(0, len(y)) :
        print(f"{y[i]} (", end = ' ')        
        for j in range(0, len(x)) :                             
            try:                                             
                if i != j :   
                    print(f"(x - {x[j]}) / ", end = '')                                              
                    print(f"({round(x[i] - x[j], 4)}) ", end = '')                       
                    if j == len(x)-1 :
                        print(")")     

                    hasil = hasil * (x[i] - x[j])
                    ai.append(x[j])
                    bi.append(x[j])                    
                    xi.append(round(nx - x[j], 4))
            except IndexError :
                pass                
        try:            
            ci.append(round(hasil, 4))
            z.append(round(y[i] / hasil, 4))
            hasil = 1
        except ZeroDivisionError:
            pass            

    # Langkah 5    
    print(")")
    print()        
    print("=== Langkah 5 ===")
    print(f"p{p}(x) =")  
    for i in range(0, len(y)) :
        print(f"{y[i]} / ", end = '')                             
        print(f"{ci[i]} ( ", end = '')                     
        for j in range(0, len(x)) :
            if i != j :
                print(f"(x - {x[j]})", end = '')                                              
                if j == len(x)-1 :
                    print(" )")       

    # Langkah 6
    print(" )")
    print()
    print("=== Langkah 6 ===")
    print(f"p{p}({nx}) =")                            
    for i in range(0, len(z)) :    
        print(z[i], end = ' ')    
        for j in range(0, p) :              
            print(f"(x - {ai[0]})", end = ' ')          
            ai.pop(0)
            if j == p-1 :
                print()  

    # Langkah 7
    print()
    print("=== Langkah 7 ===")
    print(f"p{p}({nx}) =")                          
    for i in range(0, len(z)) :    
        print(z[i], end = ' ')    
        for j in range(0, p) :              
            print(f"({nx} - {bi[0]})", end = ' ')          
            bi.pop(0)
            if j == p-1 :
                print()         
    
    # Langkah 8
    print()
    print("=== Langkah 8 ===")
    print(f"p{p}({nx}) =")      
    for i in range(0, len(z)) :                
        
        print(z[i], end = ' ')

        for j in range(0, p) :            

            print(f"({xi[0]})", end = ' ')
            hasil = hasil * xi[0]                                                    
            xi.pop(0)

            if j == p-1 :
                ei.append(hasil)
                zi.append(z[i] * hasil)                                                
                hasil = 1   
                print()

    # Langkah 9
    print()
    print("=== Langkah 9 ===")
    print(f"p{p}({nx}) =")      
    for i in range(0, len(z)) :                        
        print(z[i], end = ' ')
        print(f"({round(ei[i], 4)})", end = ' ')
        for j in range(0, p) :                    
            if j == p-1 :
                print()

    # Langkah 10
    print()
    print("=== Langkah 10 ===")
    print(f"p{p}({nx}) =")      
    for i in range(0, len(z)) :                        
        print(f"{round(z[i] * ei[i], 4)}", end = ' ')
        for j in range(0, p) :                    
            if j == p-1 :
                print()

    # Langkah 11
    print()
    print("=== Langkah 11 ===")
    print(f"p{p}({nx}) = {round(sum(zi), 4)}")

def newton(nx, ax, ay) : 
    x = ax
    y = ay

    p = len(x)
    a = [[0] * p for i in range(0, p)]    
    b = []

    # Langkah 1
    print("\n=== Langkah 1 ===")
    print(f"x = {x}")
    print(f"y = {y}")
    print(f"Polinom Derajat {p-1}")

    # Langkah 2
    print()
    print("=== Langkah 2 ===")
    print("i\txi\tyi", end = '\t')    
    for i in range(0, p-1) :          
        print(f"ST-{i+1}", end = '\t')                    
                
    print()
    print("~\t~\t~", end = '\t')
    for i in range(0, p-1) :       
        print("~", end = '\t')
        
    print()      
    for i in range(0, p) :    
        print(f"{i}\t{x[i]}\t{y[i]}\t", end = '')                                                              
        for j in range(i, p-1) :  
            print("f[", end = '')                 
            l = j + 1
            for k in range(i-1, j+1) :                   
                print(f"x{l}", end = ' ')                                                                             
                l -= 1
            print("]", end = ' ')  
        print()   

    # Langkah 3
    print()
    print("=== Langkah 3 ===")
    print("i\txi\tyi", end = '\t')    
    for i in range(0, p-1) :   
        print(f"ST-{i+1}", end = '\t')                    
                
    print()
    print("~\t~\t~", end = '\t')
    for i in range(0, p-1) :        
        print("~", end = '\t')

    print()      
    for i in range(0, p) :            
        for j in range(0, p) :            
            try:                
                a[0][j] = y[j]        
            except IndexError:
                pass         

    for i in range(0, p) :            
        for j in range(0, p) :            
            try:
                try:                
                    a[i+1][j] = (a[i][j+1] - a[i][j]) / (x[j+1+i] - x[j])                    
                except IndexError:
                    pass          
            except ZeroDivisionError:
                pass
    
    for i in range(0, p) :            
        print(f"{i}\t{x[i]}\t", end = '')                                                              
        for j in range(0, p) :            
            try:
                try:                
                    print(round(a[j][i], 4), end = '\t')                        
                except IndexError:
                    pass  
            except ZeroDivisionError:
                pass
        print()    

    # Langkah 4    
    print("=== Langkah 4 ===")
    print(f"\np{p-1}(x) :")    
    for i in range(0, p) :
        print(round(a[i][0], 4), end = ' ')
        c = 1
        k = 0
        for j in range(p-i, p) :
            print(f"(x - {x[k]})", end = ' ')                        
            c = c * (round(nx - x[k], 4))             
            k += 1
        print()

    # Langkah 5
    print()
    print("=== Langkah 5 ===")
    print(f"p{p-1}({nx}) :")    
    for i in range(0, p) :
        print(round(a[i][0], 4), end = ' ')
        c = 1
        k = 0
        for j in range(p-i, p) :
            print(f"({round(nx - x[k], 4)})", end = ' ')                        
            c = c * (round(nx - x[k], 4))             
            k += 1
        print()
        b.append(a[i][0] * c)

    # Langkah 6
    print()
    print("=== Langkah 6 ===")
    print(f"p{p-1}({nx}) :")    
    for i in range(0, p) :
        c = 1
        k = 0
        for j in range(p-i, p) :
            c = c * (round(nx - x[k], 4))             
            k += 1
        print(round(a[i][0] * c, 4))

    # Langkah 7
    print()
    print("=== Langkah 7 ===")
    print(f"p{p-1}({nx}) : {sum(b)}")

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