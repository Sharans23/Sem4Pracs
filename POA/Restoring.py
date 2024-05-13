# decimal to binary
def deci_to_bin(n):
    return bin(n).replace("0b", "")

# Shift left operation
def shift_left(C, AC, Q):
    C = AC[0]
    AC = AC[1:] + Q[0]
    Q = Q[1:] + '_'
    return C, AC, Q

# add AC and M and updates carry
def operation(C, AC, M):
    temp = C + AC
    temp = bin(int(temp, 2) + int(M, 2)).replace('0b','')
    if len(temp) > len(M):
        temp = temp[1:]
    return temp[0], temp[1:]

# Main function
def restoring_division():
    
    Q = deci_to_bin(int(input("Enter the dividend (Q) : ")))
    M = deci_to_bin(int(input("Enter the divisor (M) : ")))


    AC = '0' * (len(Q) + 1)
    C = '0'
    Q = '0' * (len(M) - len(Q)) + Q
    M = '0' + M
    M_neg = bin(int(''.join(['1' if bit == '0' else '0' for bit in M]), 2) + 1).replace('0b','')
    
    print("\nInitial C value is :", C)
    print("Initial AC value is :", AC)
    print("Initial Q value is :", Q)
    print("Value of M is :", M)
    print("Two's complement of M :", M_neg)
    print("\n\tC\tAC\tQ\tOperation done")
    print("\t" + C + "\t" + AC + "\t" + Q + "\tInitial values")

    for _ in range(len(Q)):
        C, AC, Q = shift_left(C, AC, Q)
        print("\t" + C + "\t" + AC + "\t" + Q + "\tAfter shift left operation")
        print('\n')
        C, AC = operation(C, AC, M_neg)
        print("\t" + C + "\t" + AC + "\t" + Q + "\tAC_equals_AC_minus_M operation")
        print('\n')

        if C == '1':
            Q = Q[:-1] + '0'
            C, AC = operation(C, AC, M)
            print("\t" + C + "\t" + AC + "\t" + Q + "\tAC_equals_AC_plus_M operation")
        else:
            Q = Q[:-1] + '1'

    print('\nFinal values')
    print("\t" + C + "\t" + AC + "\t" + Q)
    print("\nRemainder=(C,AC) :", int(C + AC, 2))
    print("Quotient=(Q) :", int(Q, 2))

restoring_division()