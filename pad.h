#ifndef _PAD_H_
#define _PAD_H_

#include <CL/cl.h>

struct padbag{
    cl_platform_id platform;
    cl_device_id device;
};

cl_platform_id getPlatform_PD();
cl_device_id getDevice_PD();

#endif