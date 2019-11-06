#include "gdexample.h"
#include <MultiMesh.hpp>
#include <iostream>
#include <math.h>
using namespace godot;

void GDExample::_register_methods()
{
  register_method("_process",&GDExample::_process);
}

godot::GDExample::GDExample()
{

}

godot::GDExample::~GDExample()
{
}

void godot::GDExample::_init()
{
}

void GDExample::_ready()
{
}

void GDExample::_process(float delta)
{
  time_passed += delta;
  auto multimesh = get_multimesh();
  multimesh->set_instance_count(360);
  for (int i = 0, ec = multimesh->get_instance_count(); i < ec; ++i)
  {
    Transform tr;
    auto t = i * 3.1415 / 180.;
    tr.translate(sin(t)*5, cos(t)*5, sin(t*3+time_passed));
    multimesh->set_instance_transform(i, tr);
  }
}
