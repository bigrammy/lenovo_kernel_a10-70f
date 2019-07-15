#include <linux/types.h>
#include <mach/mt_pm_ldo.h>
#include <cust_alsps.h>
//#include <mach/mt6577_pm_ldo.h>
static struct alsps_hw cust_alsps_hw = {
    .i2c_num    = 1,
	.polling_mode_als =1,
    .power_id   = MT65XX_POWER_NONE,    /*LDO is not used*/
    .power_vol  = VOL_DEFAULT,          /*LDO is not used*/
    .i2c_addr   = {0x20,0x20,0x20,0x20},
    //.als_level  = { 0,  1,  1,   7,  15,  15,  100, 500, 800,  1000,  2000, 3000, 4000, 5000, 6500},
    .als_level  = { 0,   2,   5,   8,  10,  30,   50,   80,  200,   400,   800,  1500, 3000,   5000,  6500},
    .als_value  = {40,  50,  80, 140, 235, 320,  450,  640,  870,  1200,  1600,  2100, 6400,  10240,  10240,  10240},
    //.als_value  = {40, 40, 90,  90, 160, 160,  225,  320,  640,  1280,  1280,  2600,  10240, 10240,  10240, 10240},
};
struct alsps_hw *get_cust_alsps_hw(void) {
    return &cust_alsps_hw;
}
