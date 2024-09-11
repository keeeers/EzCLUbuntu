#include "pad.h"
#include <stdio.h>

cl_platform_id getPlatform_PD(){
    cl_uint NumsPlatform;
    cl_int err;
    err = clGetPlatformIDs(0, NULL, &NumsPlatform);
    if ( 0 == NumsPlatform ){
        printf("Found 0 Platforms!");
        return NULL;
    }
    cl_platform_id* Platfroms;
    err = clGetPlatformIDs(NumsPlatform, Platfroms, NULL);
    for (int i=0; i < NumsPlatform; i++){
        pritnf("Platform ID : %-5d ", i);
        char Name[100];
        clGetPlatformInfo(Platfroms[i], CL_PLATFORM_NAME, 100, Name, NULL);
        printf("|| Name : %s\n", Name);
    }
    int select = -1;
    for (; select<0||select>=NumsPlatform;){
        printf("Select Platform by input ID:");
        scanf("%d",&select);
        if (select<0||select>=NumsPlatform){
            printf("Invaild SelectID value!\n");
        }
    }
    return Platfroms[select];
}


cl_device_id getDevice_PD(cl_platform_id platform){
    cl_uint NumsDevice;
    cl_int err;
    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 0, NULL, &NumsDevice);
    if ( 0 == NumsDevice ){
        printf("Found 0 Devices");
        return NULL;
    }
    cl_device_id* devices = (cl_device_id*)malloc(sizeof(cl_device_id) * NumsDevice);
    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, NumsDevice, devices, NULL);
    for (int i=0; i < NumsDevice; i++){
        printf("Device ID : %-3d ", i);
        char Name[100];
        err = clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 100, Name, NULL);
        printf("|| Name : %s\n",Name);
    }
    int select = -1;
    for (; select<0 || select>=NumsDevice;){
        printf("select Device by input ID:");
        scnaf("%d", &select);
        if (select<0 || select>=NumsDevice){
            printf("Invaild SelectID value!\n");
        }
    }
    return devices[select];
}

