
#include "vectors.h"
#include <cmath>
#include <iostream>

    point& point::get_point(){
        return *this;
    }
    float point::getx(){
        return this->x;
    }
    float point::gety()
    {
        return this->y;
    }
    void point::set_point(float x, float y)
    {
        this->x=x;  
        this->y=y;
    }
    void point::show_point()
    {
        std::cout<<"pos x: "<<this->x<<" pos y: "<<this->y<<std::endl;
    }
    point::point()
    {
        x=0;
        y=0;
    }
    point::point(float x,float y){
        this->x=x;
        this->y=y;
    }

    
    vector& vector::get_vector(){
        return *this;
    }
    void vector::show_vector(){
        std::cout<<"["<<this->dx<<","<<this->dy<<"]"<<std::endl;
    }
    void vector::set_vector(float x,float y){
       this-> dy=y;
       this-> dx=x;
    }
    float vector::magintude() const
    {
        return sqrt(this->dx*this->dx+this->dy*this->dy);   
    }
   
    vector::vector()
    {
        this->dx = 0;
        this->dy = 0;
    }
    vector::vector(point* p1,point* p2){
        this->dx=p1->x - p2->x;
        this->dy=p1->y - p2->y;
    }

    vector::vector(float p1, float p2)
    {
        this->dx = p1;
        this->dy = p2;
    }
    vector vector::operator*(float d)const
    {
        return vector(dx * d,dy * d);
    }
    vector vector::operator/(const float d)
    {
        if(d!=0){
        this->dx=this->dx / d;
        this->dy=this->dy / d;
        }
        return *this;
    }
    vector vector::operator=(const vector n)
    {
        this->dx=n.dx;
        this->dy=n.dy;
        return *this;
    }
 
    vector vector::operator+(const vector n)const
    {
        return vector(dx+n.dx,dy+n.dy);
    }

    vector vector::operator-(const vector n) const
    {
        return vector(this->dx-n.dx,this->dy-n.dy);
    }

    vector vector::compontent_product(const vector *v1, const vector *v2) const
    {
        return vector(v1->dx*v2->dx,v1->dy*v2->dy);
    }

    float vector::scalar_product(const vector *v1, const vector *v2) 
    {
        float prod = v1->dx*v2->dx + v1->dy*v2->dy; 
        return prod;
    }
    float vector::get_x(){
        return dx;
    }
    float vector::get_y()
    {
        return dy;
    }
    void vector::normalize()
    {
        const float m = this->magintude();
        if(m>0){
            *this=(*this)/m;
        }
    }

    point point::operator+(vector n) 
    {
        return point(this->x+n.dx,this->y+n.dy);
    }
