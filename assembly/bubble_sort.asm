;;  Bubble Sort in assembly
;;
;;  explanation by:
;;  Kolby Heacock
;;  github.com/classmember
;;
;;  source:
;;  Malik Shahzaib Official
;;  youtube.com/watch?v=0H6i6_Cqlfw
;;

start:
data: dw 3, 8, 1, 9, 12, 5, 13, 2, 6, 7  ;; initialize data array
swap: db 0                               ;; initialize swap used to temporarily store a copy of the value when swapping
mov bx, 0                                ;; initialize bx to zero. The register bx represents the position in the data array

comparison:
mov ax, [data + bx]      ;; compare current value (ax) with next value (data+bx)
cmp ax, [data + bx + 2]  ;; compare "ax" register to value in memory
jb noSwap                ;; jb means jump if first number is less than second number

swapValues:
mov dx, [data + bx + 2]  ;; copy value to dx register
mov [data + bx + 2]      ;; copy value in current position in data array
mov [data + bx], ax      ;; copy value in ax to current position in data array
mov byte[swap], 1        ;; set swap to 1

noSwap:
add bx, 2                ;; add 2 to bx register
cmp bx, 18               ;; check if bx register is greater than 18
jnz comparison           ;; jz means jump if first number is greater than second number

end:
int ax, 0x4c00  ;; end the program (step one)
int 0x21        ;; end the program (step two)
