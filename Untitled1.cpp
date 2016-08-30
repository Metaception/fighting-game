

//The headers
#include "SDL/SDL.h"
#include <string>
#include "SDL/SDL_image.h"

//The attributes of the screen
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The surfaces that will be used
SDL_Surface *P1 = NULL;
SDL_Surface *P2 = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

SDL_Surface *load_image( std::string filename )
{
    //Temporary storage for the image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If nothing went wrong in loading the image
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );
    }

    //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

int main( int argc, char* args[] )
{
    int P1health, P2health;
    P1health =100;
    P2health =100;
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return 1;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Archon", NULL );
    
    background = load_image("background.png");
    apply_surface(0,0,background,screen);
    
    if(P1health=100){
    //Load the images
    P1 = load_image( "P1 100.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P1health=90){
    //Load the images
    P1 = load_image( "P1 90.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P1health=80){
    //Load the images
    P1 = load_image( "P1 80.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P1health=70){
    //Load the images
    P1 = load_image( "P1 70.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P1health=60){
    //Load the images
    P1 = load_image( "P1 60.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P1health=50){
    //Load the images
    P1 = load_image( "P1 50.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P1health=40){
    //Load the images
    P1 = load_image( "P1 40.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P1health=30){
    //Load the images
    P1 = load_image( "P1 30.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P1health=20){
    //Load the images
    P1 = load_image( "P1 20.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P1health=10){
    //Load the images
    P1 = load_image( "P1 10.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P1health=0){
    //Load the images
    P1 = load_image( "P1 0.png" );
    //apply the image
    apply_surface( 20, 20, P1, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    if(P2health=100){
    //Load the images
    P2= load_image( "P2 100.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
     else if(P2health=90){
    //Load the images
    P2 = load_image( "P2 90.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P2health=80){
    //Load the images
    P2 = load_image( "P2 80.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P2health=70){
    //Load the images
    P2 = load_image( "P2 70.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P2health=60){
    //Load the images
    P2 = load_image( "P2 60.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P2health=50){
    //Load the images
    P2 = load_image( "P2 50.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P2health=40){
    //Load the images
    P2 = load_image( "P2 40.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P2health=30){
    //Load the images
    P2 = load_image( "P2 30.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P2health=20){
    //Load the images
    P2 = load_image( "P2 20.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    else if(P2health=10){
    //Load the images
    P2 = load_image( "P2 10.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}    
    
    else if(P2health=0){
    //Load the images
    P2 = load_image( "P2 0.png" );
    //apply the image
    apply_surface( 370, 20, P2, screen );
    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {return 1;}}
    
    
    //Wait 2 seconds
    SDL_Delay( 20000 );
    
    //Free the surfaces
    SDL_FreeSurface( P1 );
    SDL_FreeSurface( P2 );
    SDL_FreeSurface( background );

    //Quit SDL
    SDL_Quit();

    return 0;
}
