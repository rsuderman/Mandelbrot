
#include "image.h"
#include "mandelbrot.h"

int main()
{
    int imageW = 1024;
    int imageH = 1024;

    FILE *f = initFile( "outputFile.tga", imageW, imageH);
    int i, j;
    
    float spaceHeight  =  2.4;
    float spaceWidth   =  2.4;
    float spaceCenterR = -0.6;
    float spaceCenterI =  0.0;

    for( i = 0; i < imageH; i++ )
    {
        for( j = 0; j < imageW; j++ )
        {
            float x = ((float) j) / imageW;
            float y = ((float) i) / imageH;

            x = (x - 0.5) * spaceWidth  + spaceCenterR;
            y = (y - 0.5) * spaceHeight + spaceCenterI;

            float v = mandelbrotValue( x, y, 30 );
            v = v * 255;
            savePixelValue( f, v, v, v );
        }
    }

    closeFile(f);
}

