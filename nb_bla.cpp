#include <ngstd.hpp>
#include <bla.hpp>
using namespace ngbla;

#include <nanobind/nanobind.h>
#include <nanobind/operators.h>

namespace py = nanobind;

class MyVector
{
  size_t h;
  double * data;
public:
  MyVector (size_t ah)
    : h{ah}, data{new double[ah]} { }
};


NB_MODULE(bla, m) {
  m.def("Hi", []{cout << "hi" << endl;});

  py::class_<MyVector> (m, "MyVector")
    .def(py::init<size_t>())
    ;

  
  py::class_<Vector<double>> (m, "Vector")
    // .def(py::init<size_t>())
    .def("__init__", [](Vector<double> * t, size_t n) { new (t) Vector<double>(n); })
    ;

  py::class_<Matrix<double>> (m, "Matrix")
    .def(py::init<size_t,size_t>())
    ;

}
