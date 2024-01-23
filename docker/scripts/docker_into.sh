#!/usr/bin/env bash

# xhost +local:root：允许本地的root用户通过X11协议进行图形界面的显示。
# 1>/dev/null 2>&1：将标准输出和标准错误输出重定向到/dev/null，即丢弃这些输出。
# docker exec：在正在运行的Docker容器中执行命令。
# -u root：以root用户身份执行命令。
# -it linux_monitor：指定要执行命令的Docker容器名称。
# /bin/bash：要执行的命令，这里是以交互方式启动Bash终端。
# xhost -local:root：限制本地root用户使用X11协议进行图形界面的显示。

xhost +local:root 1>/dev/null 2>&1
docker exec \
    -u root \
    -it linux_distribute_monitor \
    /bin/bash
xhost -local:root 1>/dev/null 2>&1