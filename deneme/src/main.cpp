#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <GL/glut.h>
#include <vector>
#include<Windows.h>
#define GLUT_DISABLE_ATEXIT_HACK 
double PI = 3.14159265358979;

//	 COMPUTER GRAPHICS FINAL PROJE ÖDEVI
//	 HAZIRLAYAN : HAKKI EGEMEN GÜLPINAR (17-155-014)
//	             Bilgisayar Mühendisliði 3.Sýnýf

//			PROJEDE UÇGEN-DÖRTGEN-2D DAIRE-3D KÜP(her yüzeyi farklý renk) modelleri bulunmaktadýr.

void init(void);  // ayarlari init ettiðimiz fonksiyon
void display(void); // tüm çizim iþlemlerinin bulunduðu fonksiyon

int i = 0;
float kup[8][3] =
{
	{-0.5,-0.5,0.5},
	{-0.5,0.5,0.5},
	{0.5,0.5,0.5},
	{0.5,-0.5,0.5},
	{-0.5,-0.5,-0.5},
	{-0.5,0.5,-0.5},
	{0.5,0.5,-0.5},
	{0.5,-0.5,-0.5},
};

GLfloat color[8][3] =
{
	{0.5,0.0,0.5},
	{0.5,0.0,0.0},
	{0.5,0.5,0.0},
	{0.0,0.5,0.0},
	{0.0,0.0,0.5},
	{0.5,0.5,0.5},
	{0.0,0.5,0.5},
};


void init() {
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 50, 0, 50, 0, 10);

}

void quad(int a, int b, int c, int d,int e) //sondaki deðer (yani"e" oluyor),küpün yüzüne  hangi rengi vermek istediðimi  seçebilmek için vermiþ olduðum bir index.
{
	glBegin(GL_QUADS);
		glColor3fv(color[e]);
		glVertex3fv(kup[a]);

		glColor3fv(color[e]);
		glVertex3fv(kup[b]);

		glColor3fv(color[e]);
		glVertex3fv(kup[c]);

		glColor3fv(color[e]);
		glVertex3fv(kup[d]);
   
	glEnd();
	
}

void colorcube()
{
   
	quad(0, 3, 2, 1,0); 
	
	quad(2, 3, 7, 6,1);   
   
	quad(0, 4, 7, 3,2);
	
	quad(1, 2, 6, 5,3);
	
	quad(4, 5, 6, 7,4);
	quad(0, 1, 5, 4,5);
}

double rotate_y = 0;
double rotate_x = 0;
void specialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_RIGHT)// OK TUÞLARI ÝLE OBJEYÝ  HAREKET ETTÝRME
		rotate_y += 5;
	else if (key == GLUT_KEY_LEFT)// OK TUÞLARI ÝLE OBJEYÝ  HAREKET ETTÝRME
		rotate_y -= 5;
	else if (key == GLUT_KEY_UP)// OK TUÞLARI ÝLE OBJEYÝ  HAREKET ETTÝRME
		rotate_x += 5;
	else if (key == GLUT_KEY_DOWN)   // OK TUÞLARI ÝLE OBJEYÝ  HAREKET ETTÝRME
		rotate_x -= 5;
	glutPostRedisplay();
}

void kupCiz() {
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	colorcube();
}




void ucgenCiz() {
	glPointSize(10.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0, 0);
		glVertex2f(2.5f, 0.0f);
		glColor3f(0, 1.0f, 0);
		glVertex2f(2.0f, -1.0f);
		glColor3f(0, 0, 1.0f);
		glVertex2f(1.5f, -0.5f);
	glEnd();
}


void dikdortgenCiz() {


	glColor3ub(122, 0, 0);
	glLineWidth(99); // çizgi kalýnlýðý
	glBegin(GL_LINES);
	glVertex2f(1.15, 1);
	glVertex2f(1.35, -0.9);
	glEnd();
	glFlush();
}


void yuvarlakCiz() {
	

	glColor3f(0, 0.50, 100);// R,G,B
	glPointSize(4.0f); // nokta boyutu
	glBegin(GL_POINTS);
	float i, r = 0.5;

	for (i = -1.0; i <= 1.0; i += 0.0001) {
		glVertex2f((cos(i * PI) * 2 * r) -1.75 , (sin(i * PI) * 2 * r) -1.75);

	}
	glEnd();
	glFlush();

}
void display()
{

	//                                                      GÝRÝÞ EKRANI AÇILIÞ YAZISI VE OK TUÞLARI HAREKET ETME BÝLGÝSÝNÝN OLDUÐU KISIM
	//        ******/////////
   glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(14, 25);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'P');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(15, 25);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'R');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(16, 25);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(17, 25);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'S');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(18, 25);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'S');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(20, 25);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(21, 25);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(22, 25);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Y');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(24, 25);
	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'K');
	//glColor3f(1.0, 0.1, 0.0);
	
	
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'K');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(25, 25);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(26, 25);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Y');
	glColor3f(1.0, 0.1, 0.0);
	glRasterPos2i(27, 25);
	


	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2i(14, 20);
	glColor3f(1.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'T');
	glRasterPos2i(15, 20);
	glColor3f(1.0, 0.1, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
	glRasterPos2i(17, 20);
	glColor3f(1.0, 0.1, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
	glRasterPos2i(18, 20);
	glColor3f(1.0, 0.1, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glRasterPos2i(19, 20);
	glColor3f(1.0, 0.1, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
	glRasterPos2i(20, 20);
	glColor3f(1.0, 0.1, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'T');
	glRasterPos2i(21, 20);
	glColor3f(1.0, 0.1, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glRasterPos2i(22, 20);
	glColor3f(1.0, 0.1, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'R');
	glRasterPos2i(23, 20);




	 
	//        ******/////////
	glLoadIdentity();
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);
	gluPerspective(20, w / h, 0.1, 100);  //görüntünün oluþabilmesi için gerekli.3D objelerin perspektif ayarý
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);

	gluLookAt  //bu kýsým küp'ün ekranda yer alacak konumunu belirliyor.
	(
		7 ,7, 7,
		0, 0, 0,
		1, 0, 1
	);

	




	// sýrayla çizilecek þekilleri glBegin ve glEnd arasýnda sýrayla çizdir
	kupCiz();
	ucgenCiz();
	yuvarlakCiz();
	dikdortgenCiz();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(1366, 768);
	glutCreateWindow("Computer Graphics Final Projesi 17-155-014 H.Egemen Gulpinar");
   
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glEnable(GL_DEPTH_TEST);
	//init(); //giriþ ekraný bilgilendirme yazýsý fonksiyonu
	glutMainLoop();
	return 0;

}


