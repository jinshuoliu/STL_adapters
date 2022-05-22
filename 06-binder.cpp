// 用来将某个Adaptable Binary function 转换为Unary Function
template <class Operation>
class binder1st : public unary_function<typename Operation::second_argument_type, typename Operation::result_type> {
protected:
  Operation op; // 内部成员
  typename Operation::first_argument_type value; // 内部成员

public:
  // 将它们记录到内部成员中
  bind1st(const Operation& x, const typename Operation::first_argument_type& y) :op(x), value(y) {}

  typename Operation::result_type operator()(const typename Operation::second_argument_type& x) const {
    return op(value, x);
  }
};

// 辅助函数
template <class Operation, class T>
inline binder1st<Operation> bind1st(const Operation& op, const T& x) {
  typedef typename Operation::first_argument_type arg1_type;
  return binder1st<Operation>(op, arg1_type(x)); // 这里要先把x转换型别
}

// 用来将某个Adaptable Binary function 转换为Unary Function
template <class Operation>
class binder2nd : public unary_function<typename Operation::first_argument_type, typename Operation::result_type> {
protected:
  Operation op; // 内部成员
  typename Operation::second_argument_type value; // 内部成员

public:
  // 将它们记录到内部成员中
  bind1st(const Operation& x, const typename Operation::second_argument_type& y) :op(x), value(y) {}

  typename Operation::result_type operator()(const typename Operation::first_argument_type& x) const {
    return op(x, value);
  }
};

// 辅助函数
template <class Operation, class T>
inline binder1st<Operation> bind2nd(const Operation& op, const T& x) {
  typedef typename Operation::second_argument_type arg2_type;
  return binder2nd<Operation>(op, arg2_type(x)); // 这里要先把x转换型别
}