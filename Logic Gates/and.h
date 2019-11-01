#ifndef AND_GATE
#define AND_GATE

SC_MODULE (And) {

  sc_in <bool> a;
  sc_in <bool> b;
  sc_out <bool> c;

  void fun () {
    c.write ( a.read() & b.read() );
  }

  SC_CTOR (And) {
    SC_METHOD (fun);
    sensitive << a << b;
  }
};

#endif//AND_GATE
