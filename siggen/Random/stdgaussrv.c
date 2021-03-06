/*
 *                            COPYRIGHT
 *
 *  stdgaussrv.c
 *  Copyright (C) 2014 Exstrom Laboratories LLC
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  A copy of the GNU General Public License is available on the internet at:
 *  http://www.gnu.org/copyleft/gpl.html
 *
 *  or you can write to:
 *
 *  The Free Software Foundation, Inc.
 *  675 Mass Ave
 *  Cambridge, MA 02139, USA
 *
 *  Exstrom Laboratories LLC contact:
 *  stefan(AT)exstrom.com
 *
 *  Exstrom Laboratories LLC
 *  Longmont, CO 80503, USA
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h> //TcheL: As a patch

// Compile: gcc -lm -o stdgaussrv stdgaussrv.c

int main( int argc, char *argv[] )
{
  if( argc < 2 )
    {
      printf("usage: %s n seed\n", argv[0]);
      printf("  Generates n gaussian random numbers with mean=0, stdev=1\n");
      printf("  seed = optional random number seed\n");
      exit( -1 );
    }

  unsigned long i, n = strtoul(argv[1], NULL, 10);
  unsigned int seed;
  double z1, z2, r, d;

  seed = argc > 2 ? strtoul(argv[2], NULL, 10) : time(NULL);
  srand(seed);

  for(i=0; i<n; ++i){
    do{
      z1 = 2.0*rand()/RAND_MAX - 1.0;
      z2 = 2.0*rand()/RAND_MAX - 1.0;
      r = z1 * z1 + z2 * z2;} while(r >= 1.0);
    d = sqrt(-2.0 * log(r) / r);
    printf("%lf\n", d * z1);}
  return(0);
}
