#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

class Point{
private:
    int x,y;
public:
    Point(){
        x=0; y=0;
    }
    Point(int auxX, int auxY){
        x=auxX; y=auxY;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    double getDistanceFromOrigin(){
        return sqrt(x*x+y*y);
    }
    double getDistance(Point point){
        int auxX=point.getX()-x;
        int auxY=point.getY()-y;
        return sqrt(auxX*auxX+auxY*auxY);
    }
};

int main()
{
    cout << "Hello, this code will tell you the distance from point(0,0) to point(12,-3) twice" << endl;
    Point p1=Point();
    Point p2=Point(12,-3);
    cout<<"The distance to the origin is: "<<p2.getDistanceFromOrigin()<<endl;
    cout<<"The distance to point 1 is: "<<p2.getDistance(p1)<<endl;
    getch();
    return 0;
}
