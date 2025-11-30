/*
CSC 134
M6HW1 - Project Prototype (Gold)
Josue Rodriguez
11/30/25

Blizzard Escape: Gold Tier
*/

#include <iostream>
using namespace std;

// Global state for this simple prototype
bool hasKeycard = false;     // Did the player find the key?
bool doorUnlocked = false;   // Has the control room door been unlocked?
bool gameOver = false;       // Ends the game loop when true
bool escaped = false;        // True if the player wins

// Function declarations (each acts like a “room”)
void intro();
void outside();
void storageRoom();
void lockedDoor();
void controlRoom();
void ending();

// -------------------- main --------------------
int main() {
    intro();
    // Start the game “outside” the outpost
    outside();

    // When the story is finished, show the ending screen
    ending();
    return 0;
}

// -------------------- intro --------------------
void intro() {
    cout << "=============================================\n";
    cout << "      BLIZZARD OUTPOST ESCAPE (Prototype)\n";
    cout << "=============================================\n\n";
    cout << "You are caught in a sudden blizzard while hiking.\n";
    cout << "Barely able to see, you stumble upon a dark, \n";
    cout << "seemingly abandoned research outpost at the base \n";
    cout << "of a mountain.\n\n";
    cout << "If you can get inside and power up the radios in\n";
    cout << "the control room, you might survive the night...\n\n";
}

// -------------------- outside --------------------
void outside() {
    while (!gameOver && !escaped) {
        int choice;

        cout << "\n--- Outside the Outpost ---\n";
        cout << "Snow whips around you. You see:\n";
        cout << "  1) The MAIN DOOR to the outpost.\n";
        cout << "  2) A small STORAGE SHED partly buried in snow.\n";
        cout << "  3) Give up and sit in the snow (quit).\n";
        cout << "Choose 1, 2, or 3: ";
        cin >> choice;

        if (choice == 1) {
            lockedDoor();
        } else if (choice == 2) {
            storageRoom();
        } else if (choice == 3) {
            cout << "\nYou sit down in the snow as the wind howls...\n";
            cout << "Probably not your best decision.\n";
            gameOver = true;
        } else {
            cout << "\nThat isn't an option. Try again.\n";
        }

        // If we escaped or died inside another room, leave the loop
        if (gameOver || escaped) {
            break;
        }
    }
}

// -------------------- storageRoom --------------------
void storageRoom() {
    int choice;

    cout << "\n--- Storage Shed ---\n";
    cout << "You force open the frozen shed door. Inside are\n";
    cout << "boxes, broken tools, and a dusty locker.\n\n";

    if (!hasKeycard) {
        cout << "On a hook you notice an old ID KEYCARD hanging.\n";
        cout << "This might open a door inside the outpost.\n\n";
        cout << "  1) Take the keycard.\n";
        cout << "  2) Leave everything and go back outside.\n";
        cout << "Choose 1 or 2: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nYou take the keycard and slip it into your pocket.\n";
            hasKeycard = true;
        } else {
            cout << "\nYou decide not to take anything.\n";
        }
    } else {
        cout << "You’ve already taken the keycard. There’s nothing\n";
        cout << "else useful here.\n";
    }

    cout << "\nYou head back out into the storm.\n";
    // Return to the outside “room”
}

// -------------------- lockedDoor --------------------
void lockedDoor() {
    int choice;

    cout << "\n--- Main Door ---\n";
    cout << "You reach the heavy metal door. Next to it is a\n";
    cout << "card reader with a faint blinking light.\n";

    if (!doorUnlocked) {
        if (hasKeycard) {
            cout << "\nYou swipe the keycard. The light turns green\n";
            cout << "and you hear a loud CLICK.\n";
            doorUnlocked = true;
        } else {
            cout << "\nYou pull on the handle, but it won't budge.\n";
            cout << "A slot next to the door looks like it needs a keycard.\n";
            cout << "Without it, you'll have to go back.\n";
            cout << "\nPress 1 to return outside: ";
            cin >> choice;
            cout << "\nYou fight your way back into the blizzard.\n";
            return; // Back to outside()
        }
    }

    cout << "\nThe door is unlocked and swings open.\n";
    cout << "You step into a dimly lit hallway.\n";
    cout << "At the end of the hall you see a sign: CONTROL ROOM.\n";
    cout << "\nEnter the control room?\n";
    cout << "  1) Yes\n";
    cout << "  2) No, go back outside\n";
    cout << "Choose 1 or 2: ";
    cin >> choice;

    if (choice == 1) {
        controlRoom();
    } else {
        cout << "\nYou decide to head back out to the storm for now.\n";
    }
}

// -------------------- controlRoom --------------------
void controlRoom() {
    int choice;

    cout << "\n--- Control Room ---\n";
    cout << "You enter a cramped room filled with dead screens\n";
    cout << "and a radio console. A backup generator hums softly.\n\n";

    cout << "On the wall is a note:\n";
    cout << "\"IN EMERGENCY: flip MAIN POWER, then press SEND.\"\n\n";

    cout << "What do you do?\n";
    cout << "  1) Flip the MAIN POWER switch.\n";
    cout << "  2) Press random buttons on the console.\n";
    cout << "  3) Leave and go back outside.\n";
    cout << "Choose 1, 2, or 3: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nThe screens flicker to life. A green light flashes\n";
        cout << "on the radio labeled SEND.\n";
        cout << "You press it and speak into the microphone,\n";
        cout << "calling for rescue.\n\n";
        cout << "After a tense moment, a voice answers:\n";
        cout << "\"This is the ranger station. We have your location.\n";
        cout << "Hold tight, we’re sending a snowcat!\"\n";
        escaped = true;
    } else if (choice == 2) {
        cout << "\nYou mash random buttons. The console sparks and the\n";
        cout << "room goes dark again. That was not ideal.\n";
        cout << "Without power, the radios are useless and the\n";
        cout << "generator starts to fail.\n";
        gameOver = true;
    } else if (choice == 3) {
        cout << "\nYou decide to leave the control room for now.\n";
    } else {
        cout << "\nYou hesitate, doing nothing.\n";
    }
}

// -------------------- ending --------------------
void ending() {
    cout << "\n=============================================\n";
    if (escaped) {
        cout << "ENDING: RESCUED\n";
        cout << "Several hours later, bright headlights cut through\n";
        cout << "the whiteout. You are pulled into a warm snowcat\n";
        cout << "and driven away from the abandoned outpost.\n";
        cout << "You survived the blizzard!\n";
    } else if (gameOver) {
        cout << "ENDING: LOST IN THE STORM\n";
        cout << "Your choices have led you to a cold, quiet end.\n";
        cout << "Maybe next time you'll make it to the control room.\n";
    } else {
        cout << "ENDING: GAME EXITED\n";
        cout << "You walk away from the outpost, unsure what might\n";
        cout << "have happened if you had gone inside.\n";
    }
    cout << "=============================================\n";
}
