#pragma once

#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/classes/v_box_container.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/button.hpp>

using namespace godot;

class JInputActionWindow : public Window {
    GDCLASS(JInputActionWindow, Window)

private:
    VBoxContainer* container;
    Label* label;

protected:
    static void _bind_methods();

public:
    JInputActionWindow();

    void setup_ui();
    void on_close_requested();
};