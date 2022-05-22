#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Shape {
public:
  virtual void display()=0;
};

class Rect : public Shape {
public:
  virtual void display(){
    cout << "Rect";
  }
};

class Circle : public Shape {
public:
  virtual void display(){
    cout << "Circle";
  }
};

class Square : public Shape {
public:
  virtual void display(){
    cout << "Square";
  }
};

int main() {
  vector<Shape*> V;
  // 因为STL容器只支持“实值语意”不支持“引用语意”
  // 所以 vector<Shape&> V; 无法通过编译

  V.push_back(new Rect);
  V.push_back(new Circle);
  V.push_back(new Square);
  V.push_back(new Circle);
  V.push_back(new Rect);

  for(int i=0;i<V.size(); ++i)
    (V[i])->display();
  cout << endl;
  // Rect Circle Square Circle Rect

  for_each(V.begin(), V.end(), mem_fun(&Shape::display));
  cout << endl;
  // Rect Circle Square Circle Rect
}