#ifndef _LINUX_PCA953X_H
#define _LINUX_PCA953X_H

#include <linux/types.h>
#include <linux/i2c.h>

/* platform data for the PCA9539 16-bit I/O expander driver */

struct pca953x_platform_data {
	/* number of the first GPIO */
	unsigned	gpio_base;

	/* initial polarity inversion setting */
	u32		invert;

	/* interrupt base */
	int		irq_base;

	void		*context;	/* param to setup/teardown */

	int		(*setup)(struct i2c_client *client,
				unsigned gpio, unsigned ngpio,
				void *context);
	int		(*teardown)(struct i2c_client *client,
				unsigned gpio, unsigned ngpio,
				void *context);
	const char	*const *names;
};

#ifdef CONFIG_ARCH_AM335X_ADVANTECH	
int ext_pca953x_gpio_get_value(unsigned off);
int ext_pca953x_gpio_get_output_value(unsigned off);
int ext_pca953x_gpio_get_direction(unsigned off);
#endif

#endif /* _LINUX_PCA953X_H */
