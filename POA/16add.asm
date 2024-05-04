
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

MOV AX,[1000h]
MOV BX,[1002h]
MOV CL,00h

ADD AX,BX

MOV [1004h],AX

JNC jump
INC CL

jump:
MOV [1006h],CL
HLT




