// 这个就是包装一下一元函数指针
template <class Arg, class Result>
class pointer_to_unary_function : public unary_function<Arg, Result> {
protected:
  // 函数指针
  Result (*ptr)(Arg);
public:
  pointer_to_unary_function() {}

  explicit pointer_to_unary_function(Result (*x)(Arg)) : ptr(x) {}

  // 通过函数指针执行函数
  Result operator()(Arg x) const {
    return ptr(x);
  }
};

// 辅助函数
template <class Arg, class Result>
inline pointer_to_unary_function<Arg, Result> ptr_fun(Result (*x)(Arg)) {
  return pointer_to_unary_function<Arg, Result>(x);
}


// 这个就是包装一下二元函数指针
template <class Arg1, class Arg2, class Result>
class pointer_to_binary_function : public binary_function<Arg1, Arg2, Result> {
protected:
  // 函数指针
  Result (*ptr)(Arg1, Arg2);
public:
  pointer_to_binary_function() {}

  explicit pointer_to_binary_function(Result (*x)(Arg1, Arg2)) : ptr(x) {}

  // 通过函数指针执行函数
  Result operator()(Arg1 x, Arg2 y) const {
    return ptr(x, y);
  }
};

// 辅助函数
template <class Arg1, class Arg2, class Result>
inline pointer_to_binary_function<Arg1, Arg2, Result> ptr_fun(Result (*x)(Arg1, Arg2)) {
  return pointer_to_binary_function<Arg1, Arg2, Result>(x);
}