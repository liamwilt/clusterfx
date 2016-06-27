#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define M_PI 3.141592653
#define GLFW_HAND_CURSOR   0x00036004
#define SIDE_NUM    36      // numnber of triangles we use to draw a circle
#define DISTANCE    5       // max length of a movement 
#define TOTAL_TIME  5       // 5 minutes per trial 

struct Circle {
    GLfloat x;              // center points
    GLfloat y;
    GLfloat z;
    GLfloat radius;         // circle radius
    GLint numberOfSides;    // number of side
    GLfloat xVector;        // horizontal vecotr
    GLfloat yVector;        // vertical vector
    GLfloat colour[3];      // color of the circle
};

typedef struct Circle Circle;

int chosenCircleIndex = 0;
Circle * currentCircle = NULL;
GLFWwindow *window;
GLFWcursor *cursor;
FILE * globalOut;

void drawCircle(Circle circle);

static void key_callback(GLFWwindow *w, int key, int scancode, int action, int mods);

Circle initCircle(Circle circle);
/**
 * initialize a circle 
 * @param circle
 * @return an initialized circle 
 */

void initCircleArray(Circle circle[], int length);
/**
 * initialize array of circles 
 * @param circle array
 * @param length length of the array
 */

int testCollision(Circle c1, Circle c2);
/**
 * @param c1 circle 
 * @param c2 circle
 * @return 0 if they don't collide with each other 
 *          1 if they collide
 */

void moves(Circle circle[], int length, int index);
/**
 * move each circle in the array 
 * @param circle array
 * @param length length of array
 * @param index index of current considered circle
 */

static void error(int error, const char *desc);

void writeData(FILE * out, GLfloat oX, GLfloat oY, GLfloat radius,
        GLfloat cX, GLfloat cY, double timer,
        GLfloat distance);
/* 
 * out      --> output stream
 * oX       --> center of the circle X
 * oY       --> center of the circle Y
 * radius   --> radius of the circle 
 * cX       --> cursor position   
 * cY       --> cursor position      
 * timer    --> current time
 * distance --> distance from cursor to center of the circle 
 */

int isCursorInTheChosenCircle();
/**
 * 
 * @return 1 the cursor is in the chosen circle
 *          0 the cursor is out of the chosen circle 
 */


void writeToFile(FILE * out, Circle circle, double timer, GLFWwindow *window);

void mouse_button_callback(GLFWwindow* window,
        int button, int action, int mods);

void playSound();
