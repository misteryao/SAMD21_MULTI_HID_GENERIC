/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include <string.h>
#include "main.h"
#include "multi_hid_generic.h"

int main (void)
{
	system_init();
	delay_init();
	// Start USB stack to authorize VBus monitoring
	udc_start();
	memset(ui_hid_charger_in_report, 1, sizeof(ui_hid_charger_in_report));
	memset(ui_hid_battery1_in_report, 2, sizeof(ui_hid_battery1_in_report));
	memset(ui_hid_battery2_in_report, 3, sizeof(ui_hid_battery2_in_report));
	memset(ui_hid_battery3_in_report, 4, sizeof(ui_hid_battery3_in_report));
	memset(ui_hid_battery4_in_report, 5, sizeof(ui_hid_battery4_in_report));
	memset(ui_hid_battery5_in_report, 6, sizeof(ui_hid_battery5_in_report));
	memset(ui_hid_battery6_in_report, 7, sizeof(ui_hid_battery6_in_report));
	/* Insert application code here, after the board has been initialized. */
	while(1)
	{
		udi_hid_generic_charger_send_report_in(ui_hid_charger_in_report);
		udi_hid_generic_battery1_send_report_in(ui_hid_battery1_in_report);
		udi_hid_generic_battery2_send_report_in(ui_hid_battery2_in_report);
		udi_hid_generic_battery3_send_report_in(ui_hid_battery3_in_report);
		udi_hid_generic_battery4_send_report_in(ui_hid_battery4_in_report);
		udi_hid_generic_battery5_send_report_in(ui_hid_battery5_in_report);
		udi_hid_generic_battery6_send_report_in(ui_hid_battery6_in_report);
		delay_s(1);
	}
}
