### Drivers

This folder is a container for drivers that use the HAL.

#### Usage

Create a folder for a `driver` that contains its source code

```bash
drivers
├── README.md
└── my_driver
    ├── int
    └── src
```

Create a Makefile for the driver:

```bash
drivers
├── README.md
├── my_driver.mk
└── my_driver
    ├── int
    └── src
```

Use `my_driver.mk` to add to the `SRC_FILES` and `INC_FOLDERS` make variables

```Make
SELF_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

SRC := $(SELF_DIR)/my_driver/src
INC := $(SELF_DIR)/my_driver/inc

SRC_FILES += \
  $(wildcard $(SRC)/*.c) \

INC_FOLDERS += \
  $(INC) \

```

Now just include `my_driver.mk` in the general `Makefile`:

```Make
include drivers/my_driver.mk
...
```
