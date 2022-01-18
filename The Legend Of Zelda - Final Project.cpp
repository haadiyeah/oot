/*
Haadiya Sajid - BS SE (P) '21
(CS1002) Semester Final Project: Story-Based RPG
*/

#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>

using namespace std;

//Default character name is Link.
char name[100]="Link";
char location='0';
int rupees=0;
float lives=3;
int inv=0, ab=0; //count no of abilities/inventory items
int inventory[13]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int abilities[4]={0, 0, 0, 0};

/* INVENTORY CODES
1 - Deku Shield
2 - Bottle of Milk
3 - Fairy in a bottle
4 - Kokiri Sword
    41 - Sword of Hylia
5 - Fairy Ocarina
6 - Epona
7 - Slingshot
8 - Hookshot
9 - Goron Hammer
10 - Bombuchu
11 - Bow
12 - Fire Arrows
13 - Light Arrows

ABILITIES CODES
1 - Backflip
2 - Goron Punch
3 - Zora Swimming
4 - Gerudo Stealth
*/

void clrscr() {
    system("cls");
}

//func to display text that might also be animated
void show(char x[]) {
    for(int i=0; x[i]!='\0'; i++) {
        cout<<x[i];
    }
}

//typing animation
void type(char x[], int speed=10) {
    for(int i=0; x[i]!='\0'; i++) {
        cout << x[i];
        Sleep(speed);
    }
}

//number codes to access the items using arrays based on character input from user
int itemCode(char item) { //weapons + items both incl
    switch(item) {
    case 'D':
    case 'd':
        return 1;
    case 'm':
    case 'M':
        return 2;
    case 'p':
    case 'P':
        return 21;
    case 'y':
    case 'Y':
        return 22;
    case 'r':
    case 'R':
        return 23;
    case 'a':
    case 'A':
        return 3;
    case 'k':
    case 'K':
        return 4;
    case 'H':
    case 'h':
        return 41;
    case 'o':
    case 'O':
        return 5;
    case 'e':
    case 'E':
        return 6;
    case 's':
    case 'S':
        return 7;
    case 'x':
    case 'X':
        return 8;
    case 'g':
    case 'G':
        return 9;
    case 'b':
    case 'B':
        return 10;
    case 'w':
    case 'W':
        return 11;
    case 'f':
    case 'F':
        return 12;
    case 'L':
    case 'l':
        return 13;
    }

}

//similar to item code, but for abilities
int abilityCode(char item) {
    switch(item) {
    case 'b':
    case 'B':
        return 1;
    case 'p':
    case 'P':
        return 2;
    case 'z':
    case 'Z':
        return 3;
    case 'g':
    case 'G':
        return 4;
    }
}

//print a different pattern header for different locations
//header includes lives, rupees, inventory, etc.
void header(char location='0') {
    switch(location) {
    case 'k': //kokiri forest
        for(int i=0; i<=1; i++) {
            for(int j=0; j<=25; j++){
                cout<<"-_-_";
            }
            cout<<"-"<<endl;
        }
        break;

    case 'o': //opening
    case '0':
        for(int i=0; i<=1; i++) {
            for(int j=0; j<=25; j++){
                cout<<"::::";
            }
            cout<<endl;
        }
        break;

    case 'h': //hyrule field
        for(int i=0; i<=1; i++) {
            for(int j=0; j<=25; j++){
                cout<<"^^^^";
            }
            cout<<endl;
        }
        break;

    case 'c': //hyrule castle
        for(int i=0; i<=1; i++) {
            for(int j=0; j<=25; j++){
                cout<<"][][";
            }
            cout<<endl;
        }
        break;

    case 'z': //zora's domain
        for(int i=0; i<=1; i++) {
            for(int j=0; j<=25; j++){
                cout<<"~~~~";
            }
            cout<<endl;
        }
        break;


    case 'l': //lon lon ranch
        for(int i=0; i<=1; i++) {
            for(int j=0; j<=25; j++){
                cout<<"#-#-";
            }
            cout<<endl;
        }
        break;

    case 'v': //kakariko village
        for(int i=0; i<=1; i++) {
            for(int j=0; j<=25; j++){
                cout<<"><><";
            }
            cout<<endl;
        }
        break;

    case 'g': //gerudo valley
        for(int i=0; i<=1; i++) {
            for(int j=0; j<=25; j++){
                cout<<"\\/\\/";
            }
            cout<<endl;
        }
        break;
    }

    cout<<"\n\tLives = "<<lives<<"/3"<<"\tInventory = "<<inv<<"/13"<<"\tAbilities = "<<ab<<"/4"<<"\t\tRupees = "<<rupees<<endl;
    for(int j=0; j<=20; j++) {
        cout<<"_____";
    }
    cout<<endl<<endl;

}

//blinking animation
void blink(char x[], int speed=50, int times=3) {
    for(int ct=0; ct<=times; ct++) {
        for(int i=0; x[i]!='\0'; i++){
            cout << x[i];
        }
        Sleep(speed);
        clrscr();
        Sleep(speed/2);
    }
}

//entering location animation
void enterLocation(char x[], int speed=100, int times=3) {
    for(int ct=0; ct<=times; ct++) {
        cout<<"\n\n\t\t";
        for(int i=0; x[i]!='\0'; i++){
            cout << x[i];
        }
        Sleep(speed);
        clrscr();
        Sleep(speed/3);
    }

}

//two navi "drawings" to switch between for Navi animation
void navi1() {
    cout<<"        __     __      "<<endl;
    cout<<"      |  \\   / | )) "<<endl;
    cout<<"      \\  |  |  /     "<<endl;
    cout<<"       \\/__ |_/     "<<endl;
    cout<<"         (o_)        "<<endl;
}

void navi2() {
    cout<<"      __          __   "<<endl;
    cout<<"    |  \\       /  | ))"<<endl;
    cout<<"     \\ \\     /  /    "<<endl;
    cout<<"      \\_\\__/_ /      "<<endl;
    cout<<"         (o_)         "<<endl;

}

//Navi animation
void navi(int time=10, char location='0') { //time=10 --> 1 second approx
    for(int i=1; i<time; i++) {
        header(location);
        navi1();
        Sleep(20);
        clrscr();
        header(location);
        navi2();
        Sleep(20);
        clrscr();
    }
}

void naviMessage(char message[], char location='k') {
    clrscr();
    header(location);
    cout<<"\n\t          __     __      "<<endl;
    cout<<"\t         |  \\   / | )) "<<endl;
    cout<<"\t         \\  |  |  /    ";
    show(message);
    cout<<endl;
    cout<<"\t          \\/__ |_/     "<<endl;
    cout<<"\t            (o_)        "<<endl;
    getch();
    //reset back
    clrscr();
    header(location);

}

void gameOver() {
    char gameover[]="\n\n\t\t----------------------------- \n\t\t|                             |\n\t\t|     G A M E    O V E R      |\n\t\t|                             |\n\t\t------------------------------\n";
    clrscr();
    blink(gameover, 60, 10);
    exit(0);

}

void gameWin() {
    char gamewin[]="\n\n\t\t----------------------------- \n\t\t|                             |\n\t\t|     - T H E    E N D -      |\n\t\t|                             |\n\t\t------------------------------\n";
    clrscr();
    blink(gamewin, 60, 20);
    exit(0);

}

//saving game
void saveFile() {
    ofstream savedFile;
    savedFile.open("savedFile.txt", ios::trunc);
    if(!(savedFile.is_open())) {
        cout<<"Error saving file."<<endl;
        getch();
    } else {
        savedFile << name << endl;
        savedFile << lives << endl;
        savedFile << location << endl;
        savedFile << rupees << endl;
        savedFile << ab << endl;
        for(int i=0; i<4; i++) {
            savedFile << abilities[i] << " ";
        }
        savedFile << endl;

        savedFile << inv << endl;

        for(int i=0; i<13; i++) {
            savedFile << inventory[i] << " ";
        }
        savedFile.close();
        char op;
        char close[]="\tCome back soon!";
        cout<<"\n\t\t>GAME SAVED. "<<endl;
        do {
            cout<<"\n\t(C) Continue playing \t(X) Close\t";
            cin>>op;
        } while(op!='c' && op!='C' && op!='x' && op!='X');

        if(op=='x' || op=='X') {
            naviMessage(close);
            exit(0);
        }
    }
}

//opening saved game
void openSavedFile() {
    ifstream savedFile;
    savedFile.open("savedFile.txt", ios::in);
    if(! (savedFile.is_open())) {
        cout<<"Error opening file. "<<endl;
        getch();
    } else {
        savedFile >> name;
        savedFile >> lives;
        savedFile >> location;
        savedFile >> rupees;
        savedFile >> ab;
        for(int i=0; i<4; i++) {
            savedFile >> abilities[i];
        }

        savedFile >> inv;

        for(int i=0; i<13; i++) {
            savedFile >> inventory[i];
        }
        savedFile.close();
        cout<<"\n\t\tSaved file loaded successfully."<<endl;
        getch();
    }

}

//beginning of the game
void opening() {
    location='0';
    clrscr();
    header('k');
    char dots[]="...";
    char m1[]="\n\n\t*Deep in the land of Hyrule, in the forest of Kokiri*";
    char m2[]="WAKE UP! The Great Deku Tree has a message for you.'";
    char m3[]="? ...Aren't you going to wake up?";
    type(m1);
    type(dots, 400);
    navi();
    cout<<"\n\n\t'";
    type(name);
    cout<<"! ";
    getch();
    naviMessage(m2);
    getch();
    cout<<"\n\t";

    type(name);
    type(m3);
    cout<<"\t";
    char op;
    do {
        cout<<"\n\t(1) Wake up \n\t(2) Keep sleeping \t";
        cin>>op;
    } while(op != '1' && op != '2');

    if(op=='2') {
        cout<<"\n\t";
        char m1[]="If you do not awaken now, you shall never awaken from this slumber...\n\tDo you really want to make this choice?!\t";
        type(m1);
        do {
            cout<<"\n\t(1) Wake up \n\t(2) Keep sleeping \t";
            cin>>op;
        } while(op != '1' && op != '2');

        if(op=='2') {
            char m1[]="\n\tA darkness envelops you and sucks the soul out of you...\n\twith your slumber, you have destructed yourself,\n\tyand have brought destruction upon the entirety of Hyrule!\n";
            char m2[]="... you have failed us...";
            type(m1);
            cout<<"\n\t";
            type(name, 180);
            type(m2, 80);
            getch();
            gameOver();
        }
    }

}

void instructions() {
    char m1[]="\n\tIt's dangerous to go alone... here, take these pieces of advice...";
    char i1[]="\n\t1. You can press any key to continue the dialogues.";
    char i2[]="\n\t2. Inventory is limited, so watch what you carry.";
    char i3[]="\n\t3. Your lives, inventory, abilities, and rupees will be updated on the top of the screen.";
    char i4[]="\n\t4. In the menu of different locations, you can save your game, so you can come back\n\tto the same location without loss of inventory items or rupees";
    char i5[]="\n\t5. If text is being typed on the screen, someone is speaking to you... pay careful attention!\n\tThere might be important hints in what they say...\n\tAnd you may not be able to read every dialogue again!";
    char i6[]="\n\t6. Choose wisely, for the fate of Hyrule lays in your hands...";
    type(m1);
    type(i1);
    getch();
    type(i2);
    getch();
    type(i3);
    getch();
    type(i4);
    getch();
    type(i5);
    getch();
    type(i6);
    getch();
}

void credits() {
    cout<<"\n\tThis game is based on the 1998 Nintendo classic: The Legend of Zelda, Ocarina of Time."<<endl;
    cout<<"\n\tThe credits for the names of the locations, items, & characters, as well as the general storyline, goes to Nintendo."<<endl;
    getch();
}

//the following functions are to access, manipulate, and store abilities & items in their respective arrays.
bool hasItem(int item) {
    for(int i=0; i<13; i++) {
        if(inventory[i]==item) {
            return true;
        }
    }
    return false;
}


void loseItem(int item) {
    for(int i=0; i<13; i++) {
        if(inventory[i]==item) {
            inventory[i]=0;
            inv--;
            break;
        }
    }

}

bool hasAbility(int ability) {
    for(int i=0; i<4; i++) {
        if(abilities[i]==ability) {
            return true;
        }
    }
    return false;
}

