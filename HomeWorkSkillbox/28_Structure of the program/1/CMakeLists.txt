# минимальная для сборки версия cmake
cmake_minimum_required(VERSION 3.19)

#имя проекта и его версия
project("Executive simulator" VERSION 1.0.0 )

#стандарт языка
set(CMAKE_CXX_STANDARD 14)

# .exe и список файлов
add_executable(simulator srs/main.cpp include/surg_op.h include/coordinate.h)