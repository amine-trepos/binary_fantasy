# binary_fantasy
print ANSI escape sequence fantasy like a teletype

This project provides a new CLI fantasy style called binary fantasy.
For ASCII enthusiasts.
A binary fantasy is requested to be written:
- by arranging plain text binary codes of ASCII (e.g. 01000001 01000010 01000011)
- in one line (no LF by your keyboard)
- in 8-bit ASCII (00000000 ~ 01111111)
- ANSI escape sequence is OK.

Main program is read_binary_fantasy.c
(binary fantasy reader).
Passing this program a binary fantasy,
your terminal starts to type the characters 1char/0.3s (default typing speed) like a teletype.
- Input is command line argument.
$ ./a.out 01000001 01000010 01000011
ABC (print 1char/0.3s)
- To pass a text file, use the backquote command substitution.
$ ./a.out `cat binary_fantasy1.txt`
\*mekurumeku binary fantasy\*... (my sample binary fantasy; written in romanized Japanese)

Plain text binary codes are converted into numeral chars,
and typing is done by simply itterating printf("%c").
Therefore control characters and ANSI escape sequences are all OK.
Use control characters,
and make your fantasy colorful, blinking, illustrative.

Some techniques:
- to erase a character, use "BS sp BS". This is the standard implementation:
https://unix.stackexchange.com/questions/414159/behaviour-of-the-backspace-on-terminal
- to put delay (for BEL's effect, e.g.), use "NUL NUL NUL". Nostalgic! XD
- put ENQ, ACK, NAK etc; these do not have any effect,
but enthusiasts will notice the subtle communication in the code,
and grin happily

This program is free software.
Please look into LICENSE and the license notice in the source code file.
