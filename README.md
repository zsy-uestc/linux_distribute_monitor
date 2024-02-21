# 项目简介

- 分布式linux性能监控，可以实现多台机器性能监控，并通过qt对数据进行界面显示，显示机器性能；

- 通过docker来实现对该项目所需源码以及依赖的构建；

- 编写启动脚本，通过操作脚本，避免了大量重复的操作，简化操作流程；

- 低耦合性，项目每个模块相互独立；
- 使用cmake对项目进行构建。



# 效果展示(命令行与qt界面的对比)

### 1. cpu平均负载以及cpu资源使用情况

> - **CpuLoad**模块，用来分析系统的整体负载情况，判断系统是否处于繁忙状态，以及是否有必要采取措施来提高性能或稳定性。展示了cpu在1分钟、5分钟、15分钟内的平均负载。同时显示了计算机的核数。
>
> - **CpuStat**模块，用来分析系统的性能瓶颈，识别潜在的问题，并进行相应的调整。主要参考的参数如下：用户态时间（user）、用户态低优先级时间（nice）、内核态时间（system）、空闲时间（idle）、I/O等待时间、硬件中断时间（irq）、软件中断时间（softirq）。

![](/home/zsy/图片/loadavg/qt_loadavg.png)



### 2. 软中断softirqs

> - **Softirqs**模块，用于分析软中断的数量和它们所占用的CPU时间，可以了解系统的负载情况，优化资源分配，并确保关键任务能够得到足够的处理能力。在qt终端显示出各部分中断类型的平均的变化速率（单位时间内数值的平均增长速率），数值大小无意义，展示的是单位时间内的变化率。主要参考的参数如下：高优先级软中断（HI）、定时器事件处理的软中断（TIMER）、网络数据包发送的软中断（NET_TX）、网络数据包接收的软中断（NET_RX）、任务队列的软中断（TASKLET）、块设备（如磁盘）的软中断（SCHED）、（RCU 锁）中网络接收变化最快（RCU）。

![](/home/zsy/图片/softirqs/qt_softirqs.png)



### 3.监控系统内存的使用情况

> - **meminfo**模块，用于监控系统内存的使用情况，了解系统资源以及诊断内存问题，如内存泄漏等问题。主要参考的参数如下：内存使用百分比（UsedPercent）、可供系统支配的内存（MemTotal）、系统中未使用的内存（MemFree）、应用程序可用内存（MemAvaliable）、临时存储缓冲区内存数（Buffer）、缓存区内存数（Cached）、交换文件中的已经被交换出来且与 I/O 相关的内存（SwapCached）、最近被使用的内存（Active）、不常使用的内存（Inactive）、活跃的匿名内存【进程中堆上分配的内存,是用malloc分配的内存】（Active(anon)）、不活跃的匿名内存（Inactive(anon)）、活跃的与文件关联的内存（Active(file)）、不活跃的与文件关联的内存（Inactive(file)）、等待被写回到磁盘的大小（Dirty）等。

![](/home/zsy/图片/meminfo/qt_meminfo.png)



### 4. 获取网卡实时速率

>- **net/dev**模块，用于获取网卡的网速及网络包的收发情况，在qt终端显示“平均收发总字节数”以及“平均收发数据包数”，用于实时获取网络适配器及统计信息。主要参考的参数如下：网卡名称（name）、平均发送字节速率（send_rate）、平均接收字节速率（rcv_rate）、平均发送数据包数（send_package_rate）、平均接收数据包数（rcv_package_rate）。

![](/home/zsy/图片/net/qt_net.png)



# 各模块介绍

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
> ui界面使用QWidget、QTableView、QStackedLayout、QPushButton等



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
cd /home/zsy/code/linux_distribute_monitor/cmake
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



## 压测工具的使用

- CPU测试（开启2个CPU进程执行sqrt计算）

```sh
stress --cpu 4 --timeout 60
```

> 通过cpustat看到cpu_percent列数值趋近于100%，与user（用户态）使用率接近97%。
>
> 同时cpuload中数值也逐渐上升，负载增加



- IO测试（开启2个IO进程，执行sync系统调用，刷新内存缓冲区到磁盘）

  ```sh
  stress --io 4 --timeout 60
  ```

> cpu_percent、system、io_wait列数值逐渐上升，user数值降低



## 序列化模块

### 序列化和反序列化的组件-底层原理
典型的序列化和反序列化过程往往需要如下组件：

