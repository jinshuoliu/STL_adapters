/* istream iterator */
template <class T, class Distance = ptrdiff_t>
class istream_iterator {
  friend bool operator==__STL_NULL_TMPL_ARGS (const _istream_iterator<T, Distance>& x, const istream_iterator<T, Distance>& y);
protected:
  istream* stream;
  T value;
  bool end_marker;
  void read() {
    end_marker = (*stream) ? true : false;
    if(end_marker)
      *stream>>value;
    // 输入之后stream的状态可能会改变，所以再判断一次来决定end_marker
    // 当读到eof或者别的型号不符的资料，stream处于false状态
    end_marker = (*stream) ? true : false;
  }

public:
  typedef input_iterator_tag iterator_category;
  typedef T value_type;
  typedef Distance difference_type;
  typedef const T* pointer;
  typedef const T& reference;

  istream_iterator() : stream(&cin), end_marker(false) {}
  // 调用它之后，程序会进入read()，read会等待用户输入
  // 如果用户没有输入，他就会等待，这样是一种不好的行为
  // 所以使用它的时候一定要仔细考虑
  istream_iterator(istream& s) : stream(&s) {
    read();
  }

  reference operator*() const {
    return value;
  }
  pointer operator->() const {
    return &(operator*());
  }

  // 迭代器向前进一个位置，代表要取一个数据
  istream_iterator<T, Distance>& operator++() {
    read();
    return *this;
  }
  istream_iterator<T, Distance> operator++(int) {
    istream_iterator<T, Distance> tmp = *this;
    read();
    return tmp;
  }
};


/* ostream iterator */
template <class T>
class ostream_iterator {
protected:
  ostream* stream;
  const char* string;

  void read() {
    end_marker = (*stream) ? true : false;
    if(end_marker)
      *stream>>value;
    // 输入之后stream的状态可能会改变，所以再判断一次来决定end_marker
    // 当读到eof或者别的型号不符的资料，stream处于false状态
    end_marker = (*stream) ? true : false;
  }

public:
  typedef output_iterator_tag iterator_category;
  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;

  ostream_iterator(ostream& s) : stream(&s), string(0) {}
  ostream_iterator(ostream& s, const char* c) : stream(&s), string(c) {}

  // 对迭代器做赋值操作，就是要输出一个数据
  ostream_iterator<T>& operator=(const T& value) {
    *stream << value; // 输出数值
    if(string)
      *stream << string; // 输出空格作为间隔符号
    return *this;
  }


  ostream_iterator<T>& operator*() {
    return *this;
  }
  ostream_iterator<T>& operator++() {
    return *this;
  }
  ostream_iterator<T>& operator++(int) {
    return *this;
  }
};