#include "particles.h"

particle::particle()
{
    this->pos.set_point(0.f,0.f);
    this->vel.set_vector(0.f,0.f);
    this->alc.set_vector(0.f,0.f);
}
//settery
void particle::set_pos(float x, float y)
{
    this->pos.set_point(x,y);
}

void particle::set_vel(float x, float y)
{
    this->vel.set_vector(x,y);
}

void particle::set_alc(float x, float y)
{
    this->alc.set_vector(x,y);
}
point particle::get_pos()
{
    return pos.get_point();
}
vector particle::get_vel()
{
    return vel.get_vector();
}
vector particle::get_alc()
{
    return alc.get_vector();
}
///

void particle::integrate(float dt)
{
   vel = vel + alc * dt;
   pos = pos + vel * dt;
}
