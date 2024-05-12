sort MACRO
    mov ch,04h
    
    UP2:
        mov cl,04
        lea si,string1
        
    UP1:
        mov al,[si]
        mov bl,[si+1]
        cmp al,bl
        JC down
        mov dl,[si+1]
        xchg [si],dl
        mov [si+1],dl
        
    down:
        inc si
        dec cl
        jnz UP1
        dec ch
        JNZ UP2
endm

data segment
    string1 DB 99h,33h,24h,64h,85h
data ends

code segment
    assume CS:CODE DS:DATA
    START:
        mov ax,data
        mov ds,ax
        sort
code ends
end start