# Source : https://stackoverflow.com/questions/14596367/using-python-to-convert-integer-to-binary
# Creator : Will.B

import os

def welcome():
    os.system('clear')
    print("Converter Program\n")
    print("1. Convert from integer to binary")
    print("2. Convert from binary to integer")
    print("3. Convert from binary basis -2 to integer")
    print("4. Exit\n")

    choice = input("Choose : ")
    if choice == '1' :
        I2B()
    elif choice == '2' :
        B2I()
    elif choice == '3' :
        BB2I()
    elif choice == '4' :
        exit
    else :
        welcome()

def I2B():
    integer_number = input("\nInput integer : ")
    integer_number = int(integer_number)

    result = ''  
    for x in range(8) :
        r = integer_number % 2
        integer_number = integer_number // 2
        result += str(r)
    result = result[::-1]

    print("\nBinary : " + str(result))
    input("\nPress ENTER to continue...")
    welcome()

def B2I():
    decnum = int(input("\nInput binary : "), 2)
    print("\nInteger : " + str(decnum))
    input("\nPress ENTER to continue...")
    welcome()

def BB2I():
    basis = input("\nInput binary basis -2 : ")
    basis = basis[::-1]

    binary = [0,0,0,0,0,0,0,0]    

    if basis[0] == '1' :
        binary[0] = 1

    i = 1
    for x in range(7) :
        if basis[i] == '1' :
            if i % 2 == 0 :
                binary[i] = 2 ** i
            else :
                binary[i] = -2 ** i
        i += 1

    total = 0
    i = 0
    for x in binary :
        total += binary[i]
        i += 1

    print("\nInteger : " + str(total))
    input("\nPress ENTER to continue...")
    welcome()

welcome()