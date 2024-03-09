/**
 * \file
 *
 * \brief USB Device Human Interface Device (HID) generic interface.
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

#include "conf_usb.h"
#include "usb_protocol.h"
#include "udd.h"
#include "udc.h"
#include "udi_hid.h"
#include "udi_hid_generic.h"
#include <string.h>

/**
 * \ingroup udi_hid_generic_group
 * \defgroup udi_hid_generic_group_udc Interface with USB Device Core (UDC)
 *
 * Structures and functions required by UDC.
 *
 * @{
 */


//! Global structure which contains standard UDI interface for UDC
#ifndef MULTI_HID_GENERIC
bool udi_hid_generic_enable(void);
void udi_hid_generic_disable(void);
bool udi_hid_generic_setup(void);
uint8_t udi_hid_generic_getsetting(void);

UDC_DESC_STORAGE udi_api_t udi_api_hid_generic = {
	.enable = (bool(*)(void))udi_hid_generic_enable,
	.disable = (void (*)(void))udi_hid_generic_disable,
	.setup = (bool(*)(void))udi_hid_generic_setup,
	.getsetting = (uint8_t(*)(void))udi_hid_generic_getsetting,
	.sof_notify = NULL,
};
#else
bool udi_hid_generic_charger_enable(void);
bool udi_hid_generic_battery1_enable(void);
bool udi_hid_generic_battery2_enable(void);
bool udi_hid_generic_battery3_enable(void);
bool udi_hid_generic_battery4_enable(void);
bool udi_hid_generic_battery5_enable(void);
bool udi_hid_generic_battery6_enable(void);

void udi_hid_generic_charger_disable(void);
void udi_hid_generic_battery1_disable(void);
void udi_hid_generic_battery2_disable(void);
void udi_hid_generic_battery3_disable(void);
void udi_hid_generic_battery4_disable(void);
void udi_hid_generic_battery5_disable(void);
void udi_hid_generic_battery6_disable(void);

bool udi_hid_generic_charger_setup(void);
bool udi_hid_generic_battery1_setup(void);
bool udi_hid_generic_battery2_setup(void);
bool udi_hid_generic_battery3_setup(void);
bool udi_hid_generic_battery4_setup(void);
bool udi_hid_generic_battery5_setup(void);
bool udi_hid_generic_battery6_setup(void);

uint8_t udi_hid_generic_charger_getsetting(void);
uint8_t udi_hid_generic_battery1_getsetting(void);
uint8_t udi_hid_generic_battery2_getsetting(void);
uint8_t udi_hid_generic_battery3_getsetting(void);
uint8_t udi_hid_generic_battery4_getsetting(void);
uint8_t udi_hid_generic_battery5_getsetting(void);
uint8_t udi_hid_generic_battery6_getsetting(void);

UDC_DESC_STORAGE udi_api_t udi_api_hid_generic_charger = {
	.enable = (bool(*)(void))udi_hid_generic_charger_enable,
	.disable = (void (*)(void))udi_hid_generic_charger_disable,
	.setup = (bool(*)(void))udi_hid_generic_charger_setup,
	.getsetting = (uint8_t(*)(void))udi_hid_generic_charger_getsetting,
	.sof_notify = NULL,
};

UDC_DESC_STORAGE udi_api_t udi_api_hid_generic_battery1 = {
	.enable = (bool(*)(void))udi_hid_generic_battery1_enable,
	.disable = (void (*)(void))udi_hid_generic_battery1_disable,
	.setup = (bool(*)(void))udi_hid_generic_battery1_setup,
	.getsetting = (uint8_t(*)(void))udi_hid_generic_battery1_getsetting,
	.sof_notify = NULL,
};

UDC_DESC_STORAGE udi_api_t udi_api_hid_generic_battery2 = {
	.enable = (bool(*)(void))udi_hid_generic_battery2_enable,
	.disable = (void (*)(void))udi_hid_generic_battery2_disable,
	.setup = (bool(*)(void))udi_hid_generic_battery2_setup,
	.getsetting = (uint8_t(*)(void))udi_hid_generic_battery2_getsetting,
	.sof_notify = NULL,
};

UDC_DESC_STORAGE udi_api_t udi_api_hid_generic_battery3 = {
	.enable = (bool(*)(void))udi_hid_generic_battery3_enable,
	.disable = (void (*)(void))udi_hid_generic_battery3_disable,
	.setup = (bool(*)(void))udi_hid_generic_battery3_setup,
	.getsetting = (uint8_t(*)(void))udi_hid_generic_battery3_getsetting,
	.sof_notify = NULL,
};

UDC_DESC_STORAGE udi_api_t udi_api_hid_generic_battery4 = {
	.enable = (bool(*)(void))udi_hid_generic_battery4_enable,
	.disable = (void (*)(void))udi_hid_generic_battery4_disable,
	.setup = (bool(*)(void))udi_hid_generic_battery4_setup,
	.getsetting = (uint8_t(*)(void))udi_hid_generic_battery4_getsetting,
	.sof_notify = NULL,
};

UDC_DESC_STORAGE udi_api_t udi_api_hid_generic_battery5 = {
	.enable = (bool(*)(void))udi_hid_generic_battery5_enable,
	.disable = (void (*)(void))udi_hid_generic_battery5_disable,
	.setup = (bool(*)(void))udi_hid_generic_battery5_setup,
	.getsetting = (uint8_t(*)(void))udi_hid_generic_battery5_getsetting,
	.sof_notify = NULL,
};

UDC_DESC_STORAGE udi_api_t udi_api_hid_generic_battery6 = {
	.enable = (bool(*)(void))udi_hid_generic_battery6_enable,
	.disable = (void (*)(void))udi_hid_generic_battery6_disable,
	.setup = (bool(*)(void))udi_hid_generic_battery6_setup,
	.getsetting = (uint8_t(*)(void))udi_hid_generic_battery6_getsetting,
	.sof_notify = NULL,
};
#endif
//@}


/**
 * \ingroup udi_hid_generic_group
 * \defgroup udi_hid_generic_group_internal Implementation of UDI HID Generic
 *
 * Class internal implementation
 * @{
 */

/**
 * \name Internal defines and variables to manage HID generic
 */
//@{
#ifndef MULTI_HID_GENERIC
//! To store current rate of HID generic
COMPILER_WORD_ALIGNED
		static uint8_t udi_hid_generic_rate;
//! To store current protocol of HID generic
COMPILER_WORD_ALIGNED
		static uint8_t udi_hid_generic_protocol;
//! To signal if the report IN buffer is free (no transfer on going)
static bool udi_hid_generic_b_report_in_free;
//! Report to send
COMPILER_WORD_ALIGNED
		static uint8_t udi_hid_generic_report_in[UDI_HID_REPORT_IN_SIZE];
