// 来源：C4droid吧，id: tgxx501
// https://tieba.baidu.com/p/4714439374
// 日期：2016-08-05
// 整理：QAIU

//受CGL范例启发，写了一个纯C的自动弹球机，可以用来研究反射情况。
 //#include<stdio.h>
 #include<conio.h>
 #define xx 33
 #define yy 22
 #define Time 18000
 void move(int o);
 void color(int c);
 void wk();
 int x, y, i, lost_key, cr=37, high_light=0;
 int main() {
  wk();
  printf("\e[?25l");
  x=2;y=2;move(9);//发射配置
  while (1){
  if (y==yy){//碰底,y++,判断x-- or x++
  if (lost_key==9){//从左打来
  while (y!=2&&x!=2&&x!=xx){
  move(3);
  }
  }
  else if (lost_key==7){//从右打来
  while (y!=2&&x!=2&&x!=xx){
  move(1);
  }
  }
  }
  if (y==2){//碰顶,y--,判断x-- or x++
  if (lost_key==1){//从右打来
  while (y!=yy&&x!=2&&x!=xx){
  move(7);
  }
  }
  else if (lost_key==3){//从左打来
  while (y!=yy&&x!=2&&x!=xx){
  move(9);
  }
  }
  }
  if (x==xx){//碰到右壁,x++,判断y++ or y--
  if (lost_key==3){//从下打来
  while (x!=2&&y!=2&&y!=yy){
  move(1);
  }
  }
  else if (lost_key==9){//从上打来
  while (x!=2&&y!=2&&y!=yy){
  move(7);
  }
  }
  }
  if (x==2){//碰到左壁,x--,判断y++ or y--
  if (lost_key==1){//从下打来
  while (x!=xx&&y!=2&&y!=yy){
  move(3);
  }
  }
  else if (lost_key==7){//从上打来*
  while (x!=xx&&y!=2&&y!=yy){
  move(9);
  }
  }
  }
  if (x!=xx&&y!=2&&y!=yy&&x!=2){
  move(lost_key);
  }
  if (x==xx&&y==yy){//碰到右下角(lost_key==9)
  move(1);//有风险，初始值方向设置错误也能发射。
  color(1);
  }
  if (x==2&&y==yy){//碰到左下角(lost_key==7)
  move(3);
  color(1);
  }
  if (x==xx&&y==2){//碰到右上角(lost_key==3)
  move(7);
  color(1);
  }
  if (x==2&&y==2){//碰到左上角(lost_key==1)
  move(9);
  color(1);
  }
  }
 }
 void move(int o) {
 /*if (lost_key==1){//把这部分代码去掉注释就会自动清理上一个点
 gotoxy(x+1,y+1);
 printf(" ");
 }
 else if (lost_key==3){
 gotoxy(x-1,y+1);
 printf(" ");
 }
 else if (lost_key==7){
 gotoxy(x+1,y-1);
 printf(" ");
 }
 else if (lost_key==9){
 gotoxy(x-1,y-1);
 printf(" ");
 }*/
 gotoxy(x,y);
 //printf("\e[7m ");
 if (high_light==0){
 printf("\e[0m");
 }
 else if (high_light==1){
 printf("\e[1m");
 }
 printf("\e[%dmo\e[0m",cr);
  if (o == 1) {
  if (x > 2 && y > 2) {
  x--;
  y--;
  lost_key=1;
  }
  }
  else if (o == 3) {
  if (x < xx && y > 2) {
  x++;
  y--;
  lost_key=3;
  }
 }
 else if (o == 7) {
  if (x > 2 && y < yy) {
  x--;
  y++;
  lost_key=7;
  }
 }
 else if (o == 9) {
  if (x < xx && y < yy) {
  x++;
  y++;
  lost_key=9;
  }
 }
 gotoxy(1,1);
 printf("\e[7m(%d,%d) \e[0m",x,y);
 usleep(Time);
  fflush(stdout);
 }
 void wk() {
  printf("\e[?25h");
  clrscr();
  printf("\e[7m");
  for (i = 1; i <= xx + 1; i++) {
  gotoxy(i, 1);
  printf(" ");
  }
  for (i = 2; i < yy + 1; i++) {
  gotoxy(1, i);
  printf(" ");
  gotoxy(xx + 1, i);
  printf(" ");
  }
  for (i = 1; i <= xx + 1; i++) {
  gotoxy(i, yy + 1);
  printf(" ");
  }
  printf("\e[0m");
 }
 void color(int c){
 if (c==1){
 cr--;
 if (cr==29){
 cr=37;
 if (high_light==0){
 high_light=1;
 }
 else if (high_light==1){
 high_light=0;
 }
 }
 printf("\e[%dm",cr);
 }
 else if (c==0){
 printf("\e[0m");
 }
 }