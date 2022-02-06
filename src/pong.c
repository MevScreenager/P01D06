#include <stdio.h>

void check();
void cross_and_toe_display();
void step_bord(char play);
int ball_direct = -1, x_ball = 18, y_ball = 0;
void move_ball();
int coor_bord_1 = 13, coor_bord_2 = 13;
int count_1 = 0, count_2 = 0;
int move_side = 1;
char play = ' ';

int main() {
while (1) {
move_ball();
step_bord(play);
printf("\n");

for (int i=1; i<=35; i++) printf("%c", ' ');
printf("%d\t%d", count_1, count_2);
printf("\n");

cross_and_toe_display();

for (int i = 0; i < 80; i++) printf("_");
if (count_1 == 21) {
printf("\n");
for (int i=1; i <= 18; i++) printf(" ");
printf("Поздравляем с победой игрок 1!");
return 0;
}
if (count_2 == 21) {
printf("\n");
for (int i=1; i <= 18; i++) printf(" ");
printf("Поздравляем с победой игрок 2!");
return 0;
}
int time = getchar();
if (time != 10) play = (char) time;
}
}

void cross_and_toe_display() {
char platforma = '|';
char ball = '*';
char space = ' ';
for (int i = 0; i < 25; i++) {
for (int j = 0; j < 80; j++) {
if (j == 0) {
if (i == y_ball && j == x_ball) printf("%c", ball);
else
if (i == (coor_bord_1 - 1) || i == coor_bord_1 || i == (coor_bord_1 + 1)) printf("%c", platforma);
else 
printf("%c", space);
}
if (j == 79) {
if (i == y_ball && j == x_ball) printf("%c", ball);
else
if (i == (coor_bord_2 - 1) || i == coor_bord_2 || i == (coor_bord_2 + 1)) printf("%c", platforma);
else
printf("%c", space);
}
if (j != 0 && j != 79) {
if (i == y_ball && j == x_ball) printf("%c", ball);
else
printf("%c", space);
}
}
}
}

void step_bord(char play) {
switch (play) {
case 'A': if  (coor_bord_1 > 1)
coor_bord_1 --;
break;
case 'Z': if  (coor_bord_1 < 23)
coor_bord_1 ++;
break;
case 'K': if  (coor_bord_2 > 1)
coor_bord_2 --;
break;
case 'M': if  (coor_bord_2 < 23)
coor_bord_2 ++;
break;
}
play = ' ';
}

void check() {
if (x_ball == 78 && (y_ball == (coor_bord_2 - 1) || y_ball == coor_bord_2 || y_ball == (coor_bord_2 + 1))) move_side = 2;
if (x_ball == 1 && (y_ball == (coor_bord_1 - 1) || y_ball == coor_bord_1 || y_ball == (coor_bord_1 + 1))) move_side = 1;
if (y_ball == 0 || (y_ball == (coor_bord_1 + 1) && x_ball == 1) || (y_ball == (coor_bord_2 + 1) && x_ball == 78)) ball_direct = 1;
if (y_ball == 24 || (y_ball == (coor_bord_1 - 1) && x_ball == 1) || (y_ball == (coor_bord_2 - 1) && x_ball == 78)) ball_direct = -1;
if ((y_ball == coor_bord_1 && x_ball == 1) || (y_ball == coor_bord_2 && x_ball == 78)) ball_direct = 0;
if (x_ball == 79) {
count_1 ++;
move_side = 1;
x_ball = 13;
y_ball = 13;
ball_direct = -1;
}
if (x_ball == 0) {
count_2 ++;
move_side = 2;
x_ball = 76;
y_ball = 13;
ball_direct = -1;
}
}

void move_ball() {
check();
if (move_side == 1) {
if (ball_direct == -1 && y_ball != 0) {
y_ball --;
x_ball ++;
}
else
if (ball_direct == 1 && y_ball != 24) {
y_ball ++;
x_ball ++;
}
else
x_ball ++;
}

if (move_side == 2) {
if (ball_direct == -1 && y_ball != 0) {
y_ball --;
x_ball --;
}
else
if (ball_direct == 1 && y_ball != 24) {
y_ball ++;
x_ball --;
}
else x_ball --;
}
}
