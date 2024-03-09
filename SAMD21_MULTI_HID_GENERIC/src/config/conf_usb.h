/**
 * \file
 *
 * \brief USB configuration file
 *
 * Copyright (c) 2009-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef _CONF_USB_H_
#define _CONF_USB_H_

#include "compiler.h"

/**
 * USB Device Configuration
 * @{
 */

//! Device definition (mandatory)
#define  USB_DEVICE_VENDOR_ID             USB_VID_ATMEL
#define  USB_DEVICE_PRODUCT_ID            USB_PID_ATMEL_ASF_HIDGENERIC
#define  USB_DEVICE_MAJOR_VERSION         1
#define  USB_DEVICE_MINOR_VERSION         0
#define  USB_DEVICE_POWER                 100 // Consumption on VBUS line (mA)
#define  USB_DEVICE_ATTR                  (USB_CONFIG_ATTR_REMOTE_WAKEUP | USB_CONFIG_ATTR_SELF_POWERED)

//! USB Device string definitions (Optional)
#define  USB_DEVICE_MANUFACTURE_NAME      "ONYX"
#define  USB_DEVICE_PRODUCT_NAME          "Battery Monitor"
#define  USB_DEVICE_SERIAL_NAME           "onyx_Charger" // Disk SN for MSC

/**
 * Device speeds support
 * @{
 */

//! To define a Low speed device
//#define  USB_DEVICE_LOW_SPEED

//! To authorize the High speed
#if (UC3A3||UC3A4)
#define  USB_DEVICE_HS_SUPPORT
#elif (SAM3XA||SAM3U)
#define  USB_DEVICE_HS_SUPPORT
#endif
//@}


/**
 * USB Device Callbacks definitions (Optional)
 * @{
 */
#define  UDC_VBUS_EVENT(b_vbus_high)
#define  UDC_SOF_EVENT()                  main_sof_action()
extern void main_sof_action(void);
#define  UDC_SUSPEND_EVENT()              main_suspend_action()
extern void main_suspend_action(void);
#define  UDC_RESUME_EVENT()               main_resume_action()
extern void main_resume_action(void);
//! Mandatory when USB_DEVICE_ATTR authorizes remote wakeup feature
#define  UDC_REMOTEWAKEUP_ENABLE()        main_remotewakeup_enable()
extern void main_remotewakeup_enable(void);
#define  UDC_REMOTEWAKEUP_DISABLE()       main_remotewakeup_disable()
extern void main_remotewakeup_disable(void);
//! When a extra string descriptor must be supported
//! other than manufacturer, product and serial string
#define  UDC_GET_EXTRA_STRING()				main_extra_string()
extern bool main_extra_string(void);
//@

/**
 * USB Device low level configuration
 * When only one interface is used, these configurations are defined by the class module.
 * For composite device, these configuration must be defined here
 * @{
 */

//@}

//@}

/**
 * Configuration of HID Generic interface (if used)
 * @{
 */

//If define this will disable endpoint out
#define HID_GENERIC_SINGLE_IN_ENDPOINT

//If define this will change hid generic library code to multi-HID Generic device
#define MULTI_HID_GENERIC

/**
 * USB HID Generic low level configuration
 * In standalone these configurations are defined by the HID generic module.
 * For composite device, these configuration must be defined here
 * @{
 */
//! Endpoint numbers definition
#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
#define  UDI_HID_GENERIC_EP_OUT   (2 | USB_EP_DIR_OUT)
#endif
#ifndef MULTI_HID_GENERIC
//! Control endpoint size
#define  USB_DEVICE_EP_CTRL_SIZE       64

//! Number of interfaces for this device
#define  USB_DEVICE_NB_INTERFACE       1 // 1 or more

//! Total endpoint used by all interfaces
//! Note:
//! It is possible to define an IN and OUT endpoints with the same number on XMEGA product only
//! E.g. MSC class can be have IN endpoint 0x81 and OUT endpoint 0x01
#define  USB_DEVICE_MAX_EP             7 // 0 to max endpoint requested by interfaces

//! Interface callback definition
#define  UDI_HID_GENERIC_ENABLE_EXT()        main_generic_enable()
extern void main_generic_enable(void);
#define  UDI_HID_GENERIC_DISABLE_EXT()       main_generic_disable()
extern void main_generic_disable(void);
#define  UDI_HID_GENERIC_REPORT_OUT(ptr)     //ui_led_change(ptr)
#define  UDI_HID_GENERIC_SET_FEATURE(report) main_hid_set_feature(report)
extern void main_hid_set_feature(uint8_t* report);

