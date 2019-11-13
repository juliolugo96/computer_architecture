#ifndef XOR_GATE
#define XOR_GATE

SC_MODULE (Xor) {

  sc_in <bool> a;
  sc_in <bool> b;
  sc_out <bool> c;

  void fun () {
    c = a ^ b;
    //Es lo mismo que: c = a xor b;
  }

  SC_CTOR (Xor) {
    SC_METHOD (fun);
    sensitive << a << b;
  }
};

#endif//XOR_GATE
