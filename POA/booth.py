def conversion(a): #returns a binary string of a number which has bits equal to count
    return a.zfill(count)

def add(x, y):
    max_len = max(len(x), len(y))
    x = x.zfill(max_len)
    y = y.zfill(max_len)
    carry = 0
    result = ''
    for i in range(max_len - 1, -1, -1):
        r = carry
        r += 1 if x[i] == '1' else 0
        r += 1 if y[i] == '1' else 0
        result = ('1' if r % 2 == 1 else '0') + result
        carry = 0 if r < 2 else 1
    return result

#2's complement
# The twoc function takes a binary string a as input and returns its two's complement. It does this by inverting all the bits and then adding 1 to the result using the add function.
def twoc(a):
    l = list(a)
    for i in range(len(l)):
        if l[i] == "1" :
            l[i] = "0"
        else: l[i] ="1"
    b = "0"*(len(l)-1) + "1" 
    return add("".join(l),b)

def right_shift(ac, q, q1):
    a = ac[0] + ac[:-1]
    b = ac[-1] + q[:-1]
    c = q[-1]
    return a, b, c

#Taking input and assigning values and converting to binary and assigning negative value
x = int(input("enter number one"))
y = int(input("enter number two")) #taking x and y decimal numbers as input for x * y
a = bin(x).replace("0b", "")
b = bin(y).replace("0b", "")
negative_a=0
negative_b=0
if (a[0]=="-"):
        a = a.replace("-","")
        negative_a =1
if (b[0]=="-"):
        b = b.replace("-","")
        negative_b =1

if (len(a)>len(b)):
    count = len(a)+1
else: count = len(b) + 1
count1 = count
firstP = conversion(a) #contains the positive representation of the multiplicand 
secondP = conversion(b) #contains the positive representation of the multiplier
firstN = twoc(firstP) #contains 2's complement of the multiplicand
secondN = twoc(secondP) #contains 2's complement of the multiplier

#BOOTH ALGO IMPLEMENTATION 
#just assigning values
if negative_a ==0:
    M = firstP #M is the multiplicand and M2 contains its 2's complement
    M2 = firstN
else:
    M = firstN
    M2 = firstP
if negative_b ==0:
    Q = secondP #Q is the multiplier
else:
    Q = secondN
AC = conversion("0")
Q1 = "0" # one bit for comparision
print("The table for the booth's algorithm is as follow:")
print("Count" +" "*count1 + "AC" +" "*count1 + "Q" +" "*count1 + "Q1" +" "*count1 + "Operation")
print(str(count) +" "*count1 + AC +" "*count1 + Q +" "*count1 + Q1 +" "*count1 + "initial")
print("\n")

#main logic
#until count is not equal to zero
while (count>0):
    compare = Q[-1] + Q1
    if compare[0]==compare[-1]:
        AC, Q, Q1 =right_shift(AC,Q,Q1)
        Op = "right shift" 
    elif compare =="10":
        AC = add(AC,M2)
        AC, Q, Q1 =right_shift(AC,Q,Q1)
        Op = "AC=AC-M and right shift"
    elif compare == "01":
        AC = add(AC,M)
        AC, Q, Q1 =right_shift(AC,Q,Q1)
        Op = "AC=AC+M and right shift"
    
    print(str(count) +" "*count1 + AC +" "*count1 + Q +" "*count1 + Q1 +" "*count1 + Op)
    print("\n")
    count = count-1
answer = AC+Q
if negative_a==negative_b:
    ans_d = str(int(answer,2))
else:
    ans_d = "-" + str(int(twoc(answer),2))

print("The product in binary is:" + answer)
print("Decimal conversion:" + ans_d)