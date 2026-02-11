#pragma once

#include <godot_cpp/classes/editor_inspector_plugin.hpp>
#include "../Core/jinput_action.h"
#include "jinput_action_window.h"

using namespace godot;

class JInputActionInspector : public EditorInspectorPlugin {
    GDCLASS(JInputActionInspector, EditorInspectorPlugin)

private:
    JInputActionWindow* editor_window;

protected:
    static void _bind_methods();

public:
    JInputActionInspector();

    void set_editor_window(JInputActionWindow* p_window);
    bool _can_handle(Object* p_object) const override;
    void _parse_begin(Object* p_object) override;
};