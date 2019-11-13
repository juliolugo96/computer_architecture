#ifndef AND_GATE
#define AND_GATE

SC_MODULE (And) {

  sc_in <bool> a;
  sc_in <bool> b;
  sc_out <bool> c;

  void fun () {
    c = a && b;
    //Es lo mismo que: c = a and b;
  }

  SC_CTOR (And) {
    SC_METHOD (fun);
    sensitive << a << b;
  }
};

#endif//AND_GATE
