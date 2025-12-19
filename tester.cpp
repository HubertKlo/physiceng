#include <iostream>
#include <chrono>
#include "particles.h"
using namespace std;

int main(){
    particle p1;
    auto lasttime = chrono::steady_clock::now();
    float dt = (1/144.f);
    float t=0;
    float acumulator=0;
    p1.set_pos(0,10.f);
    p1.set_alc(0.f,-9.81f);
    while(p1.get_pos().gety()>=0.1f){
        auto actualtime = chrono::steady_clock::now();
        chrono::duration<float> drealtime = actualtime - lasttime;
        lasttime = actualtime; 
        acumulator+=drealtime.count();
        while(acumulator>=dt){
            p1.integrate(dt);
            acumulator-=dt;
            t+=dt;
        }

    }  
        p1.get_pos().show_point();
        p1.get_vel().show_vector();
        p1.get_alc().show_vector();
        cout<<t;
    return 0;
}