void addAbility(int ability) {
    for(int i=0; i<4; i++) {
        if(abilities[i]==0) {
            abilities[i]=ability;
            ab++;
            break;
        }
    }
}

void showAbilities() {
    int num;
    cout<<"\n\tYour current abilities are: ";
        for(int i=0, num=1; i<ab; i++) {
            if(abilities[i] != 0) {
                switch(abilities[i]) {
                case 1:
                    cout<<"\n\t"<<num<<". Backflip"<<endl;
                    num++;
                    break;
                case 2:
                    cout<<"\n\t"<<num<<". Goron Punch"<<endl;
                    num++;
                    break;
                case 3:
                    cout<<"\n\t"<<num<<". Zora Swimming"<<endl;
                    num++;
                    break;
                case 4:
                    cout<<"\n\t"<<num<<". Gerudo Stealth"<<endl;
                    num++;
                    break;
                }
            }
        }

}

void showInventory() {
    int num=1;
    if(inv==0) {
        cout<<"\n\tInventory empty."<<endl;
    } else {
        cout<<"\n\tYour current inventory holds: ";
        for(int i=0, num=1; i<inv; i++) {
            if(inventory[i] != 0) {
                switch(inventory[i]) {
                case 1:
                    cout<<"\n\t"<<num<<". Deku Shield"<<endl;
                    num++;
                    break;
                case 2:
                    cout<<"\n\t"<<num<<". Bottle of Milk"<<endl;
                    num++;
                    break;
                case 21:
                    cout<<"\n\t"<<num<<". Bag of Peanuts"<<endl;
                    num++;
                    break;
                case 22:
                    cout<<"\n\t"<<num<<". Bag of Flowers"<<endl;
                    num++;
                    break;
                case 23:
                    cout<<"\n\t"<<num<<". Rat Poison"<<endl;
                    num++;
                    break;
                case 3:
                    cout<<"\n\t"<<num<<". Fairy in a Bottle"<<endl;
                    num++;
                    break;
                case 4:
                    cout<<"\n\t"<<num<<". Kokiri Sword"<<endl;
                    num++;
                    break;
                case 41:
                    cout<<"\n\t"<<num<<". Sword of Hylia"<<endl;
                    num++;
                    break;
                case 5:
                    cout<<"\n\t"<<num<<". Ocarina"<<endl;
                    num++;
                    break;
                case 6:
                    cout<<"\n\t"<<num<<". Epona"<<endl;
                    num++;
                    break;
                case 7:
                    cout<<"\n\t"<<num<<". Slingshot"<<endl;
                    num++;
                    break;
                case 8:
                    cout<<"\n\t"<<num<<". Hookshot"<<endl;
                    num++;
                    break;
                case 9:
                    cout<<"\n\t"<<num<<". Goron Hammer"<<endl;
                    num++;
                    break;
                case 10:
                    cout<<"\n\t"<<num<<". Bombuchu"<<endl;
                    num++;
                    break;
                case 11:
                    cout<<"\n\t"<<num<<". Bow"<<endl;
                    num++;
                    break;
                case 12:
                    cout<<"\n\t"<<num<<". Fire Arrows"<<endl;
                    num++;
                    break;
                case 13:
                    cout<<"\n\t"<<num<<". Light Arrows"<<endl;
                    num++;
                    break;
                }
            }
        }
    }

    getch();

}

//following are functions that return item code of a weapon/item/ability picked by user
int pickWeapon() {
    char op;
    cout<<"\n\n\t\tWeapons in your inventory:"<<endl;
    if(hasItem(1)) {
        cout<<"\n\t(D) Deku Shield";
    }
    if(hasItem(4)) {
        cout<<"\n\t(K) Kokiri Sword";
    }
    if(hasItem(41)) {
        cout<<"\n\t(H) Sword of Hylia";
    }
    if(hasItem(7)) {
        cout<<"\n\t(S) Slingshot";
    }
    if(hasItem(8)) {
        cout<<"\n\t(X) Hookshot";
    }
    if(hasItem(9)) {
        cout<<"\n\t(G) Goron Hammer";
    }
    if(hasItem(10)) {
        cout<<"\n\t(B) Bombchu";
    }
    if(hasItem(12)) {
        cout<<"\n\t(F) Fire Arrows";
    }
    if(hasItem(13)) {
        cout<<"\n\t(L) Light Arrows";
    }
    Sleep(100);
    char msg[]="\n\tChoose your weapon... ";
    type(msg);
    cin>>op;
    while(!(op=='d' || op=='D' || op=='k' || op=='K' || op=='h' || op=='H' || op=='s' || op=='S' || op=='x' || op=='X' || op=='g' || op=='G' || op=='b' || op=='B' || op=='f' || op=='F' || op=='l' || op=='L')) {
        cout<<"\n\tTry that again: ";
        cin>>op;
    }

    return itemCode(op);


}

int pickItem() {
    char op;
    cout<<"\n\n\t\tItems in your inventory:"<<endl;
    if(hasItem(2)) {
        cout<<"\n\t(M) Bottle of Milk";
    }
    if(hasItem(21)) {
        cout<<"\n\t(P) Bag of Peanuts";
    }
    if(hasItem(22)) {
        cout<<"\n\t(Y) Bag of Flowers";
    }
    if(hasItem(23)) {
        cout<<"\n\t(R) Rat Poison";
    }
    if(hasItem(3)) {
        cout<<"\n\t(A) Fairy in a Bottle";
    }
    if(hasItem(5)) {
        cout<<"\n\t(O) Ocarina";
    }
    if(hasItem(6)) {
        cout<<"\n\t(E) Epona";
    }
    Sleep(100);
    char msg[]="\n\tChoose your Item.. ";
    type(msg);
    cin>>op;
    while(!(op=='m' || op=='M' || op=='a' || op=='A' || op=='o' || op=='O' || op=='e' || op=='E' || op=='y' || op=='Y' || op=='p' || op=='P' || op=='r' || op=='R')) {
        cout<<"\n\tTry that again: ";
        cin>>op;
    }

    return itemCode(op);


}

int pickAbility() {
    char op;
    cout<<"\n\n\tAbilities you possess: "<<endl;
    if(hasAbility(1)) {
        cout<<"\n\t(B) Backflip";
    }
    if(hasAbility(2)) {
        cout<<"\n\t(P) Goron Punch";
    }
    if(hasAbility(3)) {
        cout<<"\n\t(Z) Zora Swimming";
    }
    if(hasAbility(4)) {
        cout<<"\n\t(G) Gerudo Stealth";
    }
    Sleep(100);
    char msg[]="\n\tPick an ability to use it... ";
    type(msg);
    cin>>op;
    while(!(op=='b' || op=='B' || op=='g' || op=='G' || op=='z' || op=='Z' || op=='p' || op=='P' )) {
        cout<<"\n\tTry that again: ";
        cin>>op;
    }

    return abilityCode(op);
}

void addItem(int item) {
    start:
    bool added=false;
    char ans;
    for(int i=0; i<13; i++) {
        if(inventory[i]==0) {
            inventory[i]=item;
            added=true;
            break;
        }
    }

    if(added==false || inv==13) {
        cout<<"\n\tInventory full - item not added!";
        cout<<"\n\tTip: You can discard items, especially those you can buy back again. \n\tDiscard an item? (Y/N): ";
        cin>>ans;
        while(ans!='y' && ans!='Y' && ans!='n' && ans!='N') {
            cout<<"\n\tTry again: ";
            cin>>ans;
        }
        if(ans=='y' || ans=='Y') {
            cout<<"\n\tPick the item to discard: ";
            int pickedItem= pickItem();
            loseItem(pickedItem);
            cout<<"\n\tItem removed from inventory.";
            cout<<"\n\tThe first item that you wished to add will be now added to inventory.";
            goto start;
        }
    } else if (added==true) {
        inv++;
    }
}

void firstDialogue() {
    char m1[]=", you have been entrusted with a heavy responsibility...\n\tI am Navi, and The Great Deku Tree has sent me with a message for you.";
    char m2[]="\n\tYour short life thus far has been spent within the Kokiri forest,\n\tbut it is time to leave the comfort of your home.";
    char m3[]="\n\tYou are no ordinary child... ";
    char m4[]=", you have a calling...\n\tPrincess Zelda awaits you with an important mission in the Hyrule Castle...";
    char imp[]="\n\tin fact, the very future of Hyrule lies in your hands now.\n\tThis is your destiny, and you must accept it.";
    char m5[]="\n\tWe have little time... Find a weapon... one that can withstand the test of time and evil...\n\tand leave the Kokiri forest immediately.";
    char m6[]="\n\tYou can count on me, Navi, to assist you!";
    clrscr();
    header('k');
    cout<<"\n\t";
    type(name);
    type(m1);
    getch();
    type(m2);
    getch();
    cout<<" ";
    type(name);
    type(m4);
    getch();
    type(imp, 120);
    getch();
    type(m5);
    getch();
    type(m6);
    getch();
}

