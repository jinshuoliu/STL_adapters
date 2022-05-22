// 集三种iterator adapters
#include <iterator>
#include <deque>
#include <algorithm>
#include <vector>
#include<iostream>
using namespace std;

int main()
{
  // 将outite绑定到cout.每次对outite指派一个元素，就在后面接一个" "
  ostream_iterator<int> outite(cout, " ");

  int ia[] = {0, 1, 2, 3, 4, 5};
  deque<int> id(ia, ia+6);

  // 将所有元素拷贝到outite
  copy(id.begin(), id.end(), outite);
  cout << endl;
  // 输出 0 1 2 3 4 5

  // 将ia[] 部分元素拷贝到id内，使用front_insert_iterator
  // front_insert_iterator也就是push_front操作
  copy(ia+1, ia+2, front_inserter(id));
  copy(id.begin(), id.end(), outite);
  cout << endl;
  // 输出 1 0 1 2 3 4 5

  // 使用back_insert_iterator(也就是push_back)
  copy(ia+3, ia+4, back_inserter(id));
  copy(id.begin(), id.end(), outite);
  cout << endl;
  // 输出 1 0 1 2 3 4 5 3

  // 搜索元素5所在的位置
  deque<int>::iterator ite = find(id.begin(), id.end(), 5);
  // 使用insert_iterator(也就是insert，插入的位置是ite也就是元素5的位置)
  copy(ia+0, ia+3, inserter(id, ite));
  copy(id.begin(), id.end(), outite);
  cout << endl;
  // 输出 1 0 1 2 3 4 0 1 2 5 3

  // 逆转
  copy(id.rbegin(), id.rend(), outite);
  cout << endl;
  // 输出 3 5 2 1 0 4 3 2 1 0 1

  // 将inite绑定到cin，将元素拷贝到inite，直到eos出现
  istream_iterator<int> inite(cin), eos; // eos: end-of-stream
  copy(inite, eos, inserter(id, id.begin()));
  copy(id.begin(), id.end(), outite);

  vector<int> iv(ia, ia+5);
  count_if(iv.begin(), iv.end(), bind2nd(less<int>(), 12));
}