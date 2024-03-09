/*
 * multi_hid_generic.c
 *
 * Created: 2015/9/13 下午 05:35:41
 *  Author: LaBest FAE
 */ 
#include <asf.h>
#include "multi_hid_generic.h"

void main_suspend_action(void)
{
}

void main_resume_action(void)
{
}

void main_sof_action(void)
{
}

void main_remotewakeup_enable(void)
{
}

void main_remotewakeup_disable(void)
{
}
#ifndef MULTI_HID_GENERIC
bool main_extra_string(void)
{
	static uint8_t udi_hid_generic_name[] = "HID generic interface";
	struct extra_strings_desc_t
	{
		usb_str_desc_t header;
		le16_t string[sizeof(udi_hid_generic_name)-1];
	};
	static UDC_DESC_STORAGE struct extra_strings_desc_t extra_strings_desc =
	{
		.header.bDescriptorType = USB_DT_STRING
	};

	uint8_t i;
	uint8_t *str;
	uint8_t str_lgt=0;

	// Link payload pointer to the string corresponding at request
	switch (udd_g_ctrlreq.req.wValue & 0xff)
	{
		case UDI_HID_GENERIC_STRING_ID:
		str_lgt = sizeof(udi_hid_generic_name)-1;
		str = udi_hid_generic_name;
		break;
		default:
		return false;
	}

	if (str_lgt!=0)
	{
		for( i=0; i<str_lgt; i++)
		{
			extra_strings_desc.string[i] = cpu_to_le16((le16_t)str[i]);
		}
		extra_strings_desc.header.bLength = 2 + (str_lgt) * 2;
		udd_g_ctrlreq.payload_size = extra_strings_desc.header.bLength;
		udd_g_ctrlreq.payload = (uint8_t *) &extra_strings_desc;
	}

	// if the string is larger than request length, then cut it
	if (udd_g_ctrlreq.payload_size > udd_g_ctrlreq.req.wLength)
	{
		udd_g_ctrlreq.payload_size = udd_g_ctrlreq.req.wLength;
	}
	return true;
}
#else
bool main_extra_string(void)
{
	static uint8_t udi_hid_generic_charger_name[] = "HID Generic Charger";
	static uint8_t udi_hid_generic_battery1_name[] = "HID Generic Battery1";
	static uint8_t udi_hid_generic_battery2_name[] = "HID Generic Battery2";
	static uint8_t udi_hid_generic_battery3_name[] = "HID Generic Battery3";
	static uint8_t udi_hid_generic_battery4_name[] = "HID Generic Battery4";
	static uint8_t udi_hid_generic_battery5_name[] = "HID Generic Battery5";
	static uint8_t udi_hid_generic_battery6_name[] = "HID Generic Battery6";
	struct extra_strings_desc_t
	{
		usb_str_desc_t header;
		le16_t string[Max(Max(Max(
		Max(sizeof(udi_hid_generic_charger_name) - 1 , sizeof(udi_hid_generic_battery1_name) - 1), \
		Max(sizeof(udi_hid_generic_battery2_name) - 1 , sizeof(udi_hid_generic_battery3_name) - 1)), \
		Max(sizeof(udi_hid_generic_battery4_name) - 1 , sizeof(udi_hid_generic_battery5_name) - 1)), \
		sizeof(udi_hid_generic_battery6_name) - 1)];
	};
	static UDC_DESC_STORAGE struct extra_strings_desc_t extra_strings_desc =
	{
		.header.bDescriptorType = USB_DT_STRING
	};

	uint8_t i;
	uint8_t *str;
	uint8_t str_lgt=0;

	// Link payload pointer to the string corresponding at request
	switch (udd_g_ctrlreq.req.wValue & 0xff)
	{
		case UDI_HID_GENERIC_CHARGER_STRING_ID:
		str_lgt = sizeof(udi_hid_generic_charger_name) - 1;
		str = udi_hid_generic_charger_name;
		break;
		
		case UDI_HID_GENERIC_BATTERY1_STRING_ID:
		str_lgt = sizeof(udi_hid_generic_battery1_name) - 1;
		str = udi_hid_generic_battery1_name;
		break;
		
		case UDI_HID_GENERIC_BATTERY2_STRING_ID:
		str_lgt = sizeof(udi_hid_generic_battery2_name)-1;
		str = udi_hid_generic_battery2_name;
		break;
		
		case UDI_HID_GENERIC_BATTERY3_STRING_ID:
		str_lgt = sizeof(udi_hid_generic_battery3_name) - 1;
		str = udi_hid_generic_battery3_name;
		break;
		
		case UDI_HID_GENERIC_BATTERY4_STRING_ID:
		str_lgt = sizeof(udi_hid_generic_battery4_name) - 1;
		str = udi_hid_generic_battery4_name;
		break;
		
		case UDI_HID_GENERIC_BATTERY5_STRING_ID:
		str_lgt = sizeof(udi_hid_generic_battery5_name) - 1;
		str = udi_hid_generic_battery5_name;
		break;
		
		case UDI_HID_GENERIC_BATTERY6_STRING_ID:
		str_lgt = sizeof(udi_hid_generic_battery6_name) - 1;
		str = udi_hid_generic_battery6_name;
		break;
		
		default:
		return false;
	}

	if (str_lgt!=0)
	{
		for( i=0; i<str_lgt; i++)
		{
			extra_strings_desc.string[i] = cpu_to_le16((le16_t)str[i]);
		}
		extra_strings_desc.header.bLength = 2 + (str_lgt) * 2;
		udd_g_ctrlreq.payload_size = extra_strings_desc.header.bLength;
		udd_g_ctrlreq.payload = (uint8_t *) &extra_strings_desc;
	}

	// if the string is larger than request length, then cut it
	if (udd_g_ctrlreq.payload_size > udd_g_ctrlreq.req.wLength)
	{
		udd_g_ctrlreq.payload_size = udd_g_ctrlreq.req.wLength;
	}
	return true;
}
#endif