- IDL（Interface description language）文件：参与通讯的各方需要对通讯的内容需要做相关的约定（Specifications）。为了建立一个与语言和平台无关的约定，这个约定需要采用与具体开发语言、平台无关的语言来进行描述。这种语言被称为接口描述语言（IDL），采用IDL撰写的协议约定称之为IDL文件。
- IDL Compiler：IDL文件中约定的内容为了在各语言和平台可见，需要有一个编译器，将IDL文件转换成各语言对应的动态库。
- Stub/Skeleton Lib：负责序列化和反序列化的工作代码。Stub是一段部署在分布式系统客户端的代码，一方面接收应用层的参数，并对其序列化后通过底层协议栈发送到服务端，另一方面接收服务端序列化后的结果数据，反序列化后交给客户端应用层；Skeleton部署在服务端，其功能与Stub相反，从传输层接收序列化参数，反序列化后交给服务端应用层，并将应用层的执行结果序列化后最终传送给客户端Stub。
- Client/Server：指的是应用层程序代码，他们面对的是IDL所生成的特定语言的class或struct。
- 底层协议栈和互联网：序列化之后的数据通过底层的传输层、网络层、链路层以及物理层协议转换成数字信号在互联网中传递。

 

![](/home/zsy/1.jpg)

### ProtoBuf 使用一般步骤
第一步：定义 proto 文件，文件的内容就是定义我们需要存储或者传输的数据结构，也就是定义我们自己的数据存储或者传输的协议。
第二步：使用 ProtoBuf 编译器 protoc 来编译自定义的 proto 文件，用于生成 .pb.h 文件（proto 文件中自定义类的头文件）和 .pb.cc（proto文件中自定义类的实现文件）。
第三步：使用 ProtoBuf 的 C++ API 来读写消息。



## 监控模块的实现

