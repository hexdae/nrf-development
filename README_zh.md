# NRF开发

[北欧半导体](https://www.nordicsemi.com) nRF5 BLE芯片的嵌入式开发环境。

## 特征

- **环境** ：为确保可复制的构建，该存储库使用`Dockerfile`来设置开发环境，并使用Linux发行版（Ubuntu 18.04）来嵌入嵌入式工具链。一个环境脚本`nrf-env.sh`可以访问开发环境中的存储库（请参阅[命令](#Commands) ）
- **软件开发套件** ：开发环境会自动下载[nRF5 SDK](https://www.nordicsemi.com/Software-and-tools/Software/nRF5-SDK)并将其放在`/sdk/`
- **单元测试** ：嵌入式测试驱动开发框架[ceedling](http://www.throwtheswitch.org/ceedling)安装，单元测试可以被添加到`test`文件夹中。

## 安装

- [安装Docker](https://docs.docker.com/get-started/#install-docker-desktop)
- 克隆存储库： `git clone https://www.github.com/d-asnaghi/nrf-development`
- 移至其目录： `cd nrf-development`
- 启用环境脚本的执行： `chmod 755 nrf-env.sh`
- 运行编译命令： `./nrf-env.sh make`

## 用法

在环境脚本之后附加的任何命令都将在开发环境中运行。要运行`<command>`键入`nrf-env.sh <command>`

一些常见的命令是：

- 编译： `./nrf-env.sh make`
- 测试`module.c` ： `./nrf-env.sh ceedling test:module`
- 测试所有模块： `./nrf-env.sh ceedling test:all`