#define  UDI_HID_GENERIC_STRING_ID            4
//! Sizes of I/O reports
#define  UDI_HID_REPORT_IN_SIZE             64
#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
#define  UDI_HID_REPORT_OUT_SIZE            8
#endif
#define  UDI_HID_REPORT_FEATURE_SIZE        4

//! Sizes of I/O endpoints
#define  UDI_HID_GENERIC_EP_SIZE            64

#define UDI_HID_GENERIC_EP_IN	(1 | USB_EP_DIR_IN)
#define  UDI_HID_GENERIC_IFACE_NUMBER    0
//! USB Interfaces descriptor structure
#define UDI_COMPOSITE_DESC_T \
	udi_hid_generic_desc_t  hid_generic
//! USB Interfaces descriptor value for Full Speed
#define UDI_COMPOSITE_DESC_FS \
	.hid_generic        = UDI_HID_GENERIC_DESC
//! USB Interfaces descriptor value for High Speed
#define UDI_COMPOSITE_DESC_HS \
	.hid_generic        = UDI_HID_GENERIC_DESC
//! USB Interface APIs
#define UDI_COMPOSITE_API \
	&udi_api_hid_generic
#else
//! Control endpoint size
#define  USB_DEVICE_EP_CTRL_SIZE       64

//! Number of interfaces for this device
#define  USB_DEVICE_NB_INTERFACE       7 // 1 or more

//! Total endpoint used by all interfaces
//! Note:
//! It is possible to define an IN and OUT endpoints with the same number on XMEGA product only
//! E.g. MSC class can be have IN endpoint 0x81 and OUT endpoint 0x01
#define  USB_DEVICE_MAX_EP             7 // 0 to max endpoint requested by interfaces

//! Interface callback definition
#define  UDI_HID_GENERIC_CHARGER_ENABLE_EXT()        main_generic_charger_enable()
extern bool main_generic_charger_enable(void);
#define  UDI_HID_GENERIC_BATTERY1_ENABLE_EXT()        main_generic_battery1_enable()
extern bool main_generic_battery1_enable(void);
#define  UDI_HID_GENERIC_BATTERY2_ENABLE_EXT()        main_generic_battery2_enable()
extern bool main_generic_battery2_enable(void);
#define  UDI_HID_GENERIC_BATTERY3_ENABLE_EXT()        main_generic_battery3_enable()
extern bool main_generic_battery3_enable(void);
#define  UDI_HID_GENERIC_BATTERY4_ENABLE_EXT()        main_generic_battery4_enable()
extern bool main_generic_battery4_enable(void);
#define  UDI_HID_GENERIC_BATTERY5_ENABLE_EXT()        main_generic_battery5_enable()
extern bool main_generic_battery5_enable(void);
#define  UDI_HID_GENERIC_BATTERY6_ENABLE_EXT()        main_generic_battery6_enable()
extern bool main_generic_battery6_enable(void);

#define  UDI_HID_GENERIC_CHARGER_DISABLE_EXT()       main_generic_charger_disable()
extern void main_generic_charger_disable(void);
#define  UDI_HID_GENERIC_BATTERY1_DISABLE_EXT()       main_generic_battery1_disable()
extern void main_generic_battery1_disable(void);
#define  UDI_HID_GENERIC_BATTERY2_DISABLE_EXT()       main_generic_battery2_disable()
extern void main_generic_battery2_disable(void);
#define  UDI_HID_GENERIC_BATTERY3_DISABLE_EXT()       main_generic_battery3_disable()
extern void main_generic_battery3_disable(void);
#define  UDI_HID_GENERIC_BATTERY4_DISABLE_EXT()       main_generic_battery4_disable()
extern void main_generic_battery4_disable(void);
#define  UDI_HID_GENERIC_BATTERY5_DISABLE_EXT()       main_generic_battery5_disable()
extern void main_generic_battery5_disable(void);
#define  UDI_HID_GENERIC_BATTERY6_DISABLE_EXT()       main_generic_battery6_disable()
extern void main_generic_battery6_disable(void);

#define  UDI_HID_GENERIC_CHARGER_REPORT_OUT(ptr)   
#define  UDI_HID_GENERIC_BATTERY1_REPORT_OUT(ptr) 
#define  UDI_HID_GENERIC_BATTERY2_REPORT_OUT(ptr)
#define  UDI_HID_GENERIC_BATTERY3_REPORT_OUT(ptr)
#define  UDI_HID_GENERIC_BATTERY4_REPORT_OUT(ptr)
#define  UDI_HID_GENERIC_BATTERY5_REPORT_OUT(ptr)
#define  UDI_HID_GENERIC_BATTERY6_REPORT_OUT(ptr)

