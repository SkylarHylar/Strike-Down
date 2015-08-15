#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;
#define MENULENGTH 5
const char strSurvival[] PROGMEM = "Survival";
const char strStatus[] PROGMEM = "Status";
const char strCtrl[] PROGMEM = "Controls";
const char strOptions[] PROGMEM = "Options";
const char strTitle[] PROGMEM = "Change Game";
const char* const menu[MENULENGTH] PROGMEM = {
  strSurvival,
  strStatus,
  strCtrl,
  strOptions,
  strTitle,
};
extern const byte Title[];
extern const byte point[];
extern const byte life[];
extern const byte playerstand[];
extern const byte playerfly[];
extern const byte platform[];
extern const byte platform2[];
extern const byte platform3[];
extern const byte bridge[];
extern const byte dactyl[];
extern const byte floater[];
extern const byte bouncer[];
extern const byte hunter[];
extern const byte egg[];
extern const byte font3x5[];
extern const byte font5x7[];
void setup(){
  gb.begin();
  gb.display.setFont(font5x7);
  gb.titleScreen(F(" "), Title);
  gb.battery.show = false;
  gb.display.persistence = false;
  gb.setFrameRate(30);
};

int playerx = 38;
int playery = 36;
int playerxv = 0;
int playerflip = NOFLIP;
int playergrav = 0;
int ground = true;

int floaterx = 20;
int floatery = 20;
int floaterline = 0;
int floaterxv = 0;
boolean floaterleft = false;
int floaterflip = NOFLIP;
int floatergrav = 0;
boolean floategg = false;

int bouncerx = 20;
int bouncery = 20;
int bouncergrav = 0;
int bouncerxv = 0;
int bouncerflip = NOFLIP;
boolean bounceegg = false;

int hunterx = 20;
int huntery = 20;
int huntergrav = 0;
int hunterxv = 0;
int hunterflip = NOFLIP;
boolean huntegg = false;

int bouncers = 0;
int hunters = 0;
int floaters = 0;

int dactylx = 84;
int dactyly = 20;

int wait = 0;
int stage = 0;
int dactyltime = 450;
int enemies = 0;
int spawn = random(0,2);
int spawnx = 0;
int spawny = 0;

int select = 0;

int rest = 150;
int CPU = gb.getCpuLoad();
int RAM = gb.getFreeRam();

boolean pause = false;

boolean pterodactyl = true;
int count = 3;
int fps = 30;

int lives = 0;
boolean alive = true;