//kokiri forest
void exploreKokiri() {
    location='k';
    int op;
    int visitBushes=0;
    bool visitSaria=false;
    bool hasWeapon=false;
    kokiri:
    char m1[]="\t\t***KOKIRI FOREST***";
    char m2[]="\n\tThere are many places we can go...";
    char m3[]="\n\t(1) Kokiri shop \n\t(2) Saria's House \n\t(3) Forest training centre \n\t(4) Some interesting-looking bushes \n\t(5) Display Inventory \n\t(6) Save Game \n\t(0) Leave Kokiri Forest \t";
    clrscr();
    enterLocation(m1);
    clrscr();
    header('k');
    show(m1);
    type(m2);
    show(m3);
    while(!(cin>>op) || !(op>=0 && op<=6)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }
    switch(op) {
    case 1: { //shop
        //***************************KOKIRI SHOP****************************************
        int op2;
        shop:
        clrscr();
        header('k');
        cout<<"\n\t\t***KOKIRI SHOP***"<<endl;
        char m1[]="\n\tGood afternoon! What do you want to purchase from our humble shop today?";
        type(m1);
        cout<<"\n\t(1) Deku Shield, made of the finest Deku wood. [20 Rupees] \n\t(2) A bottle of milk. [5 Rupees] \n\t(3) Fairy in a bottle. [30 Rupees] \n\t(0) Leave Shop \t";
        while(!(cin>>op2) || !(op2>=0 && op2<=3)) {
            cin.clear();
            cin.ignore(50, '\n');
            cout<<"\n\tTry again: ";
        }
        switch(op2) {
        case 1:
            if(rupees>=20 && hasItem(1)==false) {
                cout<<"\n\tPurchase successful!\n\t\t>DEKU SHIELD is now in your inventory.";
                getch();
                rupees -= 20;
                addItem(1);
                goto shop;
            } else if (hasItem(1)==true) {
                cout<<"\n\tYou already have this item.";
                getch();
                goto shop;
            } else if (rupees < 20) {
                cout<<"\n\tYou don't have enough money for this item.";
                getch();
                goto shop;
            }
            break;

        case 2:
            if(rupees>=5 && hasItem(2)==false) {
                cout<<"\n\tPurchase successful!\n\t\t>BOTTLE OF MILK is now in your inventory.";
                getch();
                rupees -= 5;
                addItem(2);
                goto shop;
            } else if (hasItem(2)==true) {
                cout<<"\n\tYou already have this item.";
                getch();
                goto shop;
            } else if (rupees < 5) {
                cout<<"\n\tYou don't have enough money for this item.";
                getch();
                goto shop;
            }
            break;
        case 3:
            if(rupees>=30 && hasItem(3)==false) {
                cout<<"\n\tPurchase successful!\n\t\t>FAIRY IN A BOTTLE is now in your inventory.";
                getch();
                rupees -= 30;
                addItem(3);
                goto shop;
            } else if (hasItem(3)==true) {
                cout<<"\n\tYou already have this item.";
                getch();
                goto shop;
            } else if (rupees < 30) {
                cout<<"\n\tYou don't have enough money for this item.";
                getch();
                goto shop;
            }
            break;
        case 0:
            goto kokiri;
            break;
        }
        break;
    }
    case 2: { //saria
        clrscr();
        header('k');
        cout<<"\n\t\t***SARIA'S HOME***"<<endl;
        if(visitSaria==false) {
            char m1[]="\n\t...Well hello there! I didn't expect to see you at this hour. ";
            char m2[]="\n\tIs it just me, or is that Navi with you?! ...You need to tell me everything!";
            char m3[]="\n\t...";
            char m4[]="\n\tI always knew you were very special.";
            char m5[]="... I knew this day would come... I just didn't know how soon.";
            char m6[]="\n\tListen carefully to my advice... Remember, if you keep a fairy in a bottle,\n\tin can replenish your lives if misfortune befalls you.\n\tBefore you leave... let me give you a little something... \n\tI should like to be of whatever little help I can.";
            char m7[]="\n\tTake this money, you will need it... \n\tAnd take this Ocarina... \n\tperhaps it shall be useful, or perhaps you shall remember me by it,\n\twhen the journey tires you, when the night grows long and your feet grow weary.";
            char m8[]="\n\tGood-bye, ";
            char m9[]="! Safe travels... please come back soon, and do not forget me.";
            type(m1);
            getch();
            type(m2);
            getch();
            type(m3, 200);
            type(m4);
            cout<<"\n\t";
            type(name);
            type(m5);
            getch();
            type(m6);
            getch();
            type(m7);
            getch();
            cout<<"\n\n\t\t >You got 50 RUPEES from Saria. \n\t\t>SARIA'S OCARINA was added to your inventory.\n";
            rupees+=50;
            addItem(5);
            type(m8);
            type(name);
            type(m9);
            getch();
            visitSaria=true;
            goto kokiri;
        } else if (visitSaria==true) {
            char m1[]="\n\tThere is a strange stillness here, like someone loving and full of warmth has just left...";
            char m2[]="\n\tPerhaps... Saria is not home.";
            type(m1);
            getch();
            type(m2, 130);
            getch();
            goto kokiri;
        }
        break;
    }
    case 3: { //forest training
        int op2;
        clrscr();
        header('k');
        cout<<"\n\t\t***FOREST TRAINING CENTRE***"<<endl;
        char m1[]="\n\tHello, young man!";
        char intro[]="\n\tI am the Great Warrior Mido. What can I do for you?";
        type(intro);
        centre:
        type(m1);
        cout<<"\n\t(1) 'Teach me everything you know.' \n\t(2) 'Give me a weapon.' \n\t(0) Leave \t";
        while(!(cin>>op2) || !(op2==1 || op2==2)) {
            cin.clear();
            cin.ignore(50, '\n');
            cout<<"\n\tTry again: ";
        }

        switch(op2) {
        case 1: {
            char m2[]="\n\tAlrighty, young man! I shall teach you everything I know.";
            char m3[]="\n\tFirst, remember, always stay on your feet, and keep your eyes on the enemy.";
            char m4[]="\n\tSecond, no matter what happens, keep moving; move and strike with explosive speed!";
            char m5[]="\n\tLast, but not least, remember:\n\tswords of steel always cut the sharpest, and last the longest.";
            char m6[]="\n\tI wish you luck in the journey ahead!";
            type(m2);
            getch();
            type(m3);
            getch();
            type(m4);
            getch();
            type(m5);
            getch();
            type(m6);
            getch();
            goto centre;
            break;
            }
        case 2: {
            int op3;
            if(hasWeapon) {
                char m2[]="\n\tHow brazen of you to ask for a weapon, when I can see you have one right there!\n\tShoo! Scat! Get out of my centre, brat!";
                type(m2);
                getch();
                goto kokiri;
            } else {
                char m2[]="\n\tYoung man, you look like you are destined for great things.\n\tI shall allow you to choose between these two swords...";
                char m3[]="\n\tThis is the Kokiri sword, made locally of Kokiri steel.\n\tAnd this is the diamond-studded Sword of Hylia, made of the finest bronze.\n\tYou may choose one, but you may never choose again...";
                type(m2);
                getch();
                type(m3);
                cout<<"\n\t(1) Take the Kokiri Sword \n\t(2) Take the Sword of Hylia \t";
                while(!(cin>>op3) || !(op>=1 || op<=2)) {
                    cin.clear();
                    cin.ignore(50, '\n');
                    cout<<"\n\tTry again: ";
                }
                if(op3==1) {
                    cout<<"\n\t\t>KOKIRI SWORD added to inventory.";
                    addItem(4);
                    hasWeapon=true;
                    getch();
                    goto kokiri;
                }
                if(op3==2) {
                    cout<<"\n\t\t>SWORD OF HYLIA added to inventory.";
                    addItem(41);
                    hasWeapon=true;
                    getch();
                    goto kokiri;
                }
            }
            getch();
            break;
        }
        case 0:
            goto kokiri;
            break;
        }
        break;
    } //****forest training centre ends
    case 4: { //some bushes
        cout<<"\n\tYou rustle around the bushes...";
        if(hasWeapon && visitBushes<3) {
            cout<<"\n\tYou slash some bushes with your sword.";
            getch();
            cout<<"\n\tWhat luck! A beautiful blue rupee! That's twenty rupees!";
            rupees += 20;
            visitBushes++;
            getch();
            goto kokiri;
        } else if (!(hasWeapon)) {
            cout<<"\n\tPerhaps there's something to find here... if only you had something sharp to cut these bushes with...";
            getch();
            goto kokiri;
        } else if (visitBushes>=3) {
            cout<<"\n\tYou've slashed these bushes to scrubs, "<<name<<"! There's nothing to see here!";
            getch();
            goto kokiri;
        }
        break;
    }
    case 5: { //inventory
        showInventory(); //getch in showInventory()
        goto kokiri;
    }
    case 6: {
        saveFile();
        goto kokiri;
    }
    case 0: { //leave
        int op3;
        if(!hasWeapon) {
            cout<<"\n\tYou cannot leave without a weapon... it's dangerous out there!";
            getch();
            goto kokiri;
        } else {
            char m2[]="\n\tNavi here...Remember what I said...you must find Princess Zelda.\n\t...Are you sure you are ready, well equipped, and well informed\n\tenough to leave the only home you've ever known?\n\tRemember... once you leave... there might be no way to return.";
            type(m2);
            cout<<"\n\t(1) 'Yes, let's go, Navi!' \t(2) 'Maybe later...' \t";
            while(!(cin>>op3) || !(op>=1 || op<=2)) {
                    cin.clear();
                    cin.ignore(50, '\n');
                    cout<<"\n\tTry again: ";
            }
            if(op3==2) {
                goto kokiri;
            }
        }
        break;

    }
    }
}

//some flag variables for hyrule field that needed to be accessed by multiple functions
bool zeldaFail=false;
bool zeldaComplete=false;
bool hasEpona=false;
bool eponaTired=false;

int meetZelda() { //return 1 if successfully reach end of dialogues
    char op;
    location='c';
    clrscr();
    header('c');

    if(zeldaFail) {
        char m1[]="\n\tYou look everywhere, but Princess Zelda is nowhere to be found...\n\tPerhaps you did something to bother her.";
        char m2[]="\n\tLooks like you're on your own for now.";
        type(m1);
        getch();
        type(m2);
        getch();
        return 0;
    }
    if(zeldaComplete) {
        char m1[]="\n\tThere is a heavy stillness here...";
        char m2[]="\n\tYou can feel the weight of the responsibility that was \n\thanded over to you in this very spot.";
        char navim[]="\tHey...Let's go...";
        type(m1, 40);
        getch();
        type(m2);
        getch();
        naviMessage(navim, 'c');
        return 1;
    }

    char m1[]="\n\tOh dear! So many guards inside the castle!\n\tHow are you going to get past them?!";
    char m[]="\n\t(1) Try to ride past confidently on Epona. \n\t   They'll surely assume you're one of them. \n\t(2) Sneak Epona into the guards' stables and go through the bushes. \n\t(3) Leave Epona here and go through the bushes.\t";
    char fail[]="\n\t'HALT!! WHO GOES THERE?!!";
    char fail2[]="\n\t'Not YOU again! Out you go! And no need to wince...\n\tI'm not even grabbing your collar that tight...\n\tNext time round I'll choke you with it!'";
    cout<<"\n\t\t***INSIDE HYRULE CASTLE***"<<endl;
    type(m1);
    getch();
    show(m);
    cin>>op;
    while (op!= '1' && op!='2' && op != '3') {
        cout<<"\n\tTry again: ";
        cin>>op;
    }
    if (op=='1' || op=='3') {
        if(op=='3') {
            char shout[]="\n\tWhat the heck!\n\tWHOSE...HORSE...IS THAT?!.....";
            type(shout, 90);
        }
        type(fail);
        getch();
        type(fail2);
        getch();
        return 0;
    }

    char navim1[]="\tLook! That must be her!";
    char navim2[]="\tZelda is no ordinary person...";
    char navim3[]="\tYou'll only have one chance at talking to her.";
    char navim4[]="\tAnd she can smell a lie from a mile off...";
    char navim5[]="\tThink wisely before you speak!";

    naviMessage(navim1, 'c');
    naviMessage(navim2, 'c');
    naviMessage(navim3, 'c');
    naviMessage(navim4, 'c');
    naviMessage(navim5, 'c');

    char zelda[]="\t\t***ZELDA'S COURTYARD***";
    char m3[]="...that's your name... isn't it?";
    char m4[]="\n\tI knew I could trust Navi to deliver this message to you...\n\tI'm glad you came.\n\tListen very carefully to me.";
    char m5[]="\n\tGanondorf, the evil Gerudo king, is trying to seize control of Hyrule...\n\tIf he succeeds in his quest, it will bring destruction upon Hyrule.";
    char m6[]="\n\tYou may already know about the Triforce: the union of Courage, Wisdom, and Power...";
    char m7[]="\n\tGanon has seized the Triforce of Power, and he is hiding... somewhere in Hyrule...\n\tYou must find him and take back the Triforce of Power.";
    char reply1[]="\n\n\t(1) 'Tell me more about the Triforce.' \n\t(2) 'Where is Ganon?'\t";

    clrscr();
    enterLocation(zelda);
    header('c');
    show(zelda);
    cout<<"\n\n\t";
    type(name, 190);
    type(m3, 100); getch();
    type(m4); getch();
    type(m5); getch();
    type(m6); getch();
    type(m7); getch();
    show(reply1);
    cin>>op;
    while (op!= '1' && op!='2') {
        cout<<"\n\tTry again: ";
        cin>>op;
    }
    char m8_1_1[]="\n\tThe Triforce of Wisdom is with me.\n\tAs I said, Ganon has the Triforce of Power.";
    char m8_1_2[]="\n\tAnd you, dear ";
    char m8_1_3[]=", hold the Triforce of Courage, though you may not even know it.";
    char m8_2_1[]="\n\tAh, my dear ";
    char m8_2_2[]=", if I knew that, I would have not bothered calling upon you. \n\tI do not know of his whereabouts.";

    if(op=='1') {
        type(m8_1_1);
        getch();
        type(m8_1_2);
        type(name);
        type(m8_1_3, 90);
        getch();

    } else if (op=='2') {
        type(m8_2_1);
        type(name);
        type(m8_2_2);
        getch();
    }

    char reply2[]="\n\n\t(1) 'Please give me something to help me find Ganon.' \n\t(2) 'Can I have some money for this job, at least?' \n\t(3) 'Please tell me more.'\t";
    char m9_1_1[]="\n\tYes, I can advise you...but I will make it short, so you can remember...";
    char m9_1_2[]="\n\tGanon's greatest weakness is in his left leg, \n\twhere I once struck him with my sword in a battle many years ago.";
    char m9_1_3[]="\n\tRemember his weakness when you encounter him, \n\tfor it may prove to be fatal if that wound is struck again.";
    char m9_1_4[]="\n\tHe is hiding somewhere in Hyrule...I can sense his evil...\n\tGo everywhere you can...\n\tLeave no stone unturned! \n\tGather as much information and items as possible before\n\tfacing him....";

    char lie[]="\n\t...Did you just lie to me?";
    char m9_2[]="\n\tSigh...I expected better dignity from you, ";
    char lied[]="\tOh... I think she's gone back inside.";

    show(reply2);
    cin>>op;
    while (op!= '1' && op!='2' && op!='3') {
        cout<<"\n\tTry again: ";
        cin>>op;
    }

    if(op=='1' || op=='3') {
        type(m9_1_1); getch();
        type(m9_1_2); getch();
        type(m9_1_3); getch();
        type(m9_1_4); getch();
    } else if(op=='2') {
        type(lie, 140); getch();
        type(m9_2, 50);
        type(name, 50);
        getch();
        naviMessage(lied, 'c');
        zeldaFail=true;
        return 0;

    }


    char reply3[]="\n\n\t(1) 'I'll set out immediately, don't worry!' \n\t(2) 'Is there anything else I should know or have?'\t";
    char m10_1_1[]="\n\tWait, wait! ";
    char m10_1_2[]="! Before you leave, I must ask...";
    char m11[]="\n\tDo you have a solid sword of steel, such as a Kokiri sword?";

    clrscr();
    header('c');
    show(zelda);


    show(reply3);
    cin>>op;
    while (op!= '1' && op!='2') {
        cout<<"\n\tTry again: ";
        cin>>op;
    }
    if(op=='1') {
        type(m10_1_1);
        type(name);
        type(m10_1_2);
        getch();
    }

    type(m11);

    char reply4[]="\n\t(1) 'Yes, I have a sword of steel.' \t(2) 'No, but I have the bronze, diamond-studded Sword of Hylia!'\t";
    show(reply4);
    cin>>op;
    while (op!= '1' && op!='2') {
        cout<<"\n\tTry again: ";
        cin>>op;
    }

    if(op=='2' && hasItem(41)) {
        char dots[]="...";
        char m11_1[]="\n\tNo, a bronze sword will never withstand the evil of Ganon...\n\tTake this Kokiri sword...\n\t";
        char m11_2[]=", you are Kokiri, and you should carry this sword with pride. \n\tGive me the Sword of Hylia, you can have it back upon your return;\n\tand make wiser choices next time.";
        char notif[]="\n\n\t\t>KOKIRI SWORD was added to your inventory.\n\n\t\t>SWORD OF HYLIA was removed from your inventory.";
        type(dots, 130);
        type(m11_1); getch();
        type(name); type(m11_2); getch();
        show(notif);
        addItem(4);
        loseItem(41);
        getch();
    } else if(op=='1' && hasItem(4)) {
        char m12[]="\n\tWonderful! Such a beautiful blade!";
        type(m12);
        getch();
    } else if((op=='2' && !(hasItem(41))) || (op=='1' && !(hasItem(4)))) {
        cout<<"\n\t";
        type(name);
        type(lie, 200);
        getch();
        type(m9_2); getch();
        naviMessage(lied, 'c');
        zeldaFail=true;
        return 0;
    }

    char m13[]="\n\tDo you have an Ocarina?";
    char reply5[]="\n\t(1) Yes, I do! \t(2) No... \t(3) Please...what's an Ocarina?\t";
    ocarinaQues:
    type(m13); getch();
    show(reply5);
    cin>>op;
    while (op!= '1' && op!='2' && op!='3') {
        cout<<"\n\tTry again: ";
        cin>>op;
    }

    if(op=='1' && hasItem(5)) {
        char m13_2[]="\n\tExcellent...That looks like a Kokiri Fairy Ocarina...";
        char m13_3[]="\n\tHer name...";
        char m13_4[]="Saria... isn't it?";
        char m13_5[]="\n\tShe is a special person...\n\tYou must remember her well, ";
        char m13_6[]=", and do your best to see her after all this is over...";
        type(m13_2); getch();
        type(m13_3, 50); type(m13_4, 120); getch();
        type(m13_5, 50);
        type(name, 30);
        type(m13_6);
        getch();

    } else if(op=='2' && !(hasItem(5))) {
        char m13_1[]="\n\tOh...you must not have visited Saria in the Kokiri Forest.";
        char m13_2[]="\n\tAn unwise decision, young ";
        char m13_3[]="; however, I trust you will be more mindful henceforth.";
        char m13_4[]="\n\tTake this; it is the Ocarina of Time. Keep it safe. \n\tTime will show you its worth.";
        type(m13_1);
        getch();
        type(m13_2); type(name); type(m13_3); getch();
        type(m13_4); getch();
        cout<<"\n\n\t\t>OCARINA OF TIME was added to your inventory.\n";
        addItem(5);
    } else if(op=='3') {
        char m[]="\n\tAn Ocarina is a type of vessel flute...\n\tYou shall see... it will prove to be useful on the fateful journey\n\tyou are about to embark upon.";
        type(m);
        goto ocarinaQues;
    } else {
        cout<<"\n\t";
        type(name);
        type(lie, 200);
        getch();
        type(m9_2); getch();
        naviMessage(lied, 'c');
        zeldaFail=true;
        return 0;
    }

    char endm1[]="\n\tI must leave now...\n\tI entrust to you the responsibility of finding Ganon...\n\tAnd of restoring peace to Hyrule by bringing back to me\n\tthe Triforce of Power...";
    char endm2[]="\n\n\tRemember: light overcomes darkness... fire overcomes ice...\n\tIf you are confronted with evil, fight it with good...\n\tIf you are ever at a loss, look for opposites. \n\n\tDo not forget my words, believe in yourself, and stay courageous!";
    char endm3[]="\n\tGodspeed, ";
    char endm4[]="!";
    type(endm1);
    getch();
    type(endm2);
    getch();
    type(endm3, 100);
    type(name, 70);
    type(endm4);
    getch();
    zeldaComplete=true;
    return 1;
    getch();

}

