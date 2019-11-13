#ifndef BUFFER_GATE
#define BUFFER_GATE

SC_MODULE (Buffer) {

  sc_in <bool> a;
  sc_out <bool> c;

  void fun () {
    c = a;
  }

  SC_CTOR (Buffer) {
    SC_METHOD (fun);
    sensitive << a;
  }
};

#endif//BUFFER_GATE