- 查看Linux系统中系统平均负载的信息（平均负载是指单位时间内，处于可运行状态和不可中断状态的进程数。）

  ```sh
  cat /proc/loadavg
  ```

  ![](/home/zsy/图片/loadavg.png#pic_left)

  > #### 参数的含义：
  >
  > 前三个数字：1分钟 / 5分钟 / 15分钟内的平均负载。
  > 第四个数字：正在运行的进程数 / 总进程数。
  > 第五个数字：最近运行的一个进程PID号。

- 系统进程整体的统计信息

  ```sh
  cat /proc/stat
  ```

  ![](/home/zsy/图片/2024-01-23 14-08-45 的屏幕截图.png)

  > #### 参数的含义：
  >
  > cpu: 表示所有CPU核心的总体统计信息。
  > cpu0, cpu1, …: 表示各个CPU核心的具体统计信息。
  >
  > 列1：用户态时间（user）。CPU 在低 nice 值(高优先级)用户态所占用的时间(nice<=0），典型的用户态空间程序有：Shells、数据库、web服务器……
  > 列2：用户态低优先级时间（nice）。CPU 在高 nice 值(低优先级)用户态以低优先级运行占用的时间(nice>0)，优先级的范围为[-20,19]
  > 列3：内核态时间（system）。例如：分配内存、IO操作、创建子进程……通常情况下该值会比较小，当服务器执行的 IO 比较密集的时候，该值会比较大
  > 列4：空闲时间（idle）。CPU 在空闲状态(执行 kernel idle handler )所占用的时间
  > 列5：I/O等待I时间（iowait）。等待 IO 完成所占用的时间
  > 列6：硬件中断时间（irq）。等待 IO 完成所占用的时间
  > 列7：软件中断时间（softirq）。系统处理软中断所消耗的时间
  > 列8：虚拟机管理程序时间（steal）
  > 列9：虚拟机管理程序等待时间（guest）
  > 列10：虚拟机管理程序等待低优先级时间（guest_nice）

  

  > #### 排查步骤
  >
  > CPU 占用率高很多情况下意味着一些东西，这也给服务器 CPU 使用率过高情况下指明了相应地排查思路：
  >
  >     当 user 占用率过高的时候，通常是某些个别的进程占用了大量的 CPU，这时候很容易通过 top 找到该程序；此时如果怀疑程序异常，可以通过 perf 等思路找出热点调用函数来进一步排查；
  >     
  >     当 system 占用率过高的时候，如果 IO 操作(包括终端 IO)比较多，可能会造成这部分的 CPU 占用率高，比如在 file server、database server 等类型的服务器上，否则(比如>20%)很可能有些部分的内核、驱动模块有问题；
  >     
  >     当 nice 占用率过高的时候，通常是有意行为，当进程的发起者知道某些进程占用较高的 CPU，会设置其 nice 值确保不会淹没其他进程对 CPU 的使用请求；
  >     
  >     当 iowait 占用率过高的时候，通常意味着某些程序的 IO 操作效率很低，或者 IO 对应设备的性能很低以至于读写操作需要很长的时间来完成；
  >     
  >     当 irq/softirq 占用率过高的时候，很可能某些外设出现问题，导致产生大量的irq请求，这时候通过检查 /proc/interrupts 文件来深究问题所在；



- 查看开机以来软中断累计次数

  ```sh
  cat /proc/softirqs
  ```

  ![](/home/zsy/图片/softirqs.png)

  > #### 主要参数的含义：
  >
  > TIMER：    定时器事件处理的软中断
  >
  > NET_TX：  网络数据包发送的软中断
  >
  > NET_RX：  网络数据包接收的软中断
  >
  > TASKLET：任务队列的软中断
  >
  > SCHED：   块设备（如磁盘）的软中断
  >
  > RCU：   （RCU 锁）中，网络接收变化最快

- 查看开机以来硬中断累计次数

  ```sh
  cat /proc/interrupts
  ```

  ![](/home/zsy/图片/interrupts.png)

  

### proto程序编写流程

#### 1.编写proto/cpu_load.proto

```proto
syntax = "proto3";
package monitor.proto;

message CpuLoad {
    float load_avg_1 = 1;
    float load_avg_3 = 2;
    float load_avg_15 = 3;
  }
```

#### 2.编写proto/CMakeLists.txt

```cmake
set(CMAKE_PREFIX_PATH "/usr/local/protobuf")
# 查找并加载protobuf库
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(c-ares CONFIG)

set(PROTO_FILES
    cpu_load.proto
)
# 生成protobuf库
add_library(monitor_proto ${PROTO_FILES})

# 链接protobuf库
target_link_libraries(monitor_proto
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
 )

# 设置protobuf库的头文件路径和当前构建目录的路径。
 target_include_directories(monitor_proto 
    PUBLIC
        ${PROTOBUF_INCLUDE_DIRS} 
        ${CMAKE_CURRENT_BINARY_DIR}
)


 get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
 protobuf_generate(TARGET monitor_proto LANGUAGE cpp)
 protobuf_generate(TARGET monitor_proto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")
 
```

#### 3./proto/monitor_info.proto

```protobuf
syntax = "proto3";
package monitor.proto;

import "google/protobuf/empty.proto";
import "net_info.proto";
import "mem_info.proto";
import "cpu_stat.proto";
import "cpu_softirqs.proto";
import "cpu_load.proto";

message MonitorInfo{
  string name = 1;					//转换为CPP之后，通过set_name()来调用
  repeated SoftIrqs soft_irq = 2;	//vector类型，转换为CPP之后，通过add_soft_irq()来调用
  CpuLoad cpu_load = 3;
  repeated CpuStat cpu_stat = 4;
  MemInfo mem_info = 5;
  repeated NetInfo net_info = 6;
}

// 定义一个名为GrpcManager的gRPC服务 
service GrpcManager {
	//接收 MonitorInfo 类型参数
  rpc SetMonitorInfo(MonitorInfo) returns (google.protobuf.Empty) {
  }
	//返回 MonitorInfo 类型参数
  rpc GetMonitorInfo(google.protobuf.Empty) returns (MonitorInfo) {
  }
}

```



#### 3.主目录下的CMakeLists.txt

```cmake
add_subdirectory(proto)
```

#### 4. 进入cmake目录，编译

```sh
cd /linux_distribute_monitor/cmake
```

```sh
cmake ..
```

```sh
make
```



## monitor模块

### 1.CpuSoftIrqsMonitor

> 用来解析 /proc/softirqs 中返回的数据

通过构建一个结构体，来存储各个属性的值。同时通过一个unordered_map<name, struct> 来对一定周期内各个属性的变化率做计算。



## grpc_manager模块

从文件中的服务定义开始.proto，gRPC 提供了用于生成客户端和服务器端代码的协议缓冲区编译器插件。gRPC 用户通常在客户端调用这些 API，并在服务器端实现相应的 API。
- 在服务器端，服务器实现服务声明的方法并运行 gRPC 服务器来处理客户端调用。gRPC 基础设施解码传入请求、执行服务方法并对服务响应进行编码。
- 在客户端，客户端有一个称为*存根（stub）*的本地对象，它实现与服务相同的方法。然后，客户端可以在本地对象上调用这些方法，并且这些方法将调用的参数包装在适当的协议缓冲区消息类型中，将请求发送到服务器，并返回服务器的协议缓冲区响应。

> 分为server与client端

- ### client端

  编写两个函数，实现数据的传输与获取

```c++
void RpcClient::SetMonitorInfo(const monitor::proto::MonitorInfo& monito_info){
    
}
```

```c++
void RpcClient::GetMonitorInfo(monitor::proto::MonitorInfo* monito_info) {
 
}
```

- ### server端

1. 创建和启动grpc::Server实例的构建器类

```c++
  grpc::ServerBuilder builder;
```

2. 监听客户端请求的地址和端口

```c++
  constexpr char kServerPortInfo[] = "0.0.0.0:50051";			//constexpr, 编译时就确定了它们的值
  builder.AddListeningPort(kServerPortInfo, grpc::InsecureServerCredentials());
```

3. 创建server类实例

```c++
  monitor::GrpcManagerImpl grpc_server;
  builder.RegisterService(&grpc_server);
```

4. 调用BuildAndStart()构建器，为服务创建和启动 gRPC 服务器

```c++
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  server->Wait();
```



## QT部分

### /display_monitor/monitor_iter.cpp

> 定义字体颜色、背景颜色等



































































































