//zora can be visited multiple times but epona must rest between visits using kakariko stables
int zoraVisits=0;
void zorasRiver() {
    char m[]="Be wise...";
    naviMessage(m, 'z');
    char river[]="\n\t\t***ZORA'S RIVER***";
    enterLocation(river);
    clrscr();
    header('z');
    show(river);
    char m1[]="\n\tA lanky Zora peers down at you.";
    char m2[]="\n\tWell hello there, young one. \n\tHow are you faring?";
    char m3[]="\n\tI can give you information, or I can teach you something,\n\tbut I can't do both...\n\tSo what'll it be?";
    char reply1[]="\n\t(1) What are you?! \n\t(2) Please... Do you have information about Ganondorf's whereabouts? \n\t(3) Please teach me any important skill. ";
    char op;
    show(m1); getch();
    type(m2); getch();
    type(m3); getch();
    show(reply1);
    cin>>op;
    while (op!= '1' && op!='2' && op!='3') {
        cout<<"\n\tTry again: ";
        cin>>op;
    }

    if(op=='1') {
        char m1[]="\n\tAmateur young one, you may find these fins strange;\n\t but I am a proud Zora! I can swim, charge, and electrocute like no other race in Hyrule...";
        char m2[]="\n\tI was willing to offer to help you, or perhaps teach you.\n\tBut I should not like to bear with such an imprudent and rude youth.";
        char m3[]="\n\tYou may leave Zora's Domain immediately, given that disrespectful attitude!";
        type(m1); getch();
        type(m2); getch();
        type(m3); getch();
        zoraVisits++;
    } else if (op=='2') {
        char m1[]="\n\tI do not know of his exact location, but let me tell you this: \n\tthe evil Ganon can easily endure leaping flames, \n\tbut the smallest amount of water suffocates him...";
        char m2[]="\n\tFor all his facade of power, he would probably \n\tdrown in a puddle, should you push him into one.";
        char money[]="\n\tYou seem to be listening so attentively...\n\tIt is rare that people value my words.\n\tAs a token of my appreciation, accept this Purple Rupee.";
        char money2[]="\n\t\t>You got a PURPLE RUPEE! That's 50 Rupees!";
        char m3[]="\n\tI should go... but remember my words...";
        type(m1); getch();
        type(m2); getch();
        type(money); getch();
        show(money2); getch();
        rupees+=50;
        type(m3); getch();
        zoraVisits++;
    } else if(op=='3') {
        char m1[]="\n\tI can teach you how to swim like a Zora... you must be deft and nimble, \n\teven in the worst of currents; \n\tkeep your wits about you, and move your arms and legs\n\tas fluidly as this...\n\t";
        char m2[]="\n\n\t\t>ZORA SWIMMING was added to your abilities.";
        char money[]="\n\tYou seem to be listening so attentively...\n\tIt is rare that people value my words.\n\tAs a token of my appreciation, accept this Red Rupee.";
        char money2[]="\n\t\t>You got a RED RUPEE! That's 20 Rupees!";
        char m3[]="\n\tI should go... but remember my words...";
        type(m1); getch();
        show(m2); getch();
        type(money); getch();
        show(money2); getch();
        rupees+=20;
        addAbility(3);
        type(m3); getch();
        zoraVisits++;
    }

    if(zoraVisits<3) {
        char nm1[]="What a shame he's gone...";
        char nm2[]="I think he must have had something more to offer.";
        char nm3[]="Epona is too tired to swim back here again.";
        char nm4[]="If only we could find someone who'd help rest her up.";
        naviMessage(nm1, 'z');
        naviMessage(nm2, 'z');
        naviMessage(nm3, 'z');
        naviMessage(nm4, 'z');
    } else if(zoraVisits>=3) {
        char nm1[]="I think we've seen it all here at Zora's River...";
        char nm2[]="Not much point coming back here.";
        naviMessage(nm1, 'z');
        naviMessage(nm2, 'z');
    }


}

void kakarikoShop() {
    char place[]="\t\t***KAKARIKO SHOP***";
    int op;
    shop:
    clrscr();
    enterLocation(place);
    clrscr();
    header('v');
    show(place);
    char m1[]="\n\tWelcome to our humble Kakariko Shop! \n\tWhat can we do for you today?";
    char shop[]="\n\n\t(1) Bag of roasted peanuts (guaranteed quality). [30 Rupees] \n\t(2) Bag of dried flowers (a lovely gift). [30 Rupees]. \n\t(3) Bottle of Rat Poison (handle with care). [50 Rupees] \n\t(4) Hookshot (can be used to access very high locations). [60 Rupees] \n\t(0) Leave shop \t";
    type(m1); getch();
    show(shop);
    while(!(cin>>op) || !(op>=0 && op<=4)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"Try again: ";
    }

    switch(op) {
    case 1:
        if(rupees>=30 && hasItem(21)==false) {
            cout<<"\n\tPurchase successful!\n\t\t>BAG OF PEANUTS is now in your inventory.";
            rupees -= 30;
            addItem(21);
            getch();
            goto shop;
        } else if (hasItem(21)==true) {
            cout<<"\n\tYou already have this item.";
            getch();
            goto shop;
        } else if (rupees < 30) {
            cout<<"\n\tYou don't have enough money for this item.";
            getch();
            goto shop;
        }
        break;

    case 2:
        if(rupees>=30 && hasItem(22)==false) {
            cout<<"\n\tPurchase successful!\n\t\t>BAG OF DRIED FLOWERS is now in your inventory.";
            rupees -= 30;
            addItem(22);
            getch();
            goto shop;
        } else if (hasItem(22)==true) {
            cout<<"\n\tYou already have this item.";
            getch();
            goto shop;
        } else if (rupees < 30) {
            cout<<"\n\tYou don't have enough money for this item.";
            getch();
            goto shop;
        }
        break;
    case 3:
        if(rupees>=50 && hasItem(23)==false) {
            cout<<"\n\tPurchase successful!\n\t\t>RAT POISON is now in your inventory.";
            rupees -= 50;
            addItem(23);
            getch();
            goto shop;
        } else if (hasItem(23)==true) {
            cout<<"\n\tYou already have this item.";
            getch();
            goto shop;
        } else if (rupees < 50) {
            cout<<"\n\tYou don't have enough money for this item.";
            getch();
            goto shop;
        }
        break;
    case 4:
        if(rupees>=60 && hasItem(8)==false) {
            cout<<"\n\tPurchase successful!\n\t\t>HOOKSHOT is now in your inventory.";
            rupees -= 60;
            addItem(8);
            getch();
            goto shop;
        } else if (hasItem(8)==true) {
            cout<<"\n\tYou already have this item.";
            getch();
            goto shop;
        } else if (rupees < 60) {
            cout<<"\n\tYou don't have enough money for this item.";
            getch();
            goto shop;
        }
        break;
    case 0:
        break;
    }

}

