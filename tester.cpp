#include <iostream>
#include <chrono>
#include "vectors.h"
#include "particle.h"
using namespace std;


int main(){
    Clock clock;
    particle p1;
    while(true){
        float dt = clock.dt();
        cout<<dt<<endl; 
    }
    return 0;
}