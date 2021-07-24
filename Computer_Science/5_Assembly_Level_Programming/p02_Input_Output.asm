.model small
.data
.code

    mov ah, 1h      ; This statement is for reading a character. It saves the character in register al
    int 21h         ; DOS interrupt. The system waits till the character gets input
    mov dl, al      ; Moves (copies) the character (stored in al) to dl


    mov ah, 2h      ; Prints the value in register dl
    int 21h         ; Initiates the display

end