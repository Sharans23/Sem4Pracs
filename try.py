def dec_to_bin(n):
    return bin(n).replace('0b','')

def right_shift(C,AC,Q):
    C=AC[0]
    AC=AC[1:]+Q[0]
    Q=Q[1:]+'_'
    return C,AC,Q

def operation(C,AC,M):
    temp=C+AC
    temp=bin(int(temp,2)+int(M,2)).replace('0b','')
    if len(temp)>len(M):
        temp=temp[1:]
    return temp[0],temp[1:]

def restoring():
    Q=dec_to_bin(int(input("enter first number Q")))
    M=dec_to_bin(int(input("enter second number M")))

    AC='0'*(len(Q)+1)
    C='0'
    Q='0'*(len(M)-len(Q))+Q
    M='0'+M

    M_neg=bin(int(''.join(['1' if bit =='0' else '0' for bit in M]),2)+1)[2:]

    print("inital C vale :",C)
    print("inital AC vale :",AC)
    print("inital Q vale :",Q)
    print("inital M vale :",M)
    print("two's comp of M",M_neg)
    print("\n\tC\tAC\tQ\tOperation")
    print("\t"+C+"\t"+AC+"\t"+Q+"\tinitial")

    for _ in range(len(Q)):
        C,AC,Q=right_shift(C,AC,Q)
        print("\t"+C+"\t"+AC+"\t"+Q+"\t left shift")
        C,AC=operation(C,AC,M_neg)
        print("\t"+C+"\t"+AC+"\t"+Q+"\t AC-M")

        if C=='1':
            Q=Q[:-1]+'0'
            C,AC=operation(C,AC,M)
            print("\t"+C+"\t"+AC+"\t"+Q+"\t AC+M")

        else:
            Q=Q[:-1]+'1'

    print("\nfinal value")
    print("\t" + C + "\t" + AC + "\t" + Q)
    print("Remainder=C,AC",int(C+AC,2))
    print("Quotient:",int(Q,2))

restoring()                            