#ifndef MULTI_HID_GENERIC
bool main_generic_enable(void)
{
	main_b_generic_enable = true;
	return true;
}

void main_generic_disable(void)
{
	main_b_generic_enable = false;
}

void main_hid_set_feature(uint8_t* report)
{
}
#else
bool main_generic_charger_enable(void)
{
	main_b_generic_charger_enable = true;
	return true;
}

bool main_generic_battery1_enable(void)
{
	main_b_generic_battery1_enable = true;
	return true;
}

bool main_generic_battery2_enable(void)
{
	main_b_generic_battery2_enable = true;
	return true;
}

bool main_generic_battery3_enable(void)
{
	main_b_generic_battery3_enable = true;
	return true;
}

bool main_generic_battery4_enable(void)
{
	main_b_generic_battery4_enable = true;
	return true;
}

bool main_generic_battery5_enable(void)
{
	main_b_generic_battery5_enable = true;
	return true;
}

bool main_generic_battery6_enable(void)
{
	main_b_generic_battery6_enable = true;
	return true;
}

void main_generic_charger_disable(void)
{
	main_b_generic_charger_enable = false;
}

void main_generic_battery1_disable(void)
{
	main_b_generic_battery1_enable = false;
}

void main_generic_battery2_disable(void)
{
	main_b_generic_battery2_enable = false;
}

void main_generic_battery3_disable(void)
{
	main_b_generic_battery3_enable = false;
}

void main_generic_battery4_disable(void)
{
	main_b_generic_battery4_enable = false;
}

void main_generic_battery5_disable(void)
{
	main_b_generic_battery5_enable = false;
}

void main_generic_battery6_disable(void)
{
	main_b_generic_battery6_enable = false;
}

void main_hid_charger_set_feature(uint8_t* report)
{
}

void main_hid_battery1_set_feature(uint8_t* report)
{
}

void main_hid_battery2_set_feature(uint8_t* report)
{
}

void main_hid_battery3_set_feature(uint8_t* report)
{
}

void main_hid_battery4_set_feature(uint8_t* report)
{
}

void main_hid_battery5_set_feature(uint8_t* report)
{
}

void main_hid_battery6_set_feature(uint8_t* report)
{
}
#endif