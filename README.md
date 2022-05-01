# binary_fantasy
\- print ANSI escape sequence fantasy like a teletype<br><br>

This project provides a new CLI fantasy style called binary fantasy.<br>
For ASCII enthusiasts.<br>
A binary fantasy is requested to be written:
- by arranging plain text binary codes of ASCII (e.g. 01000001 01000010 01000011)
- in one line (no LF by your keyboard)
- in 8-bit ASCII (00000000 ~ 01111111)
- ANSI escape sequence is OK.<br><br>

Main program is read_binary_fantasy.c<br>
(binary fantasy reader).<br>
Passing this program a binary fantasy,<br>
your terminal starts to type the characters 1char/0.3s (default typing speed) like a teletype.
- Input is command line argument.<br>
$ ./a.out 01000001 01000010 01000011<br>
ABC (print 1char/0.3s)
- To pass a text file, use the backquote command substitution.<br>
$ ./a.out \`cat binary_fantasy1.txt\`<br>
\*mekurumeku binary fantasy\*... (my sample binary fantasy; written in romanized Japanese)<br><br>

Plain text binary codes are converted into numeral chars,<br>
and typing is done by simply itterating printf("%c").<br>
Therefore control characters and ANSI escape sequences are all OK.<br>
Use control characters,<br>
and make your fantasy colorful, blinking, illustrative.<br><br>

Some techniques:<br>
- to erase a character, use "BS sp BS". This is the standard implementation:<br>
https://unix.stackexchange.com/questions/414159/behaviour-of-the-backspace-on-terminal
- to put delay (for BEL's effect, e.g.), use "NUL NUL NUL". Nostalgic.
- put ENQ, ACK, NAK etc; these do not have any effect,<br>
but enthusiasts will notice the subtle communication in the code,<br>
and grin happily<br><br>

This program is free software.<br>
Please look into LICENSE and the license notice in the source code file.
