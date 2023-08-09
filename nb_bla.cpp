#include <ngstd.hpp>
#include <bla.hpp>
using namespace ngbla;

#include <nanobind/nanobind.h>
#include <nanobind/operators.h>

namespace py = nanobind;

NB_MODULE(bla, m) {
  m.def("Hi", []{cout << "hi" << endl;});


  py::class_<Vector<double>> (m, "Vector")
    .def("__init__", [](Vector<double> * t, size_t n) { new (t) Vector<double>(n); })
    ;

  py::class_<Matrix<double>> (m, "Matrix")
    .def(py::init<size_t,size_t>())
    ;

}
