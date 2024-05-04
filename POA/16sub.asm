
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

mov ax,[1000h]
mov bx,[1002h]
mov cl,00h
                  
sbb ax,bx

mov [1004h],ax
jnc jump
inc cl

jump:
mov [1006h],cl
hlt                  

