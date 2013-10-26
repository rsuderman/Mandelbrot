
#ifndef IMAGE_H__
#define IMAGE_H__

#include<stdio.h>

FILE * initFile( const char * filename, int w, int h );
void savePixelValue( FILE *f, char r, char g, char b );
void closeFile(FILE *file);

#endif

