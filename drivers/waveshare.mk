ROOT_DIR := $(dir $(firstword $(MAKEFILE_LIST)))
DRIVER_DIR := $(ROOT_DIR)/drivers

CONFIG := $(DRIVER_DIR)/user/waveshare_config
EPAPER := $(DRIVER_DIR)/waveshare/e-Paper
FONTS := $(DRIVER_DIR)/waveshare/Fonts
GUI := $(DRIVER_DIR)/waveshare/GUI

SRC_FILES += \
  $(wildcard $(CONFIG)/*.c) \
  $(wildcard $(EPAPER)/*.c) \
  $(wildcard $(FONTS)/*.c) \
  $(wildcard $(GUI)/*.c) \

INC_FOLDERS += \
  $(EPAPER) \
  $(CONFIG) \
  $(FONTS) \
  $(GUI) \

  