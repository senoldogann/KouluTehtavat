cmake_minimum_required(VERSION 3.10)
project(GameProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SDL2 yolunu belirt
set(SDL2_DIR "/opt/homebrew/lib/cmake/SDL2")
set(SDL2_TTF_DIR "/opt/homebrew/lib/cmake/SDL2_ttf")

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Include dizinlerini ekle
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(/opt/homebrew/include)

add_executable(GameProject 
    src/main.cpp
    src/Game.cpp
    src/Button.cpp
    src/ProgressBar.cpp
)

target_link_libraries(GameProject 
    SDL2::SDL2
    SDL2_ttf::SDL2_ttf
)

# macOS için ek ayarlar
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework OpenGL")
endif() 