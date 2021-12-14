#include "funcs.h"

int main()
{
        invert("inImage.pgm");
        invertHalf("inImage.pgm");
        whiteBox("inImage.pgm");
        whiteBoxOutline("inImage.pgm");
        scale("inImage.pgm");
        pixelate("inImage.pgm");
	return 0;
}


