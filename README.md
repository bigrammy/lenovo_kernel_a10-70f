# lenovo_kernel_a10-70f
4.4 Kitkat Kernel Source for the Lenovo Tab2 A10-70F
kernel build instruction
======

#Get a prebuilt cross compiler from AOSP website:

##Example:
$ ```git clone https://android.googlesource.com/platform/prebuilts/gcc/linux-x86/arm/arm-eabi-4.8```

Add required cross compiler to PATH:
$ ```export PATH=/YOUR_TOOLCHAIN_PATH/arm-eabi-4.8/bin:$PATH```

Then
$ ```export CROSS_COMPILE=arm-eabi-```

Then use the following commands to build the kernel:

$ ```cd ~/PATH-TO-YOUR/lenovo_kernel_a10-70f```


This will build the kernel
$ ```./mk huaqin8752_tb_b2d_kk bm_new k```

This will list the projects available
$ ```./mk listp```  (The Tab2 is "huaqin8752_tb_b2d_kk")

This will list the some option examples:
$ ```./mk --help```

This will setup the project:
$ ```./makeMtk huaqin8752_tb_b2d_kk```

## More Notes Correction As I come across them.

## This is arm64 build later if we can update the kernel that is.
#$ ```git clone https://android.googlesource.com/platform/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.8```#
## This is arm64 build later if we can update the kernel that is.
#$ ```export PATH=/YOUR_TOOLCHAIN_PATH/aarch64-linux-android-4.8/bin:$PATH```#
## This is arm64 build later if we can update the kernel that is.
#$ ```export CROSS_COMPILE=aarch64-linux-android-```#