//! Report to receive
#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
//! Report to receive
COMPILER_WORD_ALIGNED
		static uint8_t udi_hid_generic_report_out[UDI_HID_REPORT_OUT_SIZE];
#endif
//! Report to receive via SetFeature
COMPILER_WORD_ALIGNED
		static uint8_t udi_hid_generic_report_feature[UDI_HID_REPORT_FEATURE_SIZE];
#else
//! To store current rate of HID generic
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_charger_rate;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery1_rate;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery2_rate;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery3_rate;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery4_rate;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery5_rate;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery6_rate;
//! To store current protocol of HID generic
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_charger_protocol;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery1_protocol;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery2_protocol;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery3_protocol;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery4_protocol;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery5_protocol;
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery6_protocol;
//! To signal if the report IN buffer is free (no transfer on going)
static bool udi_hid_generic_b_charger_report_in_free;
static bool udi_hid_generic_b_battery1_report_in_free;
static bool udi_hid_generic_b_battery2_report_in_free;
static bool udi_hid_generic_b_battery3_report_in_free;
static bool udi_hid_generic_b_battery4_report_in_free;
static bool udi_hid_generic_b_battery5_report_in_free;
static bool udi_hid_generic_b_battery6_report_in_free;
//! Report to send
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_charger_report_in[UDI_HID_CHARGER_REPORT_IN_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery1_report_in[UDI_HID_BATTERY1_REPORT_IN_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery2_report_in[UDI_HID_BATTERY2_REPORT_IN_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery3_report_in[UDI_HID_BATTERY3_REPORT_IN_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery4_report_in[UDI_HID_BATTERY4_REPORT_IN_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery5_report_in[UDI_HID_BATTERY5_REPORT_IN_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery6_report_in[UDI_HID_BATTERY6_REPORT_IN_SIZE];
//! Report to receive
#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
//! Report to receive
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_report_out[UDI_HID_REPORT_OUT_SIZE];
#endif
//! Report to receive via SetFeature
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_charger_report_feature[UDI_HID_CHARGER_REPORT_FEATURE_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery1_report_feature[UDI_HID_BATTERY1_REPORT_FEATURE_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery2_report_feature[UDI_HID_BATTERY2_REPORT_FEATURE_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery3_report_feature[UDI_HID_BATTERY3_REPORT_FEATURE_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery4_report_feature[UDI_HID_BATTERY4_REPORT_FEATURE_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery5_report_feature[UDI_HID_BATTERY5_REPORT_FEATURE_SIZE];
COMPILER_WORD_ALIGNED
	static uint8_t udi_hid_generic_battery6_report_feature[UDI_HID_BATTERY6_REPORT_FEATURE_SIZE];
#endif

//@}

//! HID report descriptor for standard HID generic
#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
UDC_DESC_STORAGE udi_hid_generic_report_desc_t udi_hid_generic_report_desc = { {
		0x06, 0xFF, 0xFF,	// 04|2   , Usage Page (vendor defined?)
		0x09, 0x01,	// 08|1   , Usage      (vendor defined
		0xA1, 0x01,	// A0|1   , Collection (Application)
		// IN report
		0x09, 0x02,	// 08|1   , Usage      (vendor defined)
		0x09, 0x03,	// 08|1   , Usage      (vendor defined)
		0x15, 0x00,	// 14|1   , Logical Minimum(0 for signed byte?)
		0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte?)
		0x75, 0x08,	// 74|1   , Report Size(8) = field size in bits = 1 byte
		// 94|1   , ReportCount(size) = repeat count of previous item
		0x95, sizeof(udi_hid_generic_report_in),
		0x81, 0x02,	// 80|1   , IN report (Data,Variable, Absolute)
		// OUT report
		0x09, 0x04,	// 08|1   , Usage      (vendor defined)
		0x09, 0x05,	// 08|1   , Usage      (vendor defined)
		0x15, 0x00,	// 14|1   , Logical Minimum(0 for signed byte?)
		0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte?)
		0x75, 0x08,	// 74|1   , Report Size(8) = field size in bits = 1 byte
		// 94|1   , ReportCount(size) = repeat count of previous item
		0x95, sizeof(udi_hid_generic_report_out),
		0x91, 0x02,	// 90|1   , OUT report (Data,Variable, Absolute)
		// Feature report
		0x09, 0x06,	// 08|1   , Usage      (vendor defined)
		0x09, 0x07,	// 08|1   , Usage      (vendor defined)
		0x15, 0x00,	// 14|1   , LogicalMinimum(0 for signed byte)
		0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte)
		0x75, 0x08,	// 74|1   , Report Size(8) =field size in bits = 1 byte
		0x95, sizeof(udi_hid_generic_report_feature),	// 94|x   , ReportCount in byte
		0xB1, 0x02,	// B0|1   , Feature report
		0xC0	// C0|0   , End Collection
	}
};
#else
	#ifndef MULTI_HID_GENERIC
	UDC_DESC_STORAGE udi_hid_generic_report_desc_t udi_hid_generic_report_desc = { {
			0x06, 0xFF, 0xFF,	// 04|2   , Usage Page (vendor defined?)
			0x09, 0x01,	// 08|1   , Usage      (vendor defined
			0xA1, 0x01,	// A0|1   , Collection (Application)
			// IN report
			0x09, 0x02,	// 08|1   , Usage      (vendor defined)
			0x09, 0x03,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , Logical Minimum(0 for signed byte?)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte?)
			0x75, 0x08,	// 74|1   , Report Size(8) = field size in bits = 1 byte
			// 94|1   , ReportCount(size) = repeat count of previous item
			0x95, sizeof(udi_hid_generic_report_in),
			0x81, 0x02,	// 80|1   , IN report (Data,Variable, Absolute)
			// Feature report
			0x09, 0x06,	// 08|1   , Usage      (vendor defined)
			0x09, 0x07,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , LogicalMinimum(0 for signed byte)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte)
			0x75, 0x08,	// 74|1   , Report Size(8) =field size in bits = 1 byte
			0x95, sizeof(udi_hid_generic_report_feature),	// 94|x   , ReportCount in byte
			0xB1, 0x02,	// B0|1   , Feature report
			0xC0	// C0|0   , End Collection
		}
	};
	#else
	UDC_DESC_STORAGE udi_hid_generic_report_desc_t udi_hid_generic_charger_report_desc = { {
			0x06, 0xFF, 0xFF,	// 04|2   , Usage Page (vendor defined?)
			0x09, 0x01,	// 08|1   , Usage      (vendor defined
			0xA1, 0x01,	// A0|1   , Collection (Application)
			// IN report
			0x09, 0x02,	// 08|1   , Usage      (vendor defined)
			0x09, 0x03,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , Logical Minimum(0 for signed byte?)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte?)
			0x75, 0x08,	// 74|1   , Report Size(8) = field size in bits = 1 byte
			// 94|1   , ReportCount(size) = repeat count of previous item
			0x95, sizeof(udi_hid_generic_charger_report_in),
			0x81, 0x02,	// 80|1   , IN report (Data,Variable, Absolute)
			// Feature report
			0x09, 0x06,	// 08|1   , Usage      (vendor defined)
			0x09, 0x07,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , LogicalMinimum(0 for signed byte)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte)
			0x75, 0x08,	// 74|1   , Report Size(8) =field size in bits = 1 byte
			0x95, sizeof(udi_hid_generic_charger_report_feature),	// 94|x   , ReportCount in byte
			0xB1, 0x02,	// B0|1   , Feature report
			0xC0	// C0|0   , End Collection
		}
	};

	UDC_DESC_STORAGE udi_hid_generic_report_desc_t udi_hid_generic_battery1_report_desc = { {
			0x06, 0xFF, 0xFF,	// 04|2   , Usage Page (vendor defined?)
			0x09, 0x01,	// 08|1   , Usage      (vendor defined
			0xA1, 0x01,	// A0|1   , Collection (Application)
			// IN report
			0x09, 0x02,	// 08|1   , Usage      (vendor defined)
			0x09, 0x03,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , Logical Minimum(0 for signed byte?)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte?)
			0x75, 0x08,	// 74|1   , Report Size(8) = field size in bits = 1 byte
			// 94|1   , ReportCount(size) = repeat count of previous item
			0x95, sizeof(udi_hid_generic_battery1_report_in),
			0x81, 0x02,	// 80|1   , IN report (Data,Variable, Absolute)
			// Feature report
			0x09, 0x06,	// 08|1   , Usage      (vendor defined)
			0x09, 0x07,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , LogicalMinimum(0 for signed byte)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte)
			0x75, 0x08,	// 74|1   , Report Size(8) =field size in bits = 1 byte
			0x95, sizeof(udi_hid_generic_battery1_report_feature),	// 94|x   , ReportCount in byte
			0xB1, 0x02,	// B0|1   , Feature report
			0xC0	// C0|0   , End Collection
		}
	};
	
	UDC_DESC_STORAGE udi_hid_generic_report_desc_t udi_hid_generic_battery2_report_desc = { {
			0x06, 0xFF, 0xFF,	// 04|2   , Usage Page (vendor defined?)
			0x09, 0x01,	// 08|1   , Usage      (vendor defined
			0xA1, 0x01,	// A0|1   , Collection (Application)
			// IN report
			0x09, 0x02,	// 08|1   , Usage      (vendor defined)
			0x09, 0x03,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , Logical Minimum(0 for signed byte?)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte?)
			0x75, 0x08,	// 74|1   , Report Size(8) = field size in bits = 1 byte
			// 94|1   , ReportCount(size) = repeat count of previous item
			0x95, sizeof(udi_hid_generic_battery2_report_in),
			0x81, 0x02,	// 80|1   , IN report (Data,Variable, Absolute)
			// Feature report
			0x09, 0x06,	// 08|1   , Usage      (vendor defined)
			0x09, 0x07,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , LogicalMinimum(0 for signed byte)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte)
			0x75, 0x08,	// 74|1   , Report Size(8) =field size in bits = 1 byte
			0x95, sizeof(udi_hid_generic_battery2_report_feature),	// 94|x   , ReportCount in byte
			0xB1, 0x02,	// B0|1   , Feature report
			0xC0	// C0|0   , End Collection
		}
	};
	
	UDC_DESC_STORAGE udi_hid_generic_report_desc_t udi_hid_generic_battery3_report_desc = { {
			0x06, 0xFF, 0xFF,	// 04|2   , Usage Page (vendor defined?)
			0x09, 0x01,	// 08|1   , Usage      (vendor defined
			0xA1, 0x01,	// A0|1   , Collection (Application)
			// IN report
			0x09, 0x02,	// 08|1   , Usage      (vendor defined)
			0x09, 0x03,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , Logical Minimum(0 for signed byte?)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte?)
			0x75, 0x08,	// 74|1   , Report Size(8) = field size in bits = 1 byte
			// 94|1   , ReportCount(size) = repeat count of previous item
			0x95, sizeof(udi_hid_generic_battery3_report_in),
			0x81, 0x02,	// 80|1   , IN report (Data,Variable, Absolute)
			// Feature report
			0x09, 0x06,	// 08|1   , Usage      (vendor defined)
			0x09, 0x07,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , LogicalMinimum(0 for signed byte)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte)
			0x75, 0x08,	// 74|1   , Report Size(8) =field size in bits = 1 byte
			0x95, sizeof(udi_hid_generic_battery3_report_feature),	// 94|x   , ReportCount in byte
			0xB1, 0x02,	// B0|1   , Feature report
			0xC0	// C0|0   , End Collection
		}
	};
	
	UDC_DESC_STORAGE udi_hid_generic_report_desc_t udi_hid_generic_battery4_report_desc = { {
			0x06, 0xFF, 0xFF,	// 04|2   , Usage Page (vendor defined?)
			0x09, 0x01,	// 08|1   , Usage      (vendor defined
			0xA1, 0x01,	// A0|1   , Collection (Application)
			// IN report
			0x09, 0x02,	// 08|1   , Usage      (vendor defined)
			0x09, 0x03,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , Logical Minimum(0 for signed byte?)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte?)
			0x75, 0x08,	// 74|1   , Report Size(8) = field size in bits = 1 byte
			// 94|1   , ReportCount(size) = repeat count of previous item
			0x95, sizeof(udi_hid_generic_battery4_report_in),
			0x81, 0x02,	// 80|1   , IN report (Data,Variable, Absolute)
			// Feature report
			0x09, 0x06,	// 08|1   , Usage      (vendor defined)
			0x09, 0x07,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , LogicalMinimum(0 for signed byte)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte)
			0x75, 0x08,	// 74|1   , Report Size(8) =field size in bits = 1 byte
			0x95, sizeof(udi_hid_generic_battery4_report_feature),	// 94|x   , ReportCount in byte
			0xB1, 0x02,	// B0|1   , Feature report
			0xC0	// C0|0   , End Collection
		}
	};
	
	UDC_DESC_STORAGE udi_hid_generic_report_desc_t udi_hid_generic_battery5_report_desc = { {
			0x06, 0xFF, 0xFF,	// 04|2   , Usage Page (vendor defined?)
			0x09, 0x01,	// 08|1   , Usage      (vendor defined
			0xA1, 0x01,	// A0|1   , Collection (Application)
			// IN report
			0x09, 0x02,	// 08|1   , Usage      (vendor defined)
			0x09, 0x03,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , Logical Minimum(0 for signed byte?)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte?)
			0x75, 0x08,	// 74|1   , Report Size(8) = field size in bits = 1 byte
			// 94|1   , ReportCount(size) = repeat count of previous item
			0x95, sizeof(udi_hid_generic_battery5_report_in),
			0x81, 0x02,	// 80|1   , IN report (Data,Variable, Absolute)
			// Feature report
			0x09, 0x06,	// 08|1   , Usage      (vendor defined)
			0x09, 0x07,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , LogicalMinimum(0 for signed byte)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte)
			0x75, 0x08,	// 74|1   , Report Size(8) =field size in bits = 1 byte
			0x95, sizeof(udi_hid_generic_battery5_report_feature),	// 94|x   , ReportCount in byte
			0xB1, 0x02,	// B0|1   , Feature report
			0xC0	// C0|0   , End Collection
		}
	};
	
	UDC_DESC_STORAGE udi_hid_generic_report_desc_t udi_hid_generic_battery6_report_desc = { {
			0x06, 0xFF, 0xFF,	// 04|2   , Usage Page (vendor defined?)
			0x09, 0x01,	// 08|1   , Usage      (vendor defined
			0xA1, 0x01,	// A0|1   , Collection (Application)
			// IN report
			0x09, 0x02,	// 08|1   , Usage      (vendor defined)
			0x09, 0x03,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , Logical Minimum(0 for signed byte?)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte?)
			0x75, 0x08,	// 74|1   , Report Size(8) = field size in bits = 1 byte
			// 94|1   , ReportCount(size) = repeat count of previous item
			0x95, sizeof(udi_hid_generic_battery6_report_in),
			0x81, 0x02,	// 80|1   , IN report (Data,Variable, Absolute)
			// Feature report
			0x09, 0x06,	// 08|1   , Usage      (vendor defined)
			0x09, 0x07,	// 08|1   , Usage      (vendor defined)
			0x15, 0x00,	// 14|1   , LogicalMinimum(0 for signed byte)
			0x26, 0xFF, 0x00,	// 24|1   , Logical Maximum(255 for signed byte)
			0x75, 0x08,	// 74|1   , Report Size(8) =field size in bits = 1 byte
			0x95, sizeof(udi_hid_generic_battery6_report_feature),	// 94|x   , ReportCount in byte
			0xB1, 0x02,	// B0|1   , Feature report
			0xC0	// C0|0   , End Collection
		}
	};
	#endif
