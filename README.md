# 项目简介

- 分布式linux性能监控，可以实现多台机器性能监控，并通过qt对数据进行界面显示，显示机器性能；

- 通过docker来实现对该项目所需源码以及依赖的构建；

- 编写启动脚本，通过操作脚本，避免了大量重复的操作，简化操作流程；

- 低耦合性，项目每个模块相互独立；
- 使用cmake对项目进行构建。



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
sudo ./docker_build.sh
```

### 2.启动并进入容器

> - 运行脚本docker_run.sh，进入docker容器
> - docker run

```sh
cd /home/zsy/code/linux_distribute_monitor/docker/scripts
```

```sh
./docker_run.sh
```

### 3.进入容器，启动server服务

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



































































































































