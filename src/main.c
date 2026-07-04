#include <stdio.h>
#include <gb/gb.h>
#include <gbdk/font.h>
#include "res/cat_sprite.h"
#include "res/background.h"
#include "res/background_tiles.h"
#include "res/window_map.h"

BYTE jumping;
INT8 playerlocation[2];
UINT8 gravity=-2;
UINT8 currentspeedY;
UINT8 floorYPosition=100;


void animation_left(UINT8 *index){
    *index=(*index==26)?27:26;
    set_sprite_tile(0,*index);}

void animation_right(UINT8 *index){
    *index=(*index==28)?29:28;
    set_sprite_tile(0,*index);}

//method instead of delay
void performantdelay(UINT8 numloops){
    for(UINT8 i=0; i<numloops; i++){wait_vbl_done();}}

INT8 wouldHitSurface(UINT8 projectedYPosition){
    if(projectedYPosition>=floorYPosition){
        return floorYPosition;
    } else {return -1;}}

void jump(UINT8 spriteID, UINT8 spriteLocation[2]){
    INT8 possibleSurfaceY;
    if(jumping==0){
        jumping=1;
        currentspeedY=13;} //jump heigth
    currentspeedY=currentspeedY+gravity; //pull down!
    spriteLocation[1]=spriteLocation[1]-currentspeedY;
    possibleSurfaceY = wouldHitSurface(playerlocation[1]);
    if(possibleSurfaceY>-1){
        jumping=0;
        move_sprite(spriteID,spriteLocation[0],possibleSurfaceY);
    } else {move_sprite(spriteID,spriteLocation[0],spriteLocation[1]);}}

void main(void){

    //variables
    UINT8 current_sprite_index = 28;
    jumping=0;

    //font
    font_t min_font;
    font_init();
    min_font = font_load(font_min);
    font_set(min_font);

    //show sprite
    set_sprite_data(26,4,cat);
    set_sprite_tile(0,26); //first sprite load from tile 0 in sprite data
    playerlocation[0]=10; //x coordinate
    playerlocation[1]=100; //y coordinate
    move_sprite(0,playerlocation[0],playerlocation[1]); //move sprite zero to the coordinates, initial position
    SHOW_SPRITES;

    //background and head display
    set_bkg_data(37,14,backgroundtiles);
    set_bkg_tiles(0,0,40,18, backgroundmap);
    set_win_tiles(0,0,12,1,windowmap);
    move_win(7,130);
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    //enable sound (order important!!!)
    NR52_REG=0x80; //turns sound on
    NR50_REG=0x77; //sets volume to max
    NR51_REG=0xFF; //selects channel

    //game loop
    while(1){
        UBYTE joypad_state=joypad();

        /*//overlay sound
        if(overlay){
            NR10_REG=0x34;
            NR11_REG=0x42;
            NR12_REG=0x44;
            NR13_REG=0x73;
            NR14_REG=0x86;}

        //damage sound
        if(damage){
            NR10_REG=0x3E;
            NR11_REG=0x81;
            NR12_REG=0x43;
            NR13_REG=0x73;
            NR14_REG=0x86;}

        //jump sound
        if(jump){
            NR10_REG=0x26;
            NR11_REG=0x81;
            NR12_REG=0x43;
            NR13_REG=0x73;
            NR14_REG=0x86;}

        //collect sound
        if(collect){
            NR10_REG=0x24;
            NR11_REG=0x81;
            NR12_REG=0x43;
            NR13_REG=0x73;
            NR14_REG=0x86;}*/

        //walking
        switch(joypad()){
            case J_LEFT:
                playerlocation[0]=playerlocation[0]-5;
                move_sprite(0,playerlocation[0],playerlocation[1]);
                animation_left(&current_sprite_index);
                scroll_bkg(-5,0);
                break;
            case J_RIGHT:
                playerlocation[0]=playerlocation[0]+5;
                move_sprite(0,playerlocation[0],playerlocation[1]);
                animation_right(&current_sprite_index);
                scroll_bkg(5,0);
                break;}

        if((joypad()&J_A) || jumping==1){jump(0,playerlocation);}
        performantdelay(5); //to avoid fast switching
    }
}