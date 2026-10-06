obj-y += is-helper-i2c.o
obj-$(CONFIG_EXYNOS_DEVICE_MIPI_CSIS_VER4) += csi2/

obj-$(CONFIG_VIDEO_EXYNOS_PABLO_ISP) += module_framework/ \
					module_framework/i2c_dummy/ \
					module_framework/modules/ \
					module_framework/cis/ \
					module_framework/actuator/ \
					module_framework/flash/


EXTRA_CFLAGS += -Idrivers/media/platform/exynos/camera
EXTRA_CFLAGS += -Idrivers/media/platform/exynos/camera/include
EXTRA_CFLAGS += -Idrivers/media/platform/exynos/camera/vendor
