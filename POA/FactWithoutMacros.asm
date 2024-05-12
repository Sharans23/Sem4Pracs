
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt
data segment 
    a db 5
    fact db ?
data ends

code segment
    assume cs:code ds:data
    
    start:
        mov ax,data
        mov ds,ax
        mov ah,00h
        mov al,a
        
        LI:
            dec a
            mul a
            mov cl,a
            cmp cl,01
            jnz LI
            
        mov fact,al
        
code ends
end start

                    
                    
        