#endif


#ifndef MULTI_HID_GENERIC
/**
 * \brief Send a report to HID interface
 *
 */
static bool udi_hid_generic_setreport(void);

/**
 * \brief Initialize UDD to receive setfeature data
 */
static void udi_hid_generic_setfeature_valid(void);

/**
 * \brief Callback called when the report is received
 *
 * \param status     UDD_EP_TRANSFER_OK, if transfer is completed
 * \param status     UDD_EP_TRANSFER_ABORT, if transfer is aborted
 * \param nb_sent    number of data received
 */
#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
static void udi_hid_generic_report_out_received(udd_ep_status_t status,
		iram_size_t nb_received, udd_ep_id_t ep);

/**
 * \brief Enable reception of out report
 *
 * \return \c 1 if function was successfully done, otherwise \c 0.
 */
static bool udi_hid_generic_report_out_enable(void);
#endif
/**
 * \brief Callback called when the report is sent
 *
 * \param status     UDD_EP_TRANSFER_OK, if transfer is completed
 * \param status     UDD_EP_TRANSFER_ABORT, if transfer is aborted
 * \param nb_sent    number of data transfered
 */
static void udi_hid_generic_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep);
#else
/**
 * \brief Send a report to HID interface
 *
 */
static bool udi_hid_generic_charger_setreport(void);
static bool udi_hid_generic_battery1_setreport(void);
static bool udi_hid_generic_battery2_setreport(void);
static bool udi_hid_generic_battery3_setreport(void);
static bool udi_hid_generic_battery4_setreport(void);
static bool udi_hid_generic_battery5_setreport(void);
static bool udi_hid_generic_battery6_setreport(void);

