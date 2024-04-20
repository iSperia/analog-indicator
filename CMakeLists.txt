cmake_minimum_required(VERSION 3.28)
project(assessment_huawei)

set(CMAKE_CXX_STANDARD 17)

add_executable(assessment_huawei src/main.cpp
        src/SFMLEngine.cpp
        headers/SFMLEngine.h
        src/UiComponent.cpp
        headers/UiComponent.h
        src/SeekBar.cpp
        headers/SeekBar.h
        src/CurvedIndicator.cpp
        headers/CurvedIndicator.h
        src/DemoView.cpp
        headers/DemoView.h
        src/DemoPresenter.cpp
        headers/DemoPresenter.h
        headers/ISeekBarCallbacks.cpp
        headers/ISeekBarCallbacks.h)

include_directories(headers F:/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/include)
set(SFML_ROOT F:/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(assessment_huawei ${SFML_LIBRARIES})
endif ()

add_custom_target(copy_assets COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets)
add_dependencies(assessment_huawei copy_assets)

if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()


