#include<stdio.h>
#include<GL/glut.h>
#include<vector>
#include<math.h>
//#include<windows.h>
#include<iostream>
//#include<conio.h>

void mouse(int button, int state, int mouseX, int mouseY);
void calcular(int posX, int posY);
void desenhar(void);
void init();

using namespace std;

vector<int> x;
vector<int> y;

int main(int argc, char **argv){

    glutInit(&argc, argv); //inicia o glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //um monitor e usando rgb
    glutInitWindowSize(800, 600);   //tamanho da janela
    glutCreateWindow("Atividade 2"); //cria a janela e passa o nome da janela
    init();  //funcao pra iniciar os valores da glut
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

void calcular(int posX, int posY){
	int menor=1000;
	int calc;
	int pos;

	for(int i=0;i<x.size();i++){
		int posX1 = x.at(i);
		int posY1 = y.at(i);

		calc = sqrt(((posX1-posX)*(posX1-posX))+((posY1-posY)*(posY1-posY)));
		if(calc<menor){
			menor=calc;
			pos = i;
		}
	}
	x.erase(x.begin()+pos);
	y.erase(y.begin()+pos);
}

void desenhar(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);//PRETO
	glBegin(GL_LINES);  //inicia o desenho
	for(int a=0;a<x.size();a++){
		if(a>0){
			glVertex2i(x.at(a),y.at(a));  //pontos
			glVertex2i(x.at(a-1),y.at(a-1));
		}
	}
	glEnd();
	glFlush();
}

void init() {  //funcao que inicializa o openGL
	gluOrtho2D(0,800,600,0); //proporcao da tela
}

//Matheus Cezar de Souza