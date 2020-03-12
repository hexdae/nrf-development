SELF_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

CONFIG := $(SELF_DIR)/waveshare/Config
EPAPER := $(SELF_DIR)/waveshare/e-Paper
FONTS := $(SELF_DIR)/waveshare/Fonts
GUI := $(SELF_DIR)/waveshare/GUI
EXAMPLES := $(SELF_DIR)/waveshare/Examples

SRC_FILES += \
  $(wildcard $(CONFIG)/*.c) \
  $(wildcard $(EPAPER)/*.c) \
  $(wildcard $(FONTS)/*.c) \
  $(wildcard $(GUI)/*.c) \
  $(wildcard $(EXAMPLES)/*.c) \

INC_FOLDERS += \
  $(EPAPER) \
  $(CONFIG) \
  $(FONTS) \
  $(GUI) \
  $(EXAMPLES) \

  