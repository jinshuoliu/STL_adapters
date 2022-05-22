// 此配接器用来表示某个Adaptable Predicate的逻辑负值(logical negation)
template <class Predicate>
class unary_negate : public unary_function<typename Predicate::argument_type, bool> {
protected:
  Predicate pred; // 内部成员
public:
  explicit unary_negate(const Predicate& x) : pred(x) {}
  bool operator()(const typename Predicate::argument_type& x) const {
    return !pred(x);
  }
};

// 辅助函数
template <class Predicate>
inline unary_negate<Predicate> not1(const Predicate& pred) {
  return unary_negate<Predicate>(pred);
}

// 它是表示Adaptable Binary Predicate的逻辑负值
template <class Predicate>
class binary_negate : public binary_function<typename Predicate::first_argument_type, typename Predicate::second_argument_type, bool> {
protected:
  Predicate pred; // 内部成员
public:
  explicit binary_negate(const Predicate& x) : pred(x) {}
  bool operator()(const typename Predicate::first_argument_type& x, const typename Predicate::second_argument_type& y) const {
    return !pred(x, y);
  }
};

// 辅助函数
template <class Predicate>
inline binary_negate<Predicate> not2(const Predicate& pred) {
  return binary_negate<Predicate>(pred);
}