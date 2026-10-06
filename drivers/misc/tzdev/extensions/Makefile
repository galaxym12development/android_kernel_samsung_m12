obj-$(CONFIG_TZDEV_BOOST)	+= boost.o
obj-$(CONFIG_TZDEV_HOTPLUG)	+= hotplug.o
obj-$(CONFIG_TZIRS)		+= irs.o

ifeq ($(CONFIG_SOC_EXYNOS9830), y)
ccflags-y += -DTZDEV_BOOST_CLUSTER_2
else ifeq ($(CONFIG_SOC_EXYNOS9820), y)
ccflags-y += -DTZDEV_BOOST_CLUSTER_2
else ifeq ($(CONFIG_SOC_EXYNOS9630), y)
ccflags-y += -DTZDEV_BOOST_CLUSTER_1
else ifeq ($(CONFIG_SOC_EXYNOS9610), y)
ccflags-y += -DTZDEV_BOOST_CLUSTER_1
else ifeq ($(CONFIG_SOC_EXYNOS7885), y)
ccflags-y += -DTZDEV_BOOST_CLUSTER_1
else ifeq ($(CONFIG_SOC_EXYNOS3830), y)
ccflags-y += -DTZDEV_BOOST_CLUSTER_1
else ifeq ($(CONFIG_ARCH_RANCHU), y)
else
ccflags-y += -DTZDEV_BOOST_CLUSTER_1
endif
