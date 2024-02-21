# 项目简介

- 分布式linux性能监控，可以实现多台机器性能监控。从cpu的负载、中断占用情况、系统内存使用情况、网卡及网络包的收发情况等角度进行显示与分析；并通过qt对数据进行界面显示，显示机器性能；

- 使用docker来实现对该项目所需源码以及依赖的构建；

- 编写启动脚本，通过操作脚本，避免了大量重复的操作，简化操作流程；

- 低耦合性，项目每个模块相互独立；
  
- 使用cmake对项目进行构建。



# 项目效果展示
### 1. cpu平均负载以及cpu资源使用情况

> - **CpuLoad**模块，用来分析系统的整体负载情况，判断系统是否处于繁忙状态，以及是否有必要采取措施来提高性能或稳定性。展示了cpu在1分钟、5分钟、15分钟内的平均负载。同时显示了计算机的核数。
>
> - **CpuStat**模块，用来分析系统的性能瓶颈，识别潜在的问题，并进行相应的调整。展示的是单位时间内以下主要参数的使用率：用户态时间（user）、用户态低优先级时间（nice）、内核态时间（system）、空闲时间（idle）、I/O等待时间、硬件中断时间（irq）、软件中断时间（softirq）。

![](https://github.com/zsy-uestc/linux_distribute_monitor/blob/main/resource/loadavg/qt_loadavg.png)



### 2. 软中断的数量和它们所占用的CPU时间

> - **Softirqs**模块，用于分析软中断的数量和它们所占用的CPU时间，可以了解系统的负载情况，优化资源分配，并确保关键任务能够得到足够的处理能力。在qt终端显示出各部分中断类型的平均的变化速率（单位时间内数值的平均增长速率），数值大小无意义，展示的是单位时间内的变化率。主要参考的参数如下：高优先级软中断（HI）、定时器事件处理的软中断（TIMER）、网络数据包发送的软中断（NET_TX）、网络数据包接收的软中断（NET_RX）、任务队列的软中断（TASKLET）、块设备（如磁盘）的软中断（SCHED）、（RCU 锁）中网络接收变化最快（RCU）。

![](https://github.com/zsy-uestc/linux_distribute_monitor/blob/main/resource/softirqs/qt_softirqs.png)



### 3.监控系统内存的使用情况

> - **meminfo**模块，用于监控系统内存的使用情况，了解系统资源以及诊断内存问题，如内存泄漏等问题。主要参考的参数如下：内存使用百分比（UsedPercent）、可供系统支配的内存（MemTotal）、系统中未使用的内存（MemFree）、应用程序可用内存（MemAvaliable）、临时存储缓冲区内存数（Buffer）、缓存区内存数（Cached）、交换文件中的已经被交换出来且与 I/O 相关的内存（SwapCached）、最近被使用的内存（Active）、不常使用的内存（Inactive）、活跃的匿名内存【进程中堆上分配的内存,是用malloc分配的内存】（Active(anon)）、不活跃的匿名内存（Inactive(anon)）、活跃的与文件关联的内存（Active(file)）、不活跃的与文件关联的内存（Inactive(file)）、等待被写回到磁盘的大小（Dirty）等。

![](https://github.com/zsy-uestc/linux_distribute_monitor/blob/main/resource/meminfo/qt_meminfo.png)



### 4. 获取网卡实时速率

>- **net/dev**模块，用于获取网卡的网速及网络包的收发情况，在qt终端显示“平均收发总字节数”以及“平均收发数据包数”，用于实时获取网络适配器及统计信息。主要参考的参数如下：网卡名称（name）、平均发送字节速率（send_rate）、平均接收字节速率（rcv_rate）、平均发送数据包数（send_package_rate）、平均接收数据包数（rcv_package_rate）。

![](https://github.com/zsy-uestc/linux_distribute_monitor/blob/main/resource/net/qt_net.png)



# 项目各模块介绍

### 1、docker模块：

> 通过编写dockerfile文件，指定相应的cmake，grpc，protobuf，qt等源码和依赖，构建整个项目环境，易于在多台服务器上部署环境。并编写容器操作的脚本指令，更快捷简便的实现对项目的搭建。

### 2、monitor模块：

> 采用了工厂设计模式，提供了一个通用的接口来创建对象，但将具体对象的创建延迟到子类中。这样可以将对象的创建与使用代码分离，使得代码更加灵活、可扩展和可维护。
>
> 该模块主要实现了对CPU状态，系统负载，软中断，mem，net等性能的监控。并为了模拟出真实的性能问题，使用stress工具进行模拟压测，分析相应时刻服务器的cpu状况和中断状况。

### 3、grpc模块：

> 通过grpc框架，构建出相应的server和client。
>
> - server部署在监控的服务器上，监听客户端请求的地址和端口
> - client生成静态库供monitor模块和display模块调用

### 4、 protobuf模块：

> 使用protobuf定义消息类型，构建出整个项目的数据结构。根据.proto文件生成对应的代码文件，这些代码文件提供了序列化和反序列化所需的方法。
>
> 序列化和反序列化：通过protobuf模块生成的代码文件，将数据对象序列化为二进制格式，或者将二进制数据反序列化为数据对象。这样就可以在不同的系统之间传输数据，或者将数据存储到磁盘或数据库中。protobuf模块广泛应用于分布式系统、网络通信、持久化存储等领域。相比其他数据序列化格式，如JSON和XML，protobuf具有更高的性能和更小的数据体积。

### 5、display模块：

>  display模块分为两大部分：ui界面的构造，datamodel构造；
>
> ui界面使用QWidget、QTableView、QStackedLayout、QPushButton等。

### 6、resource模块：
> 存放一些资源，如效果运行图等。

# 项目运行方法

### 1. 检测并安装docker，并构建项目镜像

> - 运行脚本docker_build.sh，检测本机是否有符合项目版本的docker。若存在符合项目版本的docker，则跳过安装，并显示docker版本，否则安装docker。
>
> - 根据dockerfile文件，来构建项目镜像，构建时间较长，构建完成后对镜像重命名。
>
>   > 主要安装如下：
>   >
>   > - cmake编译器
>   > - protobuf序列化
>   > - grpc
>   > - qt
>
> - docker build --network host -f init_docker.dockerfile .

```sh
cd /home/zsy/code/linux_distribute_monitor
```

```sh
./docker_build.sh
```

### 2.启动与进入容器，并编译

> - 运行脚本docker_run.sh，进入docker容器
> - docker run

```sh
cd /home/zsy/code/linux_distribute_monitor/docker/scripts
```

```sh
./docker_run.sh
```

```sh
./docker_into.sh
```

```sh
cd linux_distribute_monitor/cmake
```

```sh
cmake ..
```

```sh
make
```

### 3.进入容器，启动server服务 (新建终端)

> - docker exec

```sh
cd /home/zsy/code/linux_distribute_monitor/docker/scripts
```

```
./docker_into.sh
```

```sh
cd /linux_distribute_monitor/cmake/grpc_manager/server
```

```sh
./server
```

### 5.进入容器，启动client服务 (新建终端)

```sh
cd /home/zsy/code/linux_distribute_monitor/docker/scripts
```

```sh
./docker_into.sh
```

```sh
cd /linux_distribute_monitor/cmake/test_monitor/
```

```sh
./monitor
```

### 6. 进入容器，启动display终端显示(新建终端)

```sh
cd /home/zsy/code/linux_distribute_monitor/docker/scripts
```

```sh
./docker_into.sh
```

```sh
cd /linux_distribute_monitor/cmake/display_monitor
```

```sh
./display
```

### 7. 退出容器，关闭镜像

```sh
exit
```

```sh
cd /home/zsy/code/linux_distribute_monitor/docker/scripts
```

```sh
./docker_stop.sh
```



# 压测工具的使用

- CPU测试（开启3个CPU进程执行sqrt计算）

```sh
stress --cpu 3 --timeout 60
```

> 通过cpustat的cpu_percent数值趋近于76.56%，与user（用户态）使用率接近75.73%。
>
> 同时cpuload中数值也逐渐上升，负载增加
![](https://github.com/zsy-uestc/linux_distribute_monitor/blob/main/resource/loadavg/stress_cpu3.png)


- IO测试（开启4个IO进程，执行sync系统调用，刷新内存缓冲区到磁盘）

  ```sh
  stress --io 4 --timeout 60
  ```

> cpu_percent、system、io_wait列数值逐渐上升，user数值降低
![](https://github.com/zsy-uestc/linux_distribute_monitor/blob/main/resource/loadavg/stress_io4.png)






- 排查步骤
    
  ①当 user 占用率过高的时候，通常是某些个别的进程占用了大量的 CPU，这时候很容易通过 top 找到该程序；此时如果怀疑程序异常，可以通过 perf 等思路找出热点调用函数来进一步排查；    

  ②当 system 占用率过高的时候，如果 IO 操作(包括终端 IO)比较多，可能会造成这部分的 CPU 占用率高，比如在 file server、database server 等类型的服务器上，否则(比如>20%)很可能有些部分的内核、驱动模块有问题；   

  ③当 nice 占用率过高的时候，通常是有意行为，当进程的发起者知道某些进程占用较高的 CPU，会设置其 nice 值确保不会淹没其他进程对 CPU 的使用请求；   

  ④当 iowait 占用率过高的时候，通常意味着某些程序的 IO 操作效率很低，或者 IO 对应设备的性能很低以至于读写操作需要很长的时间来完成；   

  ⑤当 irq/softirq 占用率过高的时候，很可能某些外设出现问题，导致产生大量的irq请求，这时候通过检查 /proc/interrupts 文件来深究问题所在；


  