/**
 * \brief Initialize UDD to receive setfeature data
 */
static void udi_hid_generic_charger_setfeature_valid(void);
static void udi_hid_generic_battery1_setfeature_valid(void);
static void udi_hid_generic_battery2_setfeature_valid(void);
static void udi_hid_generic_battery3_setfeature_valid(void);
static void udi_hid_generic_battery4_setfeature_valid(void);
static void udi_hid_generic_battery5_setfeature_valid(void);
static void udi_hid_generic_battery6_setfeature_valid(void);

/**
 * \brief Callback called when the report is received
 *
 * \param status     UDD_EP_TRANSFER_OK, if transfer is completed
 * \param status     UDD_EP_TRANSFER_ABORT, if transfer is aborted
 * \param nb_sent    number of data received
 */
#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
static void udi_hid_generic_report_out_received(udd_ep_status_t status,
		iram_size_t nb_received, udd_ep_id_t ep);

/**
 * \brief Enable reception of out report
 *
 * \return \c 1 if function was successfully done, otherwise \c 0.
 */
static bool udi_hid_generic_report_out_enable(void);
#endif
/**
 * \brief Callback called when the report is sent
 *
 * \param status     UDD_EP_TRANSFER_OK, if transfer is completed
 * \param status     UDD_EP_TRANSFER_ABORT, if transfer is aborted
 * \param nb_sent    number of data transfered
 */
static void udi_hid_generic_charger_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep);
static void udi_hid_generic_battery1_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep);
static void udi_hid_generic_battery2_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep);
static void udi_hid_generic_battery3_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep);
static void udi_hid_generic_battery4_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep);
static void udi_hid_generic_battery5_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep);
static void udi_hid_generic_battery6_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep);
#endif
//@}


//--------------------------------------------
//------ Interface for UDI HID level
#ifndef MULTI_HID_GENERIC
bool udi_hid_generic_enable(void)
{
	// Initialize internal values
	udi_hid_generic_rate = 0;
	udi_hid_generic_protocol = 0;
	udi_hid_generic_b_report_in_free = true;
	#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
	if (!udi_hid_generic_report_out_enable())
		return false;
	#endif
	return UDI_HID_GENERIC_ENABLE_EXT();
}


void udi_hid_generic_disable(void)
{
	UDI_HID_GENERIC_DISABLE_EXT();
}


