
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt
DATA segment 
    string1 DB 99H,12H,56H,45H,36H
DATA ends

CODE segment
    ASSUME CS:CODE DS:DATA
    START:
        mov ax,data
        mov ds,ax
        mov ch,04h
        
        UP2:
            mov cl,04h
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
                jnz UP2
CODE ENDS
END START
