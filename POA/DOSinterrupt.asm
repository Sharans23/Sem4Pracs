data segment
    msg db "Enter a character:$"
data ends

code segment
    ASSUME CS:CODE DS:DATA
    START:
        mov ax,data
        mov ds,ax
        
        lea dx,msg
        
        mov ah,09h
        int 21h
        
        mov ah,01h
        int 21h
        
        mov dl,al
        mov ah,02h
        int 21h
        
        mov ah,4ch
        int 21h
code ends
end start

        