#include <vector>
#include <SDL.h>
#include <math.h>
#include <ctime>

class particle{
   private:
    float r;
    std::vector<float> vel;
    std::vector<float> acl;
    std::vector<float> pos;
   public:
    particle(){ 
        //x y z
        r=4;
        pos={400,200,0};
        vel={1,-1,0};
        acl={0,0,0};
    }
    float get_r(){return this->r;}
    std::vector<float>* get_pos(){return &pos;}
    std::vector<float>* get_vel(){return &vel;}
    std::vector<float>* get_acl(){return &acl;}
    void update(float dt){
        this->pos[0]=pos[0]+vel[0]*dt+0.5*acl[0]*dt*dt;
        this->pos[1]=pos[1]+vel[1]*dt+0.5*acl[1]*dt*dt;
        this->vel[1]=vel[1]+acl[1]*dt;
        this->vel[0]=vel[0]+acl[0]*dt;
    }
    void collison_check(){
        
        if(pos[0]<=r||pos[0]>=800-r)vel[0]*=-1;
        if(pos[1]<=r||pos[1]>=400-r)vel[1]*=-1;
    }

};

void draw_circle(SDL_Renderer *renderer,float r,float x,float y){
    
    for(float i=0;i<=(2*M_PI);i+=0.01){
        float x_next = x + r * cosf(i);
        float y_next = y + r * sinf(i);
        SDL_RenderDrawPointF(renderer,x_next,y_next);
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
         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
         SDL_RenderClear(renderer);
         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

         draw_circle(renderer,p1.get_r(),p1.get_pos()[0][0],p1.get_pos()[0][1]);
        
         clock_t before = clock();
         _sleep(1);
         clock_t duration = clock() - before;

         p1.update(duration);
         p1.collison_check();

         SDL_RenderPresent(renderer);

          
        }
    return 0;
}