#ifndef NOT_GATE
#define NOT_GATE

SC_MODULE (Not) {

  sc_in <bool> a;
  sc_out <bool> c;

  void fun () {
    c = !a;
    //Es lo mismo que: c = not a;
  }

  SC_CTOR (Not) {
    SC_METHOD (fun);
    sensitive << a;
  }
};

#endif//NOT_GATE
