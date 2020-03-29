cmake_minimum_required(VERSION 3.8)
project(GameKernelCore)

add_library(GameKernelCore INTERFACE)
target_include_directories(GameKernelCore INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/)
