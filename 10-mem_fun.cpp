// Adapter function objects: pointers to member functions

// 这个族群总共有8(2^3)个function objects
//  1.无任何参数 vs 有一个参数
//  2.通过pointer调用 vs 通过reference调用
//  3.const成员函数 vs non-const成员函数

// 如果只是使用最上层的辅助函数mem_fun、mem_fun_ref还是很简单的

// 1.无任何参数，通过pointer调用，non-const成员函数
template <class S, class T>
class mem_fun_t : public unary_function<T*, S> {
public:
  explicit mem_fun_t(S (T::*pf)()) : f(pf) {}
  S operator()(T* p) const {
    return (p->*f)();
  }
private:
  S (T::*f)(); // 内部成员，pointer to member function
};

// 2.无任何参数，通过pointer调用，const成员函数
template <class S, class T>
class const_mem_fun_t : public unary_function<const T*, S> {
public:
  explicit const_mem_fun_t(S (T::*pf)() const) : f(pf) {}
  S operator()(const T* p) const {
    return (p->*f)();
  }
private:
  S (T::*f)() const; // 内部成员，pointer to const member function
};

// 3.无任何参数，通过reference调用，non-const成员函数
template <class S, class T>
class mem_fun_ref_t : public unary_function<T, S> {
public:
  explicit mem_fun_ref_t(S (T::*pf)()) : f(pf) {}
  S operator()(T& r) const {
    return (r.*f)();
  }
private:
  S (T::*f)(); // 内部成员，pointer to member function
};

// 4.无任何参数，通过reference调用，const成员函数
template <class S, class T>
class const_mem_fun_ref_t : public unary_function<T, S> {
public:
  explicit const_mem_fun_ref_t(S (T::*pf)() const) : f(pf) {}
  S operator()(const T& r) const {
    return (r.*f)();
  }
private:
  S (T::*f)() const; // 内部成员，pointer to const member function
};

// 5.有一个参数，通过pointer调用，non-const成员函数
template <class S, class T, class A>
class mem_fun1_t : public binary_function<T*, A, S> {
public:
  explicit mem_fun1_t(S (T::*pf)(A)) : f(pf) {}
  S operator()(T* p, A x) const {
    return (p->*f)(x);
  }
private:
  S (T::*f)(A); // 内部成员，pointer to member function
};

// 6.有一个参数，通过pointer调用，const成员函数
template <class S, class T, class A>
class const_mem_fun1_t : public binary_function<const T*, A, S> {
public:
  explicit const_mem_fun1_t(S (T::*pf)(A) const) : f(pf) {}
  S operator()(const T* p, A x) const {
    return (p->*f)(x);
  }
private:
  S (T::*f)(A) const; // 内部成员，pointer to const member function
};

// 7.有一个参数，通过reference调用，non-const成员函数
template <class S, class T, class A>
class mem_fun1_ref_t : public binary_function<T, A, S> {
public:
  explicit mem_fun1_ref_t(S (T::*pf)(A)) : f(pf) {}
  S operator()(T& r, A x) const {
    return (r.*f)(x);
  }
private:
  S (T::*f)(A); // 内部成员，pointer to member function
};

// 8.有一个参数，通过reference调用，const成员函数
template <class S, class T, class A>
class const_mem_fun1_ref_t : public binary_function<const T, A, S> {
public:
  explicit const_mem_fun1_ref_t(S (T::*pf)(A) const) : f(pf) {}
  S operator()(const T& r, A x) const {
    return (r.*f)(x);
  }
private:
  S (T::*f)(A) const; // 内部成员，pointer to const member function
};

// mem_fun adapter的辅助函数：mem_fun,mem_fun_ref
// 无参的四个
template <class S, class T>
inline mem_fun_t<S, T> mem_fun(S (T::*f)()) {
  return mem_fun_t<S, T>(f);
}

template <class S, class T>
inline const_mem_fun_t<S, T> mem_fun(S (T::*f)() const) {
  return const_mem_fun_t<S, T>(f);
}

template <class S, class T>
inline mem_fun_ref_t<S, T> mem_fun_ref(S (T::*f)()) {
  return mem_fun_ref_t<S, T>(f);
}

template <class S, class T>
inline const_mem_fun_ref_t<S, T> mem_fun_ref(S (T::*f)() const) {
  return const_mem_fun_ref_t<S, T>(f);
}
// 有参的四个，它们四个是可以单纯的重载上面四个函数的，但是它选择改名子
template <class S, class T, class A>
inline mem_fun1_t<S, T, A> mem_fu1n(S (T::*f)(A)) {
  return mem_fun1_t<S, T, A>(f);
}

template <class S, class T, class A>
inline const_mem_fun1_t<S, T, A> mem_fun1(S (T::*f)(A) const) {
  return const_mem_fun1_t<S, T, A>(f);
}

template <class S, class T, class A>
inline mem_fun1_ref_t<S, T, A> mem_fun1_ref(S (T::*f)(A)) {
  return mem_fun1_ref_t<S, T, A>(f);
}

template <class S, class T, class A>
inline const_mem_fun1_ref_t<S, T, A> mem_fun1_ref(S (T::*f)(A) const) {
  return const_mem_fun1_ref_t<S, T, A>(f);
}