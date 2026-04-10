Custom Esoteric Interpreter
A C++ stack-based esoteric programming language interpreter. It reads single-character instructions from standard input and supports BigInt arithmetic using custom doubly-linked lists.

🚀 Quick Start
Bash
g++ main.cpp -o interpreter
./interpreter
📜 Instruction Set Cheat Sheet
Note: Any unrecognized character (like numbers 0-9) is automatically prepended to the list at the top of the stack.

Stack Operations
' : Push a new, empty list

, : Pop top element

: : Duplicate top element

; : Swap top two elements

@ : Pop N, push a copy of the N-th element

# : Concatenate top list to the second list, then pop top

I/O
. : Read one character from std::cin and prepend to top

> : Print the first character of top to std::cout, then pop

& : Print entire stack (debug view)

Math & Logic (Handles BigInt)
+ : Add top two lists

< : Pop two; push 1 if 2nd element < top, else 0

= : Pop two; push 1 if they are equal, else 0

! : Logical NOT (pushes 1 if top is 0 or empty, else 0)

- : Toggle negative sign

^ : Absolute value (removes negative sign)

Conversions & Control Flow
[ : Get ASCII int of the first char, push as new number

] : Convert top number to ASCII char, push it

$ : Extract first char of top, push as a new list

~ : Push current instruction index (loop counter)

? : Conditional Jump (Pops target index, then condition. Jumps if condition != 0)
