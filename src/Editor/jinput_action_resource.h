#pragma once

#include <godot_cpp/classes/editor_inspector_plugin.hpp>
#include <godot_cpp/classes/editor_property.hpp>
#include <godot_cpp/classes/button.hpp>
#include "../Core/jinput_action.h"
#include "jinput_action_window.h"

using namespace godot;

class JInputActionProperty : public EditorProperty {
    GDCLASS(JInputActionProperty, EditorProperty)

private:
    Button* open_button;
    JInputActionWindow* editor_window;

protected:
    static void _bind_methods();

public:
    JInputActionProperty();

    void set_editor_window(JInputActionWindow* p_window);
    void on_button_pressed();
	void _update_property() override;
};