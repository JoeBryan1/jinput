#include "jinput_editor.h"

using namespace godot;

JInputEditor::JInputEditor() {
    UtilityFunctions::print("Constructor called!");
	dock = nullptr;
	button = nullptr;
}

JInputEditor::~JInputEditor() = default;

void JInputEditor::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_button_pressed"), &JInputEditor::_on_button_pressed);
}

void JInputEditor::_enter_tree()
{
    UtilityFunctions::print("Tree entered");

    // Create a dock container
    dock = memnew(VBoxContainer);
    dock->set_name("JInput");

    // Create a button
    button = memnew(Button);
    button->set_text("Click Me");

    // Connect signal
    button->connect("pressed", Callable(this, "_on_button_pressed"));

    dock->add_child(button);

    // Add dock to the editor
    add_control_to_dock(DOCK_SLOT_RIGHT_UL, dock);
}

void JInputEditor::_exit_tree()
{
    UtilityFunctions::print("Tree exited");
    if (dock) {
        remove_control_from_docks(dock);
        dock->queue_free();
        dock = nullptr;
    }
}

void JInputEditor::_enable_plugin()
{
    UtilityFunctions::print("Plugin enabled");
}

void JInputEditor::_on_button_pressed()
{
    UtilityFunctions::print("Button pressed from C++ editor plugin!");
}
