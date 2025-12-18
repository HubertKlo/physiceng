#define Vectors
class point{
    friend class vector;
    private:
    float x,y;
    public:
    point* get_point();
    void set_point(float x,float y);
    point();
    point(float x,float y);
};
class vector{
    private:
    float dx;
    float dy;
    public:
    vector* get_vector();
    void show_vector();
    void set_vector(float x,float y);
    float magintude()const;
    void normalize();
    vector();
    vector(point* p1,point* p2);
    vector(point* p1,point* p2);
    vector(float p1,float p2);
    vector operator*(const float d);
    vector operator/(const float d);
    vector operator=(const vector n);
    vector operator+(const vector n)const;
    vector operator-(const vector n)const;
    vector compontent_product(const vector *v1,const vector *v2)const;
    float scalar_product(const vector *v1,const vector *v2);
};