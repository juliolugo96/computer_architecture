#ifndef XNOR_GATE
#define XNOR_GATE

SC_MODULE (Xnor) {

  sc_in <bool> a;
  sc_in <bool> b;
  sc_out <bool> c;

  void fun () {
    c = !(a ^ b);
    //Es lo mismo que: c = !(a xor b);
  }

  SC_CTOR (Xnor) {
    SC_METHOD (fun);
    sensitive << a << b;
  }
};

#endif//XNOR_GATE
