#include <vector>
#include <SDL.h>
#include <math.h>

class particle{
   private:
    float r;
    std::vector<float> vel;
    std::vector<float> acl;
    std::vector<float> pos;
   public:
    particle(){ 
        //x y z
        r=2;
        pos={20,20,0};
        vel={0,0,0};
        acl={0,0,0};
    }
    float get_r(){return this->r;}
    std::vector<float>* get_pos(){return &pos;}
    std::vector<float>* get_vel(){return &vel;}
    std::vector<float>* get_acl(){return &acl;}

};

void draw_circle(SDL_Renderer *renderer,float r,float x,float y){
    
    for(float i=0;i<(2*M_PI);i+=0.3){
        float x_next = (x)*cos(i)-(y)*sin(i);
        float y_next = (x)*sin(i)+(y)*cos(i);
        SDL_RenderDrawLineF(renderer,x,y,x_next,y_next);
    }
}

int main(){

    static constexpr int window_size_x = 800;
    static constexpr int window_size_y = 400;


    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Event event;
   
    bool RUN = true;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(window_size_x, window_size_y, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);


    particle p1;

    while (RUN)
        {
            while (SDL_PollEvent(&event))
            {
              switch (event.type)
                {
                     case SDL_QUIT:
                     RUN = false;
                     break;
               
                }
            }
         draw_circle(renderer,p1.get_r(),p1.get_pos()[0][0],p1.get_pos()[0][1]);
         SDL_RenderPresent(renderer);
        }
    return 0;
}