cmake_minimum_required(VERSION 3.29)

#set(CMAKE_GENERATOR_PLATFORM Win32)

project(bk-emulator)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(Intl REQUIRED)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-implicit-function-declaration -Wno-implicit-int -Wno-return-type -Wno-incompatible-function-pointer-types")
endif()

add_executable(bk main.c access.c boot.c branch.c bkplip.c conf.c covox.c disas.c disk.c double.c ea.c emu2149.c icon.c io.c itab.c mouse.c printer.c scr.c serial.c service.c single.c sound.c synth.c tape.c terakdisk.c timer.c timing.c tty.c ui.c weird.c)

include_directories(bk ${Intl_INCLUDE_DIRS})
include_directories(bk ${SDL2_INCLUDE_DIR})

target_link_libraries(bk PRIVATE SDL2::SDL2 SDL2::SDL2main)

# Doing this trick to force static linking for intl library
target_link_directories(bk PRIVATE "${Intl_LIBRARY}/..")
target_link_libraries(bk PRIVATE intl)
