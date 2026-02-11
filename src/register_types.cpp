#include "register_types.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "Core/jinput_action.h"
#include "Editor/jinput_action_inspector.h"
#include "Editor/jinput_action_resource.h"
#include "Editor/jinput_action_window.h"
#include "Editor/jinput_editor.h"
#include "godot_cpp/classes/editor_plugin_registration.hpp"

using namespace godot;

void initialize_jinput_module(ModuleInitializationLevel p_level) {
	UtilityFunctions::print("Init level: ", p_level);

	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		ClassDB::register_class<JInputAction>();
	}

	if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) 
	{
		UtilityFunctions::print("Registering MyEditorPlugin");
		ClassDB::register_internal_class<JInputEditor>();
		ClassDB::register_class<JInputActionProperty>();
		ClassDB::register_class<JInputActionWindow>();
		ClassDB::register_class<JInputActionInspector>();
		EditorPlugins::add_by_type<JInputEditor>();
	}
}

void terminate_jinput_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_EDITOR) {
		return;
	}
}

extern "C" {
	// Initialization.
	GDExtensionBool GDE_EXPORT jinput_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization) {
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(initialize_jinput_module);
		init_obj.register_terminator(terminate_jinput_module);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}