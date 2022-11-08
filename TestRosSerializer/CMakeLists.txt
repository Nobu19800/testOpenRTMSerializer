cmake_minimum_required (VERSION 3.0.2)
 
project (TestRosSerializer
    VERSION 1.0
    LANGUAGES CXX)


#OpenRTM-aistの検出
find_package(OpenRTM 2.0 REQUIRED)
find_package(ROSTransport REQUIRED)
#ROSの検出
find_package(PkgConfig REQUIRED)
pkg_check_modules(roscpp roscpp)

if(NOT roscpp_FOUND)
	message(FATAL_ERROR "can not find roscpp.")
endif()

#Boostの検出
find_package(Boost COMPONENTS chrono filesystem system)
if(NOT Boost_FOUND)
	find_package(Boost REQUIRED COMPONENTS chrono filesystem signals system)
endif()

#インクルードディレクトリ、リンクディレクトリ、コンパイル時のフラグの設定
include_directories(${OPENRTM_INCLUDE_DIRS})
add_definitions(${OPENRTM_CFLAGS})

link_directories(${OPENRTM_LIBRARY_DIRS})
link_directories(${roscpp_LIBRARY_DIRS})

#動的リンクライブラリの生成
add_library(${PROJECT_NAME} SHARED TestRosSerializer.cpp)


#生成するライブラリ名をTestRosSerializer.dll(もしくは.so)に設定
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

#OpenRTM-aist、ROS、Boostのライブラリとリンク
target_include_directories(${PROJECT_NAME} SYSTEM
		PRIVATE ${roscpp_INCLUDE_DIRS}
		PRIVATE ${Boost_INCLUDE_DIRS}
		PRIVATE ${ROSTRANSPORT_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENRTM_LIBRARIES} ${roscpp_LIBRARIES} ${Boost_LIBRARIES} ${ROSTRANSPORT_LIBRARIES})

