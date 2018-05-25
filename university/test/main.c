#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#pragma warning(disable : 4996)

struct dani {
 double v0;
 double r;
 double R;
};
//Функція знаходження k
double k_1(double t, double T, double k0, double c) {
 double k_1;
 if ((t >= 0) && t <= (T / 8)) {
  k_1 = k0 * (1 + exp((-(c)) * t));
 }
 else if ((t > (T / 8)) && (t <= T)) {
  k_1 = k0 * (1 + exp(c*(T / 8)));
 }
 return k_1;
}
//Функція знаходження e
double e_1(double t, double T, double k, double e0) {
 double e_1;
 if ((t >= 0) && (t <= (T / 4))) {
  e_1 = e0 * (1 - exp((-(k)) * t));
 }
 else if ((t > T / 4) && (t <= T)) {
  e_1 = e0 * (1 - exp((-(k))*(T /4)));
 }
 return e_1;
}
//Функція знаходження v
double v_1(double t, double T, double r, double v0) {
 double v_1;
 if ((t >= 0) && (t <= (T / 2))) {
  v_1 = v0 * (1 + exp((r)*t));
 }
 else if ((t > (T / 2)) && (t <= T)) {
  v_1 = v0 * (1 + exp((-(r))*(T / 2)));
 }
 return v_1;
}
int main()
{
 double T, dt, k0, e0, c, k = 0, e = 0, v = 0, H = 0, sin_a, t;
 int i = 0;
 FILE *p1, *p2;
 struct dani mas[3];
 //Відкриваємо файл для зчитування даних
 p1 = fopen("vvod.txt", "r");
 //Перевіряємо на наявність файлу з даними
 if (p1 == 0) {
  puts("File is not found!\n");
  exit(1);
 }
 else puts("File is found!\n ");
 //Відкриваємо файл для запису в нього результатів
 p2 = fopen("result.txt", "w");
 //Перевіряємо чи створений файл та чи занесений в папку з програмою
 if (p2 == 0) {
  puts("File not created!\n");
  exit(1);
 }
 //Зчитуємо дані з файлу
 fscanf(p1, "%lf%lf%lf", &k0, &e0, &c);
 //Вводимо з клавіатури значення T, dt та sin a
 printf("Write T, dt and sin a: \n");
 scanf("%lf%lf%lf", &T, &dt, &sin_a);
 for (i = 0; i < 3; i++) {
  //Зчитуємо дані з файлу та заносимо їх в структуру
  fscanf(p1, "%lf", &mas[i].v0);
  printf("mas[i]: %lf\n", mas[i].v0);
  fscanf(p1, "%lf", &mas[i].r);
  fscanf(p1, "%lf", &mas[i].R);
 }
 for (i = 0; i < 3; i++) {
  fprintf(p2, "Result of %i structure!\n", i + 1);
  for (t = 0; t <= T; t += dt) {
   k = k_1(t, T, k0, c);
   //Знаходимо заряд частинки
   e = e_1(t, T, k, e0);
   //Знаходимо швидкіть руху частинки
   v = v_1(t, T, mas[i].r, mas[i].v0);
   //Перевіряємо чи радіус більший 0
   if (mas[i].R > 0) {
    //Знаходимо напруженість
    H = (e*v*sin_a) / pow(mas[i].R, 2);
    //Заносимо дані про потужність для кожного з трьох випадків в файл
    fprintf(p2, "%lf\n", H);
   }
   else puts("R can not be negative");
  }
  fprintf(p2, "\n");
 }
 puts("Results in file!");
 //Закриваємо файли
 fclose(p1);
 fclose(p2);
 return 0;
}