# NRF Development

An embedded development environment for [Nordic Semiconductors](https://www.nordicsemi.com) nRF5 BLE chip.

## Features

- **Environment**: to ensure reproducible builds this repository uses a `Dockerfile` to set up the development environment and the embedded toolchain using a Linux distribution (Ubuntu 18.04). An envirmonemnt script `nrf-env.sh` gives access to the repository inside the development environment (see [Commands](#Commands))
- **Software Development Kit**: the development environment automatically downloads the [nRF5 SDK](https://www.nordicsemi.com/Software-and-tools/Software/nRF5-SDK) and places it in `/sdk/`
- **Unit Testing**: the Embedded Test Driven Development framework [ceedling](http://www.throwtheswitch.org/ceedling) is installed, unit tests can be added to the `test` folder.  


## Installation

- [Install Docker](https://docs.docker.com/get-started/#install-docker-desktop)
- Clone the repository: `git clone https://www.github.com/d-asnaghi/nrf-development`
- Move into its directory: `cd nrf-development`
- Enable execution of the environment script: `chmod 755 nrf-env.sh` 
- Run compilation command: `./nrf-env.sh make` 

## Usage

Any command appended after the environment script will run inside the development environment. To run `<command>` type `nrf-env.sh <command>`

Some common commands are:

- Compile: `./nrf-env.sh make`
- Test `module.c`: `./nrf-env.sh ceedling test:module`
- Test all modules: `./nrf-env.sh ceedling test:all`

