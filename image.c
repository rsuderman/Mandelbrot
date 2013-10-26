
#include"image.h"

FILE * initFile( const char * filename, int w, int h )
{
    FILE *f = fopen(filename, "w");

    fputc( 0, f );
    fputc( 0, f );
    fputc( 2, f );
    fputc( 0, f ); fputc( 0, f );
    fputc( 0, f ); fputc( 0, f );
    fputc( 0, f );
    fputc( 0, f ); fputc( 0, f );
    fputc( 0, f ); fputc( 0, f );

    fputc( (w & 0x00FF), f );
    fputc( (w & 0xFF00) / 256, f );

    fputc( (h & 0x00FF), f );
    fputc( (h & 0xFF00) / 256, f );

    fputc(24, f);
    fputc(0,  f);

    return f;
}

void savePixelValue( FILE *f, char r, char g, char b )
{
    if( !f ) return;

    fputc( b, f); // Blue  Value
    fputc( g, f); // Green Value
    fputc( r, f); // Red   Value
}


void closeFile(FILE *file)
{
    fclose(file);
}

