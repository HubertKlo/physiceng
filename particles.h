#define particle_lib
#include "vectors.h"

class particle{
    private:
    point pos;
    vector vel;
    vector alc;
    public:
    particle();
    void set_pos(float x,float y);
    void set_vel(float x,float y);
    void set_alc(float x,float y);
    point get_pos();
    vector get_vel();
    vector get_alc();
    void integrate(float dt);
};