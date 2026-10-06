# SPDX-License-Identifier: GPL-2.0
#
# Makefile for nfc devices
#

ifeq ($(CONFIG_SAMSUNG_NFC),m)
obj-$(CONFIG_SAMSUNG_NFC)		+= nfc_sec.o
nfc_sec-$(CONFIG_SEC_NFC)		+= sec_nfc.o
nfc_sec-$(CONFIG_SEC_NFC_LOGGER)	+= nfc_logger/nfc_logger.o
else
obj-$(CONFIG_SEC_NFC)			+= sec_nfc.o
obj-$(CONFIG_SEC_NFC_LOGGER)		+= nfc_logger/nfc_logger.o
endif
ccflags-$(CONFIG_NFC_DEBUG) := -DDEBUG

