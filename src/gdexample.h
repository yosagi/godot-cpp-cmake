#pragma once

#include <Godot.hpp>
#include <MultiMeshInstance.hpp>

namespace godot{
  class GDExample : public MultiMeshInstance{
    GODOT_CLASS(GDExample, MultiMeshInstance)
  private:
    float time_passed=0;
  public:
    static void _register_methods();
    GDExample();
    ~GDExample();
    void _ready();
    void _init();
    void _process(float delta);
    ;
  };
};