bool udi_hid_generic_setup(void)
{
	return udi_hid_setup(&udi_hid_generic_rate,
								&udi_hid_generic_protocol,
								(uint8_t *) &udi_hid_generic_report_desc,
								udi_hid_generic_setreport);
}


uint8_t udi_hid_generic_getsetting(void)
{
	return 0;
}


static bool udi_hid_generic_setreport(void)
{
	if ((USB_HID_REPORT_TYPE_FEATURE == (udd_g_ctrlreq.req.wValue >> 8))
			&& (0 == (0xFF & udd_g_ctrlreq.req.wValue))
			&& (sizeof(udi_hid_generic_report_feature) ==
					udd_g_ctrlreq.req.wLength)) {
		// Feature type on report ID 0
		udd_g_ctrlreq.payload =
				(uint8_t *) & udi_hid_generic_report_feature;
		udd_g_ctrlreq.callback = udi_hid_generic_setfeature_valid;
		udd_g_ctrlreq.payload_size =
				sizeof(udi_hid_generic_report_feature);
		return true;
	}
	return false;
}

//--------------------------------------------
//------ Interface for application

bool udi_hid_generic_send_report_in(uint8_t *data)
{
	if (!udi_hid_generic_b_report_in_free)
		return false;
	irqflags_t flags = cpu_irq_save();
	// Fill report
	memset(&udi_hid_generic_report_in, 0,
			sizeof(udi_hid_generic_report_in));
	memcpy(&udi_hid_generic_report_in, data,
	      		sizeof(udi_hid_generic_report_in));
	udi_hid_generic_b_report_in_free =
			!udd_ep_run(UDI_HID_GENERIC_EP_IN,
							false,
							(uint8_t *) & udi_hid_generic_report_in,
							sizeof(udi_hid_generic_report_in),
							udi_hid_generic_report_in_sent);
	cpu_irq_restore(flags);
	return !udi_hid_generic_b_report_in_free;

}

//--------------------------------------------
//------ Internal routines

static void udi_hid_generic_setfeature_valid(void)
{
	if (sizeof(udi_hid_generic_report_feature) != udd_g_ctrlreq.payload_size)
		return;	// Bad data
	UDI_HID_GENERIC_SET_FEATURE(udi_hid_generic_report_feature);
}

#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
static void udi_hid_generic_report_out_received(udd_ep_status_t status,
		iram_size_t nb_received, udd_ep_id_t ep)
{
	UNUSED(ep);
	if (UDD_EP_TRANSFER_OK != status)
		return;	// Abort reception

	if (sizeof(udi_hid_generic_report_out) == nb_received) {
		UDI_HID_GENERIC_REPORT_OUT(udi_hid_generic_report_out);
	}
	udi_hid_generic_report_out_enable();
}


static bool udi_hid_generic_report_out_enable(void)
{
	return udd_ep_run(UDI_HID_GENERIC_EP_OUT,
							false,
							(uint8_t *) & udi_hid_generic_report_out,
							sizeof(udi_hid_generic_report_out),
							udi_hid_generic_report_out_received);
}
#endif

static void udi_hid_generic_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep)
{
	UNUSED(status);
	UNUSED(nb_sent);
	UNUSED(ep);
	udi_hid_generic_b_report_in_free = true;
}
#else
bool udi_hid_generic_charger_enable(void)
{
	// Initialize internal values
	udi_hid_generic_charger_rate = 0;
	udi_hid_generic_charger_protocol = 0;
	udi_hid_generic_b_charger_report_in_free = true;
	#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
	if (!udi_hid_generic_report_out_enable())
	return false;
	#endif
	return UDI_HID_GENERIC_CHARGER_ENABLE_EXT();
}

bool udi_hid_generic_battery1_enable(void)
{
	// Initialize internal values
	udi_hid_generic_battery1_rate = 0;
	udi_hid_generic_battery1_protocol = 0;
	udi_hid_generic_b_battery1_report_in_free = true;
	#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
	if (!udi_hid_generic_report_out_enable())
	return false;
	#endif
	return UDI_HID_GENERIC_BATTERY1_ENABLE_EXT();
}

bool udi_hid_generic_battery2_enable(void)
{
	// Initialize internal values
	udi_hid_generic_battery2_rate = 0;
	udi_hid_generic_battery2_protocol = 0;
	udi_hid_generic_b_battery2_report_in_free = true;
	#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
	if (!udi_hid_generic_report_out_enable())
	return false;
	#endif
	return UDI_HID_GENERIC_BATTERY2_ENABLE_EXT();
}

bool udi_hid_generic_battery3_enable(void)
{
	// Initialize internal values
	udi_hid_generic_battery3_rate = 0;
	udi_hid_generic_battery3_protocol = 0;
	udi_hid_generic_b_battery3_report_in_free = true;
	#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
	if (!udi_hid_generic_report_out_enable())
	return false;
	#endif
	return UDI_HID_GENERIC_BATTERY3_ENABLE_EXT();
}

bool udi_hid_generic_battery4_enable(void)
{
	// Initialize internal values
	udi_hid_generic_battery4_rate = 0;
	udi_hid_generic_battery4_protocol = 0;
	udi_hid_generic_b_battery4_report_in_free = true;
	#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
	if (!udi_hid_generic_report_out_enable())
	return false;
	#endif
	return UDI_HID_GENERIC_BATTERY4_ENABLE_EXT();
}

bool udi_hid_generic_battery5_enable(void)
{
	// Initialize internal values
	udi_hid_generic_battery5_rate = 0;
	udi_hid_generic_battery5_protocol = 0;
	udi_hid_generic_b_battery5_report_in_free = true;
	#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
	if (!udi_hid_generic_report_out_enable())
	return false;
	#endif
	return UDI_HID_GENERIC_BATTERY5_ENABLE_EXT();
}

bool udi_hid_generic_battery6_enable(void)
{
	// Initialize internal values
	udi_hid_generic_battery6_rate = 0;
	udi_hid_generic_battery6_protocol = 0;
	udi_hid_generic_b_battery6_report_in_free = true;
	#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
	if (!udi_hid_generic_report_out_enable())
	return false;
	#endif
	return UDI_HID_GENERIC_BATTERY6_ENABLE_EXT();
}

void udi_hid_generic_charger_disable(void)
{
	UDI_HID_GENERIC_CHARGER_DISABLE_EXT();
}

void udi_hid_generic_battery1_disable(void)
{
	UDI_HID_GENERIC_BATTERY1_DISABLE_EXT();
}

void udi_hid_generic_battery2_disable(void)
{
	UDI_HID_GENERIC_BATTERY2_DISABLE_EXT();
}

