### Drivers

This folder is a container for drivers that use the HAL.

#### Usage

Create a folder for a `driver` that contains its source code

```bash
drivers
├── README.md
└── my_driver
    ├── inc
    └── src
```

Create a Makefile for the driver:

```bash
drivers
├── README.md
├── my_driver.mk
└── my_driver
    ├── inc
    └── src
```

Use `my_driver.mk` to add to the `SRC_FILES` and `INC_FOLDERS` make variables

```Make
ROOT_DIR := $(dir $(firstword $(MAKEFILE_LIST)))
DRIVER_DIR = ROOT_DIR/drivers/my_driver

SRC := $(DRIVER_DIR)/src
INC := $(DRIVER_DIR)/inc

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

### Configuration files
Most drivers will include some files that might be needed for configuring the driver interface on a specific platform.

In order to avoid modifying the source files of th driver, it is usually good practice to create an external folder with a copy of the configuration files and point the driver's makefile to it instead. This is the purpose of the `user` folder.  

```bash
drivers
├── README.md
├── my_driver.mk
├── my_driver
│   ├── inc
│   └── src
└── user
    └── my_driver_config
    	└── ...
```

