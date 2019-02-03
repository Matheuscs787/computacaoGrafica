#include<stdio.h>
#include<GL/glut.h>
#include<vector>
#include<math.h>
//#include<windows.h>
#include<iostream>
//#include<conio.h>

void mouse(int button, int state, int mouseX, int mouseY);
void teclado(unsigned char key, int mouseX, int mouseY);
void calcular(int posX, int posY);
void desenhar(void);
void init();

using namespace std;

vector<int> x;
vector<int> y;

int width = 800;   //largura
int height = 600;   //altura
int pos;

int main(int argc, char **argv){

    glutInit(&argc, argv); //inicia o glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //um monitor e usando rgb
    glutInitWindowSize(width, height);   //tamanho da janela
    glutCreateWindow("Atividade 2"); //cria a janela e passa o nome da janela
    init();  //funcao pra iniciar os valores da glut
    glutKeyboardFunc(teclado);
    glutMouseFunc(mouse);
    glutDisplayFunc(desenhar); //funcao pra desenhar
    glClearColor(1.0, 1.0, 1.0, 0.0);   //cor do fundo
    glutMainLoop();  //loop do glut que chama o loop do display func
}

void mouse(int button, int state, int mouseX, int mouseY){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		x.push_back(mouseX);
		y.push_back(mouseY);
	}
	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		calcular(mouseX, mouseY);
	}
}

void teclado(unsigned char key, int mouseX, int mouseY){

	switch(key){
		case 'w':
				y.at(pos)-=1;
				break;
		case 'd':
			x.at(pos)+=1;
				break;
		case 's':
			y.at(pos)+=1;
			break;
		case 'a':
			x.at(pos)-=1;
			break;
	}
	desenhar();
}

void calcular(int posX, int posY){
	int menor=1000;
	int calc;

	for(int i=0;i<x.size();i++){
		int posX1 = x.at(i);
		int posY1 = y.at(i);

		calc = sqrt(((posX1-posX)*(posX1-posX))+((posY1-posY)*(posY1-posY)));
		if(calc<menor){
			menor=calc;
			pos = i;
		}
	}
}

void desenhar(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);//PRETO
	glBegin(GL_POINTS);  //inicia o desenho
	for(int a=0;a<x.size();a++){
		if(a>-1){
			glVertex2i(x.at(a),y.at(a));  //pontos
		}
	}
	glEnd();
	glFlush();
}

void init() {  //funcao que inicializa o openGL
	gluOrtho2D(0,width,height,0); //proporcao da tela
	glPointSize(35);
}

//Matheus Cezar de Souza