void loop(){
  gb.battery.show = false;
  switch(gb.menu(menu, MENULENGTH)){
    case -1: //nothing selected
      gb.titleScreen(Title);
      break;
    case 0: //Load Survival
      gb.display.print(F("    Loading...."));
        gb.pickRandomSeed();
        playerx = 38;
        playery = 33;
        playerxv = 0;
        playerflip = NOFLIP;
        playergrav = 1;

        floaterx = 20;
        floatery = 20;
        floaterline = random(4,11);
        floaterxv = 0;
        floaterleft = false;
        floaterflip = NOFLIP;
        floatergrav = 0;
        floategg = false;

        bouncerx = 20;
        bouncery = 20;
        bouncergrav = 0;
        bouncerxv = 0;
        bouncerflip = NOFLIP;
        bounceegg = false;

        hunterx = 20;
        huntery = 20;
        huntergrav = 0;
        hunterxv = 0;
        hunterflip = NOFLIP;
        huntegg = false;

        bouncers = random(0,5);
        hunters = random(0,5);
        floaters = random(0,5);

        enemies = bouncers + hunters + floaters;

        dactylx = 84;
        dactyly = 20;

        wait = 0;
        stage = 1;
        spawn = random(0,2);
        spawnx = 0;
        spawny = 0;

        rest = 150;
        dactyltime = 450;

        gb.setFrameRate(fps);
        lives = count;

        alive = true;
        pause = false;
        gb.display.setFont(font3x5);
        play();
      break;
    case 1: //Load Status
      while (1) {
        if (gb.update()) {
          if (gb.buttons.pressed(BTN_B)) {
            gb.sound.playCancel();
            gb.battery.show = false;
            break;
          }
          gb.display.drawRect(0,0,84,48);
          gb.display.cursorX = 2;
          gb.display.cursorY = 2;
          CPU = gb.getCpuLoad();
          RAM = gb.getFreeRam();
          gb.display.print("CPU:");
          gb.display.print(CPU);
          gb.display.println("%");
          gb.display.cursorX = 2;
          gb.display.println("");
          gb.display.cursorX = 2;
          gb.display.print("Free RAM: ");
          gb.display.println(RAM);
          gb.display.cursorX = 2;
          gb.display.println("");
          gb.display.cursorX = 2;
          gb.display.println("Press \26");
          gb.battery.show = true;
      };
    };
      break;
    case 2: //Controls
      while (1) {
        if (gb.update()) {
          if (gb.buttons.pressed(BTN_B)) {
            gb.sound.playCancel();
            break;
          }
          gb.display.drawRect(0,0,84,48);
          gb.display.cursorX = 2;
          gb.display.cursorY = 2;
  
          gb.display.println("\25 Jump");
          gb.display.cursorX = 2;
          gb.display.println("");
          gb.display.cursorX = 2;
          gb.display.println("\26 Jump");
          gb.display.cursorX = 2;
          gb.display.println("");
          gb.display.cursorX = 2;
          gb.display.println("\27 Pause");
      };
    };
    case 3: //Controls
      while (1) {
        if (gb.update()) {
          if (gb.buttons.pressed(BTN_B)) {
            gb.sound.playCancel();
            break;
          }
          if (gb.buttons.repeat(BTN_UP, 15)) {
            select = select + 1;
            if(select == 3){
              select = 0;
            }
          }
          if (gb.buttons.repeat(BTN_DOWN, 15)) {
            select = select - 1;
            if(select == -1){
              select = 2;
            }
          }
          gb.display.drawRect(0,0,84,48);
          gb.display.cursorY = 10;
          if(select == 0){
            gb.display.cursorX = 10;
            gb.display.println("Pterodactyl");
            gb.display.cursorX = 2;
            gb.display.println(" ");
            gb.display.cursorX = 34;
            if(pterodactyl == true){
              gb.display.println("YES");
            }
            if(pterodactyl == false){
              gb.display.println("NO!");
            }
            if (gb.buttons.repeat(BTN_A, 15)){
              if(pterodactyl == true){
                pterodactyl = false;
              }
              else {
                pterodactyl = true;
              }
            }
          }
          if(select == 1){
            gb.display.drawBitmap(2, 28, point, NOROT, NOFLIP);
            gb.display.drawBitmap(74, 28, point, NOROT, FLIPH);
            gb.display.cursorX = 26;
            gb.display.println("Lives");
            gb.display.cursorX = 2;
            gb.display.println(" ");
            gb.display.cursorX = 24;
            if(count == 5){
              gb.display.println("Five..");
            }
            if(count == 3){
              gb.display.println("Three?");
            }
            if(count == 1){
              gb.display.println("One!!!");
            }
            if (gb.buttons.repeat(BTN_LEFT, 15)){
              count = count - 2;
              if(count <= -1) {
                count = 5;
              }
            }
            if (gb.buttons.repeat(BTN_RIGHT, 15)){
              count = count + 2;
              if(count >= 7) {
                count = 1;
              }
            }
          }
          if(select == 2){
            gb.display.drawBitmap(2, 28, point, NOROT, NOFLIP);
            gb.display.drawBitmap(74, 28, point, NOROT, FLIPH);
            gb.display.cursorX = 26;
            gb.display.println("Speed");
            gb.display.cursorX = 2;
            gb.display.println(" ");
            gb.display.cursorX = 20;
            if(fps == 45){
              gb.display.println("Fast!!!");
            }
            if(fps == 30){
              gb.display.println("Regular");
            }
            if(fps == 15){
              gb.display.println("Slow...");
            }
            if (gb.buttons.repeat(BTN_LEFT, 15)){
              fps = fps - 15;
              if(fps <= 0) {
                fps = 45;
              }
            }
            if (gb.buttons.repeat(BTN_RIGHT, 15)){
              fps = fps + 15;
              if(fps >= 60) {
                fps = 15;
              }
            }
          }

      };
    };
    break;
    case 4: //Back to the Loader
      gb.changeGame();
      break;
    default:
      break;
  };
};