#define  UDI_HID_GENERIC_CHARGER_SET_FEATURE(report) main_hid_charger_set_feature(report)
extern void main_hid_charger_set_feature(uint8_t* report);
#define  UDI_HID_GENERIC_BATTERY1_SET_FEATURE(report) main_hid_battery1_set_feature(report)
extern void main_hid_battery1_set_feature(uint8_t* report);
#define  UDI_HID_GENERIC_BATTERY2_SET_FEATURE(report) main_hid_battery2_set_feature(report)
extern void main_hid_battery2_set_feature(uint8_t* report);
#define  UDI_HID_GENERIC_BATTERY3_SET_FEATURE(report) main_hid_battery3_set_feature(report)
extern void main_hid_battery3_set_feature(uint8_t* report);
#define  UDI_HID_GENERIC_BATTERY4_SET_FEATURE(report) main_hid_battery4_set_feature(report)
extern void main_hid_battery4_set_feature(uint8_t* report);
#define  UDI_HID_GENERIC_BATTERY5_SET_FEATURE(report) main_hid_battery5_set_feature(report)
extern void main_hid_battery5_set_feature(uint8_t* report);
#define  UDI_HID_GENERIC_BATTERY6_SET_FEATURE(report) main_hid_battery6_set_feature(report)
extern void main_hid_battery6_set_feature(uint8_t* report);

#define  UDI_HID_GENERIC_CHARGER_STRING_ID            4
#define  UDI_HID_GENERIC_BATTERY1_STRING_ID            5
#define  UDI_HID_GENERIC_BATTERY2_STRING_ID            6
#define  UDI_HID_GENERIC_BATTERY3_STRING_ID            7
#define  UDI_HID_GENERIC_BATTERY4_STRING_ID            8
#define  UDI_HID_GENERIC_BATTERY5_STRING_ID            9
#define  UDI_HID_GENERIC_BATTERY6_STRING_ID            10

//! Sizes of I/O reports
#define  UDI_HID_CHARGER_REPORT_IN_SIZE             64
#define  UDI_HID_BATTERY1_REPORT_IN_SIZE             64
#define  UDI_HID_BATTERY2_REPORT_IN_SIZE             64
#define  UDI_HID_BATTERY3_REPORT_IN_SIZE             64
#define  UDI_HID_BATTERY4_REPORT_IN_SIZE             64
#define  UDI_HID_BATTERY5_REPORT_IN_SIZE             64
#define  UDI_HID_BATTERY6_REPORT_IN_SIZE             64

#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
#define  UDI_HID_REPORT_OUT_SIZE            8
#endif
#define  UDI_HID_CHARGER_REPORT_FEATURE_SIZE        4
#define  UDI_HID_BATTERY1_REPORT_FEATURE_SIZE        4
#define  UDI_HID_BATTERY2_REPORT_FEATURE_SIZE        4
#define  UDI_HID_BATTERY3_REPORT_FEATURE_SIZE        4
#define  UDI_HID_BATTERY4_REPORT_FEATURE_SIZE        4
#define  UDI_HID_BATTERY5_REPORT_FEATURE_SIZE        4
#define  UDI_HID_BATTERY6_REPORT_FEATURE_SIZE        4

//! Sizes of I/O endpoints
#define  UDI_HID_GENERIC_CHARGER_EP_SIZE            64
#define  UDI_HID_GENERIC_BATTERY1_EP_SIZE			64
#define  UDI_HID_GENERIC_BATTERY2_EP_SIZE			64
#define  UDI_HID_GENERIC_BATTERY3_EP_SIZE			64
#define  UDI_HID_GENERIC_BATTERY4_EP_SIZE			64
#define  UDI_HID_GENERIC_BATTERY5_EP_SIZE			64
#define  UDI_HID_GENERIC_BATTERY6_EP_SIZE			64

#define  UDI_HID_GENERIC_CHARGER_EP_IN    (1 | USB_EP_DIR_IN)
#define  UDI_HID_GENERIC_BATTERY1_EP_IN    (2 | USB_EP_DIR_IN)
#define  UDI_HID_GENERIC_BATTERY2_EP_IN    (3 | USB_EP_DIR_IN)
#define  UDI_HID_GENERIC_BATTERY3_EP_IN    (4 | USB_EP_DIR_IN)
#define  UDI_HID_GENERIC_BATTERY4_EP_IN    (5 | USB_EP_DIR_IN)
#define  UDI_HID_GENERIC_BATTERY5_EP_IN    (6 | USB_EP_DIR_IN)
#define  UDI_HID_GENERIC_BATTERY6_EP_IN    (7 | USB_EP_DIR_IN)

