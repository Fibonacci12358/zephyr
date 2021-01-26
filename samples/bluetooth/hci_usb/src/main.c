/*
 * Copyright (c) 2018 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
#include <usb/usb_device.h>
#include <bluetooth/controller.h>

void main(void)
{
	int ret;
  uint8_t* addr;

  addr = (uint8_t*) &NRF_FICR->DEVICEADDR[0];

  bt_ctlr_set_public_addr(addr);

	ret = usb_enable(NULL);
	if (ret != 0) {
		printk("Failed to enable USB");
		return;
	}

	printk("Bluetooth over USB sample\n");
}
