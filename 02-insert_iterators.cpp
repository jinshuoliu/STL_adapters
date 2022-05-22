/* back_insert(也就是push_back) */
template <class Container>
class back_insert_iterator {
protected:
  Container* container; // 底层容器
public:
  typedef output_iterator_tag iterator_category;
  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;

  // 此cotr使对象与容器绑定
  explicit back_insert_iterator(Container& x) : container(&x) {}

  back_insert_iterator<Container>& operator=(const typename Container::value_type& value) {
    container->push_back(value); // 这就表明了它是push_back
    return *this;
  }

  // 下面三个操作符貌似没用
  back_insert_iterator<Container>& operator*() {
    return *this;
  }
  back_insert_iterator<Container>& operator++() {
    return *this;
  }
  back_insert_iterator<Container>& operator++(int) {
    return *this;
  }
};

// 辅助函数，调用back_insert_iterator
template <class Container>
inline back_insert_iterator<Container> back_inserter(Container& x) {
  return back_insert_iterator<Container>(x);
}


/* front_insert(也就是push_front) */
template <class Container>
class front_insert_iterator {
protected:
  Container* container; // 底层容器
public:
  typedef output_iterator_tag iterator_category;
  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;

  // 此cotr使对象与容器绑定
  explicit front_insert_iterator(Container& x) : container(&x) {}

  front_insert_iterator<Container>& operator=(const typename Container::value_type& value) {
    container->push_front(value); // 这就表明了它是push_front
    return *this;
  }

  // 下面三个操作符貌似没用
  front_insert_iterator<Container>& operator*() {
    return *this;
  }
  front_insert_iterator<Container>& operator++() {
    return *this;
  }
  front_insert_iterator<Container>& operator++(int) {
    return *this;
  }
};

// 辅助函数，调用front_insert_iterator
template <class Container>
inline front_insert_iterator<Container> front_inserter(Container& x) {
  return front_insert_iterator<Container>(x);
}


/* insert */
template <class Container>
class insert_iterator {
protected:
  Container* container; // 底层容器
  typename Container::iterator iter;
public:
  typedef output_iterator_tag iterator_category;
  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;

  // 此cotr使对象与容器绑定
  explicit insert_iterator(Container& x, typename Container::iterator i) : container(&x), iter(i) {}

  insert_iterator<Container>& operator=(const typename Container::value_type& value) {
    iter = container->insert(iter, value); // 这就表明了它是insert
    ++iter;
    return *this;
  }

  // 下面三个操作符貌似没用
  insert_iterator<Container>& operator*() {
    return *this;
  }
  insert_iterator<Container>& operator++() {
    return *this;
  }
  insert_iterator<Container>& operator++(int) {
    return *this;
  }
};

// 辅助函数，调用insert_iterator
template <class Container, class Iterator>
inline insert_iterator<Container> inserter(Container& x, Iterator i) {
  typedef typename Container::iterator iter;
  return insert_iterator<Container>(x, iter(i));
}