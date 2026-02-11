#include "jinput_action.h"

using namespace godot;

void JInputAction::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_data", "data"), &JInputAction::set_data);
	ClassDB::bind_method(D_METHOD("get_data"), &JInputAction::get_data);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::STRING, "data"), "set_data", "get_data");
}

JInputAction::JInputAction() {
    data = "";
}

void JInputAction::set_data(const String& p_data) {
    data = p_data;
}

godot::String JInputAction::get_data() const {
    return data;
}