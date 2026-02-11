#include "jinput_action_resource.h"

// MyResourceProperty implementation
void JInputActionProperty::_bind_methods() 
{
    ClassDB::bind_method(D_METHOD("on_button_pressed"), &JInputActionProperty::on_button_pressed);
}

JInputActionProperty::JInputActionProperty() {
    editor_window = nullptr;

    open_button = memnew(Button);
    open_button->set_text("Open Resource Editor");
    open_button->connect("pressed", Callable(this, "on_button_pressed"));
    add_child(open_button);
    add_focusable(open_button);
}

void JInputActionProperty::set_editor_window(JInputActionWindow* p_window) {
    editor_window = p_window;
}

void JInputActionProperty::on_button_pressed() {
    if (editor_window) {
        editor_window->popup_centered();
    }
}

void JInputActionProperty::_update_property() {
    // This gets called when the property needs to update
    // You can update UI here if needed
}