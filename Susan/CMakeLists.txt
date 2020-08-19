cmake_minimum_required(VERSION 3.10)
project(demo)
set(CMAKE_CXX_STANDARD 11)
link_directories(/home/lvfengkun/anaconda3/envs/tf2/lib)
# 配置生成的可执行文件名为hello,要用到的源文件为hello.cpp

set(TENSORFLOW_ROOT_DIR /home/lvfengkun/tensorflow-r2.0)
include_directories(
    ${TENSORFLOW_ROOT_DIR}
    ${TENSORFLOW_ROOT_DIR}/bazel-include
    ${TENSORFLOW_ROOT_DIR}/bazel-bin/tensorflow
    ${TENSORFLOW_ROOT_DIR}/bazel-include
    ${TENSORFLOW_ROOT_DIR}/tensorflow/contrib/makefile/gen/proto
    ${TENSORFLOW_ROOT_DIR}/tensorflow/contrib/makefile/gen/protobuf/include
    ${TENSORFLOW_ROOT_DIR}/tensorflow/contrib/makefile/downloads/eigen
    ${TENSORFLOW_ROOT_DIR}/tensorflow/contrib/makefile/downloads/absl
)
add_executable(main main.cpp)
# 以下使能OpenCV的路径查找
find_package(OpenCV REQUIRED)
 
# 以下是将可执行文件与一些.so文件建立动态链接关系，
# 用到的有libtensorflow_cc.so，libtensorflow_framework.so,以及opencv相关的so
target_link_libraries(main tensorflow_cc tensorflow_framework ${OpenCV_LIBS})
