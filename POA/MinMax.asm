
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt
data segment
    arr db 3,6,2,7,4,1,8,5,9
    len dw $-arr
    min db ?
    max db ?
data ends

code segment
    ASSUME CS:CODE DS:DATA
    START:
        mov ax,data
        mov ds,ax  
        
        lea si,arr
        mov al,arr[si]
        mov min,al
        mov max,al
        
        mov cx,len
        repeat:
            
            mov al,arr[si]
            cmp min,al
            jl CheckMax
            mov min,al
            
            CheckMax:
            cmp max,al
            jg done
            mov max,al
                
            done:
            inc si
            loop repeat
            
        mov ah,4ch
        int 21h
code ends
end start
                    
                    
To check the output check it in variables
        