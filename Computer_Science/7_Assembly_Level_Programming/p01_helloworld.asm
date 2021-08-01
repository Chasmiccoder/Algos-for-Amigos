; Comment Line
; Install an 8086 Assembler and run the code
; Resources used: https://www.youtube.com/watch?v=zEuvNYe7WG0

.model tiny
.code
org 100h        ; Code starts with an offset of 100h

main proc near
  
    mov ah, 09h             ; Moving the value of 09h to the register ah
    mov dx, offset message  ; Moving the message to be displayed to register dx. Must end with a $ sign
    int 21h                 ; DOS Interrupt. Initiates the process. Done before almost every command
                
    mov ah, 4ch             ; Moves the value of 4ch to register ah. Function to terminate
    mov al, 00
    int 21h                 ; Again, using the interrupt to intiate the above 2 lines
        
endp                        ; Ends the main
message db "Hello World! $"         ; db data type. Variable name is message. String must be within "" and must end with $

end main                    ; Ends the program