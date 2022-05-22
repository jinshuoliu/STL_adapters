// 已知两个Adaptable Unary Functions f(),g(),以下配接器用来产生一个h()
// 使得h(x) = f(g(x))
template <class Operation1, class Operation2>
class unary_compose : public unary_function<typename Operation2::argument_type, typename Operation1::result_type> {
protected:
  // 内部成员
  Operation1 op1;
  Operation2 op2;

public:
  unary_compose(const Operation1& x, const Operation2& y) : op1(x), op2(y) {}

  template Operation1::result_type operator()(const typename Operation2::argument_type& x) const {
    return op1(op2(x));
  }
};

// 辅助函数
template <class Operation1, class Operation2>
inline unary_compose<Operation1, Operation2> compose1(const Operation1& op1, const Operation2& op2) {
  return unary_compose<Operation1, Operation2>(op1, op2);
}

// 已知一个Adaptable Binary Function f() 和两个Adaptable Unary Functions g1(),g2(),以下配接器用来产生一个h()
// 使得h(x) = f(g1(x), g2(x))
template <class Operation1, class Operation2, class Operation3>
class binary_compose : public binary_function<typename Operation2::argument_type, typename Operation1::result_type> {
protected:
  // 内部成员
  Operation1 op1;
  Operation2 op2;
  Operation3 op3;

public:
  binary_compose(const Operation1& x, const Operation2& y, const Operation3& z) : op1(x), op2(y), op3(z) {}

  template Operation1::result_type operator()(const typename Operation2::argument_type& x) const {
    return op1(op2(x), op3(x));
  }
};

// 辅助函数
template <class Operation1, class Operation2, class Operation3>
inline binary_compose<Operation1, Operation2, Operation3> compose2(const Operation1& op1, const Operation2& op2, const Operation3& op3) {
  return binary_compose<Operation1, Operation2>(op1, op2, op3);
}