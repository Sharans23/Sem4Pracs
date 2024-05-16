facto macro f
    up:
    mul f
    dec f
    jnz up
endm

data segment
    a db 5
    fact db ?
data ends

code segment    
    Start:
    mov ax,data
    mov ds,ax
    mov cl,a
    
    mov ax,0001h
    facto a
    mov fact,al
code ends
end start