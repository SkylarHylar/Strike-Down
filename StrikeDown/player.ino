void play(){
  while(true){
    if(gb.update()){
      if((lives > 0) && (pause == false)){
        
        wait = wait + 1;
        if(wait == 10){
          wait = 0;
        }
        
        //Player
        playery = playery + playergrav;
        playerx = playerx + playerxv;
        if(ground && alive == true) {
          gb.display.drawBitmap(playerx,playery,playerstand,NOROT,playerflip);
        }
        if((ground == false) && (alive == true)){
          gb.display.drawBitmap(playerx,playery,playerfly,NOROT,playerflip);
        }
        if (gb.buttons.repeat(BTN_LEFT,15)){
          playerxv = playerxv - 1;
          playerflip = NOFLIP;
        };
        if (gb.buttons.repeat(BTN_RIGHT,15)){
          playerxv = playerxv + 1;
          playerflip = FLIPH;
        };
        if(playerxv >= 3){
          playerxv = 2;
        }
        if(playerxv <= -3){
          playerxv = -2;
        }
        if(playerx <= -7){
          playerx = 83;
        }
        if(playerx >= 84){
          playerx = -6;
        }
        if ((gb.buttons.pressed(BTN_A)) || (gb.buttons.pressed(BTN_B))){
            gb.sound.playNote(5, 8, 1);
            gb.sound.command(0, 4, 0, 1);
            gb.sound.command(1, 1, 0, 1);
            gb.sound.command(4, 8, 3, 1);
            playery = playery - 1;
            playergrav = playergrav - 1;
        };
        if (gb.buttons.repeat(BTN_C,20)){
            pause = true;
        };
        //Death Code

        if(playery >= 50){
          gb.sound.playNote(1, 28, 1);
          gb.sound.command(1, 1, 0, 1);
          gb.sound.command(2, 7, -2, 1);
          alive = false;
          lives = lives - 1;
        };

        if(alive == false){
          playerx = 38;
          playery = 33;
          playerxv = 0;
          playerflip = NOFLIP;
          playergrav = 1;
          if(wait == 9){
            alive = true;
          }
        }
          //Drawing
        gb.display.drawBitmap(16, 40, platform);
        gb.display.drawBitmap(30, 26, platform2);
        gb.display.drawBitmap(0, 16, platform3);
        gb.display.drawBitmap(68, 16, platform3);
          
          //Player Collision
          if((gb.collideBitmapBitmap(playerx, playery, playerfly, 16, 40, platform)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, 16, 40, platform)) == true){
            playery = 33;
            playergrav = 0;
            ground = true;
          }
          else if((gb.collideBitmapBitmap(playerx, playery, playerfly, 30, 26, platform2)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, 30, 26, platform2)) == true){
            if(playery < 28){
              playery = 19;
              ground = true;
            } 
            else{
              playery = playery + 1;
            }
            playergrav = 0;
          }
          else if((gb.collideBitmapBitmap(playerx, playery, playerfly, 0, 16, platform3)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, 0, 16, platform3)) == true){
            if(playery < 10){
              playery = 9;
              ground = true;
            }
            else{
              playery = playery + 1;
            }
            playergrav = 0;
          }
          else if((gb.collideBitmapBitmap(playerx, playery, playerfly, 68, 16, platform3)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, 68, 16, platform3)) == true){
            if(playery < 10){
              playery = 9;
              ground = true;
            }
            else{
              playery = playery + 1;
            }
            playergrav = 0;
          }
          else if(playery <= -1){
            playery = 0;
            playergrav = 0;
          }
          else {
            ground = false;
            if(wait == 0){
            playergrav = playergrav + 1;
            }
          }
      };
      
      if(pause == true){
        gb.display.setFont(font5x7);
        gb.display.cursorX = 24;
        gb.display.cursorY = 4;
        gb.display.drawRect(0,0,84,48);
        gb.display.println("PAUSED");
        gb.display.cursorX = 8;
        gb.display.println(" ");
        gb.display.cursorX = 8;
        gb.display.println(" ");
        gb.display.cursorX = 8;
        gb.display.println("\26 to resume");
        if(gb.buttons.pressed(BTN_B)) {
          gb.display.setFont(font3x5);
          pause = false;
        };
      };
      
      if(lives <= 0){
        gb.setFrameRate(30);
        gb.display.setFont(font5x7);
        gb.display.drawRect(0,0,84,48);
        gb.display.cursorY = 2;
        gb.display.cursorX = 16;
        gb.display.println("You died!");
        gb.display.cursorX = 8;
        gb.display.println("");
        gb.display.cursorX = 20;
        gb.display.cursorY = 38;
        gb.display.println("Press \26");
        if (gb.buttons.pressed(BTN_B)){
          gb.sound.playCancel();
          break;
          break;
          break;
        };
      };
    };
  };
};
