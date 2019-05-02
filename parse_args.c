/* 
 * parse_args: demonstrate how to validate and unpack command-line arguments
 * 
 * video about this example: https://dartmouth.techsmithrelay.com/FffD
 *
 * usage: parse_args inputFilename outputFilename nlines
 *   like head -nlines inputFilename > outputFilename
 * 
 * David Kotz 2019
 */

#include <stdio.h>
#include <stdlib.h>

void
parse_args(const int argc, char *argv[], 
           char **inputFilename, char **outputFilename, int *nlines);

int
main(const int argc, char *argv[])
{
  char *inputFilename  = NULL;
  char *outputFilename = NULL;
  int nlines           = 0;

  parse_args(argc, argv, &inputFilename, &outputFilename, &nlines);

  // interesting part of the program
  // copy_file(inputFilename, outputFilename, nlines);
}

void
parse_args(const int argc, char *argv[], 
           char **inputFilenamep, char **outputFilenamep, int *nlinesp)
{
  if (argc != 4) {
    fprintf(stderr, "usage: parse_args inputFilename outputFilename nlines\n");
    exit(1);
  }
  
  *inputFilenamep  = argv[1];
  *outputFilenamep = argv[2];

  char *nlinesString = argv[3];

  FILE *fp;
  if ( (fp = fopen(*inputFilenamep, "r")) == NULL) {
    fprintf(stderr, "parse_args: '%s' not readable\n", *inputFilenamep);
    exit(2);
  }
  fclose(fp);

  if ( (fp = fopen(*outputFilenamep, "w")) == NULL) {
    fprintf(stderr, "parse_args: '%s' not writeable\n", *outputFilenamep);
    exit(3);
  }
  fclose(fp);

  *nlinesp = 0;               // the number of lines
  char excess;                // any excess chars after the number
    
  // if the argument is valid, sscanf should extract exactly one thing.
  if (sscanf(nlinesString, "%d%c", nlinesp, &excess) != 1) {
    fprintf(stderr, "parse_args: '%s' invalid integer\n", nlinesString);
    exit(4);
  }

  if (*nlinesp < 0) {
    fprintf(stderr, "parse_args: '%d' must be >= 0\n", *nlinesp);
    exit(5);
  }

}
