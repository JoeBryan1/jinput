#include "jinput_action_inspector.h"

#include "jinput_action_resource.h"

void JInputActionInspector::_bind_methods() 
{
}

JInputActionInspector::JInputActionInspector() 
{
    editor_window = nullptr;
}

void JInputActionInspector::set_editor_window(JInputActionWindow* p_window) 
{
    editor_window = p_window;
}

bool JInputActionInspector::_can_handle(Object* p_object) const 
{
    return cast_to<JInputAction>(p_object) != nullptr;
}

void JInputActionInspector::_parse_begin(Object* p_object) 
{
    const auto* resource = cast_to<JInputAction>(p_object);
    if (resource && editor_window) {
        JInputActionProperty* property = memnew(JInputActionProperty);
        property->set_editor_window(editor_window);
        add_custom_control(property);
    }
}