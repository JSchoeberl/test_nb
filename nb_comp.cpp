#include <comp.hpp>
using namespace ngcomp;

#include <nanobind/nanobind.h>
#include <nanobind/operators.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/shared_ptr.h>

namespace py = nanobind;

NB_MODULE(comp, m) {

  py::class_<MeshAccess> (m, "Mesh")
    .def(py::init<std::string>())
    ;

  py::class_<FESpace> (m, "FESpace")
    ;

  /*
  py::class_<H1HighOrderFESpace, FESpace> (m, "H1")
    .def(py::init<std::shared_ptr<MeshAccess>, Flags>())
    ;
  */

}
