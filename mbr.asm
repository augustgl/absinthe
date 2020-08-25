; hit them with that nasm -f bin mbr.asm -o mbr.bin
; then open in HxD and export as C

BITS    16
ORG     0x7c00
jmp start

start:
        call clear_screen
        mov ax,cs
        mov ds,ax
        mov si,msg

        call print

print:
        push ax
        cld
next:
        mov al,[si]
        cmp al,0
        je done
        call printchar
        inc si
        jmp next
done:
        jmp $

printchar:
        mov ah,0x0e
        int 0x10
        ret

clear_screen:
        mov ah, 0x07
        mov al, 0x00
        mov bh, 0x0C ; color
        mov cx, 0x0000 
        mov dx, 0x184f
        int 0x10
        ret

msg:            db        "absinthe",13,10,"lmao", 0
times 510 - ($-$$) db 0
dw        0xaa55
