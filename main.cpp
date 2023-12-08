#include <SDL.h>
#include <cstdlib>
#include <iostream>

using namespace std;

//Circle
void draw_circle(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

//Play Audio
void playAudio()
{
    SDL_Init(SDL_INIT_AUDIO);

    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

    SDL_LoadWAV("/Users/ksensazli/Qt_Projects/SDL_Tutorial/example.wav", &wavSpec, &wavBuffer, &wavLength);

    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
    SDL_Delay(3000);
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
}

int main()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        SDL_Window* window = SDL_CreateWindow("Robotic Bootcamp SDL2 Tutorial",
                                              SDL_WINDOWPOS_CENTERED,
                                              SDL_WINDOWPOS_CENTERED,
                                              1920,
                                              1080,
                                              SDL_WINDOW_SHOWN);

        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {

            SDL_UpdateWindowSurface( window );

            SDL_Renderer* Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if (Renderer == nullptr) {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Error", "Failed to create Window Renderer!", NULL);
                if (window != nullptr) {
                    SDL_DestroyWindow(window);
                }
                SDL_Quit();
                return EXIT_FAILURE;
            }

            SDL_Surface* BMPSurface = SDL_LoadBMP("/Users/ksensazli/Qt_Projects/SDL_Tutorial/sample.bmp");
            if (BMPSurface == nullptr) {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Error", "Failed to Load BMP Image!", NULL);
                if (Renderer != nullptr) {
                    SDL_DestroyRenderer(Renderer);
                }
                if (window != nullptr) {
                    SDL_DestroyWindow(window);
                }
                SDL_Quit();
                return EXIT_FAILURE;
            }

            SDL_Surface* BMPButton = SDL_LoadBMP("/Users/ksensazli/Qt_Projects/SDL_Tutorial/button.bmp");
            if (BMPSurface == nullptr) {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Error", "Failed to Load BMP Image!", NULL);
                if (Renderer != nullptr) {
                    SDL_DestroyRenderer(Renderer);
                }
                if (window != nullptr) {
                    SDL_DestroyWindow(window);
                }
                SDL_Quit();
                return EXIT_FAILURE;
            }

            SDL_Texture* BMPTexture = SDL_CreateTextureFromSurface(Renderer, BMPSurface);
            if (BMPTexture == nullptr) {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Error", "Failed to Create BMP Texture!", NULL);
                if (BMPSurface != nullptr) {
                    SDL_FreeSurface(BMPSurface);
                }
                if (Renderer != nullptr) {
                    SDL_DestroyRenderer(Renderer);
                }
                if (window != nullptr) {
                    SDL_DestroyWindow(window);
                }
                SDL_Quit();
                return EXIT_FAILURE;
            }

            SDL_Texture* ButtonTexture = SDL_CreateTextureFromSurface(Renderer, BMPButton);
            if (BMPTexture == nullptr) {
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Error", "Failed to Create BMP Texture!", NULL);
                if (BMPSurface != nullptr) {
                    SDL_FreeSurface(BMPSurface);
                }
                if (Renderer != nullptr) {
                    SDL_DestroyRenderer(Renderer);
                }
                if (window != nullptr) {
                    SDL_DestroyWindow(window);
                }
                SDL_Quit();
                return EXIT_FAILURE;
            }

            SDL_FreeSurface(BMPButton);
            SDL_FreeSurface(BMPSurface);

            //Image (BMP)
            SDL_Rect BMPRect;
            BMPRect.x = 0;
            BMPRect.y = 0;
            BMPRect.w = 480;
            BMPRect.h = 360;

            //Button
            SDL_Rect ButtonRect;
            ButtonRect.x = 500;
            ButtonRect.y = 200;
            ButtonRect.w = 338;
            ButtonRect.h = 115;

            //Rectangle
            SDL_Rect rectangle;
            rectangle.x = 600;
            rectangle.y = 050;
            rectangle.w = 100;
            rectangle.h = 100;

            //Clear window
            SDL_RenderClear(Renderer);
            SDL_RenderCopy(Renderer, BMPTexture, &BMPRect, &BMPRect);
            SDL_RenderCopy(Renderer, ButtonTexture, &ButtonRect, &ButtonRect);
            SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);

            //Draw Line
            SDL_SetRenderDrawColor(Renderer,255,255,255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(Renderer,460,500,20,500);

            //Draw Rectangle
            SDL_RenderDrawRect(Renderer, &rectangle);

            //Draw Circle
            draw_circle(Renderer,600,600,100,{255,255,255,255});

            //Show window
            SDL_RenderPresent(Renderer);
            playAudio();

            SDL_Event e;
            SDL_bool quit = SDL_TRUE;
            while( quit )
            {
                while( SDL_PollEvent( &e ) )
                {
                    if(e.type == SDL_QUIT)
                    {
                        quit = SDL_FALSE;
                    }
                    else if(e.type == SDL_KEYDOWN)
                    {
                        switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = SDL_FALSE;
                            break;
                        default:
                            quit = SDL_TRUE;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