#define  UDI_HID_GENERIC_IFACE_CHARGER_NUMBER    0
#define  UDI_HID_GENERIC_IFACE_BATTERY1_NUMBER    1
#define  UDI_HID_GENERIC_IFACE_BATTERY2_NUMBER    2
#define  UDI_HID_GENERIC_IFACE_BATTERY3_NUMBER    3
#define  UDI_HID_GENERIC_IFACE_BATTERY4_NUMBER    4
#define  UDI_HID_GENERIC_IFACE_BATTERY5_NUMBER    5
#define  UDI_HID_GENERIC_IFACE_BATTERY6_NUMBER    6

//! USB Interfaces descriptor structure
#if 1
#define UDI_COMPOSITE_DESC_T \
	udi_hid_generic_desc_t  hid_generic_charger; \
	udi_hid_generic_desc_t  hid_generic_battery1; \
	udi_hid_generic_desc_t  hid_generic_battery2; \
	udi_hid_generic_desc_t  hid_generic_battery3; \
	udi_hid_generic_desc_t  hid_generic_battery4; \
	udi_hid_generic_desc_t  hid_generic_battery5; \
	udi_hid_generic_desc_t  hid_generic_battery6
#else
#define UDI_COMPOSITE_DESC_T \
	udi_hid_generic_desc_t  hid_generic_charger; \
	udi_hid_generic_desc_t  hid_generic_battery1;
#endif
//! USB Interfaces descriptor value for Full Speed
#if 1
#define UDI_COMPOSITE_DESC_FS \
	.hid_generic_charger        = UDI_HID_GENERIC_CHARGER_DESC, \
	.hid_generic_battery1        = UDI_HID_GENERIC_BATTERY1_DESC, \
	.hid_generic_battery2        = UDI_HID_GENERIC_BATTERY2_DESC, \
	.hid_generic_battery3        = UDI_HID_GENERIC_BATTERY3_DESC, \
	.hid_generic_battery4        = UDI_HID_GENERIC_BATTERY4_DESC, \
	.hid_generic_battery5        = UDI_HID_GENERIC_BATTERY5_DESC, \
	.hid_generic_battery6        = UDI_HID_GENERIC_BATTERY6_DESC
#else
#define UDI_COMPOSITE_DESC_FS \
	.hid_generic_charger        = UDI_HID_GENERIC_CHARGER_DESC, \
	.hid_generic_battery1        = UDI_HID_GENERIC_BATTERY1_DESC
#endif
//! USB Interfaces descriptor value for High Speed
#if 1
#define UDI_COMPOSITE_DESC_HS \
	.hid_generic_charger        = UDI_HID_GENERIC_CHARGER_DESC, \
	.hid_generic_battery1        = UDI_HID_GENERIC_BATTERY1_DESC, \
	.hid_generic_battery2        = UDI_HID_GENERIC_BATTERY2_DESC, \
	.hid_generic_battery3        = UDI_HID_GENERIC_BATTERY3_DESC, \
	.hid_generic_battery4        = UDI_HID_GENERIC_BATTERY4_DESC, \
	.hid_generic_battery5        = UDI_HID_GENERIC_BATTERY5_DESC, \
	.hid_generic_battery6        = UDI_HID_GENERIC_BATTERY6_DESC, \
#else
#define UDI_COMPOSITE_DESC_HS \
	.hid_generic_charger        = UDI_HID_GENERIC_CHARGER_DESC, \
	.hid_generic_battery1        = UDI_HID_GENERIC_BATTERY1_DESC
#endif
//! USB Interface APIs
#if 1
#define UDI_COMPOSITE_API \
	&udi_api_hid_generic_charger, \
	&udi_api_hid_generic_battery1, \
	&udi_api_hid_generic_battery2, \
	&udi_api_hid_generic_battery3, \
	&udi_api_hid_generic_battery4, \
	&udi_api_hid_generic_battery5, \
	&udi_api_hid_generic_battery6
#else
#define UDI_COMPOSITE_API \
	&udi_api_hid_generic_charger, \
	&udi_api_hid_generic_battery1
#endif
#endif

	



#include "udi_hid_generic.h"

#endif // _CONF_USB_H_
