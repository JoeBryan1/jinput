#include "jinput_editor.h"

using namespace godot;

JInputEditor::JInputEditor() 
{
    inspector_plugin = nullptr;
    editor_window = nullptr;
}

void JInputEditor::_bind_methods() 
{
}

void JInputEditor::_enter_tree()
{
    editor_window = memnew(JInputActionWindow);
    get_editor_interface()->get_base_control()->add_child(editor_window);
    editor_window->hide();

    // Create and configure the inspector plugin
    inspector_plugin = memnew(JInputActionInspector);
    inspector_plugin->set_editor_window(editor_window);
    add_inspector_plugin(inspector_plugin);
}

void JInputEditor::_exit_tree()
{
    if (inspector_plugin) {
        remove_inspector_plugin(inspector_plugin);
        inspector_plugin = nullptr;
    }

    if (editor_window) {
        editor_window->queue_free();
        editor_window = nullptr;
    }
}