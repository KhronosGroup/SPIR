// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -fsyntax-only -verify %s

typedef struct {
    unsigned int workDimension;
} ndrange_t;

extern int enqueue_kernel(queue_t, int, const ndrange_t,
                          int, const clk_event_t*, clk_event_t*,
                          void (^block)(local void *, ...), unsigned int,...);

extern queue_t get_default_queue();

extern int get_global_id(int);

extern ndrange_t get_ndrange();

typedef void (^MyBlock)(local void*, local int*);

typedef void (^MyGBlock)(global void*, local int*);

MyBlock myBlock = (MyBlock)^(local int *p1, local int *p2) {
  int id = get_global_id(0);
  p1[id] += p2[id];
};

MyGBlock mygBlock = (MyGBlock)^(global int *p1, local int *p2) {
  int id = get_global_id(0);
  p1[id] += p2[id];
};

void kernel f1(global int* a, global int* b) {
  clk_event_t e1, e2;
  clk_event_t events[1] = {e1};
  enqueue_kernel(get_default_queue(), 0, get_ndrange(), 1, events, &e2, myBlock, 2U, a); // expected-error {{variadic arguments passed to 'enqueue_kernel' has to be of type 'unsigned int'}}
}

void kernel f2(global int* a, global int* b) {
  clk_event_t e1, e2;
  clk_event_t events[1] = {e1};
  // Correct call.
  enqueue_kernel(get_default_queue(), 0, get_ndrange(), 1, events, &e2, myBlock, 2U, 1U);
}

void kernel f3(global int* a, global int* b) {
  clk_event_t e1, e2;
  clk_event_t events[1] = {e1};
  enqueue_kernel(get_default_queue(), 0, get_ndrange(), 1, events, &e2, myBlock, 2U, 1U, 3U); // expected-error {{number of local_size argument doesn't match the block's prototype}}
}

void kernel f4(global int* a, global int* b) {
  clk_event_t e1, e2;
  clk_event_t events[1] = {e1};
  enqueue_kernel(get_default_queue(), 0, get_ndrange(), 1, events, &e2, mygBlock, 2U, 1U); // expected-error {{block parameter given must take pointers to local memory as parameters (prototype is 'void (__global void *, __local int *)')}}
}