void udi_hid_generic_battery3_disable(void)
{
	UDI_HID_GENERIC_BATTERY3_DISABLE_EXT();
}

void udi_hid_generic_battery4_disable(void)
{
	UDI_HID_GENERIC_BATTERY4_DISABLE_EXT();
}

void udi_hid_generic_battery5_disable(void)
{
	UDI_HID_GENERIC_BATTERY5_DISABLE_EXT();
}

void udi_hid_generic_battery6_disable(void)
{
	UDI_HID_GENERIC_BATTERY6_DISABLE_EXT();
}

bool udi_hid_generic_charger_setup(void)
{
	return udi_hid_setup(&udi_hid_generic_charger_rate,
			&udi_hid_generic_charger_protocol,
			(uint8_t *) &udi_hid_generic_charger_report_desc,
			udi_hid_generic_charger_setreport);
}

bool udi_hid_generic_battery1_setup(void)
{
	return udi_hid_setup(&udi_hid_generic_battery1_rate,
			&udi_hid_generic_battery1_protocol,
			(uint8_t *) &udi_hid_generic_battery1_report_desc,
			udi_hid_generic_battery1_setreport);
}

bool udi_hid_generic_battery2_setup(void)
{
	return udi_hid_setup(&udi_hid_generic_battery2_rate,
			&udi_hid_generic_battery2_protocol,
			(uint8_t *) &udi_hid_generic_battery2_report_desc,
			udi_hid_generic_battery2_setreport);
}

bool udi_hid_generic_battery3_setup(void)
{
	return udi_hid_setup(&udi_hid_generic_battery3_rate,
			&udi_hid_generic_battery3_protocol,
			(uint8_t *) &udi_hid_generic_battery3_report_desc,
			udi_hid_generic_battery3_setreport);
}

bool udi_hid_generic_battery4_setup(void)
{
	return udi_hid_setup(&udi_hid_generic_battery4_rate,
			&udi_hid_generic_battery4_protocol,
			(uint8_t *) &udi_hid_generic_battery4_report_desc,
			udi_hid_generic_battery4_setreport);
}

bool udi_hid_generic_battery5_setup(void)
{
	return udi_hid_setup(&udi_hid_generic_battery5_rate,
			&udi_hid_generic_battery5_protocol,
			(uint8_t *) &udi_hid_generic_battery5_report_desc,
			udi_hid_generic_battery5_setreport);
}

bool udi_hid_generic_battery6_setup(void)
{
	return udi_hid_setup(&udi_hid_generic_battery6_rate,
			&udi_hid_generic_battery6_protocol,
			(uint8_t *) &udi_hid_generic_battery6_report_desc,
			udi_hid_generic_battery6_setreport);
}


uint8_t udi_hid_generic_charger_getsetting(void)
{
	return 0;
}

uint8_t udi_hid_generic_battery1_getsetting(void)
{
	return 0;
}

uint8_t udi_hid_generic_battery2_getsetting(void)
{
	return 0;
}

uint8_t udi_hid_generic_battery3_getsetting(void)
{
	return 0;
}

uint8_t udi_hid_generic_battery4_getsetting(void)
{
	return 0;
}

uint8_t udi_hid_generic_battery5_getsetting(void)
{
	return 0;
}

uint8_t udi_hid_generic_battery6_getsetting(void)
{
	return 0;
}

static bool udi_hid_generic_charger_setreport(void)
{
	if ((USB_HID_REPORT_TYPE_FEATURE == (udd_g_ctrlreq.req.wValue >> 8))
	&& (0 == (0xFF & udd_g_ctrlreq.req.wValue))
	&& (sizeof(udi_hid_generic_charger_report_feature) ==
	udd_g_ctrlreq.req.wLength)) {
		// Feature type on report ID 0
		udd_g_ctrlreq.payload =
		(uint8_t *) & udi_hid_generic_charger_report_feature;
		udd_g_ctrlreq.callback = udi_hid_generic_charger_setfeature_valid;
		udd_g_ctrlreq.payload_size =
		sizeof(udi_hid_generic_charger_report_feature);
		return true;
	}
	return false;
}

static bool udi_hid_generic_battery1_setreport(void)
{
	if ((USB_HID_REPORT_TYPE_FEATURE == (udd_g_ctrlreq.req.wValue >> 8))
	&& (0 == (0xFF & udd_g_ctrlreq.req.wValue))
	&& (sizeof(udi_hid_generic_battery1_report_feature) ==
	udd_g_ctrlreq.req.wLength)) {
		// Feature type on report ID 0
		udd_g_ctrlreq.payload =
		(uint8_t *) & udi_hid_generic_battery1_report_feature;
		udd_g_ctrlreq.callback = udi_hid_generic_battery1_setfeature_valid;
		udd_g_ctrlreq.payload_size =
		sizeof(udi_hid_generic_battery1_report_feature);
		return true;
	}
	return false;
}

static bool udi_hid_generic_battery2_setreport(void)
{
	if ((USB_HID_REPORT_TYPE_FEATURE == (udd_g_ctrlreq.req.wValue >> 8))
	&& (0 == (0xFF & udd_g_ctrlreq.req.wValue))
	&& (sizeof(udi_hid_generic_battery2_report_feature) ==
	udd_g_ctrlreq.req.wLength)) {
		// Feature type on report ID 0
		udd_g_ctrlreq.payload =
		(uint8_t *) & udi_hid_generic_battery2_report_feature;
		udd_g_ctrlreq.callback = udi_hid_generic_battery2_setfeature_valid;
		udd_g_ctrlreq.payload_size =
		sizeof(udi_hid_generic_battery2_report_feature);
		return true;
	}
	return false;
}

static bool udi_hid_generic_battery3_setreport(void)
{
	if ((USB_HID_REPORT_TYPE_FEATURE == (udd_g_ctrlreq.req.wValue >> 8))
	&& (0 == (0xFF & udd_g_ctrlreq.req.wValue))
	&& (sizeof(udi_hid_generic_battery3_report_feature) ==
	udd_g_ctrlreq.req.wLength)) {
		// Feature type on report ID 0
		udd_g_ctrlreq.payload =
		(uint8_t *) & udi_hid_generic_battery3_report_feature;
		udd_g_ctrlreq.callback = udi_hid_generic_battery3_setfeature_valid;
		udd_g_ctrlreq.payload_size =
		sizeof(udi_hid_generic_battery3_report_feature);
		return true;
	}
	return false;
}

