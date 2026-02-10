#pragma once

#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/v_box_container.hpp>

namespace godot {

	class JInputEditor : public EditorPlugin {
		GDCLASS(JInputEditor, EditorPlugin)

	private:
		VBoxContainer* dock;
		Button* button;

	protected:
		static void _bind_methods();

	public:
		JInputEditor();
		~JInputEditor() override;

		void _enter_tree() override;
		void _exit_tree() override;

		void _enable_plugin() override;

		void _on_button_pressed();

	};
}