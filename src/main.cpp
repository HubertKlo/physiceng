#include <vector>
#include <SDL.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <array>



class particle{
   
   protected:
    float r;
    float mass;
    std::array<float,2> vel{};
    std::array<float,2> acl{};
    std::array<float,2> pos{};
   public:
    particle(){ 
        //x y z
        r=20;
        mass=0,5;
        pos={5,193};
        vel={0.4,-0.4};
        acl={0,0};
    }

    void ScalarMult(float x){

    }

    float get_r(){return this->r;}

    std::array<float,2>& get_pos(){return pos;}
    std::array<float,2>& get_vel(){return vel;}
    std::array<float,2>& get_acl(){return acl;}

    void set_pos(std::array<float,2> newone){pos=newone;}
    void set_vel(std::array<float,2> newone){vel=newone;}
    void set_acl(std::array<float,2> newone){acl=newone;}

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
class particles : public particle{
    private:
        std::vector<particle> group;
    public:
        particles(int n){
            srand(time(0));
            float random_x,random_y;
            for(int i=0;i<n;i++){
                random_x =rand() % 760 + 5;
                random_y =rand() % 390 + 5;
                group.push_back(particle());                                                                
                group.back().set_pos({random_x,random_y});
            }
        }

        float distance(particle &p1,particle &p2){
            float x = pow(p1.get_pos()[0]-p2.get_pos()[0],2);
            float y = pow(p1.get_pos()[1]-p2.get_pos()[1],2);
            return sqrtf(x+y);
        }
         
        void collison_particles(){
          for(auto  &it: group){
               for(auto  &jk: group){
                   if(distance(jk,it)<=r&& &jk!=&it){
                        jk.set_vel({jk.get_vel()[0]*-1,jk.get_vel()[1]*-1});
                        // it.set_vel({it.get_vel()[0]*-1,it.get_vel()[1]*-1});
                        SDL_Log("sdfsd");
                    }
                }
            }
        }
        std::vector<particle>& get_group(){
            return group;
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

    srand(time(0));

    static constexpr int window_size_x = 800;
    static constexpr int window_size_y = 400;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Event event;
   
    bool RUN = true;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(window_size_x, window_size_y, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

   

    particles p1(2);

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
        
         for(auto &it:p1.get_group())
            draw_circle(renderer,it.get_r(),it.get_pos()[0],it.get_pos()[1]);
         
        
         clock_t before = clock();
         _sleep(1);
         clock_t duration = clock() - before;



        for(auto &it : p1.get_group()){
            it.collison_check();
            it.update(duration);
            p1.collison_particles();
        }
       
         
         

         SDL_RenderPresent(renderer);

          
        }
    return 0;
}