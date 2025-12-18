#include "particle.h"
#include "vectors.h"
#include <chrono>
particle::particle()
{
    inversemass=1;
    pos.set_vector(0.f,0.f);
    vel.set_vector(0.f,0.f);
    acl.set_vector(0.f,0.f);
    dumpling=0,9.f;
}

void particle::integrate(float duration)
{
    if(duration>0.0f){

        pos = pos + (vel * duration);
    }
}

Clock::Clock()
{
    last = std::chrono::high_resolution_clock::now();
}

float Clock::dt()
{
     auto now = std::chrono::high_resolution_clock::now();
     std::chrono::duration<double> diff = now - last;
     last = now;
     return diff.count();
    return 0.0f;
}
