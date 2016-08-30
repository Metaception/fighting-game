#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
  
//Screen attributes
const int WIDTH = 640;
const int HEIGHT = 480;
  
//The images
SDL_Surface* healthplayer1 = NULL;
SDL_Surface* healthplayer2 = NULL;
SDL_Surface* player1 = NULL;
SDL_Surface* player2 = NULL;
SDL_Surface* screen = NULL;
SDL_Surface* background = NULL;
SDL_Surface* buttonSheet = NULL;
SDL_Surface* menuBackground = NULL;
  
//The event structure
SDL_Event event;

int main( int argc, char* args[] )  {   //Main program

	//All the character variables
	int health1 = 100;
	int health2 = 100;
	bool win1=true;
	bool win2=true;
	int xVel(0), aVel(0), i(0), j(0);
    SDL_Rect pos1, pos2, healthpos1, healthpos2;
    pos1.x = 0;
    pos1.y = 368;
    pos2.x = 601;
    pos2.y = 368;
    healthpos1.x = 0;
    healthpos1.y = 0;
    healthpos2.x = 390;
    healthpos2.y = 0;
      
    //Initialize SDL
	SDL_Init( SDL_INIT_EVERYTHING );
    
	//The buttons
	SDL_Rect play; SDL_Rect fullscreen; SDL_Rect exit;
	
	//Substituting integers with names for a later array
	int CLIP_PLAY = 1; int CLIP_PLAYCLICKED = 2; int CLIP_FULLSCREEN = 3; int CLIP_FULLSCREENCLICKED = 4;
	int CLIP_EXIT = 5; int CLIP_EXITCLICKED = 6;
	
	//The button graphics to be blitted
	SDL_Rect clips[6];
	
	//Where to blit the image
	SDL_Rect playClip; SDL_Rect fullscreenClip; SDL_Rect exitClip;
	
	//Load the button graphics
	buttonSheet = IMG_Load("button.png");
	
	//Load the menu background
	menuBackground = IMG_Load("menuBackground.png");
	
	//Blitting the button graphics
	clips[CLIP_PLAY].x = 0;
	clips[CLIP_PLAY].y = 0;
	clips[CLIP_PLAY].h = 44;
	clips[CLIP_PLAY].w = 132;
	
	clips[CLIP_PLAYCLICKED].x = 132;
	clips[CLIP_PLAYCLICKED].y = 0;
	clips[CLIP_PLAYCLICKED].h = 44;
	clips[CLIP_PLAYCLICKED].w = 132;
	
	clips[CLIP_FULLSCREEN].x = 0;
	clips[CLIP_FULLSCREEN].y = 44;
	clips[CLIP_FULLSCREEN].h = 44;
	clips[CLIP_FULLSCREEN].w = 132;
	
	clips[CLIP_FULLSCREENCLICKED].x = 132;
	clips[CLIP_FULLSCREENCLICKED].y = 44;
	clips[CLIP_FULLSCREENCLICKED].h = 44;
	clips[CLIP_FULLSCREENCLICKED].w = 132;
	
	clips[CLIP_EXIT].x = 0;
	clips[CLIP_EXIT].y = 88;
	clips[CLIP_EXIT].h = 44;
	clips[CLIP_EXIT].w = 132;
	
	clips[CLIP_EXITCLICKED].x = 132;
	clips[CLIP_EXITCLICKED].y = 88;
	clips[CLIP_EXITCLICKED].h = 44;
	clips[CLIP_EXITCLICKED].w = 132;
	
	//Mouse coordinates
	int x = 0, y = 0;
	
	//The default button graphics
	playClip = clips[CLIP_PLAY];
	fullscreenClip = clips[CLIP_FULLSCREEN];
	exitClip = clips[CLIP_EXIT];
	
	//Declaring the button's coordinates and dimensions
	//Play button:
		play.x = 254;
		play.y = 87;
		play.w = 132;
		play.h = 44;
	//Fullscreen button:
		fullscreen.x = 254;
		fullscreen.y = 218;
		fullscreen.w = 132;
		fullscreen.h = 44;
	//Exit button:
		exit.x = 254;
		exit.y = 349;
		exit.w = 132;
		exit.h = 44;
  
    screen = SDL_SetVideoMode( WIDTH, HEIGHT, 32, SDL_SWSURFACE );
  
    //Load images
    healthplayer1 = IMG_Load( "p1_1002.png");
	healthplayer2 = IMG_Load( "p2_1002.png");
	player1 = IMG_Load( "idleRight.png" );
    player2 = IMG_Load( "2idle.png" );
    background = IMG_Load( "background.png" );
    
    //Determines which frame to use for walking animation
	int frame = 1;
	int frame2 = 1;
	int frame3 = 1;
	int frame4 = 1;
	int frame5 = 1;
	int frame6 = 1;
    
    //Determines whether to run the menu, the game, or quit the program
    int menuGame = 1;
    
    bool attack = false, attack2 = false, attackLeft = false, attack2Left = false, faceRight = true, faceLeft = false, faceRight2 = false, faceLeft2 = true;
    
    //Determines fullscreen or windowed
    bool screenState = false;
      
    do
	{
		//Launches the menu
		while(menuGame == 1)
		{
			//If there is an event
			if( SDL_PollEvent( &event ) )
			{
				
				//If a mouse button is pressed
				if(event.type == SDL_MOUSEBUTTONDOWN)
				{
					//If the left mouse button is pressed
					if(event.button.button == SDL_BUTTON_LEFT)
					{
						//Get the mouse coordinates
						x = event.button.x;
						y = event.button.y;
						
						//Set the 'clicked' graphics if a button was clicked
						if(x > play.x && x < (play.x + play.w) && y > play.y && y < (play.y + play.h))
						{
							playClip = clips[CLIP_PLAYCLICKED];
						}
						if(x > fullscreen.x && x < (fullscreen.x + fullscreen.w) && y > fullscreen.y && y < (fullscreen.y + fullscreen.h))
						{
							fullscreenClip = clips[CLIP_FULLSCREENCLICKED];
						}
						if(x > exit.x && x < (exit.x + exit.w) && y > exit.y && y < (exit.y + exit.h))
						{
							exitClip = clips[CLIP_EXITCLICKED];
						}
					}
				}
					
				//If a mouse button is released
				if(event.type == SDL_MOUSEBUTTONUP)
				{
					//If the left mouse button was released
					if(event.button.button == SDL_BUTTON_LEFT)
					{	
						//Get the mouse coordinates
						x = event.button.x;
						y = event.button.y;
						
						//Depending on what button is pressed, a different value is returned, and will tell the main function what to do
						if(x > play.x && x < (play.x + play.w) && y > play.y && y < (play.y + play.h))
						{
							playClip = clips[CLIP_PLAY];
							menuGame = 2;					//Switches to the game
						}
						if(x > fullscreen.x && x < (fullscreen.x + fullscreen.w) && y > fullscreen.y && y < (fullscreen.y + fullscreen.h))
						{
							fullscreenClip = clips[CLIP_FULLSCREEN];
							
							//Converts fullscreen to windowed and viceversa
							if(screenState == false)
							{
								screen == SDL_SetVideoMode( WIDTH, HEIGHT, 32, SDL_FULLSCREEN);
							}
							else
							{
								screen == SDL_SetVideoMode( WIDTH, HEIGHT, 32, SDL_SWSURFACE);
							}
							screenState = abs(screenState - 1);		//Converts true to false and viceversa (1 to 0 and viceversa) for next time the button is used
						}
						if(x > exit.x && x < (exit.x + exit.w) && y > exit.y && y < (exit.y + exit.h))
						{
							exitClip = clips[CLIP_EXIT];
							menuGame = 3;					//Closes the game
						}
					}
				}
				
				//Quits the program if the window is Xed out
				if(event.type == SDL_QUIT)
				{
					menuGame = 3;
				}
			}
			
			//Apply the surfaces
			
			SDL_BlitSurface( menuBackground, NULL, screen, NULL );
			SDL_BlitSurface( buttonSheet, &playClip, screen, &play );
			SDL_BlitSurface( buttonSheet, &fullscreenClip, screen, &fullscreen );
			SDL_BlitSurface( buttonSheet, &exitClip, screen, &exit );
			
			//Update the screen
			SDL_Flip( screen );
			
		}
		
    	//Launches the game
		while(menuGame == 2)
    	{  
    	
    	
	        if ( SDL_PollEvent( &event ) ) {
	              
	            //If a key is pressed
				if( event.type == SDL_KEYDOWN ) {
					  
	                //Here the characters are moved left and right
					switch( event.key.keysym.sym ) {
	                  
	                    case SDLK_d:
	                        xVel += 1;
	                        ++i;
	                        break;
	                    case SDLK_a:
	                        xVel -= 1;
	                        --i;
	                        break;
	                    case SDLK_RIGHT:
	                        aVel += 1;
	                        --j;
	                        break;
	                    case SDLK_LEFT:
	                        aVel -= 1;
	                        ++j;
	                        break;
	                    case SDLK_ESCAPE:
	                    	menuGame = 1;
	                    	break;
	                    case SDLK_q:
	                    	menuGame = 3;
	                	    	break;
					}
					
					if(xVel == 1 || xVel == -1)
					{
						faceRight = false;
						faceLeft = false;
					}
					if(aVel == 1 || aVel == -1)
					{
						faceRight2 = false;
						faceLeft2 = false;
					}
	            }
	            //If a key is released
				else if( event.type == SDL_KEYUP ) {
	                  
	                //Here the characters are stopped, and use the idle images
	                //Also checks whether to punch
					switch( event.key.keysym.sym ) {
	                  
	                    case SDLK_d:
	                        xVel -= 1;
	                        player1 = IMG_Load("idleRight.png");
	                        faceRight = true;
	                        faceLeft = false;
	                        break;
	                    case SDLK_a:
	                        xVel += 1;
	                        player1 = IMG_Load("idle.png");
	                        faceLeft = true;
	                        faceRight = false;
	                        break;
	                    case SDLK_RIGHT:
	                        aVel -= 1;
	                        player2 = IMG_Load("2idleRight.png");
	                        faceRight2 = true;
	                        faceLeft2 = false;
	                        break;
	                    case SDLK_LEFT:
	                        aVel += 1;
	                        player2 = IMG_Load("2idle.png");
	                        faceLeft2 = true;
	                        faceRight2 = false;
	                        break;
	                    case SDLK_c:
	                    	
							
							if(xVel == 1 || faceRight == true)
	                    	{
	                    		attack = true;
	                    	}
	                    	else if(xVel == -1 || faceLeft == true)
	                    	{
	                    		attackLeft = true;
	                    	}
	                    	break;
	                    case SDLK_COMMA:
	                    
							
							if(aVel == 1 || faceRight2 == true)
	                    	{
	                    		attack2 = true;
	                    	}
	                    	else if(aVel == -1 || faceLeft2 == true)
	                    	{
	                    		attack2Left = true;
	                    	}
	                    	break;
	                }
	            }
	            //The program is quit here
				else if( event.type == SDL_QUIT ) { 
	                menuGame = 3;
	            }
	        }
	          
	        //Moving the characters
			pos1.x += xVel;
	        pos2.x += aVel;
	          
	        //Edge of map boundaries
			if (pos1.x > 601) {
	            pos1.x -= xVel;
	        }
	          
	        if (pos2.x > 601) {
	            pos2.x -= aVel;
	        }
	          
	        SDL_Delay (0);
	        
	        //Determines which image to load based on the frame and direction of the character
	        if(xVel == 1)
	        {
				switch (frame)
		        {
		        	case 10:
		        		player1 = IMG_Load("walkR1.png");
		        		break;
		        	case 20:
		        		player1 = IMG_Load("walkR2.png");
		        		break;
		        	case 30:
		        		player1 = IMG_Load("walkR3.png");
		        		break;
		        }
		        
		        //Resets the frame to 0 so that the animation loops again
		        if(frame < 30)
		        {
		        	frame++;
		        }
		        else
		        {
		        	frame = 0;
		        }
	    	}
	    else	if(xVel == -1)
	        {
				switch (frame)
		        {
		        	case 10:
		        		player1 = IMG_Load("walkL1.png");
		        		break;
		        	case 20:
		        		player1 = IMG_Load("walkL2.png");
		        		break;
		        	case 30:
		        		player1 = IMG_Load("walkL3.png");
		        		break;
		        }
		        
		        if(frame < 30)
		        {
		        	frame++;
		        }
		        else
		        {
		        	frame = 0;
		        }
	    	}
	    	
	if(aVel == 1)
	        {
				switch (frame2)
		        {
		        	case 10:
		        		player2 = IMG_Load("2walkR1.png");
		        		break;
		        	case 20:
		        		player2 = IMG_Load("2walkR2.png");
		        		break;
		        	case 30:
		        		player2 = IMG_Load("2walkR3.png");
		        		break;
		        }
		        
		        if(frame2 < 30)
		        {
		        	frame2++;
		        }
		        else
		        {
		        	frame2 = 0;
		        }
	    	}
	    	else if(aVel == -1)
	        {
				switch (frame2)
		        {
		        	case 10:
		        		player2 = IMG_Load("2walkL1.png");
		        		break;
		        	case 20:
		        		player2 = IMG_Load("2walkL2.png");
		        		break;
		        	case 30:
		        		player2 = IMG_Load("2walkL3.png");
		        		break;
		        }
		        
		        if(frame2 < 30)
		        {
		        	frame2++;
		        }
		        else
		        {
		        	frame2 = 0;
		        }
	    	}
	    	
			/* starts to play attack animation 
			if attack button was pressed.
			   It does damage if the players
			   are facing each other and
			   are within range */
			if(attack==true)
	    	{
	    		
	    		switch(frame3)
	    		{
	    			case 7:
		        		player1 = IMG_Load("attack1.png");
		        		break;
		        	case 14:
		        		player1 = IMG_Load("attack2.png");
		        		break;
		        	case 21:
		        		player1 = IMG_Load("attack3.png");
						break;
					case 28:
		        		player1= IMG_Load("idleRight.png");
		        		attack = false;
		        		if((pos2.x - pos1.x) <= 39 && (pos2.x - pos1.x) >= 0)
				        {
				        	health2 = health2 - 10;
				        }
		        		break;
	    		}
	    		
	    		if(frame3 < 28)
		        {
		        	frame3++;
		        }
		        else
		        {
		        	frame3 = 0;
		        }
		        
		        
	    	}
	    	else if(attackLeft==true)
	    	{
	    		
	    		switch(frame4)
	    		{
	    			case 7:
		        		player1 = IMG_Load("attack1Left.png");
		        		break;
		        	case 14:
		        		player1 = IMG_Load("attack2Left.png");
		        		break;
		        	case 21:
		        		player1 = IMG_Load("attack3Left.png");
						break;
					case 28:
		        		player1= IMG_Load("idle.png");
		        		attackLeft = false;
		        		if((pos1.x - pos2.x) <= 39 && (pos1.x - pos2.x) >= 0)
				        {
				        	health2 = health2 - 10;
				        }
		        		break;
	    		}
	    		
	    		if(frame4 < 28)
		        {
		        	frame4++;
		        }
		        else
		        {
		        	frame4 = 0;
		        }
		        
		        
	    	}
	       	if(attack2==true)
	    	{
	    		
	    		switch(frame5)
	    		{
	    			case 7:
		        		player2 = IMG_Load("2attack1.png");
		        		break;
		        	case 14:
		        		player2 = IMG_Load("2attack2.png");
		        		break;
		        	case 21:
		        		player2 = IMG_Load("2attack3.png");
						break;
					case 28:
		        		player2 = IMG_Load("2idleRight.png");
		        		attack2 = false;
		        		if((pos1.x - pos2.x) <= 39 && (pos1.x - pos2.x) >= 0)
				        {
				        	health1 = health1 - 10;
				        }
		        		break;
	    		}
	    		
	    		if(frame5 < 28)
		        {
		        	frame5++;
		        }
		        else
		        {
		        	frame5 = 0;
		        }
		        
	    	}
	    	else if(attack2Left==true)
	    	{
	    		
	    		switch(frame6)
	    		{
	    			case 7:
		        		player2 = IMG_Load("2attack1Left.png");
		        		break;
		        	case 14:
		        		player2 = IMG_Load("2attack2Left.png");
		        		break;
		        	case 21:
		        		player2 = IMG_Load("2attack3Left.png");
						break;
					case 28:
		        		player2= IMG_Load("2idle.png");
		        		attack2Left = false;
		        		if((pos2.x - pos1.x) <= 39 && (pos2.x - pos1.x) >= 0)
				        {
				        	health1 = health1 - 10;
				        }
		        		break;
	    		}
	    		
	    		if(frame6 < 28)
		        {
		        	frame6++;
		        }
		        else
		        {
		        	frame6 = 0;
		        }
		        
		        
	    	}
	    	
	    	//Determine which healthbar image to load
	    	switch(health1)
	    	{
	    		case 100: healthplayer1 = IMG_Load("p1_1002.png");
	    					break;
	    		case 90: healthplayer1 = IMG_Load("p1_902.png");
	    					break;
	    		case 80: healthplayer1 = IMG_Load("p1_802.png");
	    					break;
	    		case 70: healthplayer1 = IMG_Load("p1_702.png");
	    					break;
	    		case 60: healthplayer1 = IMG_Load("p1_602.png");
	    					break;
	    		case 50: healthplayer1 = IMG_Load("p1_502.png");
	    					break;
	    		case 40: healthplayer1 = IMG_Load("p1_402.png");
	    					break;
	    		case 30: healthplayer1 = IMG_Load("p1_302.png");
	    					break;
	    		case 20: healthplayer1 = IMG_Load("p1_202.png");
	    					break;
	    		case 10: healthplayer1 = IMG_Load("p1_102.png");
	    					break;
	    		case 0: healthplayer1 = IMG_Load("p1_02.png");
	    					break;
	    	}
	    	switch(health2)
	    	{
	    		case 100: healthplayer2 = IMG_Load("p2_1002.png");
	    					break;
	    		case 90: healthplayer2 = IMG_Load("p2_902.png");
	    					break;
	    		case 80: healthplayer2 = IMG_Load("p2_802.png");
	    					break;
	    		case 70: healthplayer2 = IMG_Load("p2_702.png");
	    					break;
	    		case 60: healthplayer2 = IMG_Load("p2_602.png");
	    					break;
	    		case 50: healthplayer2 = IMG_Load("p2_502.png");
	    					break;
	    		case 40: healthplayer2 = IMG_Load("p2_402.png");
	    					break;
	    		case 30: healthplayer2 = IMG_Load("p2_302.png");
	    					break;
	    		case 20: healthplayer2 = IMG_Load("p2_202.png");
	    					break;
	    		case 10: healthplayer2 = IMG_Load("p2_102.png");
	    					break;
	    		case 0: healthplayer2 = IMG_Load("p2_02.png");
	    					break;
	    	}
	    	
	    	//Determines who wins
			if (health1==0&&health2>0)
			{
					background = IMG_Load("winner2.png");
			}
			
			if (health2==0&&health1>0)
			{
					background = IMG_Load("winner1.png");
			}
		
	        //Apply the surfaces
			SDL_BlitSurface( background, NULL, screen, 0 );
			SDL_BlitSurface( player1, NULL, screen, &pos1 );
	        SDL_BlitSurface( player2, NULL, screen, &pos2 );
	        if(health1 > 0 && health2 > 0){
				SDL_BlitSurface( healthplayer1, NULL, screen, &healthpos1 );
				SDL_BlitSurface( healthplayer2, NULL, screen, &healthpos2 );
			}
			
	        //Update the screen
			SDL_Flip( screen );
    	}
    	
    } while (menuGame != 3);
  
    //Quit SDL
    SDL_FreeSurface(healthplayer1);
    SDL_FreeSurface(healthplayer2);
	SDL_FreeSurface( player1 );
    SDL_FreeSurface( player2 );
    SDL_FreeSurface( background );
    SDL_Quit();
  
    return 0;
} 
