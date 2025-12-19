#include <iostream>
#include <chrono>
#include "particles.h"
using namespace std;

int main(){
    particle p1;
    float dt = (1/144.f);
    float t=0;
    p1.set_pos(0,100.f);
    p1.set_alc(0.f,-9.81f);
    while(p1.get_pos().gety()>0.00000002f){
        p1.integrate(dt);
        t+=dt;
        //cout<<t<<endl;
    }
        p1.get_pos().show_point();
        p1.get_vel().show_vector();
        p1.get_alc().show_vector();
        cout<<t;
    return 0;
}