static bool udi_hid_generic_battery4_setreport(void)
{
	if ((USB_HID_REPORT_TYPE_FEATURE == (udd_g_ctrlreq.req.wValue >> 8))
	&& (0 == (0xFF & udd_g_ctrlreq.req.wValue))
	&& (sizeof(udi_hid_generic_battery4_report_feature) ==
	udd_g_ctrlreq.req.wLength)) {
		// Feature type on report ID 0
		udd_g_ctrlreq.payload =
		(uint8_t *) & udi_hid_generic_battery4_report_feature;
		udd_g_ctrlreq.callback = udi_hid_generic_battery4_setfeature_valid;
		udd_g_ctrlreq.payload_size =
		sizeof(udi_hid_generic_battery4_report_feature);
		return true;
	}
	return false;
}

static bool udi_hid_generic_battery5_setreport(void)
{
	if ((USB_HID_REPORT_TYPE_FEATURE == (udd_g_ctrlreq.req.wValue >> 8))
	&& (0 == (0xFF & udd_g_ctrlreq.req.wValue))
	&& (sizeof(udi_hid_generic_battery5_report_feature) ==
	udd_g_ctrlreq.req.wLength)) {
		// Feature type on report ID 0
		udd_g_ctrlreq.payload =
		(uint8_t *) & udi_hid_generic_battery5_report_feature;
		udd_g_ctrlreq.callback = udi_hid_generic_battery5_setfeature_valid;
		udd_g_ctrlreq.payload_size =
		sizeof(udi_hid_generic_battery5_report_feature);
		return true;
	}
	return false;
}

static bool udi_hid_generic_battery6_setreport(void)
{
	if ((USB_HID_REPORT_TYPE_FEATURE == (udd_g_ctrlreq.req.wValue >> 8))
	&& (0 == (0xFF & udd_g_ctrlreq.req.wValue))
	&& (sizeof(udi_hid_generic_battery6_report_feature) ==
	udd_g_ctrlreq.req.wLength)) {
		// Feature type on report ID 0
		udd_g_ctrlreq.payload =
		(uint8_t *) & udi_hid_generic_battery6_report_feature;
		udd_g_ctrlreq.callback = udi_hid_generic_battery6_setfeature_valid;
		udd_g_ctrlreq.payload_size =
		sizeof(udi_hid_generic_battery6_report_feature);
		return true;
	}
	return false;
}
//--------------------------------------------
//------ Interface for application

bool udi_hid_generic_charger_send_report_in(uint8_t *data)
{
	if (!udi_hid_generic_b_charger_report_in_free)
		return false;
	irqflags_t flags = cpu_irq_save();
	// Fill report
	memset(&udi_hid_generic_charger_report_in, 0,
		sizeof(udi_hid_generic_charger_report_in));
	memcpy(&udi_hid_generic_charger_report_in, data,
		sizeof(udi_hid_generic_charger_report_in));
	udi_hid_generic_b_charger_report_in_free =
	!udd_ep_run(UDI_HID_GENERIC_CHARGER_EP_IN,
		false,
		(uint8_t *) & udi_hid_generic_charger_report_in,
		sizeof(udi_hid_generic_charger_report_in),
		udi_hid_generic_charger_report_in_sent);
	cpu_irq_restore(flags);
	return !udi_hid_generic_b_charger_report_in_free;
}

bool udi_hid_generic_battery1_send_report_in(uint8_t *data)
{
	if (!udi_hid_generic_b_battery1_report_in_free)
		return false;
	irqflags_t flags = cpu_irq_save();
	// Fill report
	memset(&udi_hid_generic_battery1_report_in, 0,
		sizeof(udi_hid_generic_battery1_report_in));
	memcpy(&udi_hid_generic_battery1_report_in, data,
		sizeof(udi_hid_generic_battery1_report_in));
	udi_hid_generic_b_battery1_report_in_free =
	!udd_ep_run(UDI_HID_GENERIC_BATTERY1_EP_IN,
		false,
		(uint8_t *) & udi_hid_generic_battery1_report_in,
		sizeof(udi_hid_generic_battery1_report_in),
		udi_hid_generic_battery1_report_in_sent);
	cpu_irq_restore(flags);
	return !udi_hid_generic_b_battery1_report_in_free;
}

bool udi_hid_generic_battery2_send_report_in(uint8_t *data)
{
	if (!udi_hid_generic_b_battery2_report_in_free)
		return false;
	irqflags_t flags = cpu_irq_save();
	// Fill report
	memset(&udi_hid_generic_battery2_report_in, 0,
		sizeof(udi_hid_generic_battery2_report_in));
	memcpy(&udi_hid_generic_battery2_report_in, data,
		sizeof(udi_hid_generic_battery2_report_in));
	udi_hid_generic_b_battery2_report_in_free =
	!udd_ep_run(UDI_HID_GENERIC_BATTERY2_EP_IN,
		false,
	(uint8_t *) & udi_hid_generic_battery2_report_in,
		sizeof(udi_hid_generic_battery2_report_in),
		udi_hid_generic_battery2_report_in_sent);
	cpu_irq_restore(flags);
	return !udi_hid_generic_b_battery2_report_in_free;
}

bool udi_hid_generic_battery3_send_report_in(uint8_t *data)
{
	if (!udi_hid_generic_b_battery3_report_in_free)
		return false;
	irqflags_t flags = cpu_irq_save();
	// Fill report
	memset(&udi_hid_generic_battery3_report_in, 0,
		sizeof(udi_hid_generic_battery3_report_in));
	memcpy(&udi_hid_generic_battery3_report_in, data,
		sizeof(udi_hid_generic_battery3_report_in));
	udi_hid_generic_b_battery3_report_in_free =
	!udd_ep_run(UDI_HID_GENERIC_BATTERY3_EP_IN,
			false,
			(uint8_t *) & udi_hid_generic_battery3_report_in,
			sizeof(udi_hid_generic_battery3_report_in),
			udi_hid_generic_battery3_report_in_sent);
	cpu_irq_restore(flags);
	return !udi_hid_generic_b_battery3_report_in_free;
}

bool udi_hid_generic_battery4_send_report_in(uint8_t *data)
{
	if (!udi_hid_generic_b_battery4_report_in_free)
		return false;
	irqflags_t flags = cpu_irq_save();
	// Fill report
	memset(&udi_hid_generic_battery4_report_in, 0,
		sizeof(udi_hid_generic_battery4_report_in));
	memcpy(&udi_hid_generic_battery4_report_in, data,
		sizeof(udi_hid_generic_battery4_report_in));
	udi_hid_generic_b_battery4_report_in_free =
		!udd_ep_run(UDI_HID_GENERIC_BATTERY4_EP_IN,
		false,
		(uint8_t *) & udi_hid_generic_battery4_report_in,
		sizeof(udi_hid_generic_battery4_report_in),
		udi_hid_generic_battery4_report_in_sent);
	cpu_irq_restore(flags);
	return !udi_hid_generic_b_battery4_report_in_free;
}

