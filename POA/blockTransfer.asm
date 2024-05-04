
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt
data segment
    string1 db 40h, 47h, 92h
data ends        

extra segment
    string2 db ?                    
extra ends

code segment
    START:
        mov ax,data
        mov ds,ax
        mov ax,extra
        mov es,ax
        
        lea si,string1
        lea di,string2
        
        mov cx,03h
        
        jump:
            mov ah,ds:[si]
            mov es:[di],ah
            inc si
            inc di
            dec cx
            jnz jump
            int 3
code ends
end start