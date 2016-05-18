#include "SDLImageLoader.h"
#include <math.h>
#include <vector>
#include <memory>
#include <list>
#include <iterator>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "Instance.h"
#include "Camera.h"
#include "Game.h"
#include "world/BenchMark.h"

const Uint8 *keys;
Uint32 currentFPS = 0;
Uint32 deltaClock = 0;
int main (int argc, char* args[]) {
    keys = SDL_GetKeyboardState(NULL);
    Game game;
    game.init();

    BenchMark *bm = new BenchMark();

    game.scenes.insert(game.scenes.begin(), bm);

    SDL_Event e;
    float delta;
    int newTime;
    int oldTime = SDL_GetTicks(); 
    int startClock = SDL_GetTicks(); 
    while (!game.quit) {
        newTime = SDL_GetTicks(); 
        delta = (float) (newTime - oldTime) / 1000;

        deltaClock = SDL_GetTicks() - startClock;
        startClock = SDL_GetTicks();

        if(deltaClock != 0){
            currentFPS = 1000 / deltaClock;
        }

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                game.quit = true;
            }
        }

        game.tick(delta);
        game.draw(delta);

        SDL_GL_SwapWindow(display);
        SDL_Delay(1);
        oldTime = newTime; 
    }
    game.close();


    return 0;
}
