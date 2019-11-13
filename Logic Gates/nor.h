#ifndef Nor_GATE
#define Nor_GATE

SC_MODULE (Nor) {

  sc_in <bool> a;
  sc_in <bool> b;
  sc_out <bool> c;

  void fun () {
    c = !(a || b);
    //Es lo mismo que: c = not (a or b);
  }

  SC_CTOR (Nor) {
    SC_METHOD (fun);
    sensitive << a << b;
  }
};

#endif//Nor_GATE
