#include <glut.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>

//===================================================================
//  Расчетно-графическая работа по информатике
//  Задание #2
//  Группа АБ-021 Шуваев В.А.
//===================================================================

// ----------------------------------------------------------
// Объявление функций
// ----------------------------------------------------------
void display();
void specialKeys(int key, int x, int y);

// ----------------------------------------------------------
// Голбальные переменные
// ----------------------------------------------------------
double rotate_y = 0;
double rotate_x = 0;

// ----------------------------------------------------------
// Вызов дисплея
// ----------------------------------------------------------
void display() {
  //  Задание цвета фона
  glClearColor(0.13, 0, 0.38, 1);

  //  Очистка экрана и буфера
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //  Очистка матрицы
  glLoadIdentity();

  //  Изменение положения в пространстве
  glRotatef(rotate_x, 1.0, 0.0, 0.0);
  glRotatef(rotate_y, 0.0, 1.0, 0.0);

  //  Перед верх
  glBegin(GL_POLYGON);
  glColor3f(0.25, 0.25, 0.25);
  glVertex3f(0.25, 0, -0.25);
  glVertex3f(0, 0.5, 0);
  glVertex3f(-0.25, 0, -0.25);
  glEnd();

  //  Задняя часть верх
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.5, 0);
  glVertex3f(0.25, 0, 0.25);
  glVertex3f(0, 0.5, 0);
  glVertex3f(-0.25, 0, 0.25);
  glEnd();

  //  Правая сторона верх
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 1.0);
  glVertex3f(0.25, 0, -0.25);
  glVertex3f(0, 0.5, 0);
  glVertex3f(0.25, 0, 0.25);
  glEnd();

  //  Левая сторона верх
  glBegin(GL_POLYGON);
  glColor3f(0.0, 0.65, 1);
  glVertex3f(-0.25, 0, 0.25);
  glVertex3f(0, 0.5, 0);
  glVertex3f(-0.25, 0, -0.25);
  glEnd();

  //  Перед низ
  glBegin(GL_POLYGON);
  glColor3f(0.65, 1, 0);
  glVertex3f(0.25, 0, -0.25);
  glVertex3f(0, -0.5, 0);
  glVertex3f(-0.25, 0, -0.25);
  glEnd();

  //  Задняя часть низ
  glBegin(GL_POLYGON);
  glColor3f(0.55, 0, 1.0);
  glVertex3f(0.25, 0, 0.25);
  glVertex3f(0, -0.5, 0);
  glVertex3f(-0.25, 0, 0.25);
  glEnd();

  //  Правая сторона низ
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.68);
  glVertex3f(0.25, 0, -0.25);
  glVertex3f(0, -0.5, 0);
  glVertex3f(0.25, 0, 0.25);
  glEnd();

  //  Левая сторона низ
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 0.82);
  glVertex3f(-0.25, 0, 0.25);
  glVertex3f(0, -0.5, 0);
  glVertex3f(-0.25, 0, -0.25);
  glEnd();

  //  Очистка буферов
  glFlush();
  glutSwapBuffers();
}

// ----------------------------------------------------------
//  Вызов функции для работы с клавиатурой
// ----------------------------------------------------------
void specialKeys(int key, int x, int y) {
  switch (key) {
    //  Клавиша "Right" - повернуть на 1 градусов вправо
    case GLUT_KEY_RIGHT:
      rotate_y += 1;
      break;
    //  Клавиша "Left" - повернуть на 1 градусов влево
    case GLUT_KEY_LEFT:
      rotate_y -= 1;
      break;
    //  Клавиша "Up" - повернуть на 1 градусов вверх
    case GLUT_KEY_UP:
      rotate_x += 1;
      break;
    //  Клавиша "Down" - повернуть на 1 градусов вниз
    case GLUT_KEY_DOWN:
      rotate_x -= 1;
      break;
  }

  //  обновление активного окна
  glutPostRedisplay();
}

// ----------------------------------------------------------
//  Вызов функции для работы с мышью
// ----------------------------------------------------------
void mouse(int button, int state, int x, int y) {
  switch (button) {
    //  Левая кнопка мыши - поворот по диагонали влево вверх на 5 градусов
    case GLUT_LEFT_BUTTON:
      rotate_x -= 5;
      rotate_y -= 5;
      break;
    //  Правая кнопка мыши - поворот по диагонали вправо вверх на 5 градусов
    case GLUT_RIGHT_BUTTON:
      rotate_x -= 5;
      rotate_y += 5;
      break;
  }

  //  Обновление активного окна
  glutPostRedisplay();
}

int main(int argc, char* argv[]) {
  //  Инициализация GlUT
  glutInit(&argc, argv);

  //  Инициализация буферов обмена и координаты Z
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  //  Задание размера вызываемого окна
  glutInitWindowSize(700, 700);

  //  Вызов окна с графическим интерфейсом
  glutCreateWindow("Октаэдр");

  //  Инициализация функции теста
  glEnable(GL_DEPTH_TEST);

  //  Вызов дисплея и управления клавишами клавиатуры и мыши
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
  glutMouseFunc(mouse);

  //  Зацикливание показа кадров
  glutMainLoop();

  //  Выход из программы
  return 0;
}

