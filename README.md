#ft_printf
<br/>
42 school project (Paris, France).
<br/>
## Synopsis
<br/>
My own printf function.
<br/>
Available options :
<br/>
-> width     : An optional decimal digit string (with nonzero first digit) specifying a minimum field width.<br/>
-> precision : Give the minimun number of digits/character to appear.<br/>
<br/>
-> Flags :
<br/>
. '#' (Add a prefix to the converted value, depending on format type).<br/>
. '-' (The converted value is to be left adjusted on the field boundary).  
. ' ' (A sign must always be placed before a number produced by a signed conversion).<br/>
. '+' (A blank should be left before a positive number produced by a signed conversion).<br/>
. '0' (For all conversions except n, the converted value is padded on the left with zeros rather than blanks).<br/>
<br/>
-> Formats :<br/>
<br/>
. %% (A `%' is written, no argument is converted).<br/>
. %s (The char * argument is expected to be a pointer to an array of character type (pointer to a string)).<br/>
. %S (Treated as s with the l (ell) modifier, see below).<br/>
. %c (The int argument is converted to an unsigned char, and the resulting character is written).
. %C (Treated as c with the l (ell) modifier, see below).
. %i (The int argument is converted to signed decimal notation).
. %d (The int argument is converted to signed decimal notation).
. %D (Treated as d with the l (ell) modifier, see below).
. %x (The unsigned int argument is converted to unsigned hexadecimal).
. %X (Treated as x with the l (ell) modifier, see below).
. %p (The void * pointer argument is printed in hexadecimal).
. %o (The unsigned int argument is converted to unsigned octal).
. %O (Treated as o with the l (ell) modifier, see below).
. %u (The unsigned int argument is converted to unsigned decimal).
. %U (Treated as U with the l (ell) modifier, see below).

-> Length modifiers :

. hh (The following integer conversion corresponds to a signed char or unsigned char argument).
. ll (The following integer conversion corresponds to a long long int or unsigned long long int argument).
. h  (A following integer conversion corresponds to a short int or unsigned short int argument).
. l  (A following integer conversion corresponds to a long int or unsigned long int argument).
. j  (A following integer conversion corresponds to an intmax_t or uintmax_t argument).
. z  (A following integer conversion corresponds to a size_t or ssize_t argument).

## Installation

. type 'Make' in the root directory of the project.
. compile the created library with your program : 'cc libftprintf.a exemple.c'.
. run the created binary : './a.out'.