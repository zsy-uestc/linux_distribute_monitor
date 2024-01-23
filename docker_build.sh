#!/usr/bin/env bash

# 检查是否已经安装Docker
if ! command -v docker &> /dev/null; then
    echo "未检测到Docker的安装，开始安装..."
    sudo apt install curl
    curl -fsSL https://test.docker.com -o test-docker.sh
    sudo sh test-docker.sh
    echo "Docker安装完成！"
else
    echo "已检测到Docker已安装，版本信息为:"
    docker --version
fi

# 构建镜像
echo "docker building..."
cd docker/build/
docker build --network host -f init_docker.dockerfile .

# 镜像命名
echo "docker rename..."
image_ids=$(docker images --format "{{.ID}}\t{{.Repository}}" | awk '{if ($2 == "<none>") print $1}')
rename="linux_distribute_monitor:v1_0"
docker tag ${image_ids} ${rename}
docker images