#
#  Makefile for Exynos-Debug
#

obj-$(CONFIG_EXYNOS_CORESIGHT)		+= exynos-coresight.o
ifeq ($(CONFIG_SOC_EXYNOS3830),y)
obj-$(CONFIG_EXYNOS_ITMON)		+= exynos3830-itmon.o
endif
ifeq ($(CONFIG_DEBUG_SNAPSHOT),y)
obj-$(CONFIG_ARCH_EXYNOS)		+= exynos-helper.o
obj-$(CONFIG_ARCH_EXYNOS)		+= exynos-handler.o

endif
obj-$(CONFIG_EXYNOS_DEBUG_TEST)         += exynos-debug-test.o
