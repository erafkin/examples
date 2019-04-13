/* 
 * section4.c - Section meeting, week 4: exercise with pointers and malloc.
 * A program to read two lines from input and store their concatenation.
 *
 * compile with
 *  mygcc section4.c readlinep.c -o section4a
 * 
 * David Kotz, April 2017, 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readlinep.h"

/* main program */
int main()
{
  char *line1 = readlinep();
  char *line2 = readlinep();

  // allocate space for the concatenation
  char *result = ...
  
  // copy line1 into result
  ...

  // copy line2 into result
  ...

  // print result
  puts(result);

  return 0;
}
