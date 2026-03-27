#define Vectors
class vector;
class point{
    friend class vector;
    private:
    float x,y;
    public:
    point& get_point();
    float getx();
    float gety();
    void set_point(float x, float y);
    void show_point();
    point();
    point(float x,float y);
    point operator+(vector n);
};
class vector{
    friend class point;
    private:
    float dx;
    float dy;
    public:
    vector& get_vector();
    void show_vector();
    void set_vector(float x,float y);
    float get_x();
    float get_y();
    float magintude()const;
    void normalize();
    vector();
    vector(point* p1,point* p2);
    vector(float p1,float p2);
    vector operator*(const float d)const;
    vector operator/(const float d);
    vector operator=(const vector n);
    vector operator+(const vector n)const;
    vector operator-(const vector n)const;
    vector compontent_product(const vector *v1,const vector *v2)const;
    float scalar_product(const vector *v1,const vector *v2);
};