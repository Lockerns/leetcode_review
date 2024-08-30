#include <iostream>
using namespace std;

class Man
{
public:
  Man(){
    cout << "默认构造" << endl;
  }
  Man(string n, int a):name(n),age(a) {
    cout << "初始化列表" << endl;
  }
  Man(const Man& a) {
    cout << "拷贝构造" << endl;
  }
  Man& operator=(const Man& a) {
    name = a.name;
    age = a.age;
    cout << "赋值操作" << endl;
    return *this;
  }
private:
  string  name;
  int   age;
};

class ChineseMan {
public:
  ChineseMan(Man a, string i) {
    man = a;
    id = i;
  }
private:
  string  id;
  Man   man;
};

int main()
{
  // Man vincent("vincent", 26);
  Man vincent = Man("vincent", 26);
  cout << "-----------" << endl;
  ChineseMan vincent_CN(vincent, "001");
  return 0;
}
