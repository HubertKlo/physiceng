#define particle_dynamic
#define Vectors
class particle
{
private:
    float inversemass;
    float dumpling;
    vector pos;
    vector vel;
    vector acl;
public:
    particle();
    void integrate(float duration);
};
class Clock
{
private:
    std::chrono::high_resolution_clock::time_point last;
public:
    float dt();
    Clock();
    ~Clock();
};