#ifndef _CL_CONTEXT_H_
#define _CL_CONTEXT_H_

#include <CL/cl.h>
#include "pad.h"

cl_int err;
cl_context context;
cl_command_queue queue;
cl_command_queue_properties queue_properties;
cl_program program;
cl_kernel kernel;

int InitContext(){
    context = clCreateContext(
        NULL,1,&pad.device,
        NULL,NULL,&err);
	queue_properties = 0;
    queue = clCreateCommandQueueWithProperties(
        context,pad.device,
        &queue_properties,&err);
    
}

#endif