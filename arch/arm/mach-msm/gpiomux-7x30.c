/* Copyright (c) 2010, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#include <asm/mach-types.h>
#include <mach/gpio.h>
#include <mach/gpiomux.h>
#include <mach/socinfo.h>
#include "devices.h"

static struct gpiomux_setting akm_int_sus_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
	.dir = GPIOMUX_IN,
};

static struct msm_gpiomux_config ancora_standard_configs[] __initdata = {
	{
		/* AKM_INT */
		.gpio = 180,
		.settings = {
			[GPIOMUX_SUSPENDED]	= &akm_int_sus_cfg,
		},
	},
};


static int __init gpiomux_init(void)
{
	return msm_gpiomux_init(NR_GPIO_IRQS);

	msm_gpiomux_install(ancora_standard_configs,
			ARRAY_SIZE(ancora_standard_configs));
}
postcore_initcall(gpiomux_init);
