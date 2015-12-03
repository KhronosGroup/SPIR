// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -fsyntax-only -verify %s

global pipe int GlobalPipe;            // expected-error {{pipes can be used only as function parameters}}
global reserve_id_t GlobalID;          // expected-error {{the '__global reserve_id_t' type cannot be used to declare a program scope variable}}

void test1() {
  pipe int p1;                         // expected-error {{pipes can be used only as function parameters}}
}

extern pipe write_only int get_pipe(); // expected-error {{pipes can be used only as function parameters}}

void test2(read_write pipe int p) {    // expected-error {{read_write access qualifier can't be specified for pipes}}
}

void test3(read_only write_only pipe int p) { // expected-error {{multiple access qualifiers}}
}

void test4(read_only pipe int p1, write_only pipe int p2) {

  float f;
  int i;
  reserve_id_t id;

  read_pipe(p1, &i, 1);        // expected-error {{invalid number of arguments to function: read_pipe}}
  write_pipe(p2, &i, 2);       // expected-error {{invalid number of arguments to function: write_pipe}}

  read_pipe(p1, i);             // expected-error {{invalid argument type to function read_pipe (expecting: 'int *')}}
  write_pipe(p2, i);            // expected-error {{invalid argument type to function write_pipe (expecting: 'int *')}}

  read_pipe(f, &f);             // expected-error {{first argument to read_pipe must be a pipe type}}
  write_pipe(f, &f);            // expected-error {{first argument to write_pipe must be a pipe type}}

  read_pipe(p1, &f);            // expected-error {{argument type doesn't match pipe type}}
  write_pipe(p2, &f);           // expected-error {{argument type doesn't match pipe type}}


  read_pipe(p1, i, 0, &i);      // expected-error {{invalid argument type to function read_pipe (expecting: 'reserve_id_t')}}
  write_pipe(p2, i, 0, &i);     // expected-error {{invalid argument type to function write_pipe (expecting: 'reserve_id_t')}}

  read_pipe(p1, id, f, &i);     // expected-error {{invalid argument type to function read_pipe (expecting: 'unsigned int')}}
  write_pipe(p2, id, f, &i);    // expected-error {{invalid argument type to function write_pipe (expecting: 'unsigned int')}}

  read_pipe(p1, id, 0, &f);     // expected-error {{argument type doesn't match pipe type}}
  write_pipe(p2, id, 0, &f);    // expected-error {{argument type doesn't match pipe type}}
}

kernel void test_sema_invalid_read(global int *Dst, write_only pipe int Pipe) {
  read_pipe(Pipe, Dst);         // expected-error {{invalid pipe access modifier (expecting read_only)}}
}

kernel void test_sema_invalid_write(global int *Src, read_only pipe int Pipe) {
  write_pipe(Pipe, Src);        // expected-error {{invalid pipe access modifier (expecting write_only)}}
}

kernel void test_invalid_reserved_id(reserve_id_t ID) { // expected-error {{'reserve_id_t' cannot be used as the type of a kernel parameter}}
}

bool test_id_comprision(void) {
  reserve_id_t id1, id2;
  return (id1 == id2);          // expected-error {{invalid operands to binary expression ('reserve_id_t' and 'reserve_id_t')}}
}

void test5(pipe int *p1) {}     // expected-error {{pipes packet types cannot be of reference type}}
