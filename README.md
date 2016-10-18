#ft_printf
  
42 school project (Paris, France)
  
## Synopsis
  
My own printf function.
  
Available options :
  
-> width&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: An optional decimal digit string (with nonzero first digit) specifying a minimum field width.  
-> precision&nbsp;: Give the minimun number of digits/character to appear.  

-> Flags :  

. '#' (Add a prefix to the converted value, depending on format type)  
. '-' (The converted value is to be left adjusted on the field boundary)  
. ' ' (A sign must always be placed before a number produced by a signed conversion)  
. '+' (A blank should be left before a positive number produced by a signed conversion)  
. '0' (For all conversions except n, the converted value is padded on the left with zeros rather than blanks)  
  
-> Formats :  
  
. %% (A `%' is written, no argument is converted)  
. %s (The char * argument is expected to be a pointer to an array of character type (pointer to a string))  
. %S (Treated as s with the l (ell) modifier, see below)  
. %c (The int argument is converted to an unsigned char, and the resulting character is written)  
. %C (Treated as c with the l (ell) modifier, see below)  
. %i (The int argument is converted to signed decimal notation)  
. %d (The int argument is converted to signed decimal notation)  
. %D (Treated as d with the l (ell) modifier, see below)  
. %x (The unsigned int argument is converted to unsigned hexadecimal)  
. %X (Treated as x with the l (ell) modifier, see below)  
. %p (The void * pointer argument is printed in hexadecimal)  
. %o (The unsigned int argument is converted to unsigned octal)  
. %O (Treated as o with the l (ell) modifier, see below)  
. %u (The unsigned int argument is converted to unsigned decimal)  
. %U (Treated as U with the l (ell) modifier, see below)  

-> Length modifiers :

. hh (The following integer conversion corresponds to a signed char or unsigned char argument)  
. ll (The following integer conversion corresponds to a long long int or unsigned long long int argument)  
. h&nbsp; (A following integer conversion corresponds to a short int or unsigned short int argument)  
. l&nbsp; (A following integer conversion corresponds to a long int or unsigned long int argument)  
. j&nbsp; (A following integer conversion corresponds to an intmax_t or uintmax_t argument)  
. z&nbsp; (A following integer conversion corresponds to a size_t or ssize_t argument)  
  
## Installation  
  
. type 'Make' in the root directory of the project  
. compile the created library with your program : 'cc libftprintf.a exemple.c'  
. run the created binary : './a.out'  
