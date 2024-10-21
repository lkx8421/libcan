cmake_minimum_required(VERSION 3.10)  # 设置最低 CMake 版本要求
project(CANTest)                       # 项目名称

set(CMAKE_CXX_STANDARD 14)             # 设置 C++ 标准
# set(CMAKE_CXX_STANDARD_REQUIRED ON)     # 强制要求该标准

# 包含目录，查找头文件
include_directories(include)

# 添加源文件
set(SOURCES
    src/CANAdapter.cpp
    src/CANFrameParser.cpp
    src/SocketCAN.cpp
    test/test.cpp   # 包括 test.cpp 文件
)

# 创建可执行文件
add_executable(test ${SOURCES})

# 链接 pthread 库（如果需要）
target_link_libraries(test pthread)
