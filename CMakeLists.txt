cmake_minimum_required(VERSION 3.23)
project(miniRT C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lmlx -L../mlx")
include_directories(includes)

add_executable(miniRT
        main.c
        vector.c
        ray.c
        object.c
        hit.c
        util.c
        init.c
        lighting.c
        )

