cmake_minimum_required(VERSION 3.10)
project(borsa_fatihi)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt5 REQUIRED COMPONENTS Network)




find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)

add_executable(borsa_fatihi 
main.cpp


)

# glad yerine glad::glad dene
target_link_libraries(borsa_fatihi PRIVATE glfw glad::glad OpenGL::GL)

target_link_libraries(borsa_fatihi 
    PRIVATE Qt5::Widgets
)

target_link_libraries(borsa_fatihi PRIVATE Eigen3::Eigen)
target_link_libraries(borsa_fatihi PRIVATE Qt5::Network)