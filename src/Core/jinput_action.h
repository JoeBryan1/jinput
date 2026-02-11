#pragma once

#include <godot_cpp/classes/resource.hpp>

namespace godot {

    class JInputAction : public Resource {
	    GDCLASS(JInputAction, Resource)

    private:
	    String data;

    protected:
        static void _bind_methods();

    public:
        JInputAction();

	    void set_data(const String& p_data);
	    [[nodiscard]] String get_data() const;
    };

}