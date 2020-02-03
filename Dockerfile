
FROM ubuntu:18.04

MAINTAINER Davide Asnaghi "https://github.com/d-asnaghi"

# Install required packages
RUN apt-get update
RUN apt-get install -y git gcc gcc-arm-none-eabi ruby wget unzip make

# Install ceedling
RUN gem install ceedling

# Install the Nordic SDK
WORKDIR /sdk
RUN wget https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v16.x.x/nRF5_SDK_16.0.0_98a08e2.zip
RUN unzip nRF5_SDK_16.0.0_98a08e2.zip && rm nRF5_SDK_16.0.0_98a08e2.zip

# Install the Nordic command line tools
WORKDIR /tools
RUN wget https://www.nordicsemi.com/-/media/Software-and-other-downloads/Desktop-software/nRF-command-line-tools/sw/Versions-10-x-x/nRFCommandLineTools1060Linuxamd64tar.gz
RUN tar -xvf nRFCommandLineTools1060Linuxamd64tar.gz && rm nRFCommandLineTools1060Linuxamd64tar.gz
RUN dpkg -i --force-overwrite nRF-Command-Line-Tools_10_6_0_Linux-amd64.deb
RUN dpkg -i --force-overwrite JLink_Linux_V660e_x86_64.deb

# Current working directory
WORKDIR /app