//return true if bow recieved
bool kakarikoHome() {
    clrscr();
    header('v');
    char m1[]="\n\tThe wails of a crying baby pierce the air.";
    char m2[]="\n\t'Oh, young man, do you not have anything that could soothe\n\tmy poor child? \n\tI have no money to buy any milk...";
    char ans;
    type(m1); getch();
    type(m2); getch();
    cout<<"\n\tPick an item from your inventory? (Y/N): ";
    cin>>ans;
    if(ans!='y' && ans!='Y' && ans!='n' && ans!='N') {
        cout<<"\n\tTry again: ";
        cin>>ans;
    }
    if(ans=='y' || ans=='Y') {
        if(pickItem() == 2) {
            loseItem(2);
            char m3[]="\n\tOh, thank you so much, kind one! \n\tHow shall I ever repay you for this kindness...";
            char m4[]="\n\tIf I could offer you some money, I would. But I have none...";
            char m5[]="\n\tThis poor child's father, and my beloved husband, sadly perished some time ago\n\tfighting the evil forces of Ganon's armies...";
            char m6[]="\n\tSniff...sniff...One of his bows... is still here...";
            char m7[]="\n\tTake it, child, perhaps it shall be useful...\n\tIt is all I can offer...\n\tI thank you again!";
            type(m3); getch();
            type(m4); getch();
            type(m5); getch();
            type(m6); getch();
            type(m7); getch();
            cout<<"\n\t>>BOW was added to your inventory.";
            addItem(11);
            getch();
            char nm[]="If you have some arrows, you'll be able to shoot them now!";
            naviMessage(nm);
            return true;
        }
        else {
            char m3[]="\n\tI'm sorry, my child, that is not useful to me...";
            type(m3); getch();
            return false;
        }
    } else {
        return false;
    }
}

