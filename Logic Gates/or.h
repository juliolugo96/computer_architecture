#ifndef OR_GATE
#define OR_GATE

SC_MODULE (Or) {

  sc_in <bool> a;
  sc_in <bool> b;
  sc_out <bool> c;

  void fun () {
    c = a || b;
    //Es lo mismo que: c = a or b;
  }

  SC_CTOR (Or) {
    SC_METHOD (fun);
    sensitive << a << b;
  }
};

#endif//OR_GATE
