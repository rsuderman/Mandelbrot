
#include "mandelbrot.h"
#include <math.h>

float mandelbrotValue( float real, float imaginary, int iterations )
{
    int i = 0;

    float xr = real;
    float xi = imaginary;

    for( i = 0; i < iterations; i++ )
    {
        float nxr =     xr * xr - xi * xi + real;
        float nxi = 2 * xr * xi           + imaginary;
        xr = nxr;
        xi = nxi;

        if( (xr * xr + xi * xi) > (2 << 16) )
            break;
    }

    float value;
    if( i < iterations )
    {
        float xn = xr * xr + xi * xi;
        xn       = ( i + 1 - log( log(xn) ) ) / iterations;
        value = xn;
    }
    else
    {
        value = 0.0;
    }

    return value;
}

