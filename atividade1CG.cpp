#include <stdio.h>
#include <GL/glut.h>

int width = 700;
int height = 700;
/*
void reshape(int w, int h) {
	width=w;
	height=h;
	gluOrtho2D(-3.5,3.5,-3.5,3.5);
}
*/

void init() {  //funcao que inicializa o openGL
	glMatrixMode(GL_PROJECTION);  //pra nao bugar os pixel
	glLoadIdentity();  //da load na matrixmode
	gluOrtho2D(-10,10,-10,10); //proporcao da tela
	glPointSize(35.0);  //seta o tamanho da tela, fala o tamanho da camera
}

void desenhar(void){
    glClear(GL_COLOR_BUFFER_BIT);  //cor padrao do fundo
    glBegin(GL_POINTS);  //inicia o desenho
    glColor3f(0, 0, 0);//PRETO
    glVertex2i(-2,8);  //pontos
    glVertex2i(-1,8);
    glVertex2i(0,8);
    glVertex2i(1,8);
    glVertex2i(2,8);
    glVertex2i(3,8);
    glVertex2i(3,7);
    glVertex2i(4,7);
    glVertex2i(5,7);
    glVertex2i(-2,7);
    glVertex2i(-3,7);
    glVertex2i(-4,7);
    glVertex2i(-4,6);
    glVertex2i(-5,6);
    glVertex2i(5,6);
    glVertex2i(6,6);
    glVertex2i(6,5);
    glVertex2i(6,4);
    glVertex2i(-5,5);
    glVertex2i(-5,4);
    glVertex2i(-6,4);
    glVertex2i(-6,3);
    glVertex2i(-6,-4);
    glVertex2i(-6,-5);
    glVertex2i(-6,-6);
    glVertex2i(-5,-4);
    glVertex2i(-5,-5);
    glVertex2i(-5,-6);
    glVertex2i(-5,-7);
    glVertex2i(-5,-8);
    glVertex2i(-4,-8);
    glVertex2i(-4,-4);
    glVertex2i(5,-4);
    glVertex2i(5,-8);
    glVertex2i(5,-4);
    glVertex2i(6,-4);
    glVertex2i(6,-5);
    glVertex2i(6,-6);
    glVertex2i(6,-7);
    glVertex2i(6,-8);
    glVertex2i(7,-4);
    glVertex2i(7,-5);
    glVertex2i(7,-6);
    glVertex2i(7,4);
    glVertex2i(7,3);
    glVertex2i(-1,-4);
    glVertex2i(-1,-5);
    glVertex2i(2,-4);
    glVertex2i(2,-5);

    for(int a=-4;a<4;a++){
    	glVertex2i(8,a);
    	glVertex2i(-7,a);
    }

    for(int l=-4;l<6;l++){
    	glVertex2i(l,-9);
    	glVertex2i(l,-3);
    }

//////////////////////////////////////////////////////////////////////////////////////////

glColor3f(1.0, 0.0, 0.0);//VERMELHO
    glVertex2i(-1,7);
    glVertex2i(-1,6);
    glVertex2i(-2,5);
    glVertex2i(-2,6);
    glVertex2i(-3,6);
    glVertex2i(-3,5);

    glVertex2i(2,7);
    glVertex2i(2,6);
    glVertex2i(3,5);
    glVertex2i(3,6);
    glVertex2i(4,6);
    glVertex2i(4,5);

    glVertex2i(-5,-1);
    glVertex2i(6,-1);

    for(int a=0;a<4;a++){
    	glVertex2i(-5,a);
    	glVertex2i(-4,a);
    	glVertex2i(5,a);
    	glVertex2i(6,a);
    }

    for(int a=-1;a<3;a++){
    	glVertex2i(-6,a);
    	glVertex2i(7,a);
    }

    for(int a=-2;a<3;a++){
    	for(int l=-1;l<3;l++){
    		glVertex2i(l,a);
    	}
    }

    for(int a=-1;a<2;a++){
    	glVertex2i(-2,a);
    	glVertex2i(3,a);
    }

glEnd(); //acaba o desenho
glFlush(); //garante que tudo sera relizado
}

int main(int argc, char **argv){

    glutInit(&argc, argv); //inicia o glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //um monitor e usando rgb
    glutInitWindowSize(width, height);   //tamanho da janela
    glutCreateWindow("Toad Mario"); //cria a janela e passa o nome da janela
    init();  //funcao pra iniciar os valores da glut
    glutDisplayFunc(desenhar);  //funcao pra desenhar
    //glutReshapeFunc(reshape);
    glClearColor(1.0, 1.0, 1.0, 0.0);   //cor do fundo
    glutMainLoop();  //loop do glut que chama o loop do display func
}

//Matheus Cezar de Souza
