cmake_minimum_required(VERSION 3.10)

include(FetchContent)

FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v3.0.0
        )

FetchContent_GetProperties(ftxui)
if (NOT ftxui_POPULATED)
    FetchContent_Populate(ftxui)
    add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()

project(todos_tui)

set(CMAKE_CXX_STANDARD 17)

add_executable(todos_tui
        src/main.cpp
        src/todos/TodoItem.cpp
        src/todos/TodoItem.h
        src/todos/TodoList.cpp
        src/todos/TodoList.h
        src/todos/TodoListFileManager.cpp
        src/todos/TodoListFileManager.h
        src/tui/TodosTui.cpp
        src/tui/TodosTui.h)
target_include_directories(todos_tui PRIVATE src)

target_link_libraries(todos_tui
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
        )
