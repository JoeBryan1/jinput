#pragma once

#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/editor_interface.hpp>
#include "jinput_action_inspector.h"
#include "jinput_action_window.h"

namespace godot {

	class JInputEditor : public EditorPlugin {
		GDCLASS(JInputEditor, EditorPlugin)

	private:
		JInputActionInspector* inspector_plugin;
		JInputActionWindow* editor_window;

	protected:
		static void _bind_methods();

	public:
		JInputEditor();

		void _enter_tree() override;
		void _exit_tree() override;
	};
}
