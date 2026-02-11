cmake_minimum_required(VERSION 4.0)
project(godot_cpp_example)

set(CMAKE_CXX_STANDARD 26)

add_compile_definitions(TYPED_METHOD_BIND)

add_executable(${PROJECT_NAME}
        "src/Editor/jinput_editor.cpp"
        src/register_types.cpp "src/Core/jinput_action.cpp" "src/Editor/jinput_action_window.cpp" "src/Editor/jinput_action_window.h" "src/Editor/jinput_action_inspector.cpp" "src/Editor/jinput_action_inspector.h" "src/Editor/jinput_action_resource.cpp")

target_include_directories(${PROJECT_NAME} PRIVATE "godot-cpp/gen/include")
target_include_directories(${PROJECT_NAME} PRIVATE "godot-cpp/include")
target_include_directories(${PROJECT_NAME} PRIVATE "godot-cpp/gdextension")
