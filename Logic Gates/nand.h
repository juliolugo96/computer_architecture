#ifndef NAND_GATE
#define NAND_GATE

SC_MODULE (Nand) {

  sc_in <bool> a;
  sc_in <bool> b;
  sc_out <bool> c;

  void fun () {
    c = !(a && b);
    //Es lo mismo que: c = not (a and b);
  }

  SC_CTOR (Nand) {
    SC_METHOD (fun);
    sensitive << a << b;
  }
};

#endif//NAND_GATE
