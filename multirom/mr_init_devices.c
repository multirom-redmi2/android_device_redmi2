#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    // Framebuffer
    "/sys/class/graphics/fb0", 
    "/sys/devices/virtual/graphics/fb0",

    "/sys/block/mmcblk0",
    "/sys/devices/soc.0/7824900.sdhci",
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/*",
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/mmc0:0001",
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0",
    // boot and data
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p22",
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p30",

    // system and cache
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p23",
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p24",

    "/sys/bus/mmc",
    "/sys/bus/mmc/drivers/mmcblk",
    "/sys/bus/sdio/drivers/bcmsdh_sdmmc",
    "/sys/module/mmc_core",
    "/sys/module/mmcblk",
    "sys/module/sdhci",
    "sys/module/sdhci/*",
    "/sys/module/sdhci_msm",
    "/sys/module/sdhci_msm/*",

    // for input
    "/sys/devices/virtual/input*",
    "/sys/devices/virtual/misc/uinput",
    "/sys/devices/soc.0/gpio_keys.63/input*",
    "/sys/bus/platform/devices/gpio_keys.63/input*"
    "/sys/devices/virtual/misc/uinput",
    "/sys/devices/virtual/misc/uinput/*",
    "/sys/devices/virtual/input*",
    "/sys/devices/soc.0/78b9000.i2c/i2c-5/5-0038/input*",
    "/sys/devices/soc.0/78b9000.i2c/i2c-5/5-0038/input/input0",

    // for adb
    "/sys/class/tty/ptmx",
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p23", // system
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p24", // cache
    "/sys/class/misc/android_adb",
    "/sys/class/android_usb/android0*",
    "/sys/class/android_usb/android0/f_adb",
    "/sys/bus/platform/drivers/android_usb",
    "/sys/bus/usb",

    // Mount persist and firmware
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p25", // persist
    "/sys/devices/soc.0/7824900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p1", // firmware

    // USB Drive is in here
    "/sys/devices/soc.0/7864900.sdhci/mmc_host/mmc1/mmc1:aaaa/block/mmcblk1/mmcblk1p1", // sdcard
    "/sys/devices/platform/msm_hsusb_host*",


    /*
    "/sys/bus/mmc",
    "/sys/bus/mmc/drivers/mmcblk",
    "/sys/bus/sdio/drivers/bcmsdh_sdmmc",
    "/sys/module/mmc_core",
    "/sys/module/mmcblk",

    "/sys/devices/platform/msm_hsusb_host*",
    "/sys/bus/mmc*",
    "/sys/dev/block*",

	// Input
    "/sys/bus/platform/devices/gpio_keys.63/input*"
    "/sys/devices/virtual/misc/uinput",
    "/sys/devices/virtual/input*",
    "/sys/devices/soc.0/78b9000.i2c/i2c-5/5-0038/input*",
    "/sys/devices/soc.0/78b9000.i2c/i2c-5/5-0038/input/input0",

	// For adb
    "/sys/devices/virtual/tty/ptmx",
    "/sys/devices/virtual/misc/android_adb",
    "/sys/devices/virtual/android_usb/android0/f_adb",
    "/sys/bus/usb",
    */

    NULL
};
