def conversion(a):
    q=''
    current_n=len(a)
    temp=count - current_n
    if(current_n!=count):
        q='0'*temp+a
    return q 

def add(x,y):
    max_len=max(len(x),len(y))
    x=x.zfill(max_len)
    y=y.zfill(max_len)
    carry=0
    result=''
    for i in range(max_len-1,-1,-1):
        r=carry
        r+=1 if x[i]=='1' else 0
        r+=1 if y[i]=='1' else 0   
        result=('1' if r%2==1 else '0')+result
        carry=0 if r<2 else 1
    return result

def twoc(a):
    l=list(a)
    for i in range(len(l)):
        if l[i]=='1':
            l[i]='0'
        else: l[i]='1'
    b='0'*(len(l)-1)+'1'
    return add("".join(l),b)

def right_shift(ac,q,q1):
    a=ac[0]
    for i in range(1,len(ac)):
        a+=ac[i-1]
    b=ac[-1]        
    for j in range(1,len(q)):
        b+=q[j-1]
    c=q[-1]      
    return a ,b,c  

x = int(input("enter number one"))
y = int(input("enter number two"))
a=bin(x).replace('0b',"")
b=bin(y).replace('0b',"")
negative_a=0
negative_b=0
if(a[0]=='-'):
    a=a.replace("-","")
    negative_a=1
if(b[0]=='-'):
    b=b.replace("-","")
    negative_b=1

if(len(a)>len(b)):
    count=len(a)+1
else: count=len(b)+1

count1=count
firstP=conversion(a)
secondP=conversion(b)
firstN=twoc(firstP)
secondN=twoc(secondP)

if negative_a==0:
    M=firstP
    M2=firstN
else:
    M=firstN
    M2=firstP
if negative_b==0:
    Q=secondP
else:
    Q=secondN
AC=conversion("0")
Q1='0'                
print("table")
print("Count"+" "*count1+"AC"+" "*count1+"Q"+" "*count1 +"Q1"+" "*count1 + "Operation")
print(str(count)+" "*count1 +AC+" "*count1 + Q +" "*count1+Q1+" "*count1+"initial")
print("\n")

while(count>0):
    compare=Q[-1]+Q1
    if compare[0]==compare[-1]:
        AC,Q,Q1=right_shift(AC,Q,Q1)
        op="right shift"
    elif compare =='10':
        AC = add(AC,M2)
        AC,Q,Q1=right_shift(AC,Q,Q1)
        op="AC+=M and right shift"
    elif compare =='01':
        AC=add(AC,M)
        AC,Q,Q1=right_shift(AC,Q,Q1)
        op="AC+=M and right shift"

    print(str(count)+" "*count1 + AC + " "*count1 + op)
    print("\n")
    count=count-1 
answer=AC+Q
if negative_a==negative_b:
    ans_d=str(int(answer,2))
else:
    asw_d="-"+str(int(twoc(answer),2))                           
print("Product"+answer)
print("decimal conversion"+ans_d)  