//return true if trade done
bool dekuBusinessScrub() {
    int op;
    char m1[]="\n\tI am a Deku Scrub, but no ordinary one...\n\tI'm a business typa guy!";
    char m2[]="\n\tI loveeee...I loveeeee nuts....ahhh!";
    char m3[]="\n\tPeanuts...Walnuts...Doughnuts...ahhh!!!";
    char m4[]="\n\tIf you gimme some nuts, I'll give you sommin really helpful! A weapon, of sorts! BUSINESSS! ...Deal?!";
    char reply[]="\n\t(1) Okay! (2) Heck no! I'm out!\t";
    clrscr(); header('v');
    type(m1); getch();
    type(m2); getch();
    type(m3); getch();
    type(m4); getch();
    show(reply);
    while(!(cin>>op) || !(op>=1 && op<=2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"Try again: ";
    }
    if(op==1) {
        if (pickItem() == 21 ) {
            char m1[]="\n\tHurrah! Beautiful! \n\tAs promised, here is the barter...\n\tHere's a slingshot!";
            type(m1); getch();
            cout<<"\n\t\t>SLINGSHOT was added to your inventory. \n\t\t>BAG OF PEANUTS was removed from your inventory.";
            loseItem(21);
            addItem(7);
            getch();
            return true;
        } else {
            char m1[]="\n\tYou're no fun...\n\tIt's nuts that I love... sigh...\n\tWell, YOUR LOSS!";
            type(m1); getch();
            return false;
        }
    } else {
        return false;
    }

}

int goronsDen() {
    int op;
    char place[]="\n\t\t***GORON'S DEN***";
    enterLocation(place);
    clrscr();
    header('v');
    show(place);
    char m1[]="\n\tHello there, young one. I am Darunia of the Gorons. \n\tDo not be fazed by my appearance. We Gorons eat rocks. \n\tThat's why we look a bit intimidating and rough. But trust me, I can be pretty nice.";
    char m2[]="\n\tI'm so nice, in fact, that I'll sell you a Goron Hammer for just fifty rupees,\n\t or teach you the epic Goron Punch for 30 rupees.";

    type(m1); getch();
    type(m2); getch();
    cout<<"\n\t(1) Give me the hammer. \n\t(2) Teach me the Goron Punch. \n\t(3) I'll take both offers. \n\t(4) I'll come back later.\t";
    while(!(cin>>op) || !(op>=1 && op<=4)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }
    if(op==1 && hasItem(9)==false && rupees>=50) {
        cout<<"\n\t\t>GORON HAMMER was added to your inventory.";
        addItem(9);
        rupees-=50;
        getch();
        return 0;
    } else if (op==1 && hasItem(9)==true) {
        cout<<"\n\tNo one other than a Goron can carry TWO Goron Hammers!";
        getch();
        return 0;
    } else if(op==2 && hasAbility(2)==false && rupees>=30) {
        cout<<"\n\t\t>GORON PUNCH was added to your abilities.";
        rupees-=30;
        addAbility(2);
        getch();
        return 0;
    } else if(op==2 && hasAbility(2)==true ) {
        cout<<"\n\tOh, so you can't Goron Punch? \n\tPretty sure I already taught you!";
        getch();
        return 0;
    } else if(op==3 && hasAbility(2)==false && hasItem(9)==false && rupees>=80) {
        cout<<"\n\t\t>GORON HAMMER was added to your inventory.";
        addItem(9);
        cout<<"\n\t\t>GORON PUNCH was added to your abilities.";
        addAbility(2);
        rupees-=80;
        getch();
        return 0;
    } else {
        cout<<"\n\tYoung man, let me give you some words to live by. \n\tDon't ask for things you already have, and don't ask when you're broke!";
        getch();
        return 0;
    }
}


int kakarikoStables(bool ratProblem) { //return 0 if epona rested, 1 if rat problem solved.
    int op;
    char place[]="\n\t\t***KAKARIKO STABLES***";
    char m1[]="\n\tUGH! EWWW!! THERE'S SO MANY RATS!!!!";
    char m2[]="\n\tOh - hahah - didn't see ya there! I'm Jiro the stable hand. \n\tDyu want me to rest and feed yer horse? It'll cost ya 20 Rupees.";
    char reply[]="\n\t(1) Yes please.";
    char reply2[]="\n\t(2) I might have something that'll help with your rat problem, actually.\t";
    enterLocation(place);
    header('v');
    show(place);
    if(ratProblem) {
        type(m1); getch();
    }
    type(m2); getch();
    show(reply);
    if(ratProblem) {
        show(reply2);
    }

    while(!(cin>>op) || !(op>=1 && op<=2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"Try again: ";
    }
    if(op==1 && hasItem(6)==true && eponaTired==true) {
        char m[]="\n\tYer horse's been rested and fed! Yer welcome! Ta ta!";
        type(m);
        rupees-=20;
        getch();
        return 0;
    } else if (op==1 && eponaTired==false) {
        char m[]="\n\tYer horse's already doin' pretty well. Not takin' yer money for nothin.";
        type(m);
        getch();
        return 0;
    } else if(op==1 && hasItem(6)==false) {
        char m[]="\n\tUh...what horse...exactly?";
        type(m);
        getch();
        return 0;
    } else if(op==2 && ratProblem==true) {
        char m[]="\n\tReally? Whatcha got?!";
        type(m); getch();
        if(pickItem()==23) {
            loseItem(23);
            char m[]="\n\tOH MY! WONDERFUL! HOW WONDERFUL!";
            char m2[]="\n\tMan! In repayment, I'll teach you a little secret....\n\tI'll show you how to BACKFLIP!\n\tYou can move out of the way real quick,\n\twith a backflip... great way to dodge slaps or flying objects, hee hee!";
            type(m); getch();
            type(m2); getch();
            cout<<"\n\t\t>BACKFLIP was added to your abilities.";
            addAbility(1);
            char m3[]="\n\tThankies, man! Hope you enjoyed learning my little trick...\n\tCatcha later!";
            type(m3); getch(); return 1;
        } else {
            char m[]="\n\tEh, that wouldn't really help. But thanks anyway!";
            type(m);
            getch(); return 0;
        }
    }
}

//return true only if wall demolished
bool kakarikoWall() {
    int op;
    clrscr();
    header('v');
    cout<<"\n\tThis wall's so battered, anything could blow it apart.";
    getch();
    cout<<"\n\tMaybe there's something valuable on the other side...\n\tDo you have something you can use to blow up the wall? \n\t(1) Yeah. \n\t(2) I think not. \t";
    getch();
    while(!(cin>>op) || !(op>=1 && op<=2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"Try again: ";
    }
    if(op==1) {
        if(pickWeapon() == 10) {
            cout<<"\n\tThe Bombchu obliterated the wall in seconds! \n\tWhat's this...?"; getch();
            cout<<"\n\tFire arrows and light arrows! And a Purple Rupee! What a find!"; getch();
            cout<<"\n\t\t>FIRE ARROWS were added to your inventory. \n\t\t>LIGHT ARROWS were added to your inventory.";
            addItem(12);
            addItem(13);
            rupees+=50;
            getch();
            return true;

        } else {
            cout<<"\n\tThat wouldn't really work.";
            getch();
            return false;
        }
    } else {
        cout<<"\n\tNothing much to do here, then.";
        getch();
        return false;
    }

}

//get Epona from here if you talk properly
void lonLonRanch() {
    location='l';
    char ranch[]="\n\t\t***LON LON RANCH***";
    clrscr();
    enterLocation(ranch);
    clrscr();
    header('l');
    show(ranch);
    int op2;
    char m1[]="\n\tThe neighing of horses and mooing of cows fills the air...";
    char m2[]="\n\tA little girl runs screaming into view, in hot pursuit of a runaway foal.";
    char m3[]="\n\tAAAAHHHH!!! COME BACK HEREEEE!!!!";
    char m4[]="\n\tYOU! OVER THERE! SHUT THAT GATE, BEFORE THIS RASCAL RUNS OUT OF IT!";
    char m2_1[]="\n\tIt's peaceful, but there isn't much to do.";
    char nm[]="Let's get going, we have places to be!";
    char options[]="\n\t(1) Close the gate. \t(2) Stand and laugh.\t";
    if(hasItem(6)) {
        type(m1); getch();
        type(m2_1); getch();
        naviMessage(nm);
    } else if (!hasItem(6)) {
        type(m1); getch();
        type(m2); getch();
        type(m3); getch();
        type(m4); getch();
        show(options);
        while(!(cin>>op2) || !(op2>=1 && op2<=2)) {
            cin.clear();
            cin.ignore(50, '\n');
            cout<<"Try again: ";
        }
        if(op2==1) {
            int op;
            char m1[]="\n\tAH! Thank you! This little guy can be quite a handful!";
            char m2[]="\n\tNice to meet you. I'm Malon. My pa runs Lon Lon Ranch. What's your name? \n\t";
            char m3[]="...? That's such a nice name! \n\tLet me show you around...\n\tLook, that's Epona. She's a very silly horse...\n\tMy Pa's thinking to get rid of her.";
            char reply1[]="\n\t(1) Why? She looks so nice. \t(2) What'd she do?\t";
            char m4[]="\n\tWell, she's not like the other horses... she doesn't listen to anyone.";
            char m5[]="\n\tHey! Do you know Saria? You look a bit like...the people from Kokiri.";
            char reply2[]="\n\t(1) What about Saria? Is it your business? \t(2) Yeah, I know her!\t";
            char m6_1[]="\n\tWoah, calm down. No need to be so snappy.";
            char m6[]="\n\tI used to know Saria...when I was very small, she would sometimes come here.\n\tShe was the only person that Epona was okay with. \n\tSaria had something she would play for Epona... a bit like a flute... what is it called?";

            char reply3[]="\n\t(1) An Ocarina? \t(2) This is getting boring.\t";
            char m7_1[]="\n\tJust listen a little longer, it gets interesting.\n\tAh yes, AN OCARINA...";
            char m7[]="\n\tYes, yes, an Ocarina. Epona loved it. I bet if someone played an ocarina again, \n\tEpona would totally let them ride her. \n\tBut Pa doesn't understand Epona. I'm afraid he'll give her off to someone who doesn't understand her. \n\tShe's such a sweet horse. Would be a shame.";
            char reply4[]="\n\t(1) What a coincidence...I have an ocarina, you know! \t(2) Nice. I'll leave now.\t";
            char m8_1[]="\n\tOkay, wow, you're a ray of sunshine. \n\tTake that attitude somewhere else.";
            type(m1); getch();
            type(m2); getch();
            type(name, 100); type(m3); getch();
            show(reply1);
            while(!(cin>>op) || !(op>=1 && op<=2)) {
                cin.clear();
                cin.ignore(50, '\n');
                cout<<"Try again: ";
            }
            type(m4); getch();
            type(m5); getch();
            show(reply2);
            while(!(cin>>op) || !(op>=1 && op<=2)) {
                cin.clear();
                cin.ignore(50, '\n');
                cout<<"Try again: ";
            }
            if(op==1) {
                type(m6_1); getch();
            }
            type(m6); getch();
            show(reply3);
            while(!(cin>>op) || !(op>=1 && op<=2)) {
                cin.clear();
                cin.ignore(50, '\n');
                cout<<"Try again: ";
            }
            if(op==2) {
                type(m7_1); getch();
            }
            type(m7); getch();
            show(reply4);
            while(!(cin>>op) || !(op>=1 && op<=2)) {
                cin.clear();
                cin.ignore(50, '\n');
                cout<<"Try again: ";
            }
            if(op==2) {
                type(m8_1); getch();
            } else {
                char m[]="\n\tYOU DO??!! OH YES!!!";
                char m1[]="\n\tPlease, please, show me! Take it out right now!";
                type(m); getch();
                type(m1); getch();
                if(pickItem()==5) {
                    char m[]="\n\tPlay it!! ...Oh look, Epona's coming over here!";
                    char m1[]="\n\tIt's just as if Saria was here again! I haven't seen Epona this happy in so long!";
                    char m2[]="\n\n\tUh oh, my pa's coming.";
                    char m3[]="\n\t'MALON! WHAT GOES HERE? WHAT'S ALL THIS NONSENSE?!'";
                    char reply1[]="\n\t(1) Sir, I was just playing this Ocarina. \n\t(2) Sir, I was wondering if you'd borrow me this horse for a while. \t";
                    type(m); getch();
                    type(m1); getch();
                    clrscr(); header('l');
                    type(m2); getch();
                    type(m3); getch();
                    show(reply1);
                    while(!(cin>>op) || !(op>=1 && op<=2)) {
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout<<"Try again: ";
                    }
                    if(op==1) {
                        char m4[]="\n\tDO...I...LOOK...LIKE...I CARE??!!";
                        type(m4, 100); getch();
                    } else if (op==2) {
                        char m4[]="\n\tBORROW?? KID, YOU CAN TAKE THAT USELESS NAG FOR ALL ETERNITY, FOR ALL I CARE!";
                        type(m4); getch();
                    }
                    char m5[]="\n\tGIT OUT OF MY SIGHT! AND TAKE THAT GEE-GEE WITH YOU!";
                    type(m5); getch();
                    cout<<"\n\t\t>EPONA'S BRIDLE was added to your inventory. \n\tYou can now ride Epona and access new locations!";
                    hasEpona=true;
                    addItem(6);
                    getch();
                } else {
                    char m1[]="\n\tWow, I really didn't think you'd lie to me like that. \n\tOh well. Catch you later.";
                    type(m1); getch();
                    char nm[]="What a wasted opportunity!";
                    naviMessage(nm);
                }
            }

        } else if (op2==2) {
            cout<<"\n\tThe foal runs at you and knocks you over...\n\tWhoa, that hurt!";
            getch();
            char nm[]="You lost a life over a very silly mistake!";
            naviMessage(nm);
            lives--;
        }
    }



}

bool acceptBossFight=false;
void gerudoValley() {
    char place[]="\t\t***GERUDO VALLEY***";
    int op;
    clrscr();
    enterLocation(place);
    clrscr();
    header('g');
    char m1[]="\n\tA musty scent hangs in the air and dust swirls all around you...\n\tThe forces of evil are definitely at work here...";
    char m2[]="\n\tOther than the low howl of the wind, it is deathly quiet, \n\tand an impending feeling of doom crawls all around you.";
    char nm1[]="\tSomething awful is lurking out here...Watch out!";
    char m3[]="\n\tA narrow, winding path disappears into the swirling dust in front of you; \n\tThere is not another soul to be seen.";
    char nm2[]="\tWh- what's that?!";
    char m4[]="\n\tTheres an old lady lying against those rocks over there...\n\tWhat's she doing out here all alone? \n\tAnd how didn't you see her before?!";
    char options[]="\n\t(1) Talk to the old Gerudo lady. \n\t(2) Go down the path. \n\t(3) Go back to Hyrule field.\t";
    type(m1); getch();
    type(m2); getch();
    naviMessage(nm1, 'g');
    type(m3); getch();
    naviMessage(nm2, 'g');
    type(m4); getch();
    show(options);
    while(!(cin>>op) || !(op>=1 && op<=3)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"Try again: ";
    }
    if(op==1 && hasAbility(4)==false) {
        char m1[]="\n\tY-y-y-young m-m-an...";
        char m2[]="\n\tM-m-m-my dying... w-w-w-wish...";
        char m3[]="\n\tT-t-to h-h-h-ear... the sound... o-o-of an...";
        char m4[]="\n\tOh... to h-h-hear... t-t-the... t-t-to... soothe...";
        type(m1, 100); getch();
        type(m2, 120); getch();
        type(m3, 150); getch();
        type(m4, 180); getch();
        cout<<"\n\t(1) Pick an item from your inventory. \t(2) Leave. \t";
        while(!(cin>>op) || !(op>=1 && op<=2)) {
            cin.clear();
            cin.ignore(50, '\n');
            cout<<"Try again: ";
        }
        if(op==1) {
            if(pickItem()==5) {
                char m1[]="\n\tAhhh... who... are... you...";
                char dots[]="\n\t...";
                char m2[]="\n\tG-g-g-Ganon....";
                char m3[]="\n\tI d-d-don't w-w-want... th-that he... d-d-destruct h-h-h-Hyrule...";
                char m4[]="\n\tT-t-take this...young o-o-one... m-m-my...G-g-gerudo s-s-slippers...";
                char m5[]="\n\tY-y-you shall have...th-th-the stealth.. of a G-g-gerudo...\n\tY-y-you will n-n-not be very fast... b-b-but you will be u-u-unnoticed...";
                char m6[]="\n\t...Ah... Y-y-you w-w-were here... w-w-when...";
                char m7[]="n-n-no one was...";
                type(m1, 100); getch();
                type(dots, 200); type(name, 100); type(dots, 100); getch();
                type(m2, 100); getch();
                type(m3, 100); getch();
                type(m4, 100); getch();
                type(m5, 100); getch();
                type(m6, 100); getch();
                type(m7, 100); getch();
                cout<<"\n\t\t>GERUDO STEALTH was added to your abilities.";
                addAbility(4);
                cout<<"\n\tThe roaring wind sweeps you off your feet...";
                getch();

            } else {
                cout<<"\n\tThat doesn't really work here...";
                getch();
                cout<<"\n\tThe roaring wind sweeps you off your feet...";
                getch();
            }
        }
    } else if(op==1 && hasAbility(4)==true) {
        char m1[]="\n\tShe doesn't seem to be breathing.";
        type(m1);
        getch();
        cout<<"\n\tThe roaring wind sweeps you off your feet..."; getch();

    } else if(op==2) {
        char m1[]="\n\tAre you absolutely sure you are strong enough for this battle?";
        char m2[]="\n\tYou have only one chance at this, and the forces of evil \n\tare harrowingly strong...";
        type(m2); getch(); type(m1, 70); getch();
        cout<<"\n\t(1) Yes. \t(2) No. \t";
        while(!(cin>>op) || !(op>=1 && op<=2)) {
            cin.clear();
            cin.ignore(50, '\n');
            cout<<"Try again: ";
        }
        if(op==1) {
            acceptBossFight=true;
        }
    }

}

//all the functions to be used inside hyruleField() are above this function.
void hyruleField() {
    int castleVisits=0;
    bool getBow=false;
    bool getSlingshot=false;
    bool ratProblem=true;
    bool hasBombs=false;
    bool wallBlasted=false;
    int pots=0;
    location='h';
    char place[]="\t\t***HYRULE FIELD***";
    char m1[]="\n\tHyrule field lays before you... a wide, rolling expanse...\n\tEverywhere you look is a new horizon, a new landscape you've never seen before...";
    char m2[]="\n\tA huge, royal-looking castle looms to your far left...\n\tIs that the sound of rushing water? There must be a river somewhere nearby. \n\tThe clatter of horsecarts and the chatter of people...\n\tsounds like there is a village somewhere here as well...\n\tThe neighing of horses, like music to your ears, is coming from somewhere in front of you.\n\tWhat a strange place, yet so full of possibilities!";
    char m3[]="\t'I know this unfamiliar place is scary, but you got me!'";
    char m4[]="\n\tLet's see what we have here...";
    char m5[]="\n\tThis rolling expanse... the heart of Hyrule and the place of possibilities!";
    char m[]="\n\n\t(1) Hyrule Castle \n\t(2) Zora's River \n\t(3) Kakariko Village \n\t(4) Gerudo Valley \n\t(5) Lon Lon Ranch \n\t(6) Display Inventory \n\t(7) Save Game \t";

    clrscr();
    header('h');
    cout<<endl;
    type(m1);
    getch();
    type(m2,5);
    getch();
    naviMessage(m3, 'h');
    type(m4);
    getch();

    hyrule:
    clrscr();
    enterLocation(place);
    header('h');
    show(place);
    cout<<"\n\tThere are many places we can go..."<<endl;
    show(m);
    int op;
    while(!(cin>>op) || !(op>=1 && op<=7)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"Try again: ";
    }

    switch(op) {
    case 1: { //hyrule castle
        castle:
            location='c';
            char castle[]="\t\t***HYRULE CASTLE***";
            clrscr();
            enterLocation(castle);
            header('c');
            char op;
            if(castleVisits==0) {
                castleVisits++;
                char op2;
                char m1[]="\tThere's a lot of guards here...";
                char m2[]="\n\tWho goes there?!";
                char m3[]="\n\tAh, a knee-high youth.\n\tYoung man, you must be lost.\n\tGo back home! This is no place for young 'uns!";
                char reply[]="\n\t(1) 'I need to see Princess Zelda.' \n\t(2) 'Please, allow me to see Princess Zelda.\n\t     The Great Deku Tree has sent me for something extremely important.' \n\t(3) *Run out* \t";
                naviMessage(m1, 'c');
                type(m2);
                getch();
                type(m3);
                getch();
                show(reply);
                cin>>op2;

                while(op2!='1' && op2!='2' && op2!='3') {
                    cout<<"\n\tTry again: ";
                    cin>>op2;
                }

                if(op2=='3') {
                    goto hyrule;
                }
            }
            else if (castleVisits>0) {
                char m1[]="\n\tLanky, sneering guards peer down at you...\n\tThey don't seem very pleased to see you here again.";
                type(m1);
                getch();
            }

            if(!(hasItem(6))) {
                char m4[]="\n\t'How dare you show up here and try to sneak in with your tall tales!\n\tWhat a little imp!'";
                char m5[]="\n\tGet out of here!!! You shall not be allowed in!'";
                type(m4); getch();
                type(m5); getch();
                char naviMsg[]="\tYou'll need to scale the walls of the castle and sneak in.";
                char naviMsg2[]="\tTry finding something - or someone - that can help you do that.";
                naviMessage(naviMsg, 'c');
                naviMessage(naviMsg2, 'c');
                goto hyrule;

            } else if(hasItem(6)) {
                char jok[]="\n\t'HA, HA, HA! A silly child! What fine entertainment! \n\tTake your tall tales of heroism somewhere else!'";
                char naviMsg[]="No use arguing with them... They wouldn't understand!";
                char naviMsg2[]="\tDon't you have something... or someone... that could help you scale these walls?";
                char naviMsg3[]="\tI don't think that'll work!";
                char m6[]="\n\tYou run up to the walls of the castle on the far side...\n\tEpona's stride is sure and steady, and the wind rushes through your hair...";
                char m7[]="\n\tEpona takes a flying leap - you hold on for dear life!";
                char m8[]="\n\t...You're...inside... the castle!";
                type(jok);
                getch();
                naviMessage(naviMsg, 'c');
                naviMessage(naviMsg2, 'c');

                if(pickItem()==6) {
                    type (m6);
                    getch();
                    type(m7);
                    getch();
                    type(m8, 100);
                    getch();
                } else {
                    naviMessage(naviMsg3, 'c');
                    cout<<"\n\tYOU'VE BEEN HERE TOO LONG, YOUNG 'UN!\n\tWe're kicking you out!";
                    getch();
                    goto hyrule;
                }

                meetZelda();
                goto hyrule;

            }

    break;
    }

    case 2: { //zora river
        char zoras[]="\t\t***ZORA'S DOMAIN***";
        enterLocation(zoras);
        clrscr();
        header('z');
        show(zoras);

        if(!(hasItem(6))) {
            char m[]="\n\tA rushing river spans in front of you...\n\tThere's no way you can make it across...";
            char m1[]="\tFind someone - or something - that'll help you get across!";
            type(m); getch();
            naviMessage(m1, 'z');
        } else if(hasItem(6)==true && eponaTired==false) {
            char m[]="\n\tA rushing river spans in front of you...\n\tEpona jumps in and swims across, kicking powerfully with her strong legs...";
            char m1[]="\n\tYou're across!";
            type(m); getch();
            type(m1); getch();
            zorasRiver();
            eponaTired=true;
        } else if(hasItem(6)==true && eponaTired==true) {
            char m[]="\n\tA rushing river spans in front of you...\n\tYou kick Epona and encourage her, \n\tBut she's too tired to swim across again.";
            char m1[]="\tIf you find a place that could rest Epona up, she could swim across again.";
            type(m); getch();
            naviMessage(m1, 'z');
        }
        goto hyrule;
        break;
    }

    case 3: { //kakariko
        int op;
        char kakariko[]="\n\t\t***KAKARIKO VILLAGE***";
        kakariko:
        location='v';
        clrscr();
        enterLocation(kakariko);
        clrscr();
        header('v');
        show(kakariko);
        cout<<"\n\t(1) Kakariko Shop \t\t(2) A small, cozy-looking home \n\t(3) Deku Business Scrub \t(4) A very tall pole \n\t(5) Gorons' Den \t\t(6) Kakariko Stables \n\t(7) A battered-looking wall \t(8) Some pots lying around \n\t(9) Display Inventory \t\t(10) Save Game \n\t(0) Leave Kakariko\t";
        while(!(cin>>op) || !(op>=0 && op<=10)) {
            cin.clear();
            cin.ignore(50, '\n');
            cout<<"Try again: ";
        }
        switch(op){
        case 1: //shop
            kakarikoShop();
            goto kakariko;
            break;
        case 2: //home
            if(getBow==false) {
                getBow= kakarikoHome();
            } else {
                clrscr(); header('v');
                cout<<"\n\tA baby and his mother are sleeping peacefully here.";
                getch();
            }
            goto kakariko;
        break;
        case 3: //dekuBusinesssScrub
            if(getSlingshot==false) {
                getSlingshot= dekuBusinessScrub();
            } else {
                clrscr(); header('v');
                cout<<"\n\tA sign reads: 'DEKU BUSINESS SCRUB - Out for business. Will be back shortly.'";
                getch();
            }
            goto kakariko;
            break;
        case 4: //pole
            if(hasItem(8) && hasBombs==false) {
                clrscr(); header('v'); cout<<"\n\tThis pole is really tall, but there might be something interesting up top...\n\tMaybe you have something you can use to get up there...";
                if(pickWeapon()==8) {
                    cout<<"\n\tYou aim the Hookshot at the top of the pole and release the trigger..."; getch();
                    cout<<"\n\tWith a whoosh, you're pulled up to the top of the pole!"; getch();
                    cout<<"\n\tYou found some Bombchus = a special type of bomb that can blast away walls in seconds!"; getch();
                    cout<<"\n\t\t>BOMBCHUS were added to your inventory.";
                    hasBombs=true;
                    addItem(10);
                    getch();
                    goto kakariko;
                } else {
                    cout<<"\n\tThat wouldn't really work...";
                    getch();
                    goto kakariko;
                }
            } else if (hasBombs==true) {
                cout<<"\n\tNothing much to see here."; getch(); goto kakariko;
            } else if (!(hasItem(8))) {
                cout<<"\n\tThis pole is really tall, but there might be something interesting up top...\n\tIf only you had something that could help you get up there!";
                getch();
                goto kakariko;
            }
        break;
        case 5: //goron
            goronsDen();
            goto kakariko;
            break;
        case 6: //stables
            if ((kakarikoStables(ratProblem))==1) {
                ratProblem=false;
            };
            goto kakariko;
            break;
        case 7: //wall
            if (wallBlasted) {
                    cout<<"\n\tNothing much to see here.\n\tJust the wall that you obliterated with the Bombchu.";
                    getch();
            } else {
                wallBlasted = kakarikoWall();
            }
            goto kakariko;
            break;
        case 8: //pots
            clrscr(); header('v');
            if(pots>4) {
                cout<<"\n\tYou've smashed these pots to smithereens, "<<name<<"! Noting to see here!"; getch();
            } else {
                char ans;
                cout<<"\n\tA line of pots stands before you...";
                do {
                cout<<"\n\tBreak some pots? (Y/N): ";
                cin>>ans;
                } while (ans!='y' && ans!='Y' && ans!='N' && ans!='n');
                if(ans=='y' || ans=='Y') {
                    cout<<"\n\tYou smashed some pots and found 30 Rupees!";
                    rupees+=30;
                    pots++;;
                    getch();
                }
            }
            goto kakariko;
            break;
        case 9: //inv
            showInventory();
            goto kakariko;
        case 10: //save
            saveFile();
            goto kakariko;
        case 0: //leave
            goto hyrule;
            break;
        }
    break;
    }
    case 4: { //gerudo valley
        gerudoValley();
        if(!(acceptBossFight)) {
            goto hyrule;
        }
    break;
    }
    case 5: { //lon lon ranch
        lonLonRanch();
        goto hyrule;
        break;
    }

    case 6: { //display inventory
        showInventory();
        goto hyrule;
        break;
    }

    case 7: { //save game
        saveFile();
        goto hyrule;
        break;
    }

    }
}

//special header for boss fight that includes Ganon's life meter
void ganonHeader(int gLives) {
    for(int i=0; i<=1; i++) {
        for(int j=0; j<=25; j++){
            cout<<"%%%%";
        }
        cout<<endl;
    }
    cout<<"\n\tLives = "<<lives<<"/3"<<"\tInventory = "<<inv<<"/13"<<"\tAbilities = "<<ab<<"/4"<<"\t\tRupees = "<<rupees<<endl;
    for(int j=0; j<=20; j++) {
        cout<<"_____";
    }
    cout<<endl<<endl;

    cout<<"\t\t\t GANON'S LIFE:   [";
    int remSpace=8-gLives;
    for(int i=1; i<=gLives; i++) {
        cout<<"\\\\\\";
    }
    for(int i=1; i<=remSpace; i++) {
        cout<<"   ";
    }
    cout<<"]"<<endl<<endl;;

    for(int j=0; j<=20; j++) {
        cout<<"_____";
    }

}

void bossFight() {
    clrscr();
    header('g');
    location='b'; //boss fight
    char ans;
    do {
    cout<<"\n\tSave Game before continuing? Y/N: ";
    cin>>ans;
    } while(ans!='y' && ans!='Y' && ans!='n' && ans!='N');
    if(ans=='y' || ans=='Y') {
        saveFile();
    }
    char castle[]="\n\t\t***GANON'S CASTLE***";
    clrscr();
    enterLocation(castle);
    clrscr();
    header('g');
    show(castle);
    char s1[]="\n\tA FOOL!";
    char s2[]="\n\tAh... much about you amuses me, ";
    char dots[]="...";
    char s3[]="\n\tThe nerve... the cheek... the gall... the audacity... THE TOMFOOLERY!";
    type(s1, 200);
    getch();
    type(s2);
    type(name);
    type(dots);
    getch();
    type(s3);
    getch();
    char s4[]="\n\tCome on now! Zelda's pathetic little minion...\n\tIf you must be so bold, \n\tchoose to enter my dungeon...";
    char s5[]="\n\tNever mind, it's not like you're getting a menu to choose from... \n\tThe choices you make will be quick and few - \n\t (and foolish) - \n\tbut this shall not be a choice.";
    char s6[]="\n\tENTER MY DUNGEON, AND BEHOLD MY POWER!";
    type(s4);
    getch();
    type(s5);
    getch();
    type(s6);
    getch();

    clrscr();
    char dungeon[]="\n\n\t\t***GANON'S DUNGEON***\n\n";
    int gLives = 8;
    int op;
    type(dungeon, 200);
    clrscr();
    enterLocation(dungeon, 200, 5);

    clrscr();
    ganonHeader(gLives);
    show(dungeon);
    char m1[]="\n\tGanon towers before you, a stocky, hefty mass of reeking muscle...\n\tHe's so huge, you can barely see past his legs.";
    char a1[]="\n\t(1) Slash his left leg \n\t(2) Slash his right leg \t";
    type(m1); getch();
    show(a1);
    while(!(cin>>op) || !(op==1 || op==2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }
    if(op==1) {
        char g[]="\n\tARRRGHHHH!!! NOT... NOT THAT DAMNED WOUND!";
        type(g, 100);
        gLives--;
        getch();
    } else if (op==2) {
        char g[]="\n\tOUCH! YOU FILTHY IMP!\n\tWHAM!...TAKE THAT!";
        type(g, 20);
        lives -= 0.5;
        getch();
    }

    //1
    clrscr();
    ganonHeader(gLives);
    show(dungeon);
    char m2[]="\n\tGanon has his back turned to you - seems like he's \n\ttaking out something long and pointed...";
    char m3[]="\n\tGanon flips around - a spear is whizzing right at you with incredible speed!";
    char a2[]="\n\n\t(1) Use an Ability \n\t(2) Use a Weapon \t";
    type(m2);
    getch();
    type(m3);
    getch();
    show(a2);
    while(!(cin>>op) || !(op==1 || op==2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }
    if(op==1) {
        if(pickAbility()==1) {
            char g[]="\n\tARRRGHHHH!!! MISSED YOU!";
            type(g);
            getch();
        } else {
            char g[]="\n\tThat didn't work! The spear hit your arm.\n\tOuch!";
            type(g);
            lives -= 0.5;
            getch();
        }
    } else if (op==2) {
        if(pickWeapon()==1) {
            char g[]="\n\tOUCH! MY SPEAR DEFLECTED BACK AT ME?!";
            char g1[]="\n\tARGGGHH! YOU'LL PAY FOR THIS!";
            type(g, 20);
            getch();
            type(g1);
            gLives --;
            getch();
        } else {
            char g[]="\n\tThat didn't work! The spear hit your arm.\n\tOuch!";
            type(g);
            lives -= 0.5;
            getch();
        }
    }


    //2
    clrscr();
    ganonHeader(gLives);
    show(dungeon);
    char m4[]="\n\tGanon raises his hand...";
    char m5[]="\n\tAn icy chill envelops you... There seems to be some kind of freezing spell\n\tcoming from his hand...";
    type(m4); getch();
    type(m5); getch();
    show(a2);
    while(!(cin>>op) || !(op==1 || op==2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }
    if(op==1) {
        pickAbility();
        char g[]="\n\tThat didn't work! The freezing winds dealt you a lot of damage.\n\tOuch!";
        type(g);
        lives -= 0.5;
        getch();

    } else if (op==2) {
        if(pickWeapon()==12) {
            char g[]="\n\tOUCH! THAT HURT!!!";
            char g1[]="\n\tARGGGHH! YOU'LL PAY FOR THIS!";
            type(g, 20);
            getch();
            type(g1);
            gLives --;
            getch();
        } else {
            char g[]="\n\tThat didn't work! The freezing winds dealt you a lot of damage.\n\tOuch!";
            type(g);
            lives -= 0.5;
            getch();
        }
    }

    //3
    clrscr();
    ganonHeader(gLives);
    show(dungeon);
    char m6[]="\n\tSomething trembles under your feet... a disgusting, slimy mass \n\tseems to be growing out of the floor, \n\tlike... a nail sticking out of a wall...";
    char m7[]="\n\t'YOU DIDN'T THINK I DIDN'T HAVE MY OWN LITTLE MINIONS, EH? \n\tThat's a Like Like, and as long as it's not \n\tflattened out, it'll swallow you and your posessions \n\tone by one. HA HA!";
    type(m6); getch();
    type(m7); getch();
    show(a2);
    while(!(cin>>op) || !(op==1 || op==2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }
    if(op==1) {
        pickAbility();
        char g[]="\n\tThat didn't work! The Like Like swallowed some of your items.\n\tOh no!";
        type(g);
        if(hasItem(7)) {
            loseItem(7);
        }
        if(hasItem(9)) {
            loseItem(9);
        }
        if(hasItem(23)) {
            loseItem(23);
        }
        getch();

    } else if (op==2) {
        if(pickWeapon()==9) {
            char g[]="\n\tYou smashed the Like-Like flat into the floor.\n\tSome of your health is restored.";
            char g1[]="\n\tWELL, WELL, WELL! DON'T GET OVERCONFIDENT!\n\tIT WON'T BE THIS EASY NEXT TIME!";
            type(g, 20); getch(); type(g1, 30);
            if(lives<3) {
                lives+=0.5;
            }
            getch();
        } else {
            char g[]="\n\tThat didn't work! The Like Like swallowed some of your items.\n\tOh no!";
            type(g);
            if(hasItem(7)) {
                loseItem(7);
            }
            if(hasItem(9)) {
                loseItem(9);
            }
            if(hasItem(23)) {
                loseItem(23);
            }
            getch();
        }
    }

    //4
    clrscr();
    ganonHeader(gLives);
    show(dungeon);
    char m8[]="\n\tGanon must have summoned some more of his minions, \n\tfor what appears to be fire-breathing bats are flying at you from a corner of the dungeon. ";
    type(m8); getch();
    show(a2);
    while(!(cin>>op) || !(op==1 || op==2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }
    if(op==1) {
        pickAbility();
        char g[]="\n\tThat didn't work! You were set on fire by the bats!\n\tOuch! PAINFUL!";
        type(g);
        lives-=0.5;
        getch();

    } else if (op==2) {
        int weapon=pickWeapon();
        if(weapon==13 || weapon==7) {
            char g[]="\n\tYou knocked down the bats one by one. \n\tSome of their lifeless bodies clunked against Ganon's head, too.";
            char g1[]="\n\tARGGGHH! YOU'LL PAY FOR THIS!";
            type(g, 20);
            getch();
            type(g1);
            gLives--;
            getch();
        } else if (weapon==12) {
            char g[]="\n\tThat didn't work! The Fire Arrows made the bats even stronger.\n\tYou lost a whole life!";
            type(g); lives--;
            getch();
        } else {
        char g[]="\n\tThat didn't work! You were set on fire by the bats!\n\tOuch! PAINFUL!";
        type(g);
        lives-=0.5;
        getch();
        }
    }

    //5
    clrscr();
    ganonHeader(gLives);
    show(dungeon);
    char m9[]="\n\tGanon seems to have disappeared behind a wall... \n\tIs there something you can use to get past the wall,\n\twithout wasting time going around it?!";
    type(m9); getch();
    show(a2);
    while(!(cin>>op) || !(op==1 || op==2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }
    if(op==1) {
        pickAbility();
        char g[]="\n\tThat didn't work! Ganon smashes right through the wall and \n\tlunges at you with his sword!";
        type(g);
        lives-=0.5;
        getch();

    } else if (op==2) {
        if(pickWeapon()==10) {
            char g[]="\n\tThe Bombchu obliterated the wall! You dealt Ganon some damage, too.";
            char g1[]="\n\tARGGGHH! YOU'LL PAY FOR THIS!";
            type(g, 20); getch(); type(g1);
            gLives--;
            getch();
        } else {
            char g[]="\n\tThat didn't work! Ganon smashes right through the wall and \n\tlunges at you with his sword!";
            type(g);
            lives-=0.5;
            getch();
        }
    }


    if(lives==0) {
        if(hasItem(3)) {
            cout<<"\n\n\t\t>Your FAIRY IN A BOTTLE replenished your lives. \n\tYou're good to go!";
            lives=3;
            loseItem(3);
        }
        else
            cout<<"\n\tYOU LOST ALL YOUR LIVES!"<<endl;
            getch();
            gameOver();
    }

    //6
    clrscr();
    ganonHeader(gLives);
    show(dungeon);
    char m10[]="\n\t\n\tLooks like the way the wall shattered triggered something...\n\tThe pipes of the dungeon have burst!\n\tGanon seems safe and dry on a raised platform in the center... \n\tbut you find yourself in rushing water, gasping for breath... ";
    type(m10); getch();
    show(a2);
    while(!(cin>>op) || !(op==1 || op==2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }
    if(op==1) {
        if(pickAbility()==3) {
            char g[]="\n\tYou manage to swim across and climb up on the platform.\n\tYour health is restored!";
            type(g);
            if(lives<3) {
                lives+=0.5;
            }
            getch();
        } else {
            char g[]="\n\tYou couldn't hold up against the rushing current - you drowned!";
            type(g);
            getch();
            gameOver();
        }

    } else if (op==2) {
        pickWeapon();
        char g[]="\n\tThat didn't work! \n\tYou couldn't hold up against the rushing current - you drowned!";
        type(g);
        getch();
        gameOver();
    }

    //7
    clrscr();
    ganonHeader(gLives);
    show(dungeon);
    char m11[]="\n\n\tGanon seems rather disoriented... What will you use this opportunity for?";
    type(m11); getch();
    char a3[]="\n\t(1) Lunge at him with your sword. \n\t(2) Goron Punch him. \n\t(3) Push him into the water. \t";
    show(a3);
    while(!(cin>>op) || !(op==1 || op==2 || op==3)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }

    if(op==1) {
        char g[]="\n\tYou dealt Ganon some damage, but he slashed back at you, too.";
        type(g);
        gLives--;
        lives-=0.5;
        getch();

    } else if (op==2) {
        char g[]="\n\tYou dealt Ganon some damage, but he slashed back at you, too.";
        type(g);
        gLives--;
        lives-=0.5;
        getch();
    } else if (op==3) {
        char g[]="\n\tAAAAAAAGGGGHHHHH!!!! NOOOOOOOOOOOO!!!!!!!! \n\tJUST WAIT AND SEE WHAT I DO TO YOU!";
        type(g); getch();
        char g1[]="\n\tYou dealt Ganon a lot of damage!";
        type(g1);
        gLives-=2;
        lives-=0.5;
        getch();
    }

    if(lives==0) {
        if(hasItem(3)) {
            cout<<"\n\n\t\t>Your FAIRY IN A BOTTLE replenished your lives. \n\tYou're good to go!";
            lives=3;
            loseItem(3);
        }
        else
            cout<<"\n\tYOU LOST ALL YOUR LIVES!"<<endl;
            getch();
            gameOver();
    }

    //max ganon lives lost at this point=6
    //8
    clrscr();
    ganonHeader(gLives);
    show(dungeon);
    char m12[]="\n\n\tGanon really does have a problem with water...\n\tHe's started scaling a pole to reach the upper storey of the dungeon! \n\tQuick, find a way to reach before he does!";
    type(m12); getch();
    show(a2);
    while(!(cin>>op) || !(op==1 || op==2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }

    if(op==1) {
        pickAbility();
        char g[]="\n\tThat didn't work! Ganon drops a huge concrete block from above - \n\tyour breath's knocked out!";
        type(g);
        lives--;
        getch();

    } else if (op==2) {
        if(pickWeapon()==8) {
            char g[]="\n\tThe Hookshot propels you to the upper floor in seconds - \n\tyou find a concrete block teetering at the edge. \n\tWith one firm push, it goes crashing down - \n\tAnd takes Ganon with it!";
            char g1[]="\n\tARGGGHH! YOU'LL PAY FOR THIS!";
            type(g, 20); getch(); type(g1);
            gLives--;
            getch();
        } else {
            char g[]="\n\tThat didn't work! Ganon drops a huge concrete block from above - \n\tyour breath's knocked out!";
            type(g);
            lives--;
            getch();
        }
    }

    //9
    clrscr();
    ganonHeader(gLives);
    show(dungeon);
    char m13[]="\n\n\tIs this the final showdown?! ...\n\tA sudden darkness envelops the dungeon...\n\tYou can hardly see anything. \n\tGanon's face looms before you...almost as though it is radiating \n\tdarkness...";
    type(m13); getch();
    show(a2);
    while(!(cin>>op) || !(op==1 || op==2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }

    if(op==1) {
        pickAbility();
        char g[]="\n\tThat didn't work! With a massive howl, Ganon knocks you to the floor...";
        type(g);
        char g1[]="\n\tIt's over...";
        type(g1, 150);
        gameOver();

    } else if (op==2) {
        if(pickWeapon()==13) {
            char g[]="\n\tWith one deft movement, you shoot the Light Arrow at Ganon's ugly forehead...";
            char g1[]="\n\tBrightness floods into the dungeon as Ganon convulses and screeches.";
            char g2[]="\n\tAAAAAAARRRGGGGGGHHHH!";
            type(g); getch(); type(g1); getch();
            type(g2, 200);
            getch();
        } else {
            char g[]="\n\tThat didn't work! With a massive howl, Ganon knocks you to the floor...";
            type(g);
            char g1[]="\n\tIt's over...";
            type(g1, 150);
            gameOver();
        }
    }

}

void conclusion() {
    int op;
    char nm1[]="\n\tYou did it...! You really did it!";
    naviMessage(nm1);
    char place[]="\n\t\t***HYRULE FIELD***";
    clrscr();
    start:
    enterLocation(place);
    header('h');
    show(place);
    cout<<"\n\tThere are many places we can go...";
    getch();
    cout<<"\n\tBut only two that could matter.";
    cout<<"\n\t(1) Hyrule Castle \n\t(2) Kokiri Forest \t";
    while(!(cin>>op) || !(op==1 || op==2)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }

    if(op==1) {
        clrscr();
        header('c');
        cout<<"\n\t\t***ZELDA'S COURTYARD***";
        char m1[]="\n\tA hero's welcome to you, dearest ";
        type(m1); type(name); getch();
        char m2[]="\n\tThanks to you, the evil Ganon has been banished to the Realm of Darkness...\n\tAnd the Triforce of Power has been returned to its rightful place once again.";
        char m3[]="\n\tHyrule shall be at peace again once more.";
        char m4[]="\n\tIf you made any promises... to anyone... I trust you shall fulfill them.";
        type(m2); getch();
        type(m3); getch();
        type(m4); getch();
        goto start;
    } else if (op==2) {
        clrscr();
        char place[]="\n\t\t***KOKIRI FOREST***";
        enterLocation(place);
        clrscr();
        header('k');
        show(place);
        cout<<"\n\n\tSomeone greets you enthusiastically...";
        getch();
        cout<<"\n\n\t";
        char m[]="!!";
        char m1[]="...welcome back home!\n\tWe are so relieved you came back...\n\tYou must have so many stories to tell us!";
        char m2[]="\n\n\tBegin by telling me...\n\n\tWas my Ocarina useful, after all?";
        type(name); type(m); getch();
        type(m1,80); getch();
        type(m2,120); getch();
        getch();
    }

}

int main() {
    int op;
    mainMenu:
    clrscr();
    header('o');
    cout<<"\n\tTHE LEGEND OF ZELDA: The Ocarina of Time [adapted]"<<endl;
    cout<<"\t(1) Start New Game \n\t(2) Load Game from Saved File \n\t(3) Instructions\n\t(4) Credits \n\t(0) Quit \t";

    while(!(cin>>op) || !(op>=0 && op<=4)) {
        cin.clear();
        cin.ignore(50, '\n');
        cout<<"\n\tTry again: ";
    }


    if(op==0) {
        gameOver();
    } else if (op==3) {
        instructions();
        goto mainMenu;
    } else if (op==4) {
        credits();
        goto mainMenu;
    } else if (op==2) {
        openSavedFile();
    } else {
        location='0';
        cout<<"\n\t\t(1) Enter your name \n\t\t(2) Play as Link (default) \t";
        while(!(cin>>op) || !(op==1 || op==2)) {
            cin.clear();
            cin.ignore(50, '\n');
            cout<<"\n\tTry again: ";
        }

        if (op==1) {
            cout<<"\n\t\tEnter the name that you wish to be called by [spaces not allowed]: ";
            cin>>name;
        }
    }

    switch(location) {
    case '0':
        goto step1;
        break;
    case 'k':
        goto step2;
        break;
    case 'h':
    case 'v': //if you save in kakariko > still open in hyrule field (kakariko is within hyrule)
        goto step3;
        break;
    case 'b':
        goto step4;
        break;
    }
    step1:
        opening();
        firstDialogue();
    step2:
        exploreKokiri();
    step3:
        hyruleField();
    step4:
        bossFight();
        conclusion();
        gameWin();

    return 0;

}
