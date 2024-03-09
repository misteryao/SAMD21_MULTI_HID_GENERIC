/*
 * multi_hid_generic.h
 *
 * Created: 2015/9/13 下午 05:39:12
 *  Author: LaBest FAE
 */ 


#ifndef MULTI_HID_GENERIC_H_
#define MULTI_HID_GENERIC_H_
#include "conf_usb.h"

#ifndef MULTI_HID_GENERIC
static volatile bool main_b_generic_enable = false;

static uint8_t ui_hid_in_report[UDI_HID_REPORT_IN_SIZE];

bool main_generic_enable(void);
void main_generic_disable(void);
void main_hid_set_feature(uint8_t* report);
#else
static volatile bool main_b_generic_charger_enable = false;
static volatile bool main_b_generic_battery1_enable = false;
static volatile bool main_b_generic_battery2_enable = false;
static volatile bool main_b_generic_battery3_enable = false;
static volatile bool main_b_generic_battery4_enable = false;
static volatile bool main_b_generic_battery5_enable = false;
static volatile bool main_b_generic_battery6_enable = false;

bool main_generic_charger_enable(void);
bool main_generic_battery1_enable(void);
bool main_generic_battery2_enable(void);
bool main_generic_battery3_enable(void);
bool main_generic_battery4_enable(void);
bool main_generic_battery5_enable(void);
bool main_generic_battery6_enable(void);

void main_generic_charger_disable(void);
void main_generic_battery1_disable(void);
void main_generic_battery2_disable(void);
void main_generic_battery3_disable(void);
void main_generic_battery4_disable(void);
void main_generic_battery5_disable(void);
void main_generic_battery6_disable(void);

void main_hid_charger_set_feature(uint8_t* report);
void main_hid_battery1_set_feature(uint8_t* report);
void main_hid_battery2_set_feature(uint8_t* report);
void main_hid_battery3_set_feature(uint8_t* report);
void main_hid_battery4_set_feature(uint8_t* report);
void main_hid_battery5_set_feature(uint8_t* report);
void main_hid_battery6_set_feature(uint8_t* report);
#endif



#endif /* MULTI_HID_GENERIC_H_ */