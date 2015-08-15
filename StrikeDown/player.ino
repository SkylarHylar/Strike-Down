void play(){
  while(true){
    if(gb.update()){
      if((lives > 0) && (pause == false)){

        //enemy counter
        enemies = bouncers + hunters + floaters;
        if(enemies == 0){
          bouncers = random(1,5);
          hunters = random(0,5);
          floaters = random(1,5);
          rest = 150;
          dactyltime = 450;
          stage = stage + 1;
        }

        //Random Spawn
        if(spawn == 0){
          spawnx = 8;
          spawny = 11;
        }
        if(spawn == 1){
          spawnx = 40;
          spawny = 19;
        }
        if(spawn == 2){
          spawnx = 76;
          spawny = 11;
        }

        //Rest variable(so the player can have a break)
        if(rest > 0){
          rest = rest - 1;
          gb.display.cursorX = 30;
          gb.display.cursorY = 14;
          gb.display.print("Stage ");
          gb.display.print(stage);
        }

        //wait counter (for timing)
        wait = wait + 1;
        if(wait == 20){
          wait = 0;
        }

        //Pterodactyl
        if((dactyltime > 0) && (rest == 0)){
          dactyltime = dactyltime - 1;
          dactylx  = 84;
        }
        if(dactyltime == 0){
          gb.display.drawBitmap(dactylx,dactyly,dactyl);
          dactylx = dactylx - 1;
          if(dactylx <= -15){
            dactylx = 91;
          }
          if(dactylx >= 92){
            dactylx = -14;
          }
          if((dactyly < playery) && (wait == 0 || 10)){
            dactyly = dactyly + 1;
          }
          else if(wait == 0 || 10){
            dactyly = dactyly - 1;
          }
        }

        //Floater
        if(floaterx <= -7){
          floaterx = 83;
        }
        if(floaterx >= 84){
          floaterx = -6;
        }
        if(floategg == false){
          if((floaters > 0) && (rest == 0)){
            floatergrav = 0;
            gb.display.drawBitmap(floaterx, floatery, floater, NOROT, floaterflip);
            if(floaterleft == true){
              if(wait == 0 || 5 || 10 || 15){
                floaterxv = -1;
                floaterx = floaterx + floaterxv;
                floaterflip = NOFLIP;
              }
            }
            if(floaterleft == false){
              if(wait == 0 || 5 || 10 || 15){
                floaterxv = +1;
                floaterx = floaterx + floaterxv;
                floaterflip = FLIPH;
              }
            }
            if(wait == 0 || 10){
              floatery = random(floaterline - 1,floaterline + 1);
            }
            
          }
        }
        if(floategg == true){
          floatery = floatery + floatergrav;
          floaterx = floaterx + floaterxv;
          gb.display.drawBitmap(floaterx, floatery, egg, NOROT, floaterflip);
          floatergrav = 1;
        }

        //Bouncer
        if(bouncerx <= -7){
          bouncerx = 83;
         }
        if(bouncerx >= 84){
          bouncerx = -6;
        }
        if(bounceegg == false){
          if((bouncers > 0) && (rest == 0)){
            bouncery = bouncery + bouncergrav;
            bouncerx = bouncerx + bouncerxv;
            gb.display.drawBitmap(bouncerx, bouncery, bouncer, NOROT, bouncerflip);
            
            if((bouncery < playery) && (wait == 0) && (bouncergrav < 1)){
              bouncergrav = bouncergrav + 1;
            }
            if(bouncery == playery){
              bouncergrav = 0;
            }
            if((bouncery > playery) && (wait == 0) && (bouncergrav > -1)){
            bouncergrav = bouncergrav - 1;
            }
            if((bouncerx < playerx) && (wait == 0) && (bouncerxv < 1)){
              bouncerxv = bouncerxv + 1;
              bouncerflip = FLIPH;
            }
            if((bouncerx > playerx) && (wait == 0) && (bouncerxv > -1)){
              bouncerxv = bouncerxv - 1;
              bouncerflip = NOFLIP;
            }
          }
        }
        if(bounceegg == true){
          bouncery = bouncery + bouncergrav;
          bouncerx = bouncerx + bouncerxv;
          gb.display.drawBitmap(bouncerx, bouncery, egg, NOROT, bouncerflip);
          bouncergrav = 1;
        }

        //Hunter
        if(hunterx <= -7){
          hunterx = 83;
        }
        if(hunterx >= 84){
          hunterx = -6;
        }
        if(huntegg == false){
          if((hunters > 0) && (rest == 0)){
            huntery = huntery + huntergrav;
            hunterx = hunterx + hunterxv;
            gb.display.drawBitmap(hunterx, huntery, hunter, NOROT, hunterflip);
            if(alive == true){
              if(huntery == playery){
                huntergrav = 0;
              }
              if((huntery < playery) && (wait == 10) && (huntergrav < 1)){
                huntergrav = huntergrav + 1;
              }
              if((huntery > playery) && (wait == 10) && (huntergrav > -1)){
                huntergrav = huntergrav - 1;
              }
              if(hunterx < playerx){
                hunterx = hunterx + 1;
                hunterflip = FLIPH;
              }
              if(hunterx > playerx){
                hunterx = hunterx - 1;
                hunterflip = NOFLIP;
              }
            }
          }
        }
        if(huntegg == true){
          huntery = huntery + huntergrav;
          hunterx = hunterx + hunterxv;
          gb.display.drawBitmap(hunterx, huntery, egg, NOROT, hunterflip);
          huntergrav = 1;
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
        if((gb.collideBitmapBitmap(playerx, playery, playerfly, dactylx, dactyly, dactyl)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, dactylx, dactyly, dactyl)) == true){
          if(dactyltime == 0){
            if(playery <= dactyly - 3){
              dactyltime = 450;
            }
            else if(alive == true){
              dactyltime = 450;
              gb.sound.playNote(1, 28, 1);
              gb.sound.command(1, 1, 0, 1);
              gb.sound.command(2, 7, -2, 1);
              alive = false;
              lives = lives - 1;
            } 
          } 
        }
        if((gb.collideBitmapBitmap(playerx, playery, playerfly, floaterx, floatery, floater)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, floaterx, floatery, floater)) == true){
          if(floaters > 0){
            if(playery <= floatery - 1){
              floaterx = floaterx + 2;
              floatery = floatery + 2;
              floategg = true;
            }
            else if((alive == true) && (rest == 0)){
              gb.sound.playNote(1, 28, 1);
              gb.sound.command(1, 1, 0, 1);
              gb.sound.command(2, 7, -2, 1);
              alive = false;
              lives = lives - 1;
            }  
          }
        }
        if((gb.collideBitmapBitmap(playerx, playery, playerfly, bouncerx, bouncery, bouncer)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, bouncerx, bouncery, bouncer)) == true){
          if(bouncers > 0){
            if(playery <= bouncery - 1){
              bouncerx = bouncerx + 2;
              bouncery = bouncery + 2;
              bounceegg = true;
            }
            else if((bouncerflip == FLIPH) && (alive == true) && (rest == 0)){
              playerxv = 1;
              bouncerxv = -1;
              playerflip = FLIPH;
            }
            else if((alive == true) && (rest == 0)){
              playerxv = -1;
              bouncerxv = 1;
              playerflip = NOFLIP;
            }
          }
        }
        if((gb.collideBitmapBitmap(playerx, playery, playerfly, hunterx, huntery, hunter)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, hunterx, huntery, hunter)) == true){
          if(hunters > 0){
            if(playery <= huntery - 1){
              hunterx = hunterx + 2;
              huntery = huntery + 2;
              huntegg = true;
            }
            else if((alive == true) && (rest == 0)){
              gb.sound.playNote(1, 28, 1);
              gb.sound.command(1, 1, 0, 1);
              gb.sound.command(2, 7, -2, 1);
              alive = false;
              lives = lives - 1;
            }
          }  
        }
        if((gb.collideBitmapBitmap(playerx, playery, playerfly, floaterx, floatery, egg)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, floaterx, floatery, egg)) == true){
          if(floaters > 0){
            spawn = random(0,2);
            floaterline = random(4,11);
            floaterx = -10;
            floatery = 0;
            floaterxv = 0;
            floaters = floaters - 1;
            floaterleft = random(0,1);
          }
          floategg = false;
        }
        if((gb.collideBitmapBitmap(playerx, playery, playerfly, bouncerx, bouncery, egg)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, bouncerx, bouncery, egg)) == true){
          if(bouncers > 0){
            spawn = random(0,2);
            bouncerx = spawnx;
            bouncery = spawny;
            bouncerxv = 0;
            bouncergrav = 0;
            bouncers = bouncers - 1;
          }
          bounceegg = false;
        }
        if((gb.collideBitmapBitmap(playerx, playery, playerfly, hunterx, huntery, egg)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, hunterx, huntery, egg)) == true){
          if(hunters > 0){
            spawn = random(0,2);
            hunterx = spawnx;
            huntery = spawny;
            hunterxv = 0;
            huntergrav = 0;
            hunters = hunters - 1;
          }
          huntegg = false;
        }

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
        gb.display.drawBitmap(14, 40, platform);
        if(stage < 3){
          gb.display.drawBitmap(0, 40, bridge, NOROT, FLIPH);
          gb.display.drawBitmap(70, 40, bridge);
        }
        if(stage < 6){
          gb.display.drawBitmap(30, 26, platform2);
        }
        if(stage < 9){
          gb.display.drawBitmap(0, 16, platform3);
        }
        if(stage < 11){
          gb.display.drawBitmap(68, 16, platform3);
        }
        if(lives < 1){
          gb.display.drawBitmap(18, 0, life);
        }
        if(lives < 2){
          gb.display.drawBitmap(24, 42, life);
        }
        if(lives < 3){
          gb.display.drawBitmap(30, 42, life);
        }
        if(lives < 4){
          gb.display.drawBitmap(36, 42, life);
        }
        
          
          //Player Collision
          if((gb.collideBitmapBitmap(playerx, playery, playerfly, 14, 40, platform)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, 14, 40, platform)) == true){
            if(playery < 35){
              playery = 33;
              playergrav = 0;
              ground = true;
            }
          }
          else if((gb.collideBitmapBitmap(playerx, playery, playerfly, 30, 26, platform2)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, 30, 26, platform2)) == true){
            if(stage < 6){
              if(playery < 21){
                playery = 19;
                ground = true;
              } 
              else{
                playery = playery + 1;
              }
              playergrav = 0;
            }
          }
          else if((gb.collideBitmapBitmap(playerx, playery, playerfly, 0, 16, platform3)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, 0, 16, platform3)) == true){
            if(stage < 9){
              if(playery < 11){
                playery = 9;
                ground = true;
              } 
              else{
                playery = playery + 1;
              }
              playergrav = 0;
            }
          }
          else if((gb.collideBitmapBitmap(playerx, playery, playerfly, 68, 16, platform3)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, 68, 16, platform3)) == true){
            if(stage < 11){
              if(playery < 11){
                playery = 9;
                ground = true;
              } 
              else{
                playery = playery + 1;
              }
              playergrav = 0;
            }
          }
          else if((gb.collideBitmapBitmap(playerx, playery, playerfly, 0, 40, bridge)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, 0, 40, bridge)) == true){
            if(stage < 3){
              playery = 33;
              playergrav = 0;
              ground = true;
            }
          }
          else if((gb.collideBitmapBitmap(playerx, playery, playerfly, 70, 40, bridge)) || (gb.collideBitmapBitmap(playerx, playery, playerstand, 70, 40, bridge)) == true){
            if(stage < 3){
              playery = 33;
              playergrav = 0;
              ground = true;
            }
          }
          else if(playery <= -1){
            playery = 0;
            playergrav = 0;
          }
          else {
            ground = false;
            if(wait == 10){
            playergrav = playergrav + 1;
            }
          }

          //Hunter Collision
          if(gb.collideBitmapBitmap(hunterx, huntery, hunter, 14, 40, platform) == true){
            if(huntery < 37){
              huntery = 35;
              huntergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(hunterx, huntery, hunter, 30, 26, platform2) == true){
            if(stage < 6){
              if(huntery < 21){
                huntery = 19;
              } 
              else{
                huntery = huntery + 1;
              }
              huntergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(hunterx, huntery, hunter, 0, 16, platform3) == true){
            if(stage < 9){
              if(huntery < 13){
                huntery = 11;
              }
              else{
                huntery = huntery + 1;
              }
              huntergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(hunterx, huntery, hunter, 68, 16, platform3) == true){
            if(stage < 6){
              if(huntery < 13){
                huntery = 11;
              }
              else{
                huntery = huntery + 1;
              }
              huntergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(hunterx, huntery, hunter, 0, 40, bridge) == true){
            if(stage < 3){
              huntery = 35;
              huntergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(hunterx, huntery, hunter, 70, 40, bridge) == true){
            if(stage < 3){
              huntery = 35;
              huntergrav = 0;
            }
          }
          else if(huntery <= -1){
            huntery = 0;
            huntergrav = 0;
          }

          //Floater Egg
          if(gb.collideBitmapBitmap(floaterx, floatery, egg, 14, 40, platform) == true){
            floatery = 36;
            floaterxv = 0;
            floatergrav = 0;
          }
          else if(gb.collideBitmapBitmap(floaterx, floatery, egg, 30, 26, platform2) == true){
            if(stage < 6){
              floatery = 22;
              floaterxv = 0;
              floatergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(floaterx, floatery, egg, 0, 16, platform3) == true){
            if(stage < 9){
              floatery = 12;
              floaterxv = 0;
              floatergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(floaterx, floatery, egg, 68, 16, platform3) == true){
            if(stage < 11){
              floatery = 12;
              floaterxv = 0;
              floatergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(floaterx, floatery, egg, 0, 40, bridge) == true){
            if(stage < 3){
              floatery = 36;
              floatergrav = 0;
              floaterxv = 0;
            }
          }
          else if(gb.collideBitmapBitmap(floaterx, floatery, egg, 70, 40, bridge) == true){
            if(stage < 3){
              floatery = 36;
              floatergrav = 0;
              floaterxv = 0;
            }
          }

          //Bouncer Egg
          if(gb.collideBitmapBitmap(bouncerx, bouncery, egg, 14, 40, platform) == true){
            bouncery = 36;
            bouncerxv = 0;
            bouncergrav = 0;
          }
          else if(gb.collideBitmapBitmap(bouncerx, bouncery, egg, 30, 26, platform2) == true){
            if(stage < 6){
              bouncery = 22;
              bouncerxv = 0;
              bouncergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(bouncerx, bouncery, egg, 0, 16, platform3) == true){
            if(stage < 9){
              bouncery = 12;
              bouncerxv = 0;
              bouncergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(bouncerx, bouncery, egg, 68, 16, platform3) == true){
            if(stage < 11){
              bouncery = 12;
              bouncerxv = 0;
              bouncergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(bouncerx, bouncery, egg, 0, 40, bridge) == true){
            if(stage < 3){
              bouncery = 36;
              bouncergrav = 0;
              bouncerxv = 0;
            }
          }
          else if(gb.collideBitmapBitmap(bouncerx, bouncery, egg, 70, 40, bridge) == true){
            if(stage < 3){
              bouncery = 36;
              bouncergrav = 0;
              bouncerxv = 0;
            }
          }

          //Hunter Egg
          if(gb.collideBitmapBitmap(hunterx, huntery, egg, 14, 40, platform) == true){
            huntery = 36;
            hunterxv = 0;
            huntergrav = 0;
          }
          else if(gb.collideBitmapBitmap(hunterx, huntery, egg, 30, 26, platform2) == true){
            if(stage < 6){
              huntery = 22;
              hunterxv = 0;
              huntergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(hunterx, huntery, egg, 0, 16, platform3) == true){
            if(stage < 9){
              huntery = 12;
              hunterxv = 0;
              huntergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(hunterx, huntery, egg, 68, 16, platform3) == true){
            if(stage < 11){
              huntery = 12;
              hunterxv = 0;
              huntergrav = 0;
            }
          }
          else if(gb.collideBitmapBitmap(hunterx, huntery, egg, 0, 40, bridge) == true){
            if(stage < 3){
              huntery = 36;
              huntergrav = 0;
              hunterxv = 0;
            }
          }
          else if(gb.collideBitmapBitmap(hunterx, huntery, egg, 70, 40, bridge) == true){
            if(stage < 3){
              huntery = 36;
              huntergrav = 0;
              hunterxv = 0;
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
        gb.display.print(lives);
        gb.display.println(" lives");
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
