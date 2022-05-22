template <class Iterator>
class reverse_iterator {
protected:
  Iterator current; // 记录对应的正向迭代器
public:
  typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
  typedef typename iterator_traits<Iterator>::value_type value_type;
  typedef typename iterator_traits<Iterator>::difference_type difference_type;
  typedef typename iterator_traits<Iterator>::pointer pointer;
  typedef typename iterator_traits<Iterator>::reference reference;

  typedef Iterator iterator_type; // 正向迭代器
  typedef reverse_iterator<Iterator> self; // 逆向迭代器

public:
  reverse_iterator() {}

  explicit reverse_iterator(iterator_type x) : current(x) {}
  reverse_iterator(const self& x) : current(x.current) {}

  // 取出正向迭代器
  iterator_type base() const {
    return current;
  }

  // 对逆向迭代器取值，就是将对应的正向迭代器后退一格然后取值
  reference operator*() const {
    Iterator tmp current;
    return *--tmp;
  }

  pointer operator->() const {
    return *(operator*());
  }

  self& operator++(){
    --current;
    return *this;
  }
  self operator++(int) {
    self tmp = *this;
    --current;
    return tmp;
  }
  self& operator--(){
    ++current;
    return *this;
  }
  self operator--(int) {
    self tmp = *this;
    ++current;
    return tmp;
  }

  self operator+(difference_type n) const {
    return self(current-n);
  }

  self& operator+=(difference_type n) {
    current -= n;
    return *this;
  }

  self operator-(difference_type n) const {
    return self(current+n);
  }

  self& operator-=(difference_type n) {
    current += n;
    return *this;
  }

  reference operator[](difference_type n) const {
    return *(*this + n) ;
  }

};