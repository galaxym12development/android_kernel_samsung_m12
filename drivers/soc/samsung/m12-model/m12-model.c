// SPDX-License-Identifier: GPL-2.0
/*
 * Galaxy M12 per-model device tree overlay
 *
 * Copyright (C) 2026 The galaxym12development Project
 */

#define pr_fmt(fmt) "m12-model: " fmt

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/of.h>
#include <linux/string.h>

#define MODEL_DTB(sym)						\
	extern u8 __dtb_##sym##_begin[];			\
	extern u8 __dtb_##sym##_end[]

MODEL_DTB(sm_m127f);
MODEL_DTB(sm_m127g);
MODEL_DTB(sm_m127n);

#define MODEL(_name, sym)					\
	{ _name, __dtb_##sym##_begin, __dtb_##sym##_end }

static const struct m12_model {
	const char *name;
	const u8 *begin;
	const u8 *end;
} m12_models[] __initconst = {
	MODEL("SM-M127F", sm_m127f),
	MODEL("SM-M127G", sm_m127g),
	MODEL("SM-M127N", sm_m127n),
};

static char em_model[32] __initdata;

static int __init em_model_setup(char *str)
{
	strlcpy(em_model, str, sizeof(em_model));
	return 1;
}
__setup("androidboot.em.model=", em_model_setup);

static int __init m12_model_init(void)
{
	const struct m12_model *m;
	struct device_node *np;
	int i, id, ret;

	np = of_find_node_by_path("/model_overlay");
	if (!np)
		return 0;
	of_node_put(np);

	for (i = 0; i < ARRAY_SIZE(m12_models); i++) {
		m = &m12_models[i];
		if (!strncmp(em_model, m->name, strlen(m->name)))
			break;
	}
	if (i == ARRAY_SIZE(m12_models)) {
		pr_err("no overlay for model '%s'\n", em_model);
		return 0;
	}

	ret = of_overlay_fdt_apply(m->begin, m->end - m->begin, &id);
	if (ret)
		pr_err("%s: failed to apply overlay: %d\n", m->name, ret);
	else
		pr_info("%s: overlay applied\n", m->name);

	return 0;
}
arch_initcall(m12_model_init);
