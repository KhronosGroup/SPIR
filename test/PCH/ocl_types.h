/* Used with the ocl_types.cl test */

// image1d_t
typedef image1d_t img1d_t;

// image1d_array_t
typedef image1d_array_t img1darr_t;

// image1d_buffer_t
typedef image1d_buffer_t img1dbuff_t;

// image2d_t
typedef image2d_t img2d_t;

// image2d_array_t
typedef image2d_array_t img2darr_t;

// image3d_t
typedef image3d_t img3d_t;

// sampler_t
typedef sampler_t smp_t;

// event_t
typedef event_t evt_t;

// pipe specifier

typedef struct _person {
  int id;
  const char *name;
} Person;

void int_pipe_function(pipe int);

void person_pipe_function(pipe Person);
