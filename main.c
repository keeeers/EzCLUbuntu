#include <stdio.h>
#include "pad.h"

int main(){
    pad.platform = getPlatform_PD();
    pad.device = getDevice_PD(pad.platform);
    printf("Hello world!\n");
    return 0;
}