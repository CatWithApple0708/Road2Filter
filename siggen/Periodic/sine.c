/*
 *                            COPYRIGHT
 *
 *  sine.c
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
#include <math.h>

// Compile: gcc -lm -o sine sine.c

int main( int argc, char *argv[] )
{
  if( argc != 6 )
  {
    printf("usage: %s s f a p n\n", argv[0]);
    printf("  Produces n samples of a*sin(2*pi*f*t + p)\n");
    printf("  s = sampling frequency\n");
    printf("  f = frequency\n");
    printf("  a = amplitude\n");
    printf("  p = phase\n");
    printf("  n = number of samples to generate\n");
    exit( -1 );
  }

  double s = strtod(argv[1], NULL);
  double f = strtod(argv[2], NULL);
  double a = strtod(argv[3], NULL);
  double p = strtod(argv[4], NULL);
  unsigned long int i, n = strtoul(argv[5], NULL, 10);
  double t = 2.0*M_PI*f/s;
  double x = a*cos(p);
  double y = a*sin(p);
  double cs = cos(t);
  double sn = sin(t);

  printf("%lf\n", y);
  for(i=1; i<n; ++i){
    t = x;
    x = cs*x - sn*y;  // x = samples of a*cos(2*pi*f*t + p)
    y = sn*t + cs*y;  // y = samples of a*sin(2*pi*f*t + p)
    printf("%lf\n", y);}

  return( 0 );
}
