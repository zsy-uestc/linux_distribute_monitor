#!/usr/bin/env bash

# 防止重复启动,先结束已启动的容器
source docker_stop.sh

# MONITOR_HOME_DIR将包含一个指向脚本文件所在目录的绝对路径
MONITOR_HOME_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"

# 用户登录到图形界面时，会分配一个显示设备（例如:0）。某些情况下，可能没有启用图形界面或X服务器，此时DISPLAY环境变量可能为空
# 如下是确保display变量始终有一个默认值
display=""
if [ -z ${DISPLAY} ];then
    display=":1"
else
    display="${DISPLAY}"
fi

local_host="$(hostname)"
user="${USER}"
uid="$(id -u)"
group="$(id -g -n)"
gid="$(id -g)"

echo "start docker..."
docker_name="linux_distribute_monitor"
docker run -it -d \
--name ${docker_name} \
-e DISPLAY=$display \
-e DOCKER_USER="${user}" \
-e USER="${user}" \
-e DOCKER_USER_ID="${uid}" \
-e DOCKER_GRP="${group}" \
-e DOCKER_GRP_ID="${gid}" \
-e XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR \
-v ${MONITOR_HOME_DIR}:/${docker_name} \
-v ${XDG_RUNTIME_DIR}:${XDG_RUNTIME_DIR} \
--net host \
--privileged=true \
${docker_name}:v1_0

echo ""
docker ps
echo ""