bool udi_hid_generic_battery5_send_report_in(uint8_t *data)
{
	if (!udi_hid_generic_b_battery5_report_in_free)
		return false;
	irqflags_t flags = cpu_irq_save();
	// Fill report
	memset(&udi_hid_generic_battery5_report_in, 0,
		sizeof(udi_hid_generic_battery5_report_in));
	memcpy(&udi_hid_generic_battery5_report_in, data,
		sizeof(udi_hid_generic_battery5_report_in));
	udi_hid_generic_b_battery5_report_in_free =
		!udd_ep_run(UDI_HID_GENERIC_BATTERY5_EP_IN,
		false,
		(uint8_t *) & udi_hid_generic_battery5_report_in,
		sizeof(udi_hid_generic_battery5_report_in),
		udi_hid_generic_battery5_report_in_sent);
	cpu_irq_restore(flags);
	return !udi_hid_generic_b_battery5_report_in_free;
}

bool udi_hid_generic_battery6_send_report_in(uint8_t *data)
{
	if (!udi_hid_generic_b_battery6_report_in_free)
		return false;
	irqflags_t flags = cpu_irq_save();
	// Fill report
	memset(&udi_hid_generic_battery6_report_in, 0,
		sizeof(udi_hid_generic_battery6_report_in));
	memcpy(&udi_hid_generic_battery6_report_in, data,
		sizeof(udi_hid_generic_battery6_report_in));
	udi_hid_generic_b_battery6_report_in_free =
		!udd_ep_run(UDI_HID_GENERIC_BATTERY6_EP_IN,
		false,
		(uint8_t *) & udi_hid_generic_battery6_report_in,
		sizeof(udi_hid_generic_battery6_report_in),
		udi_hid_generic_battery6_report_in_sent);
	cpu_irq_restore(flags);
	return !udi_hid_generic_b_battery6_report_in_free;
}

//--------------------------------------------
//------ Internal routines

static void udi_hid_generic_charger_setfeature_valid(void)
{
	if (sizeof(udi_hid_generic_charger_report_feature) != udd_g_ctrlreq.payload_size)
	return;	// Bad data
	UDI_HID_GENERIC_CHARGER_SET_FEATURE(udi_hid_generic_charger_report_feature);
}

static void udi_hid_generic_battery1_setfeature_valid(void)
{
	if (sizeof(udi_hid_generic_battery1_report_feature) != udd_g_ctrlreq.payload_size)
	return;	// Bad data
	UDI_HID_GENERIC_BATTERY1_SET_FEATURE(udi_hid_generic_battery1_report_feature);
}

static void udi_hid_generic_battery2_setfeature_valid(void)
{
	if (sizeof(udi_hid_generic_battery2_report_feature) != udd_g_ctrlreq.payload_size)
	return;	// Bad data
	UDI_HID_GENERIC_BATTERY2_SET_FEATURE(udi_hid_generic_battery2_report_feature);
}

static void udi_hid_generic_battery3_setfeature_valid(void)
{
	if (sizeof(udi_hid_generic_battery3_report_feature) != udd_g_ctrlreq.payload_size)
	return;	// Bad data
	UDI_HID_GENERIC_BATTERY3_SET_FEATURE(udi_hid_generic_battery3_report_feature);
}

static void udi_hid_generic_battery4_setfeature_valid(void)
{
	if (sizeof(udi_hid_generic_battery4_report_feature) != udd_g_ctrlreq.payload_size)
	return;	// Bad data
	UDI_HID_GENERIC_BATTERY4_SET_FEATURE(udi_hid_generic_battery4_report_feature);
}

static void udi_hid_generic_battery5_setfeature_valid(void)
{
	if (sizeof(udi_hid_generic_battery5_report_feature) != udd_g_ctrlreq.payload_size)
	return;	// Bad data
	UDI_HID_GENERIC_BATTERY5_SET_FEATURE(udi_hid_generic_battery5_report_feature);
}

static void udi_hid_generic_battery6_setfeature_valid(void)
{
	if (sizeof(udi_hid_generic_battery6_report_feature) != udd_g_ctrlreq.payload_size)
	return;	// Bad data
	UDI_HID_GENERIC_BATTERY6_SET_FEATURE(udi_hid_generic_battery6_report_feature);
}

#ifndef HID_GENERIC_SINGLE_IN_ENDPOINT
static void udi_hid_generic_report_out_received(udd_ep_status_t status,
		iram_size_t nb_received, udd_ep_id_t ep)
{
	UNUSED(ep);
	if (UDD_EP_TRANSFER_OK != status)
	return;	// Abort reception

	if (sizeof(udi_hid_generic_report_out) == nb_received) {
		UDI_HID_GENERIC_REPORT_OUT(udi_hid_generic_report_out);
	}
	udi_hid_generic_report_out_enable();
}


static bool udi_hid_generic_report_out_enable(void)
{
	return udd_ep_run(UDI_HID_GENERIC_EP_OUT,
	false,
	(uint8_t *) & udi_hid_generic_report_out,
	sizeof(udi_hid_generic_report_out),
	udi_hid_generic_report_out_received);
}
#endif

static void udi_hid_generic_charger_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep)
{
	UNUSED(status);
	UNUSED(nb_sent);
	UNUSED(ep);
	udi_hid_generic_b_charger_report_in_free = true;
}

static void udi_hid_generic_battery1_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep)
{
	UNUSED(status);
	UNUSED(nb_sent);
	UNUSED(ep);
	udi_hid_generic_b_battery1_report_in_free = true;
}

static void udi_hid_generic_battery2_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep)
{
	UNUSED(status);
	UNUSED(nb_sent);
	UNUSED(ep);
	udi_hid_generic_b_battery2_report_in_free = true;
}

static void udi_hid_generic_battery3_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep)
{
	UNUSED(status);
	UNUSED(nb_sent);
	UNUSED(ep);
	udi_hid_generic_b_battery3_report_in_free = true;
}

static void udi_hid_generic_battery4_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep)
{
	UNUSED(status);
	UNUSED(nb_sent);
	UNUSED(ep);
	udi_hid_generic_b_battery4_report_in_free = true;
}

static void udi_hid_generic_battery5_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep)
{
	UNUSED(status);
	UNUSED(nb_sent);
	UNUSED(ep);
	udi_hid_generic_b_battery5_report_in_free = true;
}

static void udi_hid_generic_battery6_report_in_sent(udd_ep_status_t status,
		iram_size_t nb_sent, udd_ep_id_t ep)
{
	UNUSED(status);
	UNUSED(nb_sent);
	UNUSED(ep);
	udi_hid_generic_b_battery6_report_in_free = true;
}
#endif
//@}
