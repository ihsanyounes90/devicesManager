/* 
 * File:   KeyboardDevice.cpp
 * Author: Ihsan Younes
 */

#include "KeyboardDevice.h"
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h> 

KeyboardDevice::KeyboardDevice() {
    active = false;
}

KeyboardDevice::~KeyboardDevice() {

}


void KeyboardDevice::start() {
    active = true;
    
    //start the key listening
    keyListener();
}

void KeyboardDevice::stop() {
    active = false;
}

/**
 * Utility method to check if a key was pressed 
 * @return 
 */
int kbhit(void){
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

void KeyboardDevice::keyListener() {
    
    //Setup screen
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);    
    
    
    printw("Press [ctrl+c] to finish...\n\n");
    
    //Iterate until a stop is called
    while (active) {
        
        if (kbhit()) {
            printw("Key press received! %d\n", getch());
            
            //send a notification of message received
            messageReceived();
            refresh();
        } else {
            printw("No key pressed yet...\n");
            refresh();
            sleep(2);
        }
    }